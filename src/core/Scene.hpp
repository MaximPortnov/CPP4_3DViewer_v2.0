#ifndef __SCENE_H__
#define __SCENE_H__

#include "Object.hpp"
#include "TransformMatrix.hpp"

namespace s21 {
class Scene {
  s21::Object _object;
  s21::TransformMatrix _matrix;
  bool _transform_loop = false;
  public:
  void load_obj(const std::string& path);
  void render();
  void transform(TransformMatrix matrix);
  void transform_loop_begin();
  void transform_loop_end();
};
}  // namespace s21
#endif  // __SCENE_H__