#include "pronto_ros2_controller/pronto_controller.hpp"

#include "pluginlib/class_list_macros.hpp"
#define VEC3 3
#define QUAT 4
#define JNT_VAR 3

namespace pronto_controller
{
Pronto_Controller::Pronto_Controller() {};

Pronto_Controller::~Pronto_Controller() {};

CallbackReturn Pronto_Controller::on_init()
{
    RCLCPP_INFO(rclcpp::get_logger("PRONTO_ESTIMATOR INIT"), "Started Pronto Estimator Controller");

    try {
        // declaration of all the estimator param covariances
        for (int i = 0; i < COV_PAR_NUM; i++) {
            // RCLCPP_INFO(rclcpp::get_logger("PRONTO_ESTIMATOR INIT"),"Declared Parameter %s",est_params_[i].c_str());
            auto_declare<double>(est_params_[i], 0.0);
        }
        // RCLCPP_INFO(rclcpp::get_logger("PRONTO_ESTIMATOR INIT"),"Declared Covariance parameter");

        //declaration of all the estimator param states
        for (int i = COV_PAR_NUM; i < COV_PAR_NUM + STT_PAR_NUM; i++) {
            // RCLCPP_INFO(rclcpp::get_logger("PRONTO_ESTIMATOR INIT"),"Declared Parameter %s",est_params_[i].c_str());
            auto_declare<std::vector<double>>(est_params_[i], {0.0, 0.0, 0.0});
        }
        // RCLCPP_INFO(rclcpp::get_logger("PRONTO_ESTIMATOR INIT"),"Declared state param");
        //declaration of all the estimator topic
        for (int i = 0; i < PRONTO_NAMES; i++) {
            auto_declare<std::string>(output_params_[i], std::string());
            // RCLCPP_INFO(rclcpp::get_logger("PRONTO_ESTIMATOR INIT"),"Declared Parameter %s",output_params_[i].c_str());
        }
        // RCLCPP_INFO(rclcpp::get_logger("PRONTO_ESTIMATOR INIT"),"Declared topic names param");
        //declaration of output mode and history
        for (int i = PRONTO_NAMES; i < PRONTO_NAMES + PUB_SET_UP; i++) {
            auto_declare<bool>(output_params_[i], false);
            // RCLCPP_INFO(rclcpp::get_logger("PRONTO_ESTIMATOR INIT"),"Declared Parameter %s %d of %d",output_params_[i].c_str(),i,PRONTO_NAMES+PUB_SET_UP);
        }
        // RCLCPP_INFO(rclcpp::get_logger("PRONTO_ESTIMATOR INIT"),"Declared Parameter history_span pre declared");

        auto_declare<long int>("utime_history_span", 100);

        // RCLCPP_INFO(rclcpp::get_logger("PRONTO_ESTIMATOR INIT"),"Declared Parameter history_span");

        auto_declare<std::vector<std::string>>("joints", std::vector<std::string>());

        // RCLCPP_INFO(rclcpp::get_logger("PRONTO_ESTIMATOR INIT"),"Declared Parameter joints");


        auto_declare<std::string>("urdf_path", std::string());

        // RCLCPP_INFO(rclcpp::get_logger("PRONTO_ESTIMATOR INIT"),"Declared Parameter urdf");
    }
    catch (const std::exception& e) {
        RCLCPP_ERROR(get_node()->get_logger(), "Exception thrown during declaration of joints name with message: %s", e.what());
    }
    RCLCPP_INFO(rclcpp::get_logger("PRONTO_ESTIMATOR INIT"), "Construct the Ros2 Control Estimator Pronto-based");
    return CallbackReturn::SUCCESS;
};

CallbackReturn Pronto_Controller::on_configure(const rclcpp_lifecycle::State&)
{
    //define qos of all topic as best effort
    rclcpp::QoS out_qos(10);
    std::string name_spot;
    std::tuple<double, double, double> zeros = {0.0, 0.0, 0.0};
    out_qos.reliability(rclcpp::ReliabilityPolicy::BestEffort);

    RCLCPP_INFO(get_node()->get_logger(), "on_configure: init broadcaster ");
    tf2_broadcaster_ = std::make_shared<tf2_ros::TransformBroadcaster>(*get_node());

    //get the parameter to set up the controller publisher
    for (int i = PRONTO_NAMES; i < PRONTO_NAMES + PUB_SET_UP; i++) {
        if (!get_node()->get_parameter(output_params_[i], pub_data_[i - PRONTO_NAMES])) {
            RCLCPP_ERROR(get_node()->get_logger(), "Error in parse the parameter %s", output_params_[i].c_str());
            return CallbackReturn::ERROR;
        }
    }
    RCLCPP_ERROR(get_node()->get_logger(), "pub data is %d,%d,%d", pub_data_[0], pub_data_[1], pub_data_[2]);


    //get the parameter declared in structure
    for (int i = 0; i < PRONTO_NAMES; i++) {
        if (!get_node()->get_parameter(output_params_[i], name_spot)) {
            RCLCPP_ERROR(get_node()->get_logger(), "Error in parse the parameter %s", output_params_[i].c_str());
            return CallbackReturn::ERROR;
        }
        RCLCPP_INFO(get_node()->get_logger(), "on_configure: index of for cycle is %d ", i);
        name_spot = "~/" + name_spot;
        switch (i) {
        // case create topic pose
        case 0:
            if (pub_data_[i % 2]) {
                RCLCPP_ERROR(get_node()->get_logger(), "creating pose publisher");
                pose_pub_ = get_node()->create_publisher<Pose_with_Cov_msg>(name_spot, out_qos);
            }
            break;
        // set up frame id in pose message
        case 1:
            pose_msg_.header.set__frame_id(name_spot);
            break;
        // case create topic twist
        case 2:
            if (pub_data_[i % 2])
                twist_pub_ = get_node()->create_publisher<Twist_with_Cov_msg>(name_spot, out_qos);
            break;
        // set up frame id in twist message
        case 3:
            twist_msg_.header.set__frame_id(name_spot);
            break;
        // set up tf transform if need
        case 4:
            transform_msg_.header.frame_id = pose_msg_.header.frame_id;
            transform_msg_.child_frame_id = name_spot;
            break;
        default:
            return CallbackReturn::ERROR;
            break;
        }
    }
    RCLCPP_INFO(get_node()->get_logger(), "on_configure: created topic and frame name");
    // set hystoric utime
    long int data_history;
    if (!get_node()->get_parameter("utime_history_span", data_history)) {
        RCLCPP_ERROR(get_node()->get_logger(), "Error parsing the history utime");
        return CallbackReturn::ERROR;
    }

    history_span_ = static_cast<u_int64_t>(data_history);
    if (!get_node()->get_parameter("joints", joints_)) {
        RCLCPP_ERROR(get_node()->get_logger(), "Error parsing the joints name");
        return CallbackReturn::ERROR;
    }
    if (joints_.empty()) {
        RCLCPP_INFO(get_node()->get_logger(), "the joints could not be empty");
        return CallbackReturn::ERROR;
    }

    if (!get_node()->get_parameter("urdf_path", urdf_path_)) {
        RCLCPP_ERROR(get_node()->get_logger(), "Error parsing the urdf name");
        return CallbackReturn::ERROR;
    }

    for (auto& jnt_n : joints_) {
        jnt_stt_.insert({jnt_n, zeros});
    }
    // initialize state and covariance from parameter calling the init function

    initializeState();
    RCLCPP_INFO(get_node()->get_logger(), "on_configure: made state initialization");
    initializeCovariance();
    RCLCPP_INFO(get_node()->get_logger(), "on_configure: made covariance initialization");
    // create the proprioceptive and exteroceptive sensormanager and build the data structure
    propr_man_ = std::make_unique<Prop_Sensor_Manager>(get_node(), jnt_stt_, urdf_path_);
    RCLCPP_INFO(get_node()->get_logger(), "on_configure:create prop sens menager");

    propr_man_->conf_prop_sens();
    // exter_man_ = std::make_unique<Exte_Sensor_Manager>(get_node());
    RCLCPP_INFO(get_node()->get_logger(), "Completed estimator Configuration ");
    return CallbackReturn::SUCCESS;
};

CallbackReturn Pronto_Controller::on_activate(const rclcpp_lifecycle::State&)
{
    // here can not be done the filter initialization because need some particel to initialize the bias and the orientation
    // will be done a enumarate to separate the two different phases
    return CallbackReturn::SUCCESS;
};

CallbackReturn Pronto_Controller::on_deactivate(const rclcpp_lifecycle::State&)
{
    return CallbackReturn::SUCCESS;
};

CallbackReturn Pronto_Controller::on_cleanup(const rclcpp_lifecycle::State&)
{
    return CallbackReturn::SUCCESS;
};

controller_interface::InterfaceConfiguration Pronto_Controller::command_interface_configuration() const
{
    controller_interface::InterfaceConfiguration cmd_int_cnf;
    cmd_int_cnf.type = controller_interface::interface_configuration_type::NONE;
    return cmd_int_cnf;
};

controller_interface::InterfaceConfiguration Pronto_Controller::state_interface_configuration() const
{
    controller_interface::InterfaceConfiguration stt_int_cnf;
    std::string imu_name = "imu_sensor/";
    stt_int_cnf.type = controller_interface::interface_configuration_type::INDIVIDUAL;

    // add imu interface first
    stt_int_cnf.names.push_back(imu_name + hardware_interface::HW_IF_LIN_ACC_X);
    stt_int_cnf.names.push_back(imu_name + hardware_interface::HW_IF_LIN_ACC_Y);
    stt_int_cnf.names.push_back(imu_name + hardware_interface::HW_IF_LIN_ACC_Z);

    stt_int_cnf.names.push_back(imu_name + hardware_interface::HW_IF_ANG_SPD_X);
    stt_int_cnf.names.push_back(imu_name + hardware_interface::HW_IF_ANG_SPD_Y);
    stt_int_cnf.names.push_back(imu_name + hardware_interface::HW_IF_ANG_SPD_Z);

    stt_int_cnf.names.push_back(imu_name + hardware_interface::HW_IF_QUATERN_W);
    stt_int_cnf.names.push_back(imu_name + hardware_interface::HW_IF_QUATERN_X);
    stt_int_cnf.names.push_back(imu_name + hardware_interface::HW_IF_QUATERN_Y);
    stt_int_cnf.names.push_back(imu_name + hardware_interface::HW_IF_QUATERN_Z);

    // add joints inteface
    for (auto& jnt : joints_) {
        stt_int_cnf.names.push_back(jnt + "/" + hardware_interface::HW_IF_POSITION);
        stt_int_cnf.names.push_back(jnt + "/" + hardware_interface::HW_IF_VELOCITY);
        stt_int_cnf.names.push_back(jnt + "/" + hardware_interface::HW_IF_EFFORT);
    }


    return stt_int_cnf;
};

controller_interface::return_type Pronto_Controller::update(const rclcpp::Time& time, const rclcpp::Duration& period)
{
    // get the imu and joint data from HW interface
    get_IMU_data(time);
    get_joints_data();


    if (fil_stt_ == Filter_State::NOT_INITIALIZED) {
        // try to configure the filter
        RCLCPP_INFO(get_node()->get_logger(), "the filter is not initialized");
        if (!isFilterInitialized()) {
            // try to init the INS

            if (propr_man_->isInsInitialized(
                    &imu_data_,
                    sens_init_stt_,
                    default_state_,
                    default_cov_,
                    init_state_,
                    init_cov_)) {
                initializeFilter();
                RCLCPP_INFO(get_node()->get_logger(), "the filter is initialized");
                fil_stt_ = Filter_State::INITIALIZED;
            }
        }
    } else if (fil_stt_ == Filter_State::INITIALIZED) {
        // set the update dt get from the update arguments

        propr_man_->setInsTimeStep(period);
        // get the update from imu sensor
        pronto::RBISUpdateInterface* update_imu = propr_man_->processInsData(&imu_data_, stt_est_.get());

        // update the filter with Ins
        stt_est_->addUpdate(update_imu,true);
        //update the proprioceptive update

        pronto::RBISUpdateInterface* update_odom = propr_man_->update_odom(time, stt_est_.get());
        // RCLCPP_INFO(get_node()->get_logger(),"pass");
        // // update the filter with Ins
        if(update_odom != nullptr)
            stt_est_->addUpdate(update_odom, true);
        // RCLCPP_INFO(get_node()->get_logger(),"pass");
        //get the updated state anc cov
        stt_est_->getHeadState(head_state_, head_cov_);

        // get the base state and build the ros2 message
        // start from velocity
        Eigen::Quaterniond orient;

        orient = head_state_.orientation();
        Eigen::Matrix3d rot_mat = orient.toRotationMatrix();
        Eigen::Vector3d vel_base = Eigen::Vector3d::Zero();
        BlockToVector3d(head_state_.velocity(), twist_msg_.twist.twist.linear);
        vel_base << twist_msg_.twist.twist.linear.x, twist_msg_.twist.twist.linear.y, twist_msg_.twist.twist.linear.z;
        vel_base = rot_mat * vel_base;

        twist_msg_.twist.twist.linear.set__x(vel_base(0));
        twist_msg_.twist.twist.linear.set__y(vel_base(1));
        twist_msg_.twist.twist.linear.set__z(vel_base(2));
        BlockToVector3d(head_state_.angularVelocity(), twist_msg_.twist.twist.angular);

        twist_msg_.header.set__stamp(rclcpp::Time(head_state_.utime * 1000));


        twist_msg_.twist.covariance.fill(0.0);

        Eigen::Block<pronto::RBIM, 3, 3> vel_cov = head_cov_.block<3, 3>(pronto::RBIS::velocity_ind, pronto::RBIS::velocity_ind);
        Eigen::Block<pronto::RBIM, 3, 3> omega_cov = head_cov_.block<3, 3>(pronto::RBIS::angular_velocity_ind, pronto::RBIS::angular_velocity_ind);

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                twist_msg_.twist.covariance[6 * i + j] = vel_cov(i, j);
                twist_msg_.twist.covariance[6 * (i + 3) + j + 3] = omega_cov(i, j);
            }
        }

        twist_pub_->publish(twist_msg_);

        //pass to pose
        BlockToPoint(head_state_.position(), pose_msg_.pose.pose.position);
        QuaternionToMsg(head_state_.orientation(), pose_msg_.pose.pose.orientation);


        pose_msg_.header.stamp = rclcpp::Time(head_state_.utime * 1000);

        // RCLCPP_INFO(get_node()->get_logger(),"the pos is %f,%f,%f",pose_msg_.pose.pose.position.x,pose_msg_.pose.pose.position.y,pose_msg_.pose.pose.position.z);
        pose_pub_->publish(pose_msg_);

        // TODO add the tranform data for the base respect to the odom
        // update the filter state using the proprioceptive data
    } else {
        // if the state has come in error state then will return the error type
        return controller_interface::return_type::ERROR;
    }
    return controller_interface::return_type::OK;
};

bool Pronto_Controller::initializeINS()
{
    // if(isFilterInitialized())
    //     return true;

    // // if all sensor are initialied try to initialize imu
    // if(!exter_man_->isExteroceptiveSensorInit())
    //     return false;
    // // if imu will be initialize correctly also the filter will be initialize

    return propr_man_->isInsInitialized(
        &imu_data_,
        exter_man_->get_initialized_sens(),
        default_state_,
        default_cov_,
        init_state_,
        init_cov_);
};

void Pronto_Controller::initializeState()
{
    rclcpp::Parameter init_vec;
    std::vector<double> vect;
    RCLCPP_INFO(get_node()->get_logger(), "start init state");
    for (int i = COV_PAR_NUM; i < COV_PAR_NUM + STT_PAR_NUM; i++) {
        // RCLCPP_INFO(get_node()->get_logger(),"get parameter %d-th %s",i,est_params_[i].c_str());
        try {
            vect = get_node()->get_parameter(est_params_[i]).as_double_array();
        }
        catch (std::exception& e) {
            RCLCPP_INFO(get_node()->get_logger(), "the error is %s", e.what());
        }
        // if(!get_node()->get_parameter(est_params_[i],init_vec))
        // {
        //     RCLCPP_ERROR(get_node()->get_logger(),"Error in parse the parameter %s, state not initialized", output_params_[i].c_str());
        //     return;
        // }
        // RCLCPP_INFO(get_node()->get_logger(),"get parameter");
        // vect = init_vec.as_double_array();
        // RCLCPP_INFO(get_node()->get_logger(),"the state to init are %d and the vector are [%f,%f,%f]",i-COV_PAR_NUM,vect[0],vect[1],vect[2]);
        switch (i - COV_PAR_NUM) {
        case 1:
            // set linear velocity
            default_state_.velocity() = Eigen::Map<Eigen::Vector3d>(vect.data());
            break;
        case 2:
            default_state_.angularVelocity() = Eigen::Map<Eigen::Vector3d>(vect.data());
            break;
        case 3:
            default_state_.position() = Eigen::Map<Eigen::Vector3d>(vect.data());
            break;
        case 4:
            default_state_.orientation() = pronto::rotation::setQuatEulerAngles(Eigen::Map<Eigen::Vector3d>(vect.data()));
            break;

        default:
            break;
        }
    }
    init_state_ = default_state_;
    head_state_ = default_state_;
    RCLCPP_INFO(get_node()->get_logger(), "Filter Initial State initialized.");
};

void Pronto_Controller::initializeCovariance()
{
    double init_val = 0.0;
    std::array<double, 7> cov;
    for (int i = 0; i < COV_PAR_NUM; i++) {
        //get tje param and manafe the error
        if (!get_node()->get_parameter(est_params_[i], init_val)) {
            RCLCPP_ERROR(get_node()->get_logger(), "Error in parse the parameter %s, state not initialized", output_params_[i].c_str());
            return;
        }
        // convert all to radiant
        cov[i] = init_val = M_PI / 180.0;
    }

    //collect param in a compact way
    Eigen::Vector3d xyz_cov_diag =
        Eigen::Array3d(cov[3], cov[3], cov[4]).square();

    Eigen::Vector3d init_chi_cov_diag =
        Eigen::Array3d(cov[1], cov[1], cov[2]).square();

    //set all the sub-blocks of the covariance matrix
    default_cov_.block<3, 3>(pronto::RBIS::velocity_ind, pronto::RBIS::velocity_ind) = std::pow(cov[0], 2) * Eigen::Matrix3d::Identity();
    default_cov_.block<3, 3>(pronto::RBIS::chi_ind, pronto::RBIS::chi_ind) = init_chi_cov_diag.asDiagonal();
    default_cov_.block<3, 3>(pronto::RBIS::position_ind, pronto::RBIS::position_ind) = xyz_cov_diag.asDiagonal();
    default_cov_.block<3, 3>(pronto::RBIS::gyro_bias_ind, pronto::RBIS::gyro_bias_ind) = Eigen::Matrix3d::Identity()
                                                                                         * std::pow(cov[5], 2);
    default_cov_.block<3, 3>(pronto::RBIS::accel_bias_ind, pronto::RBIS::accel_bias_ind) = Eigen::Matrix3d::Identity()
                                                                                           * std::pow(cov[6], 2);

    init_cov_ = default_cov_;
    head_cov_ = default_cov_;
    RCLCPP_INFO(get_node()->get_logger(), "Filter Initial Covariance initialized.");
};

bool Pronto_Controller::initializeFilter()
{
    if (!isExteroceptiveSensorInit()) {
        return false;
    }
    if (isFilterInitialized()) {
        return true;
    }

    stt_est_.reset(new StateEst(new pronto::RBISResetUpdate(init_state_, init_cov_, pronto::RBISUpdateInterface::reset, imu_data_.utime), history_span_));

    filter_initialized_ = true;
    RCLCPP_INFO(get_node()->get_logger(), "Filter Initial Covariance initialized.");
    return true;
}

void Pronto_Controller::get_IMU_data(rclcpp::Time time)
{
    for (int i = 0; i < VEC3; i++) {
        imu_data_.acceleration(i) = state_interfaces_[i].get_value();
        imu_data_.omega(i) = state_interfaces_[i + VEC3].get_value();
    }
    // imu_data_.acceleration = pronto::g_vec;
    // imu_data_.omega = Eigen::Vector3d::Zero();
    imu_data_.orientation = Eigen::Quaterniond(
        state_interfaces_[2 * VEC3].get_value(),
        state_interfaces_[2 * VEC3 + 1].get_value(),
        state_interfaces_[2 * VEC3 + 2].get_value(),
        state_interfaces_[2 * VEC3 + 3].get_value());
    imu_data_.utime = time.nanoseconds() / 1000;

    // imu_data_.acceleration = Eigen::Vector3d(0.0,0.0,9.81);
    // imu_data_.omega = Eigen::Vector3d::Zero();
}


void Pronto_Controller::get_joints_data()
{
    std::string type;
    std::tuple<double, double, double> stt;
    for (size_t i = 0; i < joints_.size(); i++) {
        try {
            stt = {
                state_interfaces_[3 * i + QUAT + 2 * VEC3].get_value(),
                state_interfaces_[3 * i + 1 + QUAT + 2 * VEC3].get_value(),
                state_interfaces_[3 * i + 2 + QUAT + 2 * VEC3].get_value()};
            jnt_stt_.at(joints_[i]).swap(stt);
            // RCLCPP_INFO(get_node()->get_logger(),"the value joint %s q_dot is %f",joints_[i].c_str(),std::get<1>(jnt_stt_.at(joints_[i])));
        }
        catch (const std::exception& e) {
            std::cerr << e.what() << '\n';
            assert(false);
        }
    }
}

};    // namespace pronto_controller

#include <pluginlib/class_list_macros.hpp>

PLUGINLIB_EXPORT_CLASS(pronto_controller::Pronto_Controller, controller_interface::ControllerInterface);