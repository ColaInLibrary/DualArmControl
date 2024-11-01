/**
 ******************************************************************************
 * @Description   :
 * @author        : AN Hao
 * @Date          : 24-11-1
 * @Version       : 0.0.1
 * @File          : Body.h
 ******************************************************************************
 */

#ifndef RL_SRC_RL_MDL_BODY_H_
#define RL_SRC_RL_MDL_BODY_H_

#include <unordered_set>

#include "Frame.h"

namespace rl {
namespace mdl {
class RL_MDL_EXPORT Body : public Frame {
 public:
  Body();

  virtual ~Body();

  void forwardAcceleration();

  void forwardDynamics1();

  void forwardDynamics2();

  void forwardDynamics3();

  void forwardPosition();

  void forwardVelocity();

  bool getCollision() const;

  bool getCollision(Body* body) const;

  void inverseDynamics1();

  void inverseDynamics2();

  void setCenterOfMass(const ::rl::math::Real& x, const ::rl::math::Real& y,
                       const ::rl::math::Real& z);

  void setCollision(const bool& collision);

  void setCollision(Body* body, const bool& collision);

  void setMass(const ::rl::math::Real& m);

  void setInertia(const ::rl::math::Real& xx, const ::rl::math::Real& yy,
                  const ::rl::math::Real& zz, const ::rl::math::Real& yz,
                  const ::rl::math::Real& xz, const ::rl::math::Real& xy);

  ::rl::math::Vector3 cm;

  bool collision;

  ::rl::math::ForceVector fX;

  ::rl::math::Matrix33 ic;

  ::rl::math::Real m;

  ::std::unordered_set<Body*> selfcollision;

 protected:
 private:
};
}  // namespace mdl
}  // namespace rl

#endif  // RL_SRC_RL_MDL_BODY_H_
