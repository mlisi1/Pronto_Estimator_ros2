#include "pronto_ros2_controller/pronto_controller.hpp"
#include "pluginlib/class_list_macros.hpp"

namespace pronto_controller
{
    Pronto_Controller::Pronto_Controller()
    {
        RCLCPP_INFO(get_node()->get_logger(),"COntruct");
    };
    Pronto_Controller::~Pronto_Controller()
    {

    };
    CallbackReturn Pronto_Controller::on_init() 
    {
        return CallbackReturn::SUCCESS;
    };             
    controller_interface::InterfaceConfiguration Pronto_Controller::command_interface_configuration() const
    {
        controller_interface::InterfaceConfiguration cmd_int;
        return cmd_int;
    };
    controller_interface::InterfaceConfiguration Pronto_Controller::state_interface_configuration() const
    {
        controller_interface::InterfaceConfiguration stt_int;
        return stt_int;
    };
    CallbackReturn Pronto_Controller::on_configure(const rclcpp_lifecycle::State & previous_state)
    {
        return CallbackReturn::SUCCESS; 
    };
    CallbackReturn Pronto_Controller::on_activate(const rclcpp_lifecycle::State & previous_state)
    {
        return CallbackReturn::SUCCESS;
    };
    CallbackReturn Pronto_Controller::on_deactivate(const rclcpp_lifecycle::State & previous_state)
    {
        return CallbackReturn::SUCCESS;
    };
    CallbackReturn Pronto_Controller::on_cleanup(const rclcpp_lifecycle::State & previous_state) 
    {
        return CallbackReturn::SUCCESS;
    };
    controller_interface::return_type Pronto_Controller::update(
        const rclcpp::Time & time, const rclcpp::Duration & period
    )
    {
        return controller_interface::return_type::OK;
    };
    
};

#include <pluginlib/class_list_macros.hpp>

PLUGINLIB_EXPORT_CLASS(pronto_controller::Pronto_Controller, controller_interface::ControllerInterface);