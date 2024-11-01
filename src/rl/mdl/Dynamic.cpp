/**
 ******************************************************************************
 * @Description   :
 * @author        : AN Hao
 * @Date          : 24-11-1
 * @Version       : 0.0.1
 * @File          : Dynamic.cpp
 ******************************************************************************
 */

#include "Dynamic.h"

#include <rl/math/Quaternion.h>
#include <rl/math/Rotation.h>
#include <rl/math/Spatial.h>

#include <algorithm>
#include <stack>

#include "EulerCauchyIntegrator.h"
#include "Exception.h"
#include "Prismatic.h"
#include "Revolute.h"
#include "RungeKuttaNystromIntegrator.h"
#include "World.h"

namespace rl {
namespace mdl {
Dynamic::Dynamic() : Kinematic(), G(), invM(), invMx(), M(), V() {}

Dynamic::~Dynamic() {}

void Dynamic::calculateCentrifugalCoriolis() {
  this->calculateCentrifugalCoriolis(this->V);
}

void Dynamic::calculateCentrifugalCoriolis(::rl::math::Vector& V) {
  ::rl::math::Vector3 g = this->getWorldGravity();

  ::rl::math::Vector tmp = ::rl::math::Vector::Zero(this->getDof());

  this->setAcceleration(tmp);
  this->setWorldGravity(::rl::math::Vector3::Zero());

  this->inverseDynamics();
  V = this->getTorque();

  this->setWorldGravity(g);
}

void Dynamic::calculateGravity() { this->calculateGravity(this->G); }

void Dynamic::calculateGravity(::rl::math::Vector& G) {
  ::rl::math::Vector tmp = ::rl::math::Vector::Zero(this->getDof());

  this->setVelocity(tmp);
  this->setAcceleration(tmp);

  this->inverseDynamics();
  G = this->getTorque();
}

void Dynamic::calculateMassMatrix() { this->calculateMassMatrix(this->M); }

void Dynamic::calculateMassMatrix(::rl::math::Matrix& M) {
  ::rl::math::Vector3 g = this->getWorldGravity();

  ::rl::math::Vector tmp = ::rl::math::Vector::Zero(this->getDof());

  this->setVelocity(tmp);
  this->setWorldGravity(::rl::math::Vector3::Zero());

  for (::std::size_t i = 0; i < this->getDof(); ++i) {
    for (::std::size_t j = 0; j < this->getDof(); ++j) {
      tmp(j) = i == j ? 1 : 0;
    }

    this->setAcceleration(tmp);
    this->inverseDynamics();

    M.col(i) = this->getTorque();
  }

  this->setWorldGravity(g);
}

void Dynamic::calculateMassMatrixInverse() {
  this->calculateMassMatrixInverse(this->invM);
}

void Dynamic::calculateMassMatrixInverse(::rl::math::Matrix& invM) {
  ::rl::math::Vector3 g = this->getWorldGravity();

  ::rl::math::Vector tmp = ::rl::math::Vector::Zero(this->getDof());

  this->setVelocity(tmp);
  this->setWorldGravity(::rl::math::Vector3::Zero());

  for (::std::size_t i = 0; i < this->getDof(); ++i) {
    for (::std::size_t j = 0; j < this->getDof(); ++j) {
      tmp(j) = i == j ? 1 : 0;
    }

    this->setTorque(tmp);
    this->forwardDynamics();

    invM.col(i) = this->getAcceleration();
  }

  this->setWorldGravity(g);
}

void Dynamic::calculateOperationalMassMatrixInverse() {
  this->calculateOperationalMassMatrixInverse(this->J, this->invM, this->invMx);
}

void Dynamic::calculateOperationalMassMatrixInverse(
    const ::rl::math::Matrix& J, const ::rl::math::Matrix& invM,
    ::rl::math::Matrix& invMx) const {
  invMx = J * invM * J.transpose();
}

void Dynamic::eulerCauchy(const ::rl::math::Real& dt) {
  EulerCauchyIntegrator integrator(this);
  integrator.integrate(dt);
}

void Dynamic::forwardDynamics() {
  for (::std::vector<Element*>::iterator i = this->elements.begin();
       i != this->elements.end(); ++i) {
    (*i)->forwardDynamics1();
  }

  for (::std::vector<Element*>::reverse_iterator i = this->elements.rbegin();
       i != this->elements.rend(); ++i) {
    (*i)->forwardDynamics2();
  }

  for (::std::vector<Element*>::iterator i = this->elements.begin();
       i != this->elements.end(); ++i) {
    (*i)->forwardDynamics3();
  }
}

const ::rl::math::Vector& Dynamic::getCentrifugalCoriolis() const {
  return this->V;
}

const ::rl::math::Vector& Dynamic::getGravity() const { return this->G; }

const ::rl::math::Matrix& Dynamic::getMassMatrixInverse() const {
  return this->invM;
}

const ::rl::math::Matrix& Dynamic::getMassMatrix() const { return this->M; }

const ::rl::math::Matrix& Dynamic::getOperationalMassMatrixInverse() const {
  return this->invMx;
}

void Dynamic::inverseDynamics() {
  for (::std::vector<Element*>::iterator i = this->elements.begin();
       i != this->elements.end(); ++i) {
    (*i)->inverseDynamics1();
  }

  for (::std::vector<Element*>::reverse_iterator i = this->elements.rbegin();
       i != this->elements.rend(); ++i) {
    (*i)->inverseDynamics2();
  }
}

void Dynamic::inverseForce() {
  for (::std::vector<Element*>::reverse_iterator i = this->elements.rbegin();
       i != this->elements.rend(); ++i) {
    (*i)->inverseForce();
  }
}

void Dynamic::rungeKuttaNystrom(const ::rl::math::Real& dt) {
  RungeKuttaNystromIntegrator integrator(this);
  integrator.integrate(dt);
}

void Dynamic::update() {
  Kinematic::update();

  this->M = ::rl::math::Matrix::Identity(this->getDof(), this->getDof());
  this->V = ::rl::math::Vector::Zero(this->getDof());
  this->G = ::rl::math::Vector::Zero(this->getDof());
  this->invM = ::rl::math::Matrix::Identity(this->getDof(), this->getDof());
  this->invMx = ::rl::math::Matrix::Identity(6 * this->getOperationalDof(),
                                             6 * this->getOperationalDof());
}
}  // namespace mdl
}  // namespace rl
