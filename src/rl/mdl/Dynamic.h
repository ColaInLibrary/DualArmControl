/**
 ******************************************************************************
 * @Description   :
 * @author        : AN Hao
 * @Date          : 24-11-1
 * @Version       : 0.0.1
 * @File          : Dynamic.h
 ******************************************************************************
 */

#ifndef RL_SRC_RL_MDL_DYNAMIC_H_
#define RL_SRC_RL_MDL_DYNAMIC_H_

#include "Kinematic.h"

namespace rl {
namespace mdl {
class RL_MDL_EXPORT Dynamic : public Kinematic {
 public:
  Dynamic();

  virtual ~Dynamic();

  /**
   * Calculate centrifugal and Coriolis vector.
   *
   * @pre setPosition()
   * @pre setVelocity()
   * @post getCentrifugalCoriolis()
   *
   * @see inverseDynamics()
   */
  void calculateCentrifugalCoriolis();

  /**
   * Calculate centrifugal and Coriolis vector.
   *
   * @param[out] V Centrifugal and Coriolis vector \f$\vec{V}(\vec{q},
   * \dot{\vec{q}})\f$
   *
   * @pre setPosition()
   * @pre setVelocity()
   *
   * @see inverseDynamics()
   */
  void calculateCentrifugalCoriolis(::rl::math::Vector& V);

  /**
   * Calculate gravity vector.
   *
   * @pre setPosition()
   * @post getGravity()
   *
   * @see inverseDynamics()
   */
  void calculateGravity();

  /**
   * Calculate gravity vector.
   *
   * @param[out] G Gravity vector \f$\vec{G}(\vec{q})\f$
   *
   * @pre setPosition()
   *
   * @see inverseDynamics()
   */
  void calculateGravity(::rl::math::Vector& G);

  /**
   * Calculate joint space mass matrix.
   *
   * @pre setPosition()
   * @post getMassMatrix()
   *
   * @see inverseDynamics()
   */
  void calculateMassMatrix();

  /**
   * Calculate joint space mass matrix.
   *
   * @param[out] M Joint space mass matrix \f$\matr{M}^{-1}(\vec{q})\f$
   *
   * @pre setPosition()
   *
   * @see inverseDynamics()
   */
  void calculateMassMatrix(::rl::math::Matrix& M);

  /**
   * Calculate joint space mass matrix inverse.
   *
   * @pre setPosition()
   * @post getMassMatrixInverse()
   *
   * @see forwardDynamics()
   */
  void calculateMassMatrixInverse();

  /**
   * Calculate joint space mass matrix inverse.
   *
   * @param[out] invM Joint space mass matrix inverse
   * \f$\matr{M}^{-1}(\vec{q})\f$
   *
   * @pre setPosition()
   *
   * @see forwardDynamics()
   */
  void calculateMassMatrixInverse(::rl::math::Matrix& invM);

  /**
   * Calculate operational space mass matrix inverse.
   *
   * @pre setPosition()
   * @pre calculateJacobian()
   * @pre calculateMassMatrix()
   * @pre calculateMassMatrixInverse()
   * @post getOperationalMassMatrixInverse()
   */
  void calculateOperationalMassMatrixInverse();

  /**
   * Calculate operational space mass matrix inverse.
   *
   * @param[in] J Jacobian matrix \f$\matr{J}(\vec{q})\f$
   * @param[in] invM Joint space mass matrix inverse
   * \f$\matr{M}^{-1}(\vec{q})\f$
   * @param[out] invMx Operational space mass matrix inverse
   * \f$\matr{M}_{\mathrm{x}}^{-1}(\vec{q})\f$
   */
  void calculateOperationalMassMatrixInverse(const ::rl::math::Matrix& J,
                                             const ::rl::math::Matrix& invM,
                                             ::rl::math::Matrix& invMx) const;

  RL_MDL_DEPRECATED void eulerCauchy(const ::rl::math::Real& dt);

  /**
   * Forward dynamics via articulated-body algorithm.
   *
   * \f[ \ddot{\vec{q}} = \matr{M}^{-1}(\vec{q}) \, \bigl( \vec{\tau} -
   * \vec{C}(\vec{q}, \dot{\vec{q}}) - \vec{V}(\vec{q}) \bigr) \f]
   *
   * @pre setPosition()
   * @pre setVelocity()
   * @pre setTorque()
   * @post getAcceleration()
   */
  void forwardDynamics();

  /**
   * Access calculated centrifugal and Coriolis vector.
   *
   * @return Centrifugal and Coriolis vector \f$\vec{V}(\vec{q},
   * \dot{\vec{q}})\f$
   *
   * @pre setPosition()
   * @pre setVelocity()
   */
  const ::rl::math::Vector& getCentrifugalCoriolis() const;

  /**
   * Access calculated gravity vector.
   *
   * @return Gravity vector \f$\vec{G}(\vec{q})\f$
   *
   * @pre setPosition()
   * @pre setWorldGravity()
   */
  const ::rl::math::Vector& getGravity() const;

  /**
   * Access calculated joint space mass matrix inverse.
   *
   * @return Joint space mass matrix inverse \f$\matr{M}^{-1}(\vec{q})\f$
   *
   * @pre setPosition()
   * @pre calculateJacobian()
   * @pre calculateMassMatrix()
   * @pre calculateMassMatrixInverse()
   */
  const ::rl::math::Matrix& getMassMatrixInverse() const;

  /**
   * Access calculated joint space mass matrix.
   *
   * @return Joint space mass matrix \f$\matr{M}(\vec{q})\f$
   *
   * @pre setPosition()
   */
  const ::rl::math::Matrix& getMassMatrix() const;

  /**
   * Access calculated operational space mass matrix inverse.
   *
   * @return Operational space mass matrix inverse
   * \f$\matr{M}_{\mathrm{x}}^{-1}(\vec{q})\f$
   *
   * @pre setPosition()
   * @pre calculateJacobian()
   * @pre calculateMassMatrix()
   * @pre calculateMassMatrixInverse()
   * @pre calculateOperationalMassMatrixInverse()
   */
  const ::rl::math::Matrix& getOperationalMassMatrixInverse() const;

  /**
   * Inverse dynamics via recursive Newton-Euler algorithm.
   *
   * \f[ \vec{\tau} = \matr{M}(\vec{q}) \, \ddot{\vec{q}} + \vec{C}(\vec{q},
   * \dot{\vec{q}}) + \vec{G}(\vec{q}) \f]
   *
   * @pre setPosition()
   * @pre setVelocity()
   * @pre setAcceleration()
   * @post getTorque()
   */
  void inverseDynamics();

  void inverseForce();

  RL_MDL_DEPRECATED void rungeKuttaNystrom(const ::rl::math::Real& dt);

  virtual void update();

 protected:
  /**
   * Gravity vector
   *
   * \f[ \vec{G}(\vec{q}) \f]
   *
   * @pre calculateGravity()
   *
   * @see getGravity()
   * */
  ::rl::math::Vector G;

  /**
   * Joint space mass matrix inverse.
   *
   * \f[ \matr{M}^{-1}(\vec{q}) \f]
   *
   * @pre calculateMassMatrixInverse()
   *
   * @see getMassMatrixInverse()
   * */
  ::rl::math::Matrix invM;

  /**
   * Operational space mass matrix inverse.
   *
   * \f[ \matr{M}_{\mathrm{x}}^{-1}(\vec{q}) \f]
   *
   * @pre calculateOperationalMassMatrixInverse()
   *
   * @see getOperationalMassMatrixInverse()
   * */
  ::rl::math::Matrix invMx;

  /**
   * Joint space mass matrix.
   *
   * \f[ \matr{M}(\vec{q}) \f]
   *
   * @pre calculateMassMatrix()
   *
   * @see getMassMatrix()
   * */
  ::rl::math::Matrix M;

  /**
   * Centrifugal and Coriolis vector.
   *
   * \f[ \vec{V}(\vec{q}, \dot{\vec{q}}) \f]
   *
   * @pre calculateCentrifugalCoriolis()
   *
   * @see getCentrifugalCoriolis()
   * */
  ::rl::math::Vector V;

 private:
};
}  // namespace mdl
}  // namespace rl

#endif  // RL_SRC_RL_MDL_DYNAMIC_H_
