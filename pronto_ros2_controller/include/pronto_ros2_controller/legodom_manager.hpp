#include "rclcpp/rclcpp.hpp"
#include "rclcpp_lifecycle/lifecycle_node.hpp"
#include "pronto_quadruped/StanceEstimator.hpp"
#include "pronto_quadruped/LegOdometer.hpp"
#include <string>
#include <map>
#include <vector>
#include <pinocchio/multibody/model.hpp>
#include <pinocchio/multibody/data.hpp>
#include <pinocchio/algorithm/crba.hpp>
#include <pinocchio/algorithm/rnea.hpp>
#include <pinocchio/algorithm/frames.hpp>
#include <pinocchio/parsers/urdf.hpp>
#include "pronto_solo12/definitions.hpp"


#include <tuple>

namespace pronto_controller
{
    const std::vector<std::string> jnt_id = 
    {
        "LF_HAA",
        "LF_HFE",
        "LF_KFE",
        "RF_HAA",
        "RF_HFE",
        "RF_KFE",
        "LH_HAA",
        "LH_HFE",
        "LH_KFE",
        "RH_HAA",
        "RH_HFE",
        "RH_KFE"        
    };
    using SigmaMode = pronto::quadruped::LegOdometer::SigmaMode;
    using AverageMode = pronto::quadruped::LegOdometer::AverageMode;
    using FeetContactForces = pronto::quadruped::FeetContactForces;
    using Jointind = pronto::quadruped::JointIdentifiers;
   
    
    class LegOdom_Manager
    {
        public:
            LegOdom_Manager(const rclcpp_lifecycle::LifecycleNode::SharedPtr controller, std::string urdf_path);
        
            ~LegOdom_Manager(){};

            void get_odom_param();


            // get the initialized map and check that all the joints provided by the interface are also 
            // contained into the urdf
            bool set_jnt_map(std::map<std::string,std::tuple<double,double,double>>& jnt_data);



        private:

            std::unique_ptr<pronto::quadruped::LegOdometer> leg_odom_;
            std::unique_ptr<pronto::quadruped::StanceEstimator> stance_est_;
            rclcpp_lifecycle::LifecycleNode::SharedPtr controller_;

            std::map<std::string,int> up_map_;
            
            int jnt_num_;
            int dir_;

            std::vector<std::string> pin_jnt_names_;

            pinocchio::Model model_;
            pinocchio::Data data_;

            std::map<std::string , std::tuple<double,double,double>> joints_map_;

            // pronto like variable 
            pronto::quadruped::JointState q_,dq_,tau_;
            Eigen::Quaternion<double> orient_;
            Eigen::Vector3d dx_,ddx_,omega_,domega_;

            // pinocchio like thing
            std::vector<std::string> pin_jnt_linst_;
            std::vector<Eigen::Matrix3d> pin_jac_list_;
            std::vector<Eigen::Vector3d> pin_foot_pos_;
    };
};


// get the data from interfaces_ -> get it in a map<string,double>
// change the order folloing the pronto's one
// during the call of grf or base_vel coputation the pronto base should be reorder in pinocchio's one