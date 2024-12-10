#include "TransformMatrix.hpp"

namespace s21 {
TransformMatrix::TransformMatrix() {
  matrix = {{
      {{1, 0, 0, 0}},
      {{0, 1, 0, 0}},
      {{0, 0, 1, 0}},
      {{0, 0, 0, 1}},
  }};
}

TransformMatrix TransformMatrix::dot(const TransformMatrix& other) {

}
}  // namespace s21