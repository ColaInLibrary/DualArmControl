/**
 ******************************************************************************
 * @Description   :
 * @author        : AN Hao
 * @Date          : 24-10-22
 * @Version       : 0.0.1
 * @File          : Quaternion.h
 ******************************************************************************
 */

#ifndef DUALARMCONTROL_SRC_MATH_QUATERNION_H_
#define DUALARMCONTROL_SRC_MATH_QUATERNION_H_

#define EIGEN_MATRIXBASE_PLUGIN <rl/math/MatrixBaseAddons.h>
#define EIGEN_QUATERNIONBASE_PLUGIN <rl/math/QuaternionBaseAddons.h>
#define EIGEN_TRANSFORM_PLUGIN <rl/math/TransformAddons.h>

#include <Eigen/Geometry>

#include "Real.h"

namespace rl
{
namespace math
{
typedef ::Eigen::Quaternion<Real> Quaternion;
}
}

#endif  // DUALARMCONTROL_SRC_MATH_QUATERNION_H_
