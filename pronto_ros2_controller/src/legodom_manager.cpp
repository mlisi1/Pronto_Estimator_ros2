#include "pronto_ros2_controller/legodom_manager.hpp"
#include <urdf/model.h>


namespace pronto_controller
{
    const pinocchio::JointModelFreeFlyer root_fb;
    LegOdom_Manager::LegOdom_Manager(const rclcpp_lifecycle::LifecycleNode::SharedPtr controller,
                                     std::string urdf_path):
                                     controller_(controller)
    {
        std::size_t found;
        int ind = 0;
        urdf::Vector3 ax = urdf::Vector3(0.0,0.0,0.0);
        bool ax_int = false;
        std::vector<std::string> jnt_l;

        //get urdf joints and set the map #TODO make the same with gazebo 
        urdf::Model model;
        if(!model.initFile(urdf_path))
            RCLCPP_ERROR(controller_->get_logger(),"Error during the parsing of URDF");
        jnt_num_ = model.joints_.size();
        
        // sut up the map values
        for(auto jnt:model.joints_)
        {
            if(jnt_num_ == 8)
            {
                
                found = jnt.first.find("HAA");
                if(found!=std::string::npos)
                {
                    ind++;
                    continue;
                }
                else
                {
                    if(!ax_int)
                    {
                        ax = jnt.second->axis;
                        ax_int = true;
                    }
                }
            }
            RCLCPP_DEBUG(controller_->get_logger(),"insert joint map pair %s and ind %d",jnt.first.c_str(),ind);
            up_map_.insert(std::pair<std::string,Jointind>(jnt.first,pronto::quadruped::orderedJointIDs[ind]));
            ind++;
        }
        // check if the robot as 8 ax and set the uncontrolled force direction
        // assumes that the leg kinematic chain has the axes alligned
        if(ax_int)
        {
            if(ax.x != 0.0)
                dir_ = 0;
            else if(ax.y != 0.0)
                dir_ = 1;
            else if(ax.z != 0.0)
                dir_ = 2;
        }

        // build the model from urdf and data from model 
        
        pinocchio::urdf::buildModel(urdf_path,root_fb,model_,false);   

        data_ = pinocchio::Data(model_);

        // get the joint lists from model and create a map to use the pinocchio's stuff

        pin_jnt_names_ = model_.names; 

        //create the pronto ind/ pinocchio ind map   
        // in this way i can map the joints name 
        
        for(auto jnt:jnt_id)
        {
            for(int i = 0; i < jnt_num_; i++)
            {
                if(!jnt.compare(pin_jnt_names_[i]))
                {
                    up_map_.insert({jnt,i});
                }
            }
        }

        // for(auto jnt: jnt_l)
        // {
        //     for(int i = 0; i < 12; i++)
        //     {
        //         if(!jnt.compare(jnt_id[i]))
        //         {
        //             std::make_pair<std::string,int>(jnt.c_str(),1);
        //             up_map_.insert({jnt,pronto::quadruped::orderedJointIDs[i]});
        //         }
        //     }
        // }    
    };

    // function to get the velocity correction mode
    void LegOdom_Manager::get_odom_param()
    {
        std::string legodo_prefix = "legodo/";

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
    }


};