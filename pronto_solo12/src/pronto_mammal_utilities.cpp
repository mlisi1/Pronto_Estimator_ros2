#include "pronto_solo12/pronto_mammal_utilities.hpp"
#include "pronto_quadruped_commons/feet_contact_forces.h"
#include "Eigen/Geometry"



namespace pronto_controller
{
   bool Pinocchio_Feet_Force::computeJac(const JointStatePinocchio q)
    {
        // compute the jacobian and update the frame
        pinocchio::computeJointJacobians(model_,data_,q);
        pinocchio::updateFramePlacements(model_,data_);
    };

    bool Pinocchio_Feet_Force::getLegJacobian(
        const LegID& leg,
        LinVelJac& Jac
    )
    {
        CompleteJac J;
        // get the correct foot frame 
        pinocchio::FrameIndex leg_id;
        switch (leg)
        {
        case LegID::LF:
            leg_id = model_.getFrameId("LF_FOOT");
            break;
        case LegID::LH:
            leg_id = model_.getFrameId("LH_FOOT");
            break;
        case LegID::RF:
            leg_id = model_.getFrameId("RF_FOOT");
            break;
        case LegID::RH:
            leg_id = model_.getFrameId("RH_FOOT");
            break;
            
        default:
            return false;
            break;
        }

        //get the complete jacobian in world frame 
        pinocchio::getFrameJacobian(model_,data_,leg_id,pinocchio::ReferenceFrame::WORLD,J);

        // extract the data about the linear velocity 
        Jac = J.block<3,3>(0,6 + leg*3);

        return true;

    };

    bool Pinocchio_Feet_Force::getFootGRF(
                const JointState& q,
                const JointState& qd,
                const JointState& tau,
                const Quaterniond& orient,
                const LegID& leg,
                Vector3d& foot_grf,
                const JointState& qdd,
                const Vector3d& xd,
                const Vector3d& xdd,
                const Vector3d& omega,
                const Vector3d& omegad
            )
    {
        JointStatePinocchio q_pin;
        JointVelocityPinocchio qd_pin;
        q_pin.setZero();
        qd_pin.setZero();
        // if the counter is 0 then should be update jacobians and dynamic
        if(!leg_count_)
        {   
            // add corrctly data in pinocchio way
            q_pin.block<4,1>(3,0) = Eigen::Vector4d(orient.x(),orient.y(),orient.z(),orient.w());
            
            
        }

    };

    bool Pinocchio_Jacobian::Compute_All(const pronto::quadruped::JointState q)
    {
        
    }
};