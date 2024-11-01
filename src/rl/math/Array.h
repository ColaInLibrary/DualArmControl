/**
 ******************************************************************************
 * @Description   :
 * @author        : AN Hao
 * @Date          : 24-10-22
 * @Version       : 0.0.1
 * @File          : Array.h
 ******************************************************************************
 */

#ifndef RL_SRC_MATH_ARRAY_H_
#define RL_SRC_MATH_ARRAY_H_

#define EIGEN_MATRIXBASE_PLUGIN <rl/math/MatrixBaseAddons.h>
#define EIGEN_QUATERNIONBASE_PLUGIN <rl/math/QuaternionBaseAddons.h>
#define EIGEN_TRANSFORM_PLUGIN <rl/math/TransformAddons.h>

#include <Eigen/Core>

#include "Real.h"

namespace rl {
  namespace math {
    typedef ::Eigen::Array<Real, ::Eigen::Dynamic, 1> ArrayX;

    typedef ::Eigen::Array<Real, ::Eigen::Dynamic, ::Eigen::Dynamic> ArrayXX;
  }  // namespace math
}    // namespace rl

#endif  // RL_SRC_MATH_ARRAY_H_
