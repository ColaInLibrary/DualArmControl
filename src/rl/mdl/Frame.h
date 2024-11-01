/**
 ******************************************************************************
 * @Description   :
 * @author        : AN Hao
 * @Date          : 24-11-1
 * @Version       : 0.0.1
 * @File          : Frame.h
 ******************************************************************************
 */

#ifndef RL_SRC_RL_MDL_FRAME_H_
#define RL_SRC_RL_MDL_FRAME_H_

#include <rl/math/Spatial.h>
#include <rl/math/Transform.h>
#include <rl/math/Vector.h>

#include <boost/graph/adjacency_list.hpp>

#include "Element.h"

namespace rl {
namespace mdl {
class RL_MDL_EXPORT Frame : public Element {
 public:
  EIGEN_MAKE_ALIGNED_OPERATOR_NEW

  typedef ::boost::adjacency_list< ::boost::listS, ::boost::listS,
                                   ::boost::bidirectionalS, ::boost::listS>
      Tree;

  typedef Tree::vertex_descriptor Vertex;

  Frame();

  virtual ~Frame();

  virtual void forwardAcceleration();

  virtual void forwardDynamics1();

  virtual void forwardDynamics2();

  virtual void forwardDynamics3();

  virtual void forwardPosition();

  virtual void forwardVelocity();

  const Vertex& getVertexDescriptor() const;

  virtual void inverseDynamics1();

  virtual void inverseDynamics2();

  virtual void inverseForce();

  void setVertexDescriptor(const Vertex& descriptor);

  ::rl::math::MotionVector a;

  ::rl::math::MotionVector c;

  ::rl::math::ForceVector f;

  ::rl::math::RigidBodyInertia i;

  ::rl::math::ArticulatedBodyInertia iA;

  ::rl::math::ForceVector pA;

  ::rl::math::MotionVector v;

  ::rl::math::PlueckerTransform x;

 protected:
 private:
  Vertex descriptor;
};
}  // namespace mdl
}  // namespace rl

#endif  // RL_SRC_RL_MDL_FRAME_H_
