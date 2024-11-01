/**
 ******************************************************************************
 * @Description   :
 * @author        : AN Hao
 * @Date          : 24-11-1
 * @Version       : 0.0.1
 * @File          : Transform.cpp
 ******************************************************************************
 */

#include "Transform.h"

#include "Frame.h"

namespace rl {
namespace mdl {
Transform::Transform()
    : Element(),
      in(nullptr),
      out(nullptr),
      x(::rl::math::PlueckerTransform::Identity()),
      descriptor() {}

Transform::~Transform() {}

void Transform::forwardAcceleration() { this->out->a = this->x * this->in->a; }

void Transform::forwardDynamics1() {
  this->forwardVelocity();
  this->out->c.setZero();
}

void Transform::forwardDynamics2() {
  // I^A + X^* * I^a * X
  this->in->iA = this->in->iA + this->x / this->out->iA;

  // p^A + I^a * c
  ::rl::math::ForceVector pa(this->out->pA + this->out->iA * this->out->c);

  // p^A + X^* * p^a
  this->in->pA = this->in->pA + this->x / pa;
}

void Transform::forwardDynamics3() {
  // X * a + c
  this->out->a = this->x * this->in->a + this->out->c;
}

void Transform::forwardPosition() { this->out->x = this->in->x * this->x; }

void Transform::forwardVelocity() { this->out->v = this->x * this->in->v; }

const Transform::Edge& Transform::getEdgeDescriptor() const {
  return this->descriptor;
}

void Transform::inverseDynamics1() {
  this->forwardVelocity();
  this->forwardAcceleration();
}

void Transform::inverseDynamics2() { this->inverseForce(); }

void Transform::inverseForce() {
  // f + X * f
  this->in->f = this->in->f + this->x / this->out->f;
}

void Transform::setEdgeDescriptor(const Edge& descriptor) {
  this->descriptor = descriptor;
}
}  // namespace mdl
}  // namespace rl
