/**
 ******************************************************************************
 * @Description   :
 * @author        : AN Hao
 * @Date          : 24-10-22
 * @Version       : 0.0.1
 * @File          : Rotation.h
 ******************************************************************************
 */

#ifndef DUALARMCONTROL_SRC_MATH_ROTATION_H_
#define DUALARMCONTROL_SRC_MATH_ROTATION_H_

#define EIGEN_MATRIXBASE_PLUGIN <rl/math/MatrixBaseAddons.h>
#define EIGEN_QUATERNIONBASE_PLUGIN <rl/math/QuaternionBaseAddons.h>
#define EIGEN_TRANSFORM_PLUGIN <rl/math/TransformAddons.h>

#include <Eigen/Geometry>

#include "Matrix.h"

namespace rl {
  namespace math {
    typedef ::Eigen::AngleAxis<Real> AngleAxis;
  }
}

#endif  // DUALARMCONTROL_SRC_MATH_ROTATION_H_
