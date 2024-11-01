/**
 ******************************************************************************
 * @Description   :
 * @author        : AN Hao
 * @Date          : 24-11-1
 * @Version       : 0.0.1
 * @File          : Metric.h
 ******************************************************************************
 */

#ifndef RL_SRC_RL_MDL_METRIC_H_
#define RL_SRC_RL_MDL_METRIC_H_
#include "Model.h"

namespace rl {
namespace mdl {
class RL_MDL_EXPORT Metric : public Model {
 public:
  Metric();

  virtual ~Metric();

  void clamp(::rl::math::Vector& q) const;

  Model* clone() const;

  ::rl::math::Real distance(const ::rl::math::Vector& q1,
                            const ::rl::math::Vector& q2) const;

  void interpolate(const ::rl::math::Vector& q1, const ::rl::math::Vector& q2,
                   const ::rl::math::Real& alpha, ::rl::math::Vector& q) const;

  ::rl::math::Real inverseOfTransformedDistance(
      const ::rl::math::Real& d) const;

  bool isValid(const ::rl::math::Vector& q) const;

  void normalize(::rl::math::Vector& q) const;

  void step(const ::rl::math::Vector& q1, const ::rl::math::Vector& dq,
            ::rl::math::Vector& q2) const;

  ::rl::math::Real transformedDistance(const ::rl::math::Real& d) const;

  ::rl::math::Real transformedDistance(const ::rl::math::Vector& q1,
                                       const ::rl::math::Vector& q2) const;

  ::rl::math::Real transformedDistance(const ::rl::math::Real& q1,
                                       const ::rl::math::Real& q2,
                                       const ::std::size_t& i) const;

  virtual void update();

 protected:
 private:
};
}  // namespace mdl
}  // namespace rl

#endif  // RL_SRC_RL_MDL_METRIC_H_
