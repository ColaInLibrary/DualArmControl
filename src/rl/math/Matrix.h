/**
 ******************************************************************************
 * @Description   :
 * @author        : AN Hao
 * @Date          : 24-10-22
 * @Version       : 0.0.1
 * @File          : Matrix.h
 ******************************************************************************
 */

#ifndef RL_SRC_MATH_MATRIX_H_
#define RL_SRC_MATH_MATRIX_H_

#define EIGEN_MATRIXBASE_PLUGIN <rl/math/MatrixBaseAddons.h>
#define EIGEN_QUATERNIONBASE_PLUGIN <rl/math/QuaternionBaseAddons.h>
#define EIGEN_TRANSFORM_PLUGIN <rl/math/TransformAddons.h>

#include <Eigen/Core>

#include "Real.h"

namespace rl
{
namespace math
{
typedef ::Eigen::Matrix<Real, ::Eigen::Dynamic, ::Eigen::Dynamic> Matrix;

typedef ::Eigen::Matrix<Real, 2, 2> Matrix22;

typedef ::Eigen::Matrix<Real, 3, 3> Matrix33;

typedef ::Eigen::Matrix<Real, 4, 4> Matrix44;

typedef ::Eigen::Matrix<Real, 6, 6> Matrix66;

typedef ::Eigen::Matrix<Real, 6, 7> Matrix67;

typedef ::Eigen::Matrix<Real, 7, 6> Matrix76;

typedef ::Eigen::Block<Matrix> MatrixBlock;

typedef ::Eigen::Block<Matrix22> Matrix22Block;

typedef ::Eigen::Block<Matrix33> Matrix33Block;

typedef ::Eigen::Block<Matrix44> Matrix44Block;

typedef ::Eigen::Block<Matrix66> Matrix66Block;

typedef ::Eigen::Block<Matrix67> Matrix67Block;

typedef ::Eigen::Block<Matrix76> Matrix76Block;

typedef Matrix::ColXpr MatrixColumn;

typedef Matrix22::ColXpr Matrix22Column;

typedef Matrix33::ColXpr Matrix33Column;

typedef Matrix44::ColXpr Matrix44Column;

typedef Matrix66::ColXpr Matrix66Column;

typedef Matrix67::ColXpr Matrix67Column;

typedef Matrix76::ColXpr Matrix76Column;

typedef Matrix::RowXpr MatrixRow;

typedef Matrix22::RowXpr Matrix22Row;

typedef Matrix33::RowXpr Matrix33Row;

typedef Matrix44::RowXpr Matrix44Row;

typedef Matrix66::RowXpr Matrix66Row;

typedef Matrix67::RowXpr Matrix67Row;

typedef Matrix76::RowXpr Matrix76Row;

typedef ::Eigen::Block<const Matrix> ConstMatrixBlock;

typedef ::Eigen::Block<const Matrix22> ConstMatrix22Block;

typedef ::Eigen::Block<const Matrix33> ConstMatrix33Block;

typedef ::Eigen::Block<const Matrix44> ConstMatrix44Block;

typedef ::Eigen::Block<const Matrix66> ConstMatrix66Block;

typedef ::Eigen::Block<const Matrix67> ConstMatrix67Block;

typedef ::Eigen::Block<const Matrix76> ConstMatrix76Block;

typedef Matrix::ConstColXpr ConstMatrixColumn;

typedef Matrix22::ConstColXpr ConstMatrix22Column;

typedef Matrix33::ConstColXpr ConstMatrix33Column;

typedef Matrix44::ConstColXpr ConstMatrix44Column;

typedef Matrix66::ConstColXpr ConstMatrix66Column;

typedef Matrix67::ConstColXpr ConstMatrix67Column;

typedef Matrix76::ConstColXpr ConstMatrix76Column;

typedef Matrix::ConstRowXpr ConstMatrixRow;

typedef Matrix22::ConstRowXpr ConstMatrix22Row;

typedef Matrix33::ConstRowXpr ConstMatrix33Row;

typedef Matrix44::ConstRowXpr ConstMatrix44Row;

typedef Matrix66::ConstRowXpr ConstMatrix66Row;

typedef Matrix67::ConstRowXpr ConstMatrix67Row;

typedef Matrix76::ConstRowXpr ConstMatrix76Row;

typedef ::Eigen::Ref<Matrix> MatrixRef;

typedef ::Eigen::Ref<const Matrix> ConstMatrixRef;

typedef ::Eigen::DiagonalMatrix<Real, ::Eigen::Dynamic, ::Eigen::Dynamic> DiagonalMatrix;

typedef ::Eigen::DiagonalMatrix<Real, 2, 2> DiagonalMatrix22;

typedef ::Eigen::DiagonalMatrix<Real, 3, 3> DiagonalMatrix33;

typedef ::Eigen::DiagonalMatrix<Real, 4, 4> DiagonalMatrix44;

typedef ::Eigen::DiagonalMatrix<Real, 6, 6> DiagonalMatrix66;
}
}
#endif  // RL_SRC_MATH_MATRIX_H_
