#include "TransformMatrix.hpp"

namespace s21 {
Matrix4x4::Matrix4x4() {
  matrix = {{
      {{1, 0, 0, 0}},
      {{0, 1, 0, 0}},
      {{0, 0, 1, 0}},
      {{0, 0, 0, 1}},
  }};
}

Matrix4x4& Matrix4x4::dot(const Matrix4x4& other) {
  *this = dot(*this, other);
  return *this;
}

Matrix4x4 Matrix4x4::dot(const Matrix4x4& first, const Matrix4x4& second) {
  Matrix4x4 res;
  res.matrix = {{{{0., 0., 0., 0.}},
                 {{0., 0., 0., 0.}},
                 {{0., 0., 0., 0.}},
                 {{0., 0., 0., 0.}}}};
  for (int i = 0; i < 4; ++i) {
    for (int j = 0; j < 4; ++j) {
      for (int k = 0; k < 4; ++k) {
        res.matrix[i][j] += first.matrix[i][k] * second.matrix[k][j];
      }
    }
  }
  return res;
}

TransformMatrix::TransformMatrix(const TransformMatrix& other) {
  matrix = other.matrix;
  // for (int i = 0; i < 16; ++i){
  //   matrix[i] = other.matrix[i];
  // }
}

// TransformMatrix::TransformMatrix() {

// }

TransformMatrix::TransformMatrix(TransformMatrix&& other) {
  matrix = std::move(other.matrix);
  //   for (int i = 0; i < 16; ++i){
  //   matrix[i] = other.matrix[i];
  // }
}

TransformMatrix& TransformMatrix::operator=(const TransformMatrix& other) {
  //   for (int i = 0; i < 16; ++i){
  //   matrix[i] = other.matrix[i];
  // }
  matrix = other.matrix;
  return *this;
}

TransformMatrix& TransformMatrix::operator=(TransformMatrix&& other) {
  matrix = std::move(other.matrix);
  // for (int i = 0; i < 16; ++i){
  //   matrix[i] = other.matrix[i];
  // }
  return *this;
}

// TransformMatrix TransformMatrix::dot(const TransformMatrix& other) {
//   TransformMatrix res;
//   for (int i = 0; i < 4; ++i) {
//     for (int j = 0; j < 4; ++j) {
//       for (int k = 0; k < 4; ++k) {
//         res.matrix[i][j] += matrix[i][k] * other.matrix[k][j];
//       }
//     }
//   }
//   return res;
// }

void TransformMatrix::load_matrix() { 
  glLoadMatrixd(matrix.data()); 
}

void TransformMatrix::mult_matrix()
{
  glMultMatrixd(matrix.data());
}
TransformMatrixBuilder& TransformMatrixBuilder::scale(double sx, double sy,
                                                      double sz) {
  Matrix4x4 temp;
  temp.matrix[0][0] *= sx;
  temp.matrix[1][1] *= sy;
  temp.matrix[2][2] *= sz;
  matrix.dot(temp);
  return *this;
}

TransformMatrixBuilder& TransformMatrixBuilder::translate(double tx, double ty,
                                                          double tz) {
  Matrix4x4 temp;
  temp.matrix[0][3] += tx;
  temp.matrix[1][3] += ty;
  temp.matrix[2][3] += tz;
  matrix.dot(temp);
  return *this;
}

TransformMatrixBuilder& TransformMatrixBuilder::rotate(double angle, double x,
                                                       double y, double z) {
  double length = std::sqrt(x * x + y * y + z * z);
  if (length == 0)
    throw std::runtime_error("Не правильное конструирование rotate");
  Matrix4x4 temp;

  x /= length;
  y /= length;
  z /= length;

  double rad = angle * M_PI / 180.;
  double cosA = std::cos(rad);
  double sinA = std::sin(rad);
  double t = 1. - cosA;

  // Матрица вращения

  temp.matrix = {
      {{{t * x * x + cosA, t * x * y - z * sinA, t * x * z + y * sinA, 0.}},
       {{t * x * y + z * sinA, t * y * y + cosA, t * y * z - x * sinA, 0.}},
       {{t * x * z - y * sinA, t * y * z + x * sinA, t * z * z + cosA, 0.}},
       {{0., 0., 0., 1.}}}};

  matrix.dot(temp);
  return *this;
}

TransformMatrix TransformMatrixBuilder::build() {
  TransformMatrix res;
  for (int i = 0; i < 4; ++i) {
    for (int j = 0; j < 4; ++j) {
      res.matrix[i * 4 + j] = matrix.matrix[j][i];
    }
  }
  return res;
}

}  // namespace s21