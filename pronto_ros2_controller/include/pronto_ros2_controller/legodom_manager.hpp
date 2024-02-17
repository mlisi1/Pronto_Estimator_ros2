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
#include "geometry_msgs/msg/vector3.hpp"
#include "geometry_msgs/msg/vector3_stamped.hpp"
#include "pronto_msgs/msg/quadruped_stance.hpp"
#include "pronto_msgs/msg/quadruped_force_torque_sensors.hpp"
#include "sensor_msgs/msg/joint_state.hpp"
#include "rclcpp/qos.hpp"
#include <tuple>
#include "pronto_solo12/pinocchio_pronto_quadruped_model.hpp"


#define ALPHA_FF 0.5
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
    using Vec3_msg = geometry_msgs::msg::Vector3;
    using JntStt = sensor_msgs::msg::JointState;
    using ForceEst = pronto_msgs::msg::QuadrupedForceTorqueSensors;
    using StanceEst = pronto_msgs::msg::QuadrupedStance;
   
    
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

            // update fading filter of joints velocities
            void  update_fading_filter(double measure, int ind);

            //get the actual estimated state
            void getPreviousState(const pronto::StateEstimator *est);

            // publish the estimated force from vector3map
            void pub_est_force()
            {
                ForceEst f_est = ForceEst();
                f_est.header.set__stamp(controller_->get_clock()->now());
                f_est.lf.force.set__x(grf_[LegID::LF][0]);
                f_est.lf.force.set__y(grf_[LegID::LF][1]);
                f_est.lf.force.set__z(grf_[LegID::LF][2]);

                f_est.lh.force.set__x(grf_[LegID::LH][0]);
                f_est.lh.force.set__y(grf_[LegID::LH][1]);
                f_est.lh.force.set__z(grf_[LegID::LH][2]);

                f_est.rf.force.set__x(grf_[LegID::RF][0]);
                f_est.rf.force.set__y(grf_[LegID::RF][1]);
                f_est.rf.force.set__z(grf_[LegID::RF][2]);

                f_est.rh.force.set__x(grf_[LegID::RH][0]);
                f_est.rh.force.set__y(grf_[LegID::RH][1]);
                f_est.rh.force.set__z(grf_[LegID::RH][2]);

                est_for_pub_->publish(f_est);
            }
            void pub_est_stance()
            {
                
                StanceEst s_est = StanceEst();
                s_est.header.set__stamp(controller_->get_clock()->now());
                s_est.set__lf(stance_prob_[LegID::LF]);
                s_est.set__lh(stance_prob_[LegID::LH]);
                s_est.set__rf(stance_prob_[LegID::RF]);
                s_est.set__rh(stance_prob_[LegID::RH]);
                est_stc_pub_->publish(s_est);
            }
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
            pronto::quadruped::PinocchioProntoQuadrupedModel pin_model_;
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
            rclcpp::Publisher<Vec3_msg>::SharedPtr odom_cor_pub_;
            rclcpp::Publisher<Vec3_msg>::SharedPtr fl_jac_pub_;
            rclcpp::Publisher<Vec3_msg>::SharedPtr fr_jac_pub_;
            rclcpp::Publisher<Vec3_msg>::SharedPtr hl_jac_pub_;
            rclcpp::Publisher<Vec3_msg>::SharedPtr hr_jac_pub_;
            rclcpp::Publisher<ForceEst>::SharedPtr est_for_pub_;
            rclcpp::Publisher<StanceEst>::SharedPtr est_stc_pub_;
            rclcpp::Publisher<JntStt>::SharedPtr fading_filter_vel_pub_;
            rclcpp::Publisher<JntStt>::SharedPtr stance_pub_;
            std::vector<double> est_vel_;
            std::vector<double> est_pos_;
            JntStt jnt_msg_;
            JntStt stance_msg_;
            bool first_step_ = true;

    };
};


// get the data from interfaces_ -> get it in a map<string,double>
// change the order folloing the pronto's one
// during the call of grf or base_vel coputation the pronto base should be reorder in pinocchio's one