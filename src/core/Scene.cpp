#include "Scene.hpp"

namespace s21 {
void Scene::load_obj(const std::string& path) {
  _object = s21::Object::load_obj(path);
}

void Scene::render(VertexType vertexType, QColor vertexColor, int vertexWidth) {
  if (_transform_loop) {
    _matrix.mult_matrix(_matrix_animate);
  }
  glPushMatrix();
  glLoadIdentity();
  _matrix_view.load_matrix();
  _matrix.load_matrix();
  _object.render();
  _object.render_vertex_type(vertexType, vertexColor, vertexWidth);
  glPopMatrix();
}

void Scene::transform(TransformMatrix matrix) { _matrix = matrix; }

void Scene::animate_start(TransformMatrix matrix) {
  _matrix_animate = matrix;
  _transform_loop = true;
}

void Scene::animate_stop() { _transform_loop = false; }

void Scene::set_view(TransformMatrix matrix) { _matrix_view = matrix; }

std::size_t Scene::count_vertices() { return _object.count_vertices(); }

std::size_t Scene::count_surfaces() { return _object.count_surfaces(); }

std::size_t Scene::count_edges() { return _object.count_edges(); }
}  // namespace s21