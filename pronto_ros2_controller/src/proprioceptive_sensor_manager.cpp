#include "pronto_ros2_controller/proprioceptive_sensor_manager.hpp"

namespace pronto_controller
{
    void Prop_Sensor_Manager::conf_ins()
    {
        // the change of the imu frame into base frame is done by the hardwareinterface
        Eigen::Affine3d ins_to_body = Eigen::Isometry3d::Identity();

        std::string ins_param_prefix = "ins";
        // start to get all parameters
        pronto::InsConfig cfg;


        if (!filt_controler_->get_parameter(ins_param_prefix + "num_to_init", cfg.num_to_init)) {
        RCLCPP_WARN_STREAM(filt_controler_->get_logger(),
        "Couldn't get param \"" 
        << filt_controler_->get_namespace() << "/" << ins_param_prefix 
        << "num_to_init\". Using default: "
        << cfg.num_to_init);
    } else {
        RCLCPP_INFO_STREAM(filt_controler_->get_logger(), 
            "num_to_init: " << cfg.num_to_init);
    }

    if (!filt_controler_->get_parameter(ins_param_prefix + "accel_bias_update_online", cfg.accel_bias_update_online)) {
        RCLCPP_WARN_STREAM(filt_controler_->get_logger(), 
            "Couldn't get param" << filt_controler_->get_namespace() << "/" 
            << ins_param_prefix << "accel_bias_update_online\". Using default: "
            << cfg.accel_bias_update_online);
    }
    if (!filt_controler_->get_parameter(ins_param_prefix + "gyro_bias_update_online", cfg.gyro_bias_update_online)) {
        RCLCPP_WARN_STREAM(filt_controler_->get_logger(), 
            "Couldn't get param " << filt_controler_->get_namespace() << "/" << ins_param_prefix 
            << "gyro_bias_update_online\". Using default: "
            << cfg.gyro_bias_update_online);
    }
    if (!filt_controler_->get_parameter(ins_param_prefix + "accel_bias_recalc_at_start", cfg.accel_bias_recalc_at_start)) {
        RCLCPP_WARN_STREAM(filt_controler_->get_logger(), 
            "Couldn't get param " << filt_controler_->get_namespace() << "/" << ins_param_prefix 
            << "accel_bias_recalc_at_start\". Using default: "
            << cfg.accel_bias_recalc_at_start);
    }
    if (!filt_controler_->get_parameter(ins_param_prefix + "gyro_bias_recalc_at_start", cfg.gyro_bias_recalc_at_start)) {
        RCLCPP_WARN_STREAM(filt_controler_->get_logger(), 
            "Couldn't get param " << filt_controler_->get_namespace() << "/" << ins_param_prefix 
            << "gyro_bias_recalc_at_start\". Using default: "
            << cfg.gyro_bias_recalc_at_start);
    }
    if (!filt_controler_->get_parameter(ins_param_prefix + "timestep_dt", cfg.dt)) {
        RCLCPP_WARN_STREAM(filt_controler_->get_logger(), 
            "Couldn't get param " << filt_controler_->get_namespace() << "/" << ins_param_prefix
            << "timestep_dt\". Using default: "
            << cfg.dt);
    }
    std::vector<double> accel_bias_initial_v;
    std::vector<double> gyro_bias_initial_v;
    if (!filt_controler_->get_parameter(ins_param_prefix + "accel_bias_initial", accel_bias_initial_v)) {
        RCLCPP_WARN_STREAM(filt_controler_->get_logger(), 
            "Couldn't get param " << filt_controler_->get_namespace() << "/" << ins_param_prefix 
            << "accel_bias_initial\". Using default: "
            << cfg.accel_bias_initial.transpose());
    } else {
        cfg.accel_bias_initial = Eigen::Map<Eigen::Vector3d, Eigen::Unaligned>(accel_bias_initial_v.data());
        RCLCPP_INFO_STREAM(filt_controler_->get_logger(), 
            "accel_bias_initial: " << cfg.accel_bias_initial.transpose());
    }

    if (!filt_controler_->get_parameter(ins_param_prefix + "gyro_bias_initial", gyro_bias_initial_v)) {
        RCLCPP_WARN_STREAM(filt_controler_->get_logger(), 
            "Couldn't get param " << filt_controler_->get_namespace() << "/" << ins_param_prefix 
            << "gyro_bias_initial\". Using default: "
            << cfg.gyro_bias_initial.transpose());
    } else {
        cfg.gyro_bias_initial = Eigen::Map<Eigen::Vector3d, Eigen::Unaligned>(gyro_bias_initial_v.data());
        RCLCPP_INFO_STREAM(filt_controler_->get_logger(), 
            "gyro_bias_initial: "
            << cfg.gyro_bias_initial.transpose());
    }

    if (!filt_controler_->get_parameter(ins_param_prefix + "max_initial_gyro_bias", cfg.max_initial_gyro_bias)) {
        RCLCPP_WARN_STREAM(filt_controler_->get_logger(), 
            "Couldn't get param " << filt_controler_->get_namespace() << "/" << ins_param_prefix 
            << "max_initial_gyro_bias\". Using default: "
            << cfg.max_initial_gyro_bias);
    }

 
    int downsample_factor = downsample_factor_;
    if (!filt_controler_->get_parameter(ins_param_prefix + "downsample_factor", downsample_factor)) {
        RCLCPP_WARN_STREAM(filt_controler_->get_logger(), 
            "Couldn't get param " << filt_controler_->get_namespace() << "/" << ins_param_prefix 
            << "downsample_factor\". Using default: "
            << downsample_factor);
    } else {
        downsample_factor_ = downsample_factor;
    }

    if (!filt_controler_->get_parameter(ins_param_prefix + "roll_forward_on_receive", roll_forward_on_receive_)) {
        RCLCPP_WARN_STREAM(filt_controler_->get_logger(), 
            "Couldn't get param " << filt_controler_->get_namespace() << "/" << ins_param_prefix 
            << "roll_forward_on_receive\". Using default: "
            << roll_forward_on_receive_);
    }
    int utime_offset = utime_offset_;
    if (!filt_controler_->get_parameter(ins_param_prefix + "utime_offset", utime_offset)) {
        RCLCPP_WARN_STREAM(filt_controler_->get_logger(), 
            "Couldn't get param " << filt_controler_->get_namespace() << "/" << ins_param_prefix 
            << "utime_offset\". Using default: "
            << utime_offset);
    } else {
        utime_offset_ = utime_offset;
    }

    double std_accel = 0;
    double std_gyro = 0;
    double std_gyro_bias = 0;
    double std_accel_bias = 0;

    if (!filt_controler_->get_parameter(ins_param_prefix + "q_gyro", std_gyro)) {
        RCLCPP_WARN_STREAM(filt_controler_->get_logger(), 
            "Couldn't get param " << filt_controler_->get_namespace() << "/" << ins_param_prefix 
            << "q_gyro\". Using default: "
            << std_gyro);
    }
    if (!filt_controler_->get_parameter(ins_param_prefix + "q_gyro_bias", std_gyro_bias)) {
        RCLCPP_WARN_STREAM(filt_controler_->get_logger(), 
            "Couldn't get param " << filt_controler_->get_namespace() << "/" << ins_param_prefix 
            << "q_gyro_bias\". Using default: "
            << std_gyro_bias);
    }
    if (!filt_controler_->get_parameter(ins_param_prefix + "q_accel", std_accel)) {
        RCLCPP_WARN_STREAM(filt_controler_->get_logger(), 
            "Couldn't get param " << filt_controler_->get_namespace() << "/" << ins_param_prefix 
            << "q_accel\". Using default: "
            << std_accel);
    }
    if (!filt_controler_->get_parameter(ins_param_prefix + "q_accel_bias", std_accel_bias)) {
        RCLCPP_WARN_STREAM(filt_controler_->get_logger(), 
            "Couldn't get param " << filt_controler_->get_namespace() << "/" << ins_param_prefix 
            << "q_accel_bias\". Using default: "
            << std_accel_bias);
    }

    cfg.cov_accel = std::pow(std_accel, 2);
    cfg.cov_gyro = std::pow(std_gyro * M_PI / 180.0, 2);
    cfg.cov_accel_bias = std::pow(std_accel_bias, 2);
    cfg.cov_gyro_bias = std::pow(std_gyro_bias * M_PI / 180.0, 2);

    ins_ = std::make_unique<pronto::InsModule>(cfg, ins_to_body);


    };

    bool Prop_Sensor_Manager::isInsInitialized(
                const pronto::ImuMeasurement * msr,
                std::map<std::string,bool> init_map,
                const pronto::RBIS& default_stt,
                const pronto::RBIM& default_cov,
                pronto::RBIS& init_stt,
                pronto::RBIM& init_cov
    )
    {
        return ins_->processMessageInit(msr,init_map,default_stt,default_cov,init_stt,init_cov);
    };

    pronto::RBISUpdateInterface* Prop_Sensor_Manager::processInsData(
                    const pronto::ImuMeasurement * msr,
                    StateEst * est
            )
    {
        return ins_->processMessage(msr, est);
    }


};