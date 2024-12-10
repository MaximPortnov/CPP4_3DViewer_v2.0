#include "Scene.hpp"

namespace s21 {
void Scene::load_obj(const std::string& path) {
  _object = s21::Object::load_obj(path);
}

void Scene::render() {
  _matrix.load_matrix();
  _object.render();
}

void Scene::transform(TransformMatrix matrix) { _matrix = matrix; }

void Scene::transform_loop_begin() { _transform_loop = true; }

void Scene::transform_loop_end() { _transform_loop = false; }
}  // namespace s21