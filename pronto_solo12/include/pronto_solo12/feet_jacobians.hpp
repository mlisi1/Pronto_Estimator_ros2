#pragma once

#include <pronto_quadruped_commons/feet_jacobians.h>
#include <pinocchio/multibody/model.hpp>
#include <pinocchio/multibody/data.hpp>
#include <pinocchio/algorithm/jacobian.hpp>
#include <pinocchio/algorithm/frames.hpp>

namespace pronto {
namespace solo{

class FeetJacobians : public pronto::quadruped::FeetJacobians {
public:
    typedef pronto::quadruped::FootJac FootJac;
    typedef pronto::quadruped::JointState JointState;
    typedef pronto::quadruped::LegID LegID;

    FeetJacobians(pinocchio::Model & model, pinocchio::Data & data);
    

    FootJac getFootJacobian(const JointState& q, const LegID& leg) override;
    // FootJac getFootJacobianLF(const JointState& q) override;
    // FootJac getFootJacobianRF(const JointState& q) override;
    // FootJac getFootJacobianLH(const JointState& q) override;
    // FootJac getFootJacobianRH(const JointState& q) override;

    FootJac getFootJacobianAngular(const JointState& q, const LegID& leg) override;

private:
    // pinocchio::jointJacobian jacs_;
    pinocchio::Model model_;
    pinocchio::Data data_;
    int leg_id;
    pinocchio::Data::Matrix6x jacs_;
};

}
}

