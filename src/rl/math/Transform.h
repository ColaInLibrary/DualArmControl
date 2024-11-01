/**
 ******************************************************************************
 * @Description   :
 * @author        : AN Hao
 * @Date          : 24-10-22
 * @Version       : 0.0.1
 * @File          : Transform.h
 ******************************************************************************
 */

#ifndef DUALARMCONTROL_SRC_MATH_TRANSFORM_H_
#define DUALARMCONTROL_SRC_MATH_TRANSFORM_H_

#define EIGEN_MATRIXBASE_PLUGIN <rl/math/MatrixBaseAddons.h>
#define EIGEN_QUATERNIONBASE_PLUGIN <rl/math/QuaternionBaseAddons.h>
#define EIGEN_TRANSFORM_PLUGIN <rl/math/TransformAddons.h>

#include <Eigen/Geometry>

#include "Matrix.h"
#include "Quaternion.h"
#include "Vector.h"
#include "Rotation.h"

namespace rl {
  namespace math {
    /** Rigid transformation in 3D. */
    typedef ::Eigen::Transform<Real, 3, ::Eigen::Affine> Transform;

    /** Translation in 3D. */
    typedef ::Eigen::Translation<Real, 3> Translation;
  }
}

#endif  // DUALARMCONTROL_SRC_MATH_TRANSFORM_H_
