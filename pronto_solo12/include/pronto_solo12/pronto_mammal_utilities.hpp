#include <pronto_quadruped_commons/feet_contact_forces.h>
#include <pronto_quadruped_commons/leg_vector_map.h>
#include "pronto_solo12/feet_jacobians.hpp"
#include "Eigen/Dense"
#include "Eigen/Core"
#include "Eigen/Geometry"
#include <map>
#include "pronto_quadruped_commons/feet_contact_forces.h"

//include pinocchio's stuff
#include <pinocchio/multibody/model.hpp>
#include <pinocchio/multibody/data.hpp>
#include <pinocchio/algorithm/crba.hpp>
#include <pinocchio/algorithm/rnea.hpp>
#include <pinocchio/algorithm/frames.hpp>

#define FB_DOF 7
#define FB_VEL 6
namespace pronto_controller
{
    using JointState = pronto::quadruped::JointState;
    using LegID = pronto::quadruped::LegID;
    using Vector3d = Eigen::Vector3d;

    typedef Eigen::Matrix<double, 19, 1> JointStatePinocchio;
    typedef Eigen::Matrix<double, 18, 1> JointVelocityPinocchio;
    typedef Eigen::Matrix<double, 6, 18> CompleteJac;
    typedef Eigen::Matrix<double, 3, 3> LinVelJac;
    // create a class that directly manage the pinocchio structure and compite the estimated ground reaction force
    class Pinocchio_Feet_Force : public pronto::quadruped::FeetContactForces
    {
        public:
            Pinocchio_Feet_Force(pinocchio::Model mod,int DOF):
            model_(mod),
            data_(pinocchio::Data(mod)),
            DOF_(DOF)
            {
                q_pin_ = Eigen::MatrixXd::Zero(DOF + FB_DOF,1);
                dq_pin_ = Eigen::MatrixXd::Zero(DOF_ + FB_VEL,1);

                Jac_ = Eigen::MatrixXd::Zero(3,DOF_/4);
            };
            ~Pinocchio_Feet_Force(){};

            // compute the ground reaction force and save it in foot_grf
            bool getFootGRF(
                const JointState& q,
                const JointState& qd,
                const JointState& tau,
                const Quaterniond& orient,
                const LegID& leg,
                Vector3d& foot_grf,
                const JointState& qdd = JointState::Zero(),
                const Vector3d& xd = Vector3d::Zero(),
                const Vector3d& xdd = Vector3d::Zero(),
                const Vector3d& omega = Vector3d::Zero(),
                const Vector3d& omegad = Vector3d::Zero()
            );

            bool getLegJacobian(
                    const LegID& leg,
                    LinVelJac& Jac
                );
            bool computeJac(
                const JointStatePinocchio q
            );


        private:
            pinocchio::Model model_;
            pinocchio::Data data_;
            int DOF_;
            int leg_count_ = 0;
            Eigen::MatrixXd q_pin_,dq_pin_,Jac_;

    };

    class Pinocchio_Jacobian : public pronto::quadruped::FeetJacobians
    {
        public:
            Pinocchio_Jacobian(
                pinocchio::Model model,
                pinocchio::Data data,
                int DOF,
                std::map<std::string,int> op_map
                ):
            model_(model),
            data_(data),
            DOF_(DOF),
            op_map_(op_map)
            {
                // init the Jacobian Storage for Each LEg, here the data are computed at the beginning and then storage
                q_pin_ = Eigen::MatrixXd::Zero(DOF + FB_DOF , 1);
                dq_pin_ = Eigen::MatrixXd::Zero(DOF + FB_VEL , 1);
                Jacs_.resize(0);
                for(int i = 0; i < 4; i++)
                    Jacs_.push_back(Eigen::MatrixXd::Zero(3,DOF + FB_VEL));
                Foot_pos_.resize(4);
            };
            ~Pinocchio_Jacobian(){};

            // given the joint configuration compute both jacobian and forward kinematic and save it in class member
            // it assumes that 
            bool Compute_All(const pronto::quadruped::JointState q);

            pronto::quadruped::FootJac getFootJacobian(const JointState& q, const LegID& leg) override;

            pronto::quadruped::Vector3d getFootPos(const JointState& q, const LegID& leg);

            

            
        private:
            pinocchio::Model model_;
            pinocchio::Data data_;
            int DOF_;
            Eigen::MatrixXd q_pin_,dq_pin_;
            std::vector<Eigen::MatrixXd> Jacs_;
            std::vector<Eigen::Vector3d> Foot_pos_;
            std::vector<LegID> legs_ = {LegID::LF,LegID::LH,LegID::RF,LegID::RH};
            std::map<std::string,int> op_map_;
            std::vector<std::string> pin_jnt_name_;
    };
};