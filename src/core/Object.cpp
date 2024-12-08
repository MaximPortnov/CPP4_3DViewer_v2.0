#include "Object.hpp"

namespace {
std::vector<std::string> split(std::string_view str,
                               std::string_view separator) {
  std::vector<std::string> res;
  std::size_t start = 0;
  std::size_t end = 0;

  while ((end = str.find(separator, start)) != std::string::npos) {
    res.push_back(std::string(str.substr(start, end - start)));
    start = end + 1;
  }
  res.push_back(std::string(str.substr(start, end - start)));
  return res;
}
}  // namespace

namespace s21 {
Object Object::load_obj(std::string path) {
  Object res;
  std::ifstream object_file(path);
  if (!object_file.is_open()) {
    throw std::runtime_error("Не удалось найти файл");
  }
  std::string line;
  while (std::getline(object_file, line)) {
    std::istringstream iss(line);
    std::string prefix;
    iss >> prefix;
    if (prefix == "v") {
      Vertex vertex;
      iss >> vertex.X >> vertex.Y >> vertex.Z;
      res.vertices.push_back(vertex);
    } else if (prefix == "f") {
      std::string f1, f2, f3;
      iss >> f1 >> f2 >> f3;
      auto f1_split = split(f1, "/");
      auto f2_split = split(f2, "/");
      auto f3_split = split(f3, "/");
      s21::Surface surface;
      surface.nodes[0].vertex_index = std::stoi(f1_split[0]);
      surface.nodes[1].vertex_index = std::stoi(f2_split[0]);
      surface.nodes[2].vertex_index = std::stoi(f3_split[0]);
      res.surfaces.push_back(surface);
    }
  }
  object_file.close();
  return res;
}

void Object::render() {
  glBegin(GL_LINES);
  for (const auto& el : surfaces) {
    glColor3d(1, 0, 0);
    for (int i = 0; i < 3; i++) {
      const auto& temp = vertices[el.nodes[i].vertex_index-1];
      glVertex3d(temp.X, temp.Y, temp.Z);
    }
    // el.nodes
  }
  glEnd();
}
}  // namespace s21