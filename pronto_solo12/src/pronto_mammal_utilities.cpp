#include "pronto_solo12/pronto_mammal_utilities.hpp"
#include "pronto_quadruped_commons/feet_contact_forces.h"
#include "Eigen/Geometry"



namespace pronto_controller
{
   

    /***** Start The Feet Forces fonction definition *****/

    bool Pinocchio_Feet_Force::getLegJacobian(
        const LegID& leg,
        LinVelJac& Jac
    )
    {
        Jac.setZero();
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
        pinocchio::getFrameJacobian(model_,data_,leg_id,pinocchio::ReferenceFrame::LOCAL_WORLD_ALIGNED,Jac_);

        // extract the data about the linear velocity 
        if(DOF_ == 8)
            Jac.block<3,2>(0,1) = Jac_.block<3,2>(0,6 + leg*2);
        else    
            Jac = Jac_.block<3,3>(0,6 + leg*3);

        return true;

    };



    bool Pinocchio_Feet_Force::getFootGRF(
                const JointState& ,
                const JointState& ,
                const JointState& ,
                const Quaterniond& ,
                const LegID& leg,
                Vector3d& foot_grf,
                const JointState& ,
                const Vector3d& ,
                const Vector3d& ,
                const Vector3d& ,
                const Vector3d& 
            )
    {
        LinVelJac J;
        Eigen::Vector2d tau_leg_2d;
        Eigen::Vector3d tau_leg;
        Eigen::Matrix2d J_2d;
        if(DOF_ == 8)
        {
            
            J_2d.setZero();
        }
        
        tau_rnea_ = data_.tau;
        
        // get tau from rnea per joints
        if(DOF_ ==  12)
            tau_leg_2d = tau_rnea_.block<2,1>(leg*2,0) - tau_msr_.block<2,1>(leg*2,0);
        
        else
            tau_leg = tau_rnea_.block<3,1>(leg*3,0) - tau_msr_.block<3,1>(leg*3,0);;
        
        // get the Jacobian am compute grf

        this->getLegJacobian(leg,J);

        if(DOF_ == 12)
            foot_grf = J.inverse()*tau_leg;
        else
        {
            foot_grf.setZero();
            if(ker_ == 0)
                J_2d = J.block<2,2>(1,1);
            else if(ker_ == 2)
                J_2d = J.block<2,2>(0,1);
            else if(ker_ == 1)
            {
                J_2d.block<1,2>(0,0) = J.block<1,2>(0,1);
                J_2d.block<1,2>(1,0) = J.block<1,2>(2,1);
            }
            Eigen::Vector2d grf_2d = J_2d.inverse()*tau_leg_2d;

            if(ker_ == 0)
            {
                foot_grf(1) = grf_2d(0);
                foot_grf(2) = grf_2d(1);
            }
            else if(ker_ == 1)
            {
                foot_grf(0) = grf_2d(0);
                foot_grf(2) = grf_2d(1);
            }
            else if(ker_ == 2)
            {
                foot_grf(0) = grf_2d(0);
                foot_grf(1) = grf_2d(1); 
            }
            
            // change the frame from world to base 
            foot_grf = R_w2b_*foot_grf;
        }
        return true;
    };

    bool Pinocchio_Feet_Force::update_All()
    {
        if(update_need_)
        {
            // update kinematic
            pinocchio::forwardKinematics(model_,data_,q_pin_);

            // update Jacobian 
            pinocchio::computeJointJacobians(model_,data_,q_pin_);

            //update frame 
            pinocchio::updateFramePlacements(model_,data_);

            // compute rnea
            pinocchio::rnea(model_,data_, q_pin_, dq_pin_, ddq_pin_);
            return true;
        }
        return false;
    }

    void Pinocchio_Feet_Force::set_State(
                    std::map<std::string,std::tuple<double,double,double>> jnt_stt,
                    Quaterniond orient,
                    Vector3d xd,
                    Vector3d xdd,
                    Vector3d omega,
                    Vector3d omegad
        
    )
    {
        q_pin_.setZero();
        dq_pin_.setZero();
        ddq_pin_.setZero();
        tau_msr_.setZero();

        R_w2b_ = orient.toRotationMatrix();

        q_pin_.block<4,1>(3,0) = orient.coeffs();
        dq_pin_.block<3,1>(0,0) = xd;
        ddq_pin_.block<3,1>(0,0) = xdd;
        dq_pin_.block<3,1>(3,0) = omega;
        ddq_pin_.block<3,1>(3,0) = omegad;
        try
        {
            for(size_t i = 0; i < pin_jnt_name_.size(); i++)
            {
                q_pin_(i + FB_DOF) = std::get<0>(jnt_stt[pin_jnt_name_[i]]);
                dq_pin_(i + FB_VEL) = std::get<1>(jnt_stt[pin_jnt_name_[i]]);
                tau_msr_(i) = std::get<2>(jnt_stt[pin_jnt_name_[i]]);

            }
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
        
        
    }
    /***** Start The Feet Jacobian fonction definition *****/

    // get the foot jacobian 
    pronto::quadruped::FootJac Pinocchio_Jacobian::getFootJacobian(
        const pronto::quadruped::JointState&,
        const pronto::quadruped::LegID& leg)
    {
        LinVelJac J;
        pin_ff_.getLegJacobian(leg,J);
        return J;
    }

    pronto::quadruped::FootJac Pinocchio_Jacobian::getFootJacobianAngular(const pronto::quadruped::JointState&,const pronto::quadruped::LegID&)
    {
        LinVelJac J;
        J.setZero();
        return J;
    }
    
   /***** Start The FK fonction definition *****/

    // get the foot pos
     Eigen::Vector3d Pinocchio_FK::getFootPos(const JointState& , const LegID& leg)
     {
            return pin_ff_.get_FK(leg);
     };

    Eigen::Matrix3d Pinocchio_FK::getFootOrientation(const JointState& q, const LegID& leg)
     {
        Eigen::Matrix3d a;
        a.setZero();
        return a;
     }

};