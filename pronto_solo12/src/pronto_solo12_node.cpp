#include <rclcpp/rclcpp.hpp>
#include "pronto_quadruped_ros/conversions.hpp"
#include "pronto_quadruped_ros/stance_estimator_ros.hpp"
#include "pronto_quadruped_ros/leg_odometer_ros.hpp"
#include "pronto_quadruped_ros/bias_lock_handler_ros.hpp"
#include "pronto_quadruped_ros/legodo_handler_ros.hpp"
#include "pronto_ros/pronto_node.hpp"

#include <pinocchio/parsers/urdf.hpp>
#include <pinocchio/algorithm/compute-all-terms.hpp>
#include <pinocchio/algorithm/kinematics.hpp>
#include <pinocchio/algorithm/jacobian.hpp>
#include <pinocchio/algorithm/

#include <pronto_solo12/feet_contact_forces.hpp>

using std::placeholders::_1;

using namespace pronto;
// using namespace pinocchio;

const std::string urdf_file = "$(find solo_robot_description)/urdf/again/solo12.urdf";
pinocchio::Model robot_model;



class PinocchioNode : public rclcpp::Node 
{

  public:
  // the constructor must be done in order to build the member object in it.
    PinocchioNode() : rclcpp::Node("Pinocchio_node")//:
    //feet_forces(<constructor_legodo>(arg_legodo[urdf path]))
   {

    subscription_ = this->create_subscription<sensor_msgs::msg::JointState>(
      "joint_states", 10, std::bind(&PinocchioNode::pinocchio_callback, this, _1));
    
    // calculate feet forces, feet jacobians and forward kinematics using Pinocchio here
    FeetContactForces feet_forces;

    quadruped::StanceEstimatorROS stance_estimator(this->shared_from_this(), feet_forces);
    quadruped::LegOdometerROS leg_odometer(this->shared_from_this(), feet_jacs, fwd_kin); 
    quadruped::ImuBiasLockROS bias_lock(this->shared_from_this());
    quadruped::LegodoHandlerROS legodo_handler(this->shared_from_this(), stance_estimator, leg_odometer);
    // in hpp file must be a member LegodoHandlerROS,ImuBiasLockROS, .. all of them 
    ProntoNode<sensor_msgs::msg::JointState> node(legodo_handler, bias_lock);

   }
  private:
    void pinocchio_callback(const sensor_msgs::msg::JointState & msg)
    {
      quadruped::jointStateFromROS(msg, time, q, qd, qdd, tau);

      pinocchio::computeAllTerms(model, data, q, qd);  // q e qd sono nel formato giusto o devono essere convertiti ancora?
      // pinocchio::computeJointJacobians(model, data, q);
      // pinocchio::nonLinearEffects(model, data, q, qd);
      // pinocchio::computeMinv(model, data, q);

      J = data.J;
            
    }

    rclcpp::Subscription<sensor_msgs::msg::JointState>::SharedPtr subscription_;

    quadruped::JointState q, qd, qdd, tau;
    uint64_t time;
    

  
    pinocchio::Data::Matrix6x J;


};

int main(int argc, char *argv[])
{
  rclcpp::init(argc, argv);

  pinocchio::urdf::buildModel(urdf_file, robot_model);
  pinocchio::Data data(robot_model); // vanno spostati nel private o qui è corretto????
  
  rclcpp::spin(std::make_shared<PinocchioNode>());
  // node.run() come faccio a farlo avviare?
  // due nodi sono corretti oppure se ne può creare uno?
  
  rclcpp::shutdown();
  return 0;
}
