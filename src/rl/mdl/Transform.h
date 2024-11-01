/**
 ******************************************************************************
 * @Description   :
 * @author        : AN Hao
 * @Date          : 24-11-1
 * @Version       : 0.0.1
 * @File          : Transform.h
 ******************************************************************************
 */

#ifndef RL_SRC_RL_MDL_TRANSFORM_H_
#define RL_SRC_RL_MDL_TRANSFORM_H_

#include <rl/math/Spatial.h>
#include <rl/math/Transform.h>

#include <boost/graph/adjacency_list.hpp>

#include "Element.h"

namespace rl {
namespace mdl {
class Frame;

class RL_MDL_EXPORT Transform : public Element {
 public:
  EIGEN_MAKE_ALIGNED_OPERATOR_NEW

  typedef ::boost::adjacency_list< ::boost::listS, ::boost::listS,
                                   ::boost::bidirectionalS, ::boost::listS>
      Tree;

  typedef Tree::edge_descriptor Edge;

  Transform();

  virtual ~Transform();

  virtual void forwardAcceleration();

  virtual void forwardDynamics1();

  virtual void forwardDynamics2();

  virtual void forwardDynamics3();

  void forwardPosition();

  virtual void forwardVelocity();

  const Edge& getEdgeDescriptor() const;

  virtual void inverseDynamics1();

  virtual void inverseDynamics2();

  virtual void inverseForce();

  void setEdgeDescriptor(const Edge& descriptor);

  Frame* in;

  Frame* out;

  ::rl::math::PlueckerTransform x;

 protected:
 private:
  Edge descriptor;
};
}  // namespace mdl
}  // namespace rl

#endif  // RL_SRC_RL_MDL_TRANSFORM_H_
