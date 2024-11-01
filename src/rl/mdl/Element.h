/**
 ******************************************************************************
 * @Description   :
 * @author        : AN Hao
 * @Date          : 24-11-1
 * @Version       : 0.0.1
 * @File          : Element.h
 ******************************************************************************
 */

#ifndef RL_SRC_RL_MDL_ELEMENT_H_
#define RL_SRC_RL_MDL_ELEMENT_H_

#include <rl/math/Real.h>
#include <rl/mdl/export.h>

#include <string>

namespace rl {
namespace mdl {
class RL_MDL_EXPORT Element {
 public:
  Element();

  virtual ~Element();

  virtual void forwardAcceleration() = 0;

  virtual void forwardDynamics1() = 0;

  virtual void forwardDynamics2() = 0;

  virtual void forwardDynamics3() = 0;

  virtual void forwardPosition() = 0;

  virtual void forwardVelocity() = 0;

  const ::std::string& getName() const;

  virtual void inverseDynamics1() = 0;

  virtual void inverseDynamics2() = 0;

  virtual void inverseForce() = 0;

  void setName(const ::std::string& name);

 protected:
 private:
  ::std::string name;
};
}  // namespace mdl
}  // namespace rl

#endif  // RL_SRC_RL_MDL_ELEMENT_H_
