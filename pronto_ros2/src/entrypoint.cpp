#include "rclcpp/rclcpp.hpp"
#include "pronto_ros2/pronto_ros2_node.hpp"
#include "pronto_ros2/ins_ros_handler.hpp"



// using namespace pronto;

int main(int argc, char** argv) 
{

    rclcpp::init(argc, argv);
    pronto::ProntoNode pronto_node;
    // RCLCPP_INFO_STREAM(rclcpp::get_logger("test_node"), "test_msg");

    typedef std::vector<std::string> SensorList_t;
    SensorList_t init_sensors;
    SensorList_t active_sensors;
    SensorList_t all_sensors;


    if(!pronto_node.get_parameter("init_sensors", init_sensors)){
        RCLCPP_ERROR(pronto_node.get_logger(), "Not able to get init_sensors param");
    }

    if(!pronto_node.get_parameter("active_sensors", active_sensors)){
        RCLCPP_ERROR(pronto_node.get_logger(), "Not able to get active_sensors param");
    }
    bool publish_pose = false;
    if(!pronto_node.get_parameter("publish_pose", publish_pose)){
        RCLCPP_WARN(pronto_node.get_logger(), "Not able to get publish_pose param. Not publishing pose.");
    }


    std::shared_ptr<pronto::InsHandlerROS> ins_handler_;
    // std::shared_ptr<ViconHandlerROS> vicon_handler_;

    

    bool init = false;
    bool active = false;
    bool roll_forward = false;
    bool publish_head = false;
    std::string topic;

    for(SensorList_t::iterator it = active_sensors.begin(); it != active_sensors.end(); ++it){
        all_sensors.push_back(*it);
    }
    for(SensorList_t::iterator it = init_sensors.begin(); it != init_sensors.end(); ++it){
        all_sensors.push_back(*it);
    }

    // pronto_node.get_parameter(*all_sensors.begin() + "/topic", topic);

    // pronto_node.addSensingModule(*ins_handler_, *all_sensors.begin(), roll_forward, publish_head, topic);

    for(SensorList_t::iterator it = all_sensors.begin(); it != all_sensors.end(); ++it)
    {
        if(!pronto_node.get_parameter(*it + "/roll_forward_on_receive", roll_forward)){
            RCLCPP_WARN(pronto_node.get_logger(), "Not adding sensor \"%s \".",  (*it).c_str());
            RCLCPP_WARN(pronto_node.get_logger(), "Param \"roll_forward_on_receive\" not available.");
            continue;
        }
        if(!pronto_node.get_parameter(*it + "/publish_head_on_message", publish_head)){
            RCLCPP_WARN(pronto_node.get_logger(), "Not adding sensor \"%s \".",  (*it).c_str());
            RCLCPP_WARN(pronto_node.get_logger(), "Param \"publish_head_on_message\" not available.");
            continue;
        }
        if(!pronto_node.get_parameter(*it + "/topic", topic)){
            RCLCPP_WARN(pronto_node.get_logger(), "Not adding sensor \"%s \".",  (*it).c_str());
            RCLCPP_WARN(pronto_node.get_logger(), "Param \"topic\" not available.");
            continue;
        }
        // check if the sensor is also used to initialize
        init = (std::find(init_sensors.begin(), init_sensors.end(), *it) != init_sensors.end());
        active = (std::find(active_sensors.begin(), active_sensors.end(), *it) != active_sensors.end());
        // is the IMU module in the list? Typically yes.
        if(it->compare("ins") == 0)
        {
            ins_handler_.reset();
            ins_handler_ = std::make_shared<pronto::InsHandlerROS>();
            
            if(active){
                pronto_node.addSensingModule(*ins_handler_, *it, roll_forward, publish_head, topic);
            }
            if(init){
                pronto_node.addInitModule(*ins_handler_, *it, topic);
            }
        }
        // if(it->compare("vicon") == 0)
        // {
        //     vicon_handler_.reset();
        //     vicon_handler_ = std::make_shared<ViconHandlerROS>(nh);
        //     if(active){
        //         front_end->addSensingModule(*vicon_handler_, *it, roll_forward, publish_head, topic);
        //     }
        //     if(init){
        //         front_end->addInitModule(*vicon_handler_, *it, topic);
        //     }
        // }
    }

    rclcpp::shutdown();

    return 0;


}