#ifndef __SCENE_H__
#define __SCENE_H__

#include "Object.hpp"
#include "TransformMatrix.hpp"

namespace s21 {
class Scene {
  s21::Object _object;
  s21::TransformMatrix _matrix;
  s21::TransformMatrix _matrix_animate;
  s21::TransformMatrix _matrix_view;
  bool _transform_loop = false;

 public:
  void load_obj(const std::string& path);
  void render(VertexType vertexType, QColor vertexColor, int vertexWidth);
  void transform(TransformMatrix matrix);
  void animate_start(TransformMatrix matrix);
  void animate_stop();
  void set_view(TransformMatrix matrix);
  std::size_t count_vertices();
  std::size_t count_surfaces();
  std::size_t count_edges();
};
}  // namespace s21
#endif  // __SCENE_H__