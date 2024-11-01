/**
 ******************************************************************************
 * @Description   :
 * @author        : AN Hao
 * @Date          : 24-11-1
 * @Version       : 0.0.1
 * @File          : Frame.cpp
 ******************************************************************************
 */
#include "Frame.h"

namespace rl {
namespace mdl {
Frame::Frame()
    : Element(),
      a(::rl::math::MotionVector::Zero()),
      c(::rl::math::MotionVector::Zero()),
      f(::rl::math::ForceVector::Zero()),
      i(::rl::math::RigidBodyInertia::Identity()),
      iA(::rl::math::ArticulatedBodyInertia::Identity()),
      pA(::rl::math::ForceVector::Zero()),
      v(::rl::math::MotionVector::Zero()),
      x(::rl::math::PlueckerTransform::Identity()),
      descriptor() {}

Frame::~Frame() {}

void Frame::forwardAcceleration() {}

void Frame::forwardDynamics1() {
  this->iA.setZero();
  this->pA.setZero();
}

void Frame::forwardDynamics2() {}

void Frame::forwardDynamics3() {}

void Frame::forwardPosition() {}

void Frame::forwardVelocity() {}

const Frame::Vertex& Frame::getVertexDescriptor() const {
  return this->descriptor;
}

void Frame::inverseDynamics1() { this->f.setZero(); }

void Frame::inverseDynamics2() {}

void Frame::inverseForce() {}

void Frame::setVertexDescriptor(const Vertex& descriptor) {
  this->descriptor = descriptor;
}
}  // namespace mdl
}  // namespace rl
