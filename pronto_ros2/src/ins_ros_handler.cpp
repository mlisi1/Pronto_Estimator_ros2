#include "pronto_ros2/ins_ros_handler.hpp"



namespace pronto {

InsHandlerROS::InsHandlerROS() : Node("ins_handler_node")
{   
    
    // rclcpp::Node node("ins_handler_node");
    tf2_ros::Buffer tf_imu_to_body_buffer_(this->get_clock());
    tf2_ros::TransformListener tf_imu_to_body_listener_(tf_imu_to_body_buffer_);

    const std::string ins_param_prefix = "ins/";
    std::string imu_frame = "imu";

    this->get_parameter(ins_param_prefix + "frame", imu_frame);

    std::string base_frame = "base";
    // nh_.param<std::string>("base_link_name", base_frame, "base");
    if (!this->get_parameter("base_link_name", base_frame)) {
        base_frame = "base";
    }
    RCLCPP_INFO_STREAM(this->get_logger(), "[InsHandlerROS] Name of base_link: '" << base_frame << "'");
    Eigen::Isometry3d ins_to_body = Eigen::Isometry3d::Identity();
    while(rclcpp::ok()) {
        try {
            geometry_msgs::msg::TransformStamped temp_transform = tf_imu_to_body_buffer_.lookupTransform(base_frame, imu_frame, rclcpp::Time(0));
            ins_to_body = tf2::transformToEigen(temp_transform.transform);
            RCLCPP_INFO_STREAM(this->get_logger(), "IMU (" << imu_frame <<") to base (" << base_frame << ") transform: translation=(" << ins_to_body.translation().transpose() << "), rotation=(" << ins_to_body.rotation() << ")");
            break;
        }
        catch (const tf2::TransformException& ex) {
            RCLCPP_ERROR(this->get_logger(), "%s", ex.what());
            // ros::Duration(1.0).sleep();
            rclcpp::sleep_for(std::chrono::seconds(1));
        }
    }

    InsConfig cfg;

    if(!this->get_parameter(ins_param_prefix + "num_to_init", cfg.num_to_init)){
        RCLCPP_WARN_STREAM(this->get_logger(), "Couldn't get param \""
                        << this->get_name() << "/" << ins_param_prefix
                        << "num_to_init\". Using default: "
                        << cfg.num_to_init);
    } else {
        RCLCPP_INFO_STREAM(this->get_logger(), "num_to_init: " << cfg.num_to_init);
    }

    if(!this->get_parameter(ins_param_prefix + "accel_bias_update_online", cfg.accel_bias_update_online)){
        RCLCPP_WARN_STREAM(this->get_logger(), "Couldn't get param \""
                        << this->get_name()  << "/" << ins_param_prefix
                        << "accel_bias_update_online\". Using default: "
                        << cfg.accel_bias_update_online);
    }
    if(!this->get_parameter(ins_param_prefix + "gyro_bias_update_online", cfg.gyro_bias_update_online)){
        RCLCPP_WARN_STREAM(this->get_logger(), "Couldn't get param \""
                        << this->get_name()  << "/" << ins_param_prefix
                        << "gyro_bias_update_online\". Using default: "
                        << cfg.gyro_bias_update_online);
    }
    if(!this->get_parameter(ins_param_prefix + "accel_bias_recalc_at_start", cfg.accel_bias_recalc_at_start)){
        RCLCPP_WARN_STREAM(this->get_logger(), "Couldn't get param \""
                        << this->get_name()  << "/" << ins_param_prefix
                        << "accel_bias_recalc_at_start\". Using default: "
                        << cfg.accel_bias_recalc_at_start);

    }
    if(!this->get_parameter(ins_param_prefix + "gyro_bias_recalc_at_start", cfg.gyro_bias_recalc_at_start)){
        RCLCPP_WARN_STREAM(this->get_logger(), "Couldn't get param \""
                        << this->get_name()  << "/" << ins_param_prefix
                        << "gyro_bias_recalc_at_start\". Using default: "
                        << cfg.gyro_bias_recalc_at_start);
    }
    if(!this->get_parameter(ins_param_prefix + "timestep_dt", cfg.dt)){
        RCLCPP_WARN_STREAM(this->get_logger(), "Couldn't get param \""
                        << this->get_name()  << "/" << ins_param_prefix
                        << "timestep_dt\". Using default: "
                        << cfg.dt);
    }
    std::vector<double> accel_bias_initial_v;
    std::vector<double> gyro_bias_initial_v;
    if(!this->get_parameter(ins_param_prefix + "accel_bias_initial", accel_bias_initial_v)){
        RCLCPP_WARN_STREAM(this->get_logger(), "Couldn't get param \""
                        << this->get_name()  << "/" << ins_param_prefix
                        << "accel_bias_initial\". Using default: "
                        << cfg.accel_bias_initial.transpose());
    } else {
        cfg.accel_bias_initial = Eigen::Map<Eigen::Vector3d, Eigen::Unaligned>(accel_bias_initial_v.data());
        RCLCPP_INFO_STREAM(this->get_logger(), "accel_bias_initial: " << cfg.accel_bias_initial.transpose());
    }


    if(!this->get_parameter(ins_param_prefix + "gyro_bias_initial", gyro_bias_initial_v)){
        RCLCPP_WARN_STREAM(this->get_logger(), "Couldn't get param \""
                        << this->get_name()  << "/" << ins_param_prefix
                        << "gyro_bias_initial\". Using default: "
                        << cfg.gyro_bias_initial.transpose());
    } else {
        cfg.gyro_bias_initial = Eigen::Map<Eigen::Vector3d, Eigen::Unaligned>(gyro_bias_initial_v.data());
        RCLCPP_INFO_STREAM(this->get_logger(), "gyro_bias_initial: " << cfg.gyro_bias_initial.transpose());
    }


    if(!this->get_parameter(ins_param_prefix + "max_initial_gyro_bias", cfg.max_initial_gyro_bias)){
        RCLCPP_WARN_STREAM(this->get_logger(), "Couldn't get param \""
                        << this->get_name()  << "/" << ins_param_prefix
                        << "max_initial_gyro_bias\". Using default: "
                        << cfg.max_initial_gyro_bias);
    }

    if(!this->get_parameter(ins_param_prefix + "topic", imu_topic_)){
        RCLCPP_WARN_STREAM(this->get_logger(), "Couldn't get param \""
                        << this->get_name()  << "/" << ins_param_prefix
                        << "topic\". Using default: "
                        << imu_topic_);
    }
    int downsample_factor = downsample_factor_;
    if(!this->get_parameter(ins_param_prefix + "downsample_factor", downsample_factor)){
        RCLCPP_WARN_STREAM(this->get_logger(), "Couldn't get param \""
                        << this->get_name()  << "/" << ins_param_prefix
                        << "downsample_factor\". Using default: "
                        << downsample_factor);
    } else {
        downsample_factor_ = downsample_factor;
    }


    if(!this->get_parameter(ins_param_prefix + "roll_forward_on_receive", roll_forward_on_receive_)){
        RCLCPP_WARN_STREAM(this->get_logger(), "Couldn't get param \""
                        << this->get_name()  << "/" << ins_param_prefix
                        << "roll_forward_on_receive\". Using default: "
                        << roll_forward_on_receive_);
    }
    int utime_offset = utime_offset_;
    if(!this->get_parameter(ins_param_prefix + "utime_offset", utime_offset)){
        RCLCPP_WARN_STREAM(this->get_logger(), "Couldn't get param \""
                        << this->get_name()  << "/" << ins_param_prefix
                        << "utime_offset\". Using default: "
                        << utime_offset);
    } else {
        utime_offset_ = utime_offset;
    }

    double std_accel = 0;
    double std_gyro = 0;
    double std_gyro_bias = 0;
    double std_accel_bias = 0;

    if(!this->get_parameter(ins_param_prefix + "q_gyro", std_gyro)){
        RCLCPP_WARN_STREAM(this->get_logger(), "Couldn't get param \""
                        << this->get_name()  << "/" << ins_param_prefix
                        << "q_gyro\". Using default: "
                        << std_gyro);
    }
    if(!this->get_parameter(ins_param_prefix + "q_gyro_bias", std_gyro_bias)){
        RCLCPP_WARN_STREAM(this->get_logger(), "Couldn't get param \""
                        << this->get_name()  << "/" << ins_param_prefix
                        << "q_gyro_bias\". Using default: "
                        << std_gyro_bias);
    }
    if(!this->get_parameter(ins_param_prefix + "q_accel", std_accel)){
        RCLCPP_WARN_STREAM(this->get_logger(), "Couldn't get param \""
                        << this->get_name()  << "/" << ins_param_prefix
                        << "q_accel\". Using default: "
                        << std_accel);
    }
    if(!this->get_parameter(ins_param_prefix + "q_accel_bias", std_accel_bias)){
        RCLCPP_WARN_STREAM(this->get_logger(), "Couldn't get param \""
                        << this->get_name()  << "/" << ins_param_prefix
                        << "q_accel_bias\". Using default: "
                        << std_accel_bias);
    }

    cfg.cov_accel = std::pow(std_accel, 2);
    cfg.cov_gyro = std::pow(std_gyro * M_PI / 180.0, 2);
    cfg.cov_accel_bias = std::pow(std_accel_bias, 2);
    cfg.cov_gyro_bias = std::pow(std_gyro_bias * M_PI / 180.0,2);

    ins_module_ = InsModule(cfg, ins_to_body);
}

RBISUpdateInterface* InsHandlerROS::processMessage(const sensor_msgs::msg::Imu *imu_msg, StateEstimator *est){
    // keep one every downsample_factor messages
    if(counter++ % downsample_factor_ != 0){
        return nullptr;
    }
    msgToImuMeasurement(*imu_msg, imu_meas_, utime_offset_);
    return ins_module_.processMessage(&imu_meas_, est);
}

bool InsHandlerROS::processMessageInit(const sensor_msgs::msg::Imu *imu_msg,
                        const std::map<std::string, bool> &sensor_initialized,
                        const RBIS &default_state,
                        const RBIM &default_cov,
                        RBIS &init_state,
                        RBIM &init_cov){
    msgToImuMeasurement(*imu_msg, imu_meas_);
    return ins_module_.processMessageInit(&imu_meas_,
                                          sensor_initialized,
                                          default_state,
                                          default_cov,
                                          init_state,
                                          init_cov);

}
} // namespace pronto
