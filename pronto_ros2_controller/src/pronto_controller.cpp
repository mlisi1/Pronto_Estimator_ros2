#include "pronto_ros2_controller/pronto_controller.hpp"
#include "pluginlib/class_list_macros.hpp"

namespace pronto_controller
{
    Pronto_Controller::Pronto_Controller():
    stt_est_(nullptr)
    {
        //declaration of all the estimator param covariances
        for(int i = 0; i < COV_PAR_NUM; i++)
            auto_declare<double>(est_params_[i],0.0);
        
        //declaration of all the estimator param states
        for(int i = COV_PAR_NUM; i < COV_PAR_NUM + STT_PAR_NUM; i++)
            auto_declare<std::vector<double>>(est_params_[i],std::vector<double>());
        
        //declaration of all the estimator topic
        for(int i = 0; i < PRONTO_NAMES; i++)
            auto_declare<std::string>(output_params_[i],std::string());
        
        //declaration of output mode and history 
        for(int i = PRONTO_NAMES; i < PRONTO_NAMES+PUB_SET_UP; i++)
            auto_declare<bool>(output_params_[i],false);

        auto_declare<long int>("utime_history_span",100);

        RCLCPP_INFO(get_node()->get_logger(),"Construct the Ros2 Control Estimator Pronto-based");
    };
    Pronto_Controller::~Pronto_Controller()
    {
    };
    
    CallbackReturn Pronto_Controller::on_init() 
    {   

        //define qos of all topic as best effort 
        rclcpp::QoS out_qos(10);
        std::string name_spot;
        out_qos.reliability(rclcpp::ReliabilityPolicy::BestEffort);


        tf2_broadcaster_ = std::make_shared<tf2_ros::TransformBroadcaster>(*get_node());

        //get the parameter to set up the controller publisher 
        for(int i = PRONTO_NAMES; i < PRONTO_NAMES+PUB_SET_UP; i++)
        {
           if(!get_node()->get_parameter(output_params_[i],pub_data_[i]))
            {
                RCLCPP_ERROR(get_node()->get_logger(),"Error in parse the parameter %s", output_params_[i]);
                return CallbackReturn::ERROR;
            }
        }

        //get the parameter declared in structure
        for(int i = 0; i < PRONTO_NAMES; i++)
        {

            if(!get_node()->get_parameter(output_params_[i],name_spot))
            {
                RCLCPP_ERROR(get_node()->get_logger(),"Error in parse the parameter %s", output_params_[i]);
                return CallbackReturn::ERROR;
            }
            switch (i)
            {
            // case create topic pose
            case 0:
                if(pub_data_[i%2])
                    pose_pub_ = get_node()->create_publisher<Pose_with_Cov_msg>(name_spot,out_qos);
                break;
            // set up frame id in pose message
            case 1:
                pose_msg_.header.set__frame_id(name_spot);
                break;
            // case create topic twist
            case 2:
                if(pub_data_[i%2])
                    twist_pub_ = get_node()->create_publisher<Twist_with_Cov_msg>(name_spot,out_qos);
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

        // set hystoric utime
        if(!get_node()->get_parameter("utime_history_span", history_span_))
        {
            RCLCPP_ERROR(get_node()->get_logger(),"Error parsing the historu ustime");
            return CallbackReturn::ERROR;
        }

        return CallbackReturn::SUCCESS;
    };       

    
    CallbackReturn Pronto_Controller::on_configure(const rclcpp_lifecycle::State & previous_state)
    {
        // initialize state and covariance from parameter calling the init function 
        initializeState();
        initializeCovariance();
        return CallbackReturn::SUCCESS; 
    };

    CallbackReturn Pronto_Controller::on_activate(const rclcpp_lifecycle::State & previous_state)
    {
        return CallbackReturn::SUCCESS;
    };
    CallbackReturn Pronto_Controller::on_deactivate(const rclcpp_lifecycle::State & previous_state)
    {
        return CallbackReturn::SUCCESS;
    };
    CallbackReturn Pronto_Controller::on_cleanup(const rclcpp_lifecycle::State & previous_state) 
    {
        return CallbackReturn::SUCCESS;
    };

    controller_interface::InterfaceConfiguration Pronto_Controller::command_interface_configuration() const
    {
        controller_interface::InterfaceConfiguration cmd_int;
        return cmd_int;
    };
    controller_interface::InterfaceConfiguration Pronto_Controller::state_interface_configuration() const
    {
        controller_interface::InterfaceConfiguration stt_int;
        return stt_int;
    };

    controller_interface::return_type Pronto_Controller::update(
        const rclcpp::Time & time, const rclcpp::Duration & period
    )
    {
        return controller_interface::return_type::OK;
    };

    bool Pronto_Controller::initializeFilter()
    {
        

    };
    void Pronto_Controller::initializeState()
    {
        std::vector<double> init_vec = std::vector<double>(3,0.0);
        for(int i = COV_PAR_NUM; i < COV_PAR_NUM + STT_PAR_NUM; i++)
        {
            if(!get_node()->get_parameter(est_params_[i],init_vec))
            {
                RCLCPP_ERROR(get_node()->get_logger(),"Error in parse the parameter %s, state not initialized", output_params_[i]);
                return;
            }
            switch (i-COV_PAR_NUM)
            {
            case 1:
                // set linear velocity 
                default_state_.velocity() = Eigen::Map<Eigen::Vector3d>(init_vec.data());
                break;
            case 2:
                default_state_.angularVelocity() = Eigen::Map<Eigen::Vector3d>(init_vec.data());
                break;
            case 3:
                default_state_.position() = Eigen::Map<Eigen::Vector3d>(init_vec.data());
                break;
            case 4:
                default_state_.orientation() = pronto::rotation::setQuatEulerAngles(Eigen::Map<Eigen::Vector3d>(init_vec.data()));
                break;
            
            default:
                break;
            }
        init_state_ = default_state_;
        head_state_ = default_state_;
        RCLCPP_INFO(get_node()->get_logger(),"Filter Initial State initialized.");
        }

    };
   
    void Pronto_Controller::initializeCovariance()
    {
        double init_val = 0.0;
        std::array<double,7> cov;
        for(int i = 0; i < COV_PAR_NUM ; i++)
        {
            //get tje param and manafe the error 
            if(!get_node()->get_parameter(est_params_[i],init_val))
            {
                RCLCPP_ERROR(get_node()->get_logger(),"Error in parse the parameter %s, state not initialized", output_params_[i]);
                return;
            }
            // convert all to radiant
            cov[i] = init_val = M_PI / 180.0;
        }   
        
        //collect param in a compact way
        Eigen::Vector3d xyz_cov_diag =
        Eigen::Array3d(cov[3],cov[3],cov[4]).square();
        
        Eigen::Vector3d init_chi_cov_diag = 
        Eigen::Array3d(cov[1],cov[1],cov[2]).square();

        //set all the sub-blocks of the covariance matrix
        default_cov_.block<3, 3>(pronto::RBIS::velocity_ind, pronto::RBIS::velocity_ind) = std::pow(cov[0],2) * Eigen::Matrix3d::Identity();
        default_cov_.block<3, 3>(pronto::RBIS::chi_ind, pronto::RBIS::chi_ind) = init_chi_cov_diag.asDiagonal();
        default_cov_.block<3, 3>(pronto::RBIS::position_ind, pronto::RBIS::position_ind) = xyz_cov_diag.asDiagonal();
        default_cov_.block<3, 3>(pronto::RBIS::gyro_bias_ind,pronto::RBIS::gyro_bias_ind) = Eigen::Matrix3d::Identity()
            * std::pow(cov[5],2);
        default_cov_.block<3, 3>(pronto::RBIS::accel_bias_ind, pronto::RBIS::accel_bias_ind) = Eigen::Matrix3d::Identity()
            * std::pow(cov[6],2);

        init_cov_ = default_cov_;
        head_cov_ = default_cov_;
        RCLCPP_INFO(get_node()->get_logger(),"Filter Initial Covariance initialized.");
    };
    
    bool Pronto_Controller::initializeFilter()
    {
        if(!isExteroceptiveSensorInit())
        {
            return false;
        }
        if(isFilterInitialized())
        {
            return true;
        }
        
        stt_est_.reset(new StateEst(new pronto::RBISResetUpdate(init_state_,
                                                               init_cov_,
                                                               pronto::RBISUpdateInterface::reset,
                                                               init_state_.utime),
                                           history_span_));
        
    filter_initialized_ = true;
    RCLCPP_INFO(get_node()->get_logger(),"Filter Initial Covariance initialized.");
    return true;
    }

};

#include <pluginlib/class_list_macros.hpp>

PLUGINLIB_EXPORT_CLASS(pronto_controller::Pronto_Controller, controller_interface::ControllerInterface);