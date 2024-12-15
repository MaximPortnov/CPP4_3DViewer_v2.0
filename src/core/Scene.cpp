#include "Scene.hpp"

namespace s21 {
void Scene::load_obj(const std::string& path) {
  _object = s21::Object::load_obj(path);
}

void Scene::render() {
  if (_transform_loop) {
    _matrix.mult_matrix(_matrix_animate);
  }
  glPushMatrix();
  glLoadIdentity();
  _matrix_view.load_matrix();
  _matrix.load_matrix();
  _object.render();
  glPopMatrix();
}

void Scene::transform(TransformMatrix matrix) { _matrix = matrix; }

void Scene::animate_start(TransformMatrix matrix) {
  _matrix_animate = matrix;
  _transform_loop = true;
}

void Scene::animate_stop() { _transform_loop = false; }

void Scene::set_view(TransformMatrix matrix) { _matrix_view = matrix; }
}  // namespace s21