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

std::string readFile(const std::string& fileName) {
    std::ifstream f(fileName);
    f.seekg(0, std::ios::end);
    size_t size = f.tellg();
    std::string s(size, ' ');
    f.seekg(0);
    f.read(&s[0], size); // по стандарту можно в C++11, по факту работает и на старых компиляторах
    return s;
}

namespace s21 {
Object Object::load_obj(const std::string& path) {
  Object res;
  std::ifstream object_file(path);
  if (!object_file.is_open()) {
    throw std::runtime_error("HelloНе удалось найти файл");
  }
  std::string s = readFile(path);
  std::istringstream s1(s);
  std::string line;

  while (std::getline(s1, line)) {
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
      std::size_t v1 = std::stoi(f1_split[0]);
      std::size_t v2 = std::stoi(f2_split[0]);
      std::size_t v3 = std::stoi(f3_split[0]);
      surface.nodes[0].vertex_index = v1;
      surface.nodes[1].vertex_index = v2;
      surface.nodes[2].vertex_index = v3;
      res.edges.insert(std::minmax(v1,v2));
      res.edges.insert(std::minmax(v2,v3));
      res.edges.insert(std::minmax(v1,v3));
      res.surfaces.push_back(surface);
    }
  }
  object_file.close();
  
  return res;
}

void Object::render() {
  glBegin(GL_TRIANGLES);
  for (const auto& el : surfaces) {
    for (int i = 0; i < 3; i++) {
      const auto& temp = vertices[el.nodes[i].vertex_index - 1];
      glVertex3d(temp.X, temp.Y, temp.Z);
    }
  }
  glEnd();
}

void Object::render_vertex_type(VertexType vertexType, QColor vertexColor,
                                int vertexWidth) {
  if (vertexType == None) return;
  glColor3f(vertexColor.redF(), vertexColor.greenF(), vertexColor.blueF());
  glPointSize(vertexWidth);
  glEnable(GL_POINT_SMOOTH);
  if (vertexType == Square) glDisable(GL_POINT_SMOOTH);
  glBegin(GL_POINTS);
  for (const auto& el : surfaces) {
    for (int i = 0; i < 3; i++) {
      const auto& temp = vertices[el.nodes[i].vertex_index - 1];
      glVertex3d(temp.X, temp.Y, temp.Z);
    }
  }
  glEnd();
}
std::size_t Object::count_vertices() { return vertices.size(); }
std::size_t Object::count_surfaces() { return surfaces.size(); }
std::size_t Object::count_edges() {return edges.size();}
}  // namespace s21