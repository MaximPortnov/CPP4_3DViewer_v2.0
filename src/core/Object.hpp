#ifndef __OBJECT_H__
#define __OBJECT_H__


#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <array>

#include <QtOpenGL>

#include "Surface.hpp"
#include "Vertex.hpp"

namespace s21 {
class Object {
 private:
  std::vector<s21::Vertex> vertices;
  std::vector<s21::Surface> surfaces;

 public:
  static Object load_obj(std::string path);
  void render();
};
}  // namespace s21

#endif  // __OBJECT_H__