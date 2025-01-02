#ifndef __TRANSFORMMATRIX_H__
#define __TRANSFORMMATRIX_H__

#include <array>

#include "Object.hpp"
// #include <cmath>

namespace s21 {
class Object;
class Scene;

struct Matrix4x4 {
  using Matrix = std::array<double, 4 * 4>;
  Matrix matrix;

 public:
  double* operator[](std::size_t index);
  const double* operator[](std::size_t index) const;
  Matrix4x4();
  Matrix4x4(const Matrix4x4& other);
  Matrix4x4& operator=(const Matrix4x4& other);
  Matrix4x4& operator=(Matrix4x4&& other);
  Matrix4x4& dot(const Matrix4x4& other);
  static Matrix4x4 dot(const Matrix4x4& first, const Matrix4x4& second);
};

class TransformMatrix {
 private:
  Matrix4x4 _matrix;
  // double matrix[16];

 public:
  TransformMatrix() = default;
  TransformMatrix(const TransformMatrix& other);
  TransformMatrix(TransformMatrix&& other);
  TransformMatrix& operator=(const TransformMatrix& other);
  TransformMatrix& operator=(TransformMatrix&& other);

 private:
  void load_matrix();
  void mult_matrix(const TransformMatrix& matrix);

  friend class s21::Object;
  friend class s21::Scene;
  friend class TransformMatrixBuilder;
};

class TransformMatrixBuilder {
  Matrix4x4 matrix;

 public:
  TransformMatrixBuilder() = default;
  TransformMatrixBuilder& scale(double sx, double sy, double sz);
  TransformMatrixBuilder& translate(double tx, double ty, double tz);
  TransformMatrixBuilder& rotate(double angle, double x, double y, double z);
  TransformMatrix build();
};

}  // namespace s21

#endif  // __TRANSFORMMATRIX_H__