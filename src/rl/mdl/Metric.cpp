/**
 ******************************************************************************
 * @Description   :
 * @author        : AN Hao
 * @Date          : 24-11-1
 * @Version       : 0.0.1
 * @File          : Metric.cpp
 ******************************************************************************
 */
#include "Metric.h"

#include "Joint.h"

namespace rl {
namespace mdl {
Metric::Metric() : Model() {}

Metric::~Metric() {}

void Metric::clamp(::rl::math::Vector& q) const {
  assert(q.size() == this->getDofPosition());

  for (::std::size_t i = 0, j = 0; i < this->joints.size();
       j += this->joints[i]->getDofPosition(), ++i) {
    this->joints[i]->clamp(q.segment(j, this->joints[i]->getDofPosition()));
  }
}

::rl::math::Real Metric::distance(const ::rl::math::Vector& q1,
                                  const ::rl::math::Vector& q2) const {
  assert(q1.size() == this->getDofPosition());
  assert(q2.size() == this->getDofPosition());

  ::rl::math::Real d = 0;

  for (::std::size_t i = 0, j = 0; i < this->joints.size();
       j += this->joints[i]->getDofPosition(), ++i) {
    d += this->joints[i]->transformedDistance(
        q1.segment(j, this->joints[i]->getDofPosition()),
        q2.segment(j, this->joints[i]->getDofPosition()));
  }

  return this->inverseOfTransformedDistance(d);
}

void Metric::interpolate(const ::rl::math::Vector& q1,
                         const ::rl::math::Vector& q2,
                         const ::rl::math::Real& alpha,
                         ::rl::math::Vector& q) const {
  assert(q1.size() == this->getDofPosition());
  assert(q2.size() == this->getDofPosition());
  assert(alpha >= 0);
  assert(alpha <= 1);
  assert(q.size() == this->getDofPosition());

  for (::std::size_t i = 0, j = 0; i < this->joints.size();
       j += this->joints[i]->getDofPosition(), ++i) {
    this->joints[i]->interpolate(
        q1.segment(j, this->joints[i]->getDofPosition()),
        q2.segment(j, this->joints[i]->getDofPosition()), alpha,
        q.segment(j, this->joints[i]->getDofPosition()));
  }
}

::rl::math::Real Metric::inverseOfTransformedDistance(
    const ::rl::math::Real& d) const {
  return ::std::sqrt(d);
}

bool Metric::isValid(const ::rl::math::Vector& q) const {
  assert(q.size() == this->getDofPosition());

  for (::std::size_t i = 0, j = 0; i < this->joints.size();
       j += this->joints[i]->getDofPosition(), ++i) {
    if (!this->joints[i]->isValid(
            q.segment(j, this->joints[i]->getDofPosition()))) {
      return false;
    }
  }

  return true;
}

void Metric::normalize(::rl::math::Vector& q) const {
  assert(q.size() == this->getDofPosition());

  for (::std::size_t i = 0, j = 0; i < this->joints.size();
       j += this->joints[i]->getDofPosition(), ++i) {
    this->joints[i]->normalize(q.segment(j, this->joints[i]->getDofPosition()));
  }
}

void Metric::step(const ::rl::math::Vector& q1, const ::rl::math::Vector& dq,
                  ::rl::math::Vector& q2) const {
  assert(q1.size() == this->getDofPosition());
  assert(dq.size() == this->getDof());
  assert(q2.size() == this->getDofPosition());

  for (::std::size_t i = 0, j = 0, k = 0; i < this->joints.size();
       j += this->joints[i]->getDofPosition(), k += this->joints[i]->getDof(),
                     ++i) {
    this->joints[i]->step(q1.segment(j, this->joints[i]->getDofPosition()),
                          dq.segment(k, this->joints[i]->getDof()),
                          q2.segment(j, this->joints[i]->getDofPosition()));
  }
}

::rl::math::Real Metric::transformedDistance(const ::rl::math::Real& d) const {
  return ::std::pow(d, 2);
}

::rl::math::Real Metric::transformedDistance(
    const ::rl::math::Vector& q1, const ::rl::math::Vector& q2) const {
  assert(q1.size() == this->getDofPosition());
  assert(q2.size() == this->getDofPosition());

  ::rl::math::Real d = 0;

  for (::std::size_t i = 0, j = 0; i < this->joints.size();
       j += this->joints[i]->getDofPosition(), ++i) {
    d += this->joints[i]->transformedDistance(
        q1.segment(j, this->joints[i]->getDofPosition()),
        q2.segment(j, this->joints[i]->getDofPosition()));
  }

  return d;
}

::rl::math::Real Metric::transformedDistance(const ::rl::math::Real& q1,
                                             const ::rl::math::Real& q2,
                                             const ::std::size_t& i) const {
  ::rl::math::Real delta = ::std::abs(q1 - q2);

  if (this->joints[i]->wraparound(0)) {
    ::rl::math::Real range =
        ::std::abs(this->joints[i]->max(0) - this->joints[i]->min(0));
    return this->transformedDistance(
        ::std::max(delta, ::std::abs(range - delta)));
  } else {
    return this->transformedDistance(delta);
  }
}

void Metric::update() {
  Model::update();

  this->normalize(this->home);
}
}  // namespace mdl
}  // namespace rl
