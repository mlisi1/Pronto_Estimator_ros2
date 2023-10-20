#include "pronto_solo12/feet_jacobians.hpp"

using namespace iit::rbd;

namespace pronto{
namespace solo{


    FeetJacobians::FeetJacobians(pinocchio::Model & model, pinocchio::Data & data)
    {
        model_ = model;
        data_ = data;
    }

    FeetJacobians::FootJac FeetJacobians::getFootJacobian(const JointState& q, 
                                            const LegID& leg)
    {
        
        switch (leg)
        {
        case LF:
            leg_id = std::find(model_.names.begin(), model_.names.end(), "LF_FOOT");
            pinocchio::getJointJacobian(model_, data_, leg_id, reference_frame, jacs_);

        case RF:
            leg
        leg_id = std::find(model_.frames.begin(), model_.frames.end(), "RF_FOOT");
        default:
           
        }
    }
}
}