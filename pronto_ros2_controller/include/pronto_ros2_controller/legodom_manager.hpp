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
#include "pronto_solo12/pronto_mammal_utilities.hpp"
#include "pronto_ros2_controller/quad_model_parser.hpp"
#include "pronto_core/state_est.hpp"
#include "pronto_core/rotations.hpp"
#include "pronto_quadruped/DynamicStanceEstimator.hpp"

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
            LegOdom_Manager(const rclcpp_lifecycle::LifecycleNode::SharedPtr controller,
                                     std::map<std::string , std::tuple<double,double,double>>& joints_map,
                                     std::string urdf_path);
        
            ~LegOdom_Manager(){};

            // function to manage the parameter of the leg_odometer
            void get_odom_param();

            // funtion to manage the parameter of the stance_estimator
            void get_stance_param();

            //get the actual estimated state
            void getPreviousState(const pronto::StateEstimator *est);

            //set the joint states 
            void setJointStates();  
            void get_q_size()
            {
                std::cerr << "q is ";
                pin_ff_.q_size();
            } 
           
            //compute the update based on the stance estimation and joint states
            pronto::RBISUpdateInterface * computeVelocity(rclcpp::Time time);




            // // get the initialized map and check that all the joints provided by the interface are also 
            // // contained into the urdf
            // bool set_jnt_map(std::map<std::string,std::tuple<double,double,double>>& jnt_data);



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

            std::map<std::string , std::tuple<double,double,double>>& joints_map_;

            // pronto like variable 
            pronto::quadruped::JointState q_,dq_,ddq_,tau_;
            Eigen::Quaternion<double> orient_;
            Eigen::Vector3d dx_,ddx_,omega_,domega_;

            // pinocchio like thing
            std::vector<std::string> pin_jnt_linst_;
            std::vector<Eigen::Matrix3d> pin_jac_list_;
            std::vector<Eigen::Vector3d> pin_foot_pos_;

            std::unique_ptr<Model_Parser> mod_parse_;
            Pinocchio_Feet_Force pin_ff_;
            Pinocchio_Jacobian pin_jac_;
            Pinocchio_FK pin_fk_;


            Eigen::Matrix3d cov_legodo_;

            // stance state
            pronto::quadruped::LegVectorMap grf_;
            pronto::quadruped::LegBoolMap stance_;
            pronto::quadruped::LegScalarMap stance_prob_;


            // pronto update variable
            pronto::RBIS default_state_, init_state_,head_state_;
            pronto::RBIM default_cov_,init_cov_,head_cov_;
    };
};


// get the data from interfaces_ -> get it in a map<string,double>
// change the order folloing the pronto's one
// during the call of grf or base_vel coputation the pronto base should be reorder in pinocchio's one