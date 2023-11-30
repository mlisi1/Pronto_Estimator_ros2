#include <eigen3/Eigen/Core>
#include <eigen3/Eigen/Dense>
#include <eigen3/Eigen/Geometry>

#include "pronto_core/ins_module.hpp"
#include <vector>
#include <string>
#include <map>
#include "rclcpp/rclcpp.hpp"
#include "rclcpp_lifecycle/lifecycle_node.hpp"

namespace pronto_controller
{
    
    

    class Exte_Sensor_Manager
    {
        public:
            Exte_Sensor_Manager(rclcpp_lifecycle::LifecycleNode::SharedPtr controller)
            {

            }
            ~Exte_Sensor_Manager(){};
            bool isExteroceptiveSensorInit()
            {
                for(auto &it: initialize_sensors_)
                {
                    if(!it.second)
                        return false;
                }
                return true;
            }
            std::map<std::string,bool> get_initialized_sens()
            {
                return initialize_sensors_;
            }
        private:
            // shared pointer to the pronto core ins module, TODO check the correct initialization of it
            std::map<std::string,bool> initialize_sensors_;

          

            
    };
};