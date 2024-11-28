#ifndef __OBJECT_H__
#define __OBJECT_H__

#include <vector>

#include "Surface.hpp"
#include "Vertex.hpp"

namespace s21 {
class Object {
  std::vector<s21::Vertex> vertices;
  std::vector<s21::Surface> vertices;
 public:
  Object();
  Object(const Object& other);
  Object(Object&& other);
  Object& operator=(const Object& other);
  Object& operator=(Object&& other);
  ~Object() = default;
};
}  // namespace s21

#endif  // __OBJECT_H__