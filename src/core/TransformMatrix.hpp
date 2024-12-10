#ifndef __TRANSFORMMATRIX_H__
#define __TRANSFORMMATRIX_H__

#include <array>
namespace s21 {
class TransformMatrix {
  using Matrix4x4 = std::array<std::array<double, 4>, 4>;
  Matrix4x4 matrix;

 public:
  TransformMatrix();
  TransformMatrix dot(const TransformMatrix& other);
};

}  // namespace s21

#endif  // __TRANSFORMMATRIX_H__