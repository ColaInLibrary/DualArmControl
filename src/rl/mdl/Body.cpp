/**
 ******************************************************************************
 * @Description   :
 * @author        : AN Hao
 * @Date          : 24-11-1
 * @Version       : 0.0.1
 * @File          : Body.cpp
 ******************************************************************************
 */

#include "Body.h"

#include <rl/math/Rotation.h>

namespace rl {
namespace mdl {
Body::Body()
    : Frame(),
      cm(::rl::math::Vector3::Zero()),
      collision(true),
      fX(::rl::math::ForceVector::Zero()),
      ic(::rl::math::Matrix33::Identity()),
      m(1),
      selfcollision() {}

Body::~Body() {}

void Body::forwardAcceleration() {}

void Body::forwardDynamics1() {
  this->iA = this->i;

  // v x I * v - X_0 * f^x
  this->pA = this->v.cross(this->i * this->v) - this->x * this->fX;
}

void Body::forwardDynamics2() {}

void Body::forwardDynamics3() {}

void Body::forwardPosition() {}

void Body::forwardVelocity() {}

bool Body::getCollision() const { return this->collision; }

bool Body::getCollision(Body* body) const {
  return this->selfcollision.count(body) == 0;
}

void Body::inverseDynamics1() {
  // I * a + v x I * v - X_0 * f^x
  this->f =
      this->i * this->a + this->v.cross(this->i * this->v) - this->x * this->fX;
}

void Body::inverseDynamics2() {}

void Body::setCenterOfMass(const ::rl::math::Real& x, const ::rl::math::Real& y,
                           const ::rl::math::Real& z) {
  this->cm.x() = x;
  this->cm.y() = y;
  this->cm.z() = z;

  // m * c
  this->i.cog() = this->m * this->cm;

  // Ic - m * cx * cx
  this->i.inertia() =
      this->ic - this->m * this->cm.cross33() * this->cm.cross33();
}

void Body::setCollision(const bool& collision) { this->collision = collision; }

void Body::setCollision(Body* body, const bool& collision) {
  if (collision) {
    ::std::unordered_set<Body*>::iterator found = ::std::find(
        this->selfcollision.begin(), this->selfcollision.end(), body);

    if (found != this->selfcollision.end()) {
      this->selfcollision.erase(found);
    }
  } else {
    this->selfcollision.insert(body);
  }
}

void Body::setMass(const ::rl::math::Real& m) {
  this->m = m;

  this->i.mass() = m;

  // m * c
  this->i.cog() = this->m * this->cm;

  // Ic - m * cx * cx
  this->i.inertia() =
      this->ic - this->m * this->cm.cross33() * this->cm.cross33();
}

void Body::setInertia(const ::rl::math::Real& xx, const ::rl::math::Real& yy,
                      const ::rl::math::Real& zz, const ::rl::math::Real& yz,
                      const ::rl::math::Real& xz, const ::rl::math::Real& xy) {
  ::rl::math::Vector6 ic;
  ic << xx, yy, zz, yz, xz, xy;
  this->ic = ic.voigt33();

  // Ic - m * cx * cx
  this->i.inertia() =
      this->ic - this->m * this->cm.cross33() * this->cm.cross33();
}
}  // namespace mdl
}  // namespace rl
