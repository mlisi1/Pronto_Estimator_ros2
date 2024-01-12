#include "pronto_ros2_controller/legodom_manager.hpp"


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
        pin_ff_ = Pinocchio_Feet_Force(model_,ker_dir,DOF);

        pin_jac_ = Pinocchio_Jacobian(pin_ff_);
 
        pin_fk_ = Pinocchio_FK(pin_ff_);

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

        uint64_t utime = time.nanoseconds()/1000;
        // TODO add the marker publisher for RVIZ see davide's displayer
        stance_est_->getGRF(grf_);
        stance_est_->getStance(stance_,stance_prob_);
        leg_odom_->setGrf(grf_);
        leg_odom_->estimateVelocity(
            utime,
            q_,
            dq_,
            omega_,
            stance_,
            stance_prob_,
            dx_,
            cov_legodo_
        );
       
        return new pronto::RBISIndexedMeasurement(
                            pronto::RigidBodyState::velocityInds(),
                            dx_,
                            cov_legodo_,
                            pronto::RBISUpdateInterface::legodo,
                            utime
                            );

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
                dq_[i] = std::get<1>(jnt_tuple);
                tau_[i] = std::get<2>(jnt_tuple);
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
        }
        
        //set the pinocchio state
        pin_ff_.set_State(joints_map_,orient_,dx_,ddx_,omega_,domega_);
        // compute all the dynamics quantities
        pin_ff_.update_All();
    }

};