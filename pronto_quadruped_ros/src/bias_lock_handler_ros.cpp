#include "pronto_quadruped_ros/bias_lock_handler_ros.hpp"

using namespace pronto;
using namespace pronto::quadruped;

ImuBiasLockROS::ImuBiasLockROS(rclcpp::Node::SharedPtr nh) : ImuBiasLockBaseROS(nh){}

RBISUpdateInterface* ImuBiasLockROS::processMessage(const sensor_msgs::msg::Imu *msg,
                                                    StateEstimator *est)
{
    msgToImuMeasurement(*msg, bias_lock_imu_msg_);
    RBISUpdateInterface* update = bias_lock_module_->processMessage(&bias_lock_imu_msg_, est);

    if (update != nullptr) {
        RBIS head_state;
        RBIM head_cov;
        est->getHeadState(head_state, head_cov);
        RCLCPP_INFO_STREAM(nh_->get_logger(), "Bias update. Prior accel bias: " << head_state.accelBias().transpose() << std::endl
                                                << "Prior gyro bias: " << head_state.gyroBias().transpose());
    }
    return update;
}

bool ImuBiasLockROS::processMessageInit(const sensor_msgs::msg::Imu *msg,
                                        const std::map<std::string, bool> &sensor_initialized,
                                        const RBIS &default_state,
                                        const RBIM &default_cov,
                                        RBIS &init_state,
                                        RBIM &init_cov)
{
  msgToImuMeasurement(*msg, bias_lock_imu_msg_);
  return bias_lock_module_->processMessageInit(&bias_lock_imu_msg_,
                                               sensor_initialized,
                                               default_state,
                                               default_cov,
                                               init_state,
                                               init_cov);
}


void ImuBiasLockROS::processSecondaryMessage(const sensor_msgs::msg::JointState &msg)
{
    jointStateFromROS(msg, bias_lock_js_msg_);
    bias_lock_module_->processSecondaryMessage(bias_lock_js_msg_);
}

// pronto_msgs/JointStateWithAcceleration (includes acceleration)
void ImuBiasLockWithAccelerationROS::processSecondaryMessage(const pronto_msgs::msg::JointStateWithAcceleration &msg) {
  jointStateWithAccelerationFromROS(msg, bias_lock_js_msg_);
  bias_lock_module_->processSecondaryMessage(bias_lock_js_msg_);
}

