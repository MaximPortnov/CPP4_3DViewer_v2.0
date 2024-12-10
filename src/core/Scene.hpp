#ifndef __SCENE_H__
#define __SCENE_H__

#include "Object.hpp"
#include "TransformMatrix.hpp"

namespace s21 {
class Scene {
  s21::Object Object;
  s21::TransformMatrix main_matrix;
  s21::TransformMatrix loop_matrix;
  public:
  void render();
  void transform();
  void transform_loop();
};
}  // namespace s21
#endif  // __SCENE_H__