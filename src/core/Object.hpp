#ifndef __OBJECT_H__
#define __OBJECT_H__

#include <QtOpenGL>
#include <array>
#include <fstream>
#include <set>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>

#include "Surface.hpp"
#include "Vertex.hpp"
#include "const.hpp"

namespace s21 {
class Object {
 private:
  std::vector<s21::Vertex> vertices;
  std::vector<s21::Surface> surfaces;
  std::set<std::pair<std::size_t, std::size_t>> edges;

 public:
  static Object load_obj(const std::string& path);
  void render();

  void render_vertex_type(VertexType vertexType, QColor vertexColor,
                          int vertexWidth);

  std::size_t count_vertices();
  std::size_t count_surfaces();
  std::size_t count_edges();
};
}  // namespace s21

#endif  // __OBJECT_H__