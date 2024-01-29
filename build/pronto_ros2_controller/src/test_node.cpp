#include "rclcpp/rclcpp.hpp"
#include <urdf/model.h>
#include <urdf/model.h>
#include "pronto_ros2_controller/quad_model_parser.hpp"
#include <pinocchio/multibody/model.hpp>
#include <pinocchio/multibody/data.hpp>
#include <pinocchio/algorithm/crba.hpp>
#include <pinocchio/algorithm/rnea.hpp>
#include <pinocchio/algorithm/frames.hpp>
#include <pinocchio/parsers/urdf.hpp>
#include <eigen3/Eigen/Core>
#include <eigen3/Eigen/Dense>
#include <eigen3/Eigen/Geometry>
#include "pinocchio/algorithm/joint-configuration.hpp"
#include "pinocchio/algorithm/kinematics.hpp"
 

std::string urdf_file = "/home/jacopo/Documents/mul_pronto_ws/src/pronto_solo12/config/prova.urdf";
int main(int argc, char *argv[])
{

    rclcpp::init(argc, argv);
    RCLCPP_INFO(rclcpp::get_logger("DIO ANE"),"   ");

    pronto_controller::Model_Parser mod(urdf_file);
    
    auto ker = mod.get_ker_dir();

    RCLCPP_INFO(rclcpp::get_logger("AAA"), "the axis is %d",ker);

    pinocchio::Model p_mod;

    const pinocchio::JointModelFreeFlyer root_joint;

    pinocchio::urdf::buildModel(urdf_file, p_mod);
    pinocchio::Data data(p_mod);

    

    Eigen::VectorXd q = pinocchio::randomConfiguration(p_mod);

    RCLCPP_INFO_STREAM(rclcpp::get_logger("AAA"),"The random conf is"<< q <<" ");

    RCLCPP_INFO_STREAM(rclcpp::get_logger("AAA"),"has dim "<<q.size());

    pinocchio::computeJointJacobians(p_mod,data,q);
    pinocchio::updateFramePlacements(p_mod,data);
    RCLCPP_INFO_STREAM(rclcpp::get_logger("AAA"),"has dim 2"<<q.size());
    pinocchio::Data::Matrix6x J;
    J.resize(6,8);
    J.fill(0.0);
    pinocchio::FrameIndex id;
    RCLCPP_INFO_STREAM(rclcpp::get_logger("AAA"),"has dim 3"<<q.size());
    id = p_mod.getFrameId("LF_FOOT");
RCLCPP_INFO_STREAM(rclcpp::get_logger("AAA"),"has dim 4"<<id);
    pinocchio::getFrameJacobian(p_mod,data,id,pinocchio::ReferenceFrame::LOCAL_WORLD_ALIGNED,J);
RCLCPP_INFO_STREAM(rclcpp::get_logger("AAA"),"has dim5 "<<q.size());


    auto a = J.block<1,2>(0,4);
    RCLCPP_INFO_STREAM(rclcpp::get_logger("AAA"),"J is "<<J);
    // pinocchio::computeFrameJacobian(p_mod,data,q);
    // pinocchio::updateFramePlacement(p_mod,data);


    Eigen::Matrix2d RL_J;
    RL_J.block<1,2>(0,0) = J.block<1,2>(0,4);
    RL_J.block<1,2>(1,0) = J.block<1,2>(2,4);

    RCLCPP_INFO_STREAM(rclcpp::get_logger("AAA"),"J is "<<RL_J);

    rclcpp::shutdown();
    return 0;
};