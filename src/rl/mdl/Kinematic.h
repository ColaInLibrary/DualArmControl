/**
 ******************************************************************************
 * @Description   :
 * @author        : AN Hao
 * @Date          : 24-11-1
 * @Version       : 0.0.1
 * @File          : Kinematic.h
 ******************************************************************************
 */

#ifndef RL_SRC_RL_MDL_KINEMATIC_H_
#define RL_SRC_RL_MDL_KINEMATIC_H_
#include <rl/math/Matrix.h>

#include "Metric.h"

namespace rl {
namespace mdl {
class RL_MDL_EXPORT Kinematic : public Metric {
 public:
  EIGEN_MAKE_ALIGNED_OPERATOR_NEW

  Kinematic();

  virtual ~Kinematic();

  RL_MDL_DEPRECATED bool calculateInversePosition(
      const ::rl::math::Transform& x, const ::std::size_t& leaf = 0,
      const ::rl::math::Real& delta =
          ::std::numeric_limits<::rl::math::Real>::infinity(),
      const ::rl::math::Real& epsilon = static_cast<::rl::math::Real>(1.0e-6),
      const ::std::size_t& iterations = 10000);

  /**
   * Calculate Jacobian matrix.
   *
   * @param[in] inWorldFrame Calculate in world or tool frame
   *
   * @pre setPosition()
   * @post getJacobian()
   *
   * @see forwardVelocity()
   */
  void calculateJacobian(const bool& inWorldFrame = true);

  /**
   * Calculate Jacobian matrix.
   *
   * @param[out] J Jacobian matrix \f$\matr{J}(\vec{q})\f$
   * @param[in] inWorldFrame Calculate in world or tool frame
   *
   * @pre setPosition()
   *
   * @see forwardVelocity()
   */
  void calculateJacobian(::rl::math::Matrix& J,
                         const bool& inWorldFrame = true);

  /**
   * Calculate Jacobian derivative vector.
   *
   * @param[in] inWorldFrame Calculate in world or tool frame
   *
   * @pre setPosition()
   * @pre setVelocity()
   * @post getJacobianDerivative()
   *
   * @see forwardVelocity
   * @see forwardAcceleration
   */
  void calculateJacobianDerivative(const bool& inWorldFrame = true);

  /**
   * Calculate Jacobian derivative vector.
   *
   * @param[out] Jdqd Jacobian derivative vector \f$\dot{\matr{J}}(\vec{q},
   * \dot{\vec{q}}) \, \dot{\vec{q}}\f$
   * @param[in] inWorldFrame Calculate in world or tool frame
   *
   * @pre setPosition()
   * @pre setVelocity()
   *
   * @see forwardVelocity()
   * @see forwardAcceleration()
   */
  void calculateJacobianDerivative(::rl::math::Vector& Jdqd,
                                   const bool& inWorldFrame = true);

  /**
   * Calculate Jacobian matrix inverse.
   *
   * \f[ \matr{J}^{\dagger}(\vec{q}) = \sum_{i = 1}^{r} \frac{ \sigma_{i} }{
   * \sigma_{i}^{2} + \lambda^{2} } \, \vec{v}_{i} \, \vec{u}_{i}^{\mathrm{T}}
   * \f] \f[ \matr{J}^{\dagger}(\vec{q}) = \matr{J}^{\mathrm{T}}(\vec{q}) \,
   * \bigl( \matr{J}(\vec{q}) \, \matr{J}^{\mathrm{T}}(\vec{q}) + \lambda^{2} \,
   * \matr{1} \bigr)^{-1} \f]
   *
   * @param[in] lambda Damping factor \f$\lambda\f$
   * @param[in] doSvd Use singular value decomposition or damped least squares
   *
   * @pre setPosition()
   * @pre calculateJacobian()
   * @post getJacobianInverse()
   */
  void calculateJacobianInverse(const ::rl::math::Real& lambda = 0,
                                const bool& doSvd = true);

  /**
   * Calculate Jacobian matrix inverse.
   *
   * \f[ \matr{J}^{\dagger}(\vec{q}) = \sum_{i = 1}^{r} \frac{ \sigma_{i} }{
   * \sigma_{i}^{2} + \lambda^{2} } \, \vec{v}_{i} \, \vec{u}_{i}^{\mathrm{T}}
   * \f] \f[ \matr{J}^{\dagger}(\vec{q}) = \matr{J}^{\mathrm{T}}(\vec{q}) \,
   * \bigl( \matr{J}(\vec{q}) \, \matr{J}^{\mathrm{T}}(\vec{q}) + \lambda^{2} \,
   * \matr{1} \bigr)^{-1} \f]
   *
   * @param[in] J Jacobian matrix \f$\matr{J}\f$
   * @param[in] invJ Jacobian matrix inverse \f$\matr{J}^{\dagger}\f$
   * @param[in] lambda Damping factor \f$\lambda\f$
   * @param[in] doSvd Use singular value decomposition or damped least squares
   *
   * @pre setPosition()
   * @pre calculateJacobian()
   */
  void calculateJacobianInverse(const ::rl::math::Matrix& J,
                                ::rl::math::Matrix& invJ,
                                const ::rl::math::Real& lambda = 0,
                                const bool& doSvd = true) const;

  /**
   * Calculate manipulability measure.
   *
   * \f[ \mu(\vec{q}) = \sqrt{\det \bigl( \matr{J}(\vec{q}) \,
   * \matr{J}^{\mathrm{T}}(\vec{q}) \bigr)} \f]
   *
   * @return Manipulability measure \f$\mu(\vec{q})\f$
   *
   * @pre setPosition()
   * @pre calculateJacobian()
   */
  ::rl::math::Real calculateManipulabilityMeasure() const;

  /**
   * Calculate manipulability measure.
   *
   * \f[ \mu(\vec{q}) = \sqrt{\det \bigl( \matr{J}(\vec{q}) \,
   * \matr{J}^{\mathrm{T}}(\vec{q}) \bigr)} \f]
   *
   * @param[in] J Jacobian matrix \f$\matr{J}(\vec{q})\f$
   *
   * @return Manipulability measure \f$\mu(\vec{q})\f$
   */
  ::rl::math::Real calculateManipulabilityMeasure(
      const ::rl::math::Matrix& J) const;

  /**
   * @pre setPosition()
   * @pre setVelocity()
   * @pre setAcceleration()
   * @post getOperationalAcceleration()
   */
  void forwardAcceleration();

  /**
   * @pre setPosition()
   * @post getOperationalPosition()
   */
  void forwardPosition();

  /**
   * @pre setPosition()
   * @pre setVelocity()
   * @post getOperationalVelocity()
   */
  void forwardVelocity();

  /**
   * Access calculated Jacobian matrix.
   *
   * @return Jacobian matrix \f$\matr{J}(\vec{q})\f$
   *
   * @pre setPosition()
   * @pre calculateJacobian()
   */
  const ::rl::math::Matrix& getJacobian() const;

  /**
   * Access calculated Jacobian derivative vector.
   *
   * @return Jacobian derivative vector \f$\dot{\matr{J}}(\vec{q},
   * \dot{\vec{q}}) \, \dot{\vec{q}}\f$
   *
   * @pre setPosition()
   * @pre setVelocity()
   * @pre calculateJacobianDerivative()
   */
  const ::rl::math::Vector& getJacobianDerivative() const;

  /**
   * Access calculated Jacobian matrix inverse.
   *
   * @return Jacobian matrix inverse \f$\matr{J}^{\dagger}(\vec{q})\f$
   *
   * @pre setPosition()
   * @pre calculateJacobian()
   * @pre calculateJacobianInverse()
   */
  const ::rl::math::Matrix& getJacobianInverse() const;

  /**
   * Check if current configuration is singular.
   *
   * @pre calculateJacobian()
   */
  bool isSingular() const;

  /**
   * Check if current configuration is singular.
   *
   * @param[in] J Jacobian matrix \f$\matr{J}(\vec{q})\f$
   */
  bool isSingular(const ::rl::math::Matrix& J) const;

  virtual void update();

 protected:
  /**
   * Jacobian matrix inverse.
   *
   * \f[ \matr{J}^{\dagger}(\vec{q}) \f]
   *
   * @pre calculateJacobianInverse()
   *
   * @see getJacobianInverse()
   * */
  ::rl::math::Matrix invJ;

  /**
   * Jacobian matrix.
   *
   * \f[ \matr{J}(\vec{q}) \f]
   *
   * @pre calculateJacobian()
   *
   * @see getJacobian()
   * */
  ::rl::math::Matrix J;

  /**
   * Jacobian derivative vector.
   *
   * \f[ \dot{\matr{J}}(\vec{q}, \dot{\vec{q}}) \, \dot{\vec{q}} \f]
   *
   * @pre calculateJacobianDerivative()
   *
   * @see getJacobianDerivative()
   * */
  ::rl::math::Vector Jdqd;

 private:
};
}  // namespace mdl
}  // namespace rl

#endif  // RL_SRC_RL_MDL_KINEMATIC_H_
