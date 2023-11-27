#include <eigen3/Eigen/Core>
#include <eigen3/Eigen/Dense>
#include <eigen3/Eigen/Geometry>

#include "pronto_core/ins_module.hpp"
#include <vector>
#include <string>



namespace pronto_controller
{
    
    using INS_module = pronto::InsModule;
    class Prop_Sensor_Manager
    {
        public:

        private:
            // shared pointer to the pronto core ins module, TODO check the correct initialization of it
            std::shared_ptr<INS_module> ins_;
            std::vector<std::string> ins_params_ = {
                
            };

            
    };
};