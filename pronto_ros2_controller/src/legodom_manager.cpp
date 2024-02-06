#include "pronto_ros2_controller/legodom_manager.hpp"

#define DEBUG 1
#define TS 0.001
namespace pronto_controller
{

    std::string legodo_prefix = "legodo.";

    const pinocchio::JointModelFreeFlyer root_fb;
    LegOdom_Manager::LegOdom_Manager(const rclcpp_lifecycle::LifecycleNode::SharedPtr controller,
                                     std::map<std::string , std::tuple<double,double,double>>& joints_map,
                                     std::string urdf_path):
                                     controller_(controller),
                                     joints_map_(joints_map)
    {
        std::size_t found;
        int ind = 0,DOF;
        urdf::Vector3 ax = urdf::Vector3(0.0,0.0,0.0);
        bool ax_int = false;
        std::vector<std::string> jnt_l;

        // create the model parser to understand the 
        mod_parse_ = std::make_unique<Model_Parser>(urdf_path);

        // get the  model actuated DOF

        try
        {
            DOF = mod_parse_->get_robot_DOF();
        }
        catch(std::logic_error& e)
        {
            RCLCPP_ERROR(controller_->get_logger(),"Throw error in model parsing, check the model");
            assert(false);
        }
        stance_msg_.name.resize(1);
        stance_msg_.name[0] = "Stance Number";
        stance_msg_.position.resize(1,0.0);
        est_vel_.resize(DOF);
        est_pos_.resize(DOF);
        jnt_msg_.name.resize(DOF," ");
        jnt_msg_.position.resize(DOF,0.0);
        jnt_msg_.velocity.resize(DOF,0.0);
        jnt_msg_.effort.resize(DOF,0.0);
        // get the kernel direction in therms of force and velocity produced by the leg

        auto ker_dir = mod_parse_->get_ker_dir();

        if(ker_dir == Axis_Direction::error)
        {
            RCLCPP_ERROR(controller_->get_logger(),"Throw error in model kernel direction evaluation, check the model");
            assert(false);
        }

        // build the class to compute kinematic and dynamics value
        pinocchio::urdf::buildModel(urdf_path,root_fb,model_);
        RCLCPP_INFO(controller_->get_logger(), " the DOF computed are %d",DOF);
        
        // pin_model_ = pronto::quadruped::PinocchioProntoQuadrupedModel(model_,"base_link","LF_FOOT","RF_FOOT","LH_FOOT","RH_FOOT");

        pin_ff_ = Pinocchio_Feet_Force(model_,ker_dir,DOF);

        pin_jac_ = Pinocchio_Jacobian(&pin_ff_);
 
        pin_fk_ = Pinocchio_FK(&pin_ff_);



        // build the pronto class to make the odometry correction 

        stance_est_ = std::make_unique<pronto::quadruped::StanceEstimator>(pin_ff_);

        leg_odom_ = std::make_unique<pronto::quadruped::LegOdometer>(pin_jac_,pin_fk_);  

        // get legodom parameters

        double r_vx;
        double r_vy;
        double r_vz;
        auto a = legodo_prefix + "r_vx";
        RCLCPP_INFO(controller->get_logger(),"a %s",a.c_str());
        if(!controller_->get_parameter(legodo_prefix + "r_vx", r_vx)){
            RCLCPP_WARN(controller_->get_logger(),"Could not retrieve r_vx from parameter server. Setting to default.");
            r_vx = 0.1;
        }
        if(!controller_->get_parameter(legodo_prefix + "r_vy", r_vy)){
            RCLCPP_WARN(controller_->get_logger(),"Could not retrieve r_vy from parameter server. Setting to default.");
            r_vy = 0.1;
        }
        if(!controller_->get_parameter(legodo_prefix + "r_vz", r_vz)){
            RCLCPP_WARN(controller_->get_logger(),"Could not retrieve r_vz from parameter server. Setting to default.");
            r_vz = 0.1;
        }
        Eigen::Vector3d r_legodo_init(r_vx,r_vy,r_vz);
        leg_odom_->setInitVelocityStd(r_legodo_init);
        jnt_num_ = DOF;
        odom_cor_pub_ = controller_->create_publisher<Vec3_msg>("~/Odom_Correction",rclcpp::QoS(10));

        fl_jac_pub_ = controller_->create_publisher<Vec3_msg>("~/fl_jac_cor",rclcpp::QoS(10));
        fr_jac_pub_ = controller_->create_publisher<Vec3_msg>("~/fr_jac_cor",rclcpp::QoS(10));
        hl_jac_pub_ = controller_->create_publisher<Vec3_msg>("~/hl_jac_cor",rclcpp::QoS(10));
        hr_jac_pub_ = controller_->create_publisher<Vec3_msg>("~/hr_jac_cor",rclcpp::QoS(10));

        fading_filter_vel_pub_ = controller_->create_publisher<JntStt>("~/Fading_Filter_Est",rclcpp::QoS(10));
        stance_pub_ = controller_->create_publisher<JntStt>("~/Stance",rclcpp::QoS(10));
    };


    void LegOdom_Manager::get_stance_param()
    {
        std::vector<double> beta;

        int stance_mode;
        double hysteresis_low = 50;
        uint64_t stance_hysteresis_delay_low  = 0;
        uint64_t stance_hysteresis_delay_high = 0;
        int stance_hysteresis_delay_low_int = 0;
        int stance_hysteresis_delay_high_int = 0;
        double hysteresis_high = 50;
        double stance_threshold = 50;
        pin_ff_.set_state_dim();
        if (!controller_->get_parameter(legodo_prefix + "stance_mode", stance_mode)) 
        {
            RCLCPP_WARN_STREAM(controller_->get_logger(), "Could not get param \"" << legodo_prefix
            + "stance_mode\". Using default mode.");
            stance_est_->setMode(pronto::quadruped::StanceEstimator::Mode::THRESHOLD);
        }
        if(stance_mode < 3)
            stance_est_->setMode(static_cast<pronto::quadruped::StanceEstimator::Mode>(stance_mode));
        else
        {
            RCLCPP_ERROR(controller_->get_logger(),"The provided stance mode is not available, check the yaml parameter");
            assert(false);
        }
        switch (stance_mode)
        {
        case 0:
            //  THRESHOLD
            if (!controller_->get_parameter(legodo_prefix + "stance_threshold", stance_threshold)) 
            {
                RCLCPP_ERROR(controller_->get_logger(),"NOT valid threshold parameter, check yaml file");
                RCLCPP_ERROR(controller_->get_logger()," will be used the default param 50 N");
            }
            break;
        case 1:
            // HYSTERESIS
            if (!controller_->get_parameter(legodo_prefix + "stance_hysteresis_low", hysteresis_low)) 
            {
                RCLCPP_ERROR(controller_->get_logger(),"NOT valid stance_hysteresis_low parameter, check yaml file");
                RCLCPP_ERROR(controller_->get_logger()," will be used the default param 50 N");
            }   

            if (!controller_->get_parameter(legodo_prefix + "stance_hysteresis_high", hysteresis_high)) 
            {
                RCLCPP_ERROR(controller_->get_logger(),"NOT valid stance_hysteresis_high parameter, check yaml file");
                RCLCPP_ERROR(controller_->get_logger()," will be used the default param 50 N");
            } 
            if (!controller_->get_parameter(legodo_prefix + "stance_hysteresis_delay_low", stance_hysteresis_delay_low_int)) 
            {
                RCLCPP_ERROR(controller_->get_logger(),"NOT valid stance_hysteresis_delay_low parameter, check yaml file");
                RCLCPP_ERROR(controller_->get_logger()," will be used the default param 0 ns");
            } 
            if (!controller_->get_parameter(legodo_prefix + "stance_hysteresis_delay_high", stance_hysteresis_delay_high_int)) 
            {
                RCLCPP_ERROR(controller_->get_logger(),"NOT valid stance_hysteresis_low parameter, check yaml file");
                RCLCPP_ERROR(controller_->get_logger()," will be used the default param 0 ns");
            } 

            stance_hysteresis_delay_low  = stance_hysteresis_delay_low_int;
            stance_hysteresis_delay_high = stance_hysteresis_delay_high_int;
            break;
        case 2:
            //REGRESSION
             if (!controller_->get_parameter(legodo_prefix + "stance_regression_beta", beta)) 
            {
                RCLCPP_ERROR(controller_->get_logger(),"NOT valid threshold stance_regression_beta, check yaml file");
                RCLCPP_ERROR(controller_->get_logger()," will be used the default param 50 N");
            }
            break;
        
        default:
            assert(false);
            break;
        }

        stance_est_->setParams(beta, stance_threshold, hysteresis_low, hysteresis_high, stance_hysteresis_delay_low, stance_hysteresis_delay_high);
        pin_ff_.q_size();
    };
    
    void LegOdom_Manager::get_odom_param()
    {
        

        int legodo_mode;
        
        if (!controller_->get_parameter(legodo_prefix + "legodo_mode", legodo_mode)) 
        {
            RCLCPP_WARN_STREAM(controller_->get_logger(), "Could not get param \"" << legodo_prefix
            + "legodo_mode\". Using default.");
        }
          switch (legodo_mode) 
        {
            case 0: // 000
                leg_odom_->setMode( SigmaMode::STATIC_SIGMA, AverageMode::SIMPLE_AVG);
                break;
            case 1: // 001
                leg_odom_->setMode(SigmaMode::VAR_SIGMA, AverageMode::SIMPLE_AVG);
                break;
            case 2: // 010
                leg_odom_->setMode(SigmaMode::IMPACT_SIGMA, AverageMode::SIMPLE_AVG);
                break;
            case 3: // 011
                leg_odom_->setMode(SigmaMode::VAR_AND_IMPACT_SIGMA, AverageMode::SIMPLE_AVG);
                break;
            case 4: // 100
                leg_odom_->setMode(SigmaMode::STATIC_SIGMA, AverageMode::WEIGHTED_AVG);
                break;
            case 5: // 101
                leg_odom_->setMode(SigmaMode::VAR_SIGMA, AverageMode::WEIGHTED_AVG);
                break;
            case 6: // 110
                leg_odom_->setMode(SigmaMode::IMPACT_SIGMA, AverageMode::WEIGHTED_AVG);
                break;
            case 7: // 111
                leg_odom_->setMode(SigmaMode::VAR_AND_IMPACT_SIGMA, AverageMode::WEIGHTED_AVG);
                break;
            default:
                leg_odom_->setMode(SigmaMode::STATIC_SIGMA, AverageMode::SIMPLE_AVG);
        }
        pin_ff_.q_size();
    }

    void LegOdom_Manager::getPreviousState(const pronto::StateEstimator *est)
    {
        // get the state from estimator 
        est->getHeadState(head_state_,head_cov_);

        //set the pronto state variable 
        dx_ = head_state_.velocity();
        ddx_ = head_state_.acceleration() + head_state_.orientation().inverse()*pronto::g_vec;

        omega_ = head_state_.angularVelocity();
        domega_.setZero();

        orient_ = head_state_.orientation();
    }

    pronto::RBISUpdateInterface * LegOdom_Manager::computeVelocity(rclcpp::Time time)
    {
        bool use_cor = false;
        uint64_t utime = time.nanoseconds()/std::pow(10,3);
        JointState a;
        Eigen::Quaterniond b;
        Eigen::Vector3d c;
        // std::cerr<<" the u time is "<< utime<< std::endl;
        stance_est_->setJointStates(utime/1000,
        a,a,a,
        b,a,
        c,c,c,c
        );
        Vec3_msg deb_cor_msg;
        // TODO add the marker publisher for RVIZ see davide's displayer
        stance_est_->getGRF(grf_);
      
        stance_est_->getStance(stance_,stance_prob_);
     
        leg_odom_->setGrf(grf_);
        
        use_cor = leg_odom_->estimateVelocity(
            utime,
            q_,
            dq_,
            omega_,
            stance_,
            stance_prob_,
            dx_,
            cov_legodo_
        );
        Eigen::Vector3d foot_vel;
        Vec3_msg aaa;

        leg_odom_->get_foot_corr(0,foot_vel);
        aaa.x = foot_vel(0);
        aaa.y = foot_vel(1);
        aaa.z = foot_vel(2);
        fl_jac_pub_->publish(aaa);

        leg_odom_->get_foot_corr(1,foot_vel);
        aaa.x = foot_vel(0);
        aaa.y = foot_vel(1);
        aaa.z = foot_vel(2);
        fr_jac_pub_->publish(aaa);
        
        leg_odom_->get_foot_corr(2,foot_vel);
        aaa.x = foot_vel(0);
        aaa.y = foot_vel(1);
        aaa.z = foot_vel(2);
        hl_jac_pub_->publish(aaa);

        leg_odom_->get_foot_corr(3,foot_vel);
        aaa.x = foot_vel(0);
        aaa.y = foot_vel(1);
        aaa.z = foot_vel(2);
        hr_jac_pub_->publish(aaa);
        
        if(DEBUG)
        {
            stance_msg_.position[0] = stance_[0] + stance_[1] +stance_[2] +stance_[3];
          
            stance_pub_->publish(stance_msg_);

            // auto vel_b = orient_.toRotationMatrix()*dx_;
            auto vel_b = leg_odom_->get_odom_corr();
            deb_cor_msg.x = vel_b(0);
            deb_cor_msg.y = vel_b(1);
            deb_cor_msg.z = vel_b(2);
            odom_cor_pub_->publish(deb_cor_msg);
        }
        // RCLCPP_INFO(controller_->get_logger(),"the velocity correction is [%f,%f,%f]",dx_(0),dx_(1),dx_(2));
        if(use_cor)
            return new pronto::RBISIndexedMeasurement(
                            pronto::RigidBodyState::velocityInds(),
                            dx_,
                            cov_legodo_,
                            pronto::RBISUpdateInterface::legodo,
                            utime
                            );
        else
            return nullptr;

    }

    void LegOdom_Manager::setJointStates()
    {
       
        // set pronto joints state 
        for(size_t i = 0; i < jnt_id.size(); i++)
        {
            try
            {
                std::tuple<double,double,double> jnt_tuple = joints_map_.at(jnt_id[i]);
                
                q_[i] = std::get<0>(jnt_tuple);
                if(first_step_)
                    est_pos_[i] = q_[i];
                dq_[i] = std::get<1>(jnt_tuple);
                // update_fading_filter(q_[i],i);
                // if(DEBUG)
                //     dq_[i] = est_vel_[i];
                tau_[i] = std::get<2>(jnt_tuple);
                if(DEBUG)
                {
                    jnt_msg_.name[i] = jnt_id[i];
                    jnt_msg_.position[i] = q_[i];
                    jnt_msg_.velocity[i] = dq_[i];
                    // fading_filter_vel_pub_->publish(jnt_msg_);
                    // dq_[i] = est_vel_[i];
                }
            }
            catch(std::exception& e)
            {
                if(jnt_num_ == 8)
                {
                    if(i == 0 || i == 3 || i == 6 || i == 9)
                    {                        q_[i] = 0.0;
                        dq_[i] = 0.0;
                        tau_[i] = 0.0;
                    }
                    else
                    {
                        RCLCPP_ERROR(controller_->get_logger(),"quadruped with %d DOF raise exeption %s at ind %ld, check the URDF",jnt_num_, e.what(),i);
                        assert(false);
                    }
                }
                else
                {
                    RCLCPP_ERROR(controller_->get_logger(),"quadruped with %d DOF raise exeption %s at ind %ld, check the URDF",jnt_num_, e.what(),i);
                    assert(false);
                }
            }
            if(first_step_)
                first_step_ = false;
            
        }

        
        //set the pinocchio state
        pin_ff_.set_State(joints_map_,orient_,dx_,ddx_,omega_,domega_);
        // compute all the dynamics quantities
        pin_ff_.update_All();
    }

    void LegOdom_Manager::update_fading_filter(double measure, int ind)
    {
        double H,G;
        G = (1 - ALPHA_FF*ALPHA_FF);
        H = std::pow((1-ALPHA_FF),2);
        est_pos_[ind] = est_pos_[ind] + est_vel_[ind]*TS + G*(measure -(est_pos_[ind] + est_vel_[ind]*TS));
        est_vel_[ind] = est_vel_[ind] + (H/TS)*(measure -(est_pos_[ind] + TS * est_vel_[ind]));
    }

};