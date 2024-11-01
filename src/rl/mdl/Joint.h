/**
 ******************************************************************************
 * @Description   :
 * @author        : AN Hao
 * @Date          : 24-11-1
 * @Version       : 0.0.1
 * @File          : Joint.h
 ******************************************************************************
 */

#ifndef RL_SRC_RL_MDL_JOINT_H_
#define RL_SRC_RL_MDL_JOINT_H_

#include <rl/math/Units.h>
#include <rl/math/Vector.h>

#include "Transform.h"

namespace rl {
namespace mdl {
class RL_MDL_EXPORT Joint : public Transform {
 public:
  Joint(const ::std::size_t& dofPosition, const ::std::size_t& dofVelocity);

  virtual ~Joint();

  virtual void clamp(::rl::math::VectorRef q) const;

  virtual ::rl::math::Real distance(const ::rl::math::ConstVectorRef& q1,
                                    const ::rl::math::ConstVectorRef& q2) const;

  void forwardAcceleration();

  void forwardDynamics1();

  void forwardDynamics2();

  void forwardDynamics3();

  void forwardVelocity();

  virtual void generatePositionGaussian(const ::rl::math::ConstVectorRef& rand,
                                        const ::rl::math::ConstVectorRef& mean,
                                        const ::rl::math::ConstVectorRef& sigma,
                                        ::rl::math::VectorRef q) const;

  virtual void generatePositionUniform(const ::rl::math::ConstVectorRef& rand,
                                       ::rl::math::VectorRef q) const;

  virtual void generatePositionUniform(const ::rl::math::ConstVectorRef& rand,
                                       const ::rl::math::ConstVectorRef& min,
                                       const ::rl::math::ConstVectorRef& max,
                                       ::rl::math::VectorRef q) const;

  const ::rl::math::Vector& getAcceleration() const;

  const ::Eigen::Matrix<::rl::math::Units, ::Eigen::Dynamic, 1>&
  getAccelerationUnits() const;

  ::std::size_t getDof() const;

  ::std::size_t getDofPosition() const;

  const ::rl::math::Vector& getMaximum() const;

  const ::rl::math::Vector& getMinimum() const;

  const ::rl::math::Vector& getOffset() const;

  const ::rl::math::Vector& getPosition() const;

  const ::Eigen::Matrix<::rl::math::Units, ::Eigen::Dynamic, 1>&
  getPositionUnits() const;

  const ::rl::math::Vector& getSpeed() const;

  const ::Eigen::Matrix<::rl::math::Units, ::Eigen::Dynamic, 1>& getSpeedUnits()
      const;

  const ::rl::math::Vector& getTorque() const;

  const ::Eigen::Matrix<::rl::math::Units, ::Eigen::Dynamic, 1>&
  getTorqueUnits() const;

  const ::rl::math::Vector& getVelocity() const;

  const ::Eigen::Matrix<::rl::math::Units, ::Eigen::Dynamic, 1>&
  getVelocityUnits() const;

  const ::Eigen::Matrix<bool, ::Eigen::Dynamic, 1>& getWraparound() const;

  virtual void interpolate(const ::rl::math::ConstVectorRef& q1,
                           const ::rl::math::ConstVectorRef& q2,
                           const ::rl::math::Real& alpha,
                           ::rl::math::VectorRef q) const;

  void inverseForce();

  virtual bool isValid(const ::rl::math::ConstVectorRef& q) const;

  virtual void normalize(::rl::math::VectorRef q) const;

  void setAcceleration(const ::rl::math::ConstVectorRef& qdd);

  void setMaximum(const ::rl::math::ConstVectorRef& max);

  void setMinimum(const ::rl::math::ConstVectorRef& min);

  void setOffset(const ::rl::math::ConstVectorRef& offset);

  virtual void setPosition(const ::rl::math::ConstVectorRef& q) = 0;

  void setSpeed(const ::rl::math::ConstVectorRef& speed);

  void setTorque(const ::rl::math::ConstVectorRef& tau);

  void setVelocity(const ::rl::math::ConstVectorRef& qd);

  void setWraparound(
      const ::Eigen::Ref<const ::Eigen::Matrix<bool, ::Eigen::Dynamic, 1>>&
          wraparound);

  virtual void step(const ::rl::math::ConstVectorRef& q1,
                    const ::rl::math::ConstVectorRef& dq,
                    ::rl::math::VectorRef q2) const;

  virtual ::rl::math::Real transformedDistance(
      const ::rl::math::ConstVectorRef& q1,
      const ::rl::math::ConstVectorRef& q2) const;

  ::rl::math::MotionVector a;

  ::rl::math::MotionVector c;

  ::rl::math::Matrix D;

  ::rl::math::Vector max;

  ::rl::math::Vector min;

  ::rl::math::Vector offset;

  ::rl::math::Vector q;

  ::Eigen::Matrix<::rl::math::Units, ::Eigen::Dynamic, 1> qUnits;

  ::rl::math::Vector qd;

  ::Eigen::Matrix<::rl::math::Units, ::Eigen::Dynamic, 1> qdUnits;

  ::rl::math::Vector qdd;

  ::Eigen::Matrix<::rl::math::Units, ::Eigen::Dynamic, 1> qddUnits;

  ::rl::math::Matrix S;

  ::rl::math::Vector speed;

  ::Eigen::Matrix<::rl::math::Units, ::Eigen::Dynamic, 1> speedUnits;

  ::rl::math::Vector tau;

  ::Eigen::Matrix<::rl::math::Units, ::Eigen::Dynamic, 1> tauUnits;

  ::rl::math::Vector u;

  ::rl::math::Matrix U;

  ::rl::math::MotionVector v;

  ::Eigen::Matrix<bool, ::Eigen::Dynamic, 1> wraparound;

 protected:
 private:
};
}  // namespace mdl
}  // namespace rl

#endif  // RL_SRC_RL_MDL_JOINT_H_
