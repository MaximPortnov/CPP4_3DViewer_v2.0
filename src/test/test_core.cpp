#include "test.hpp"

TEST(core_test, load_obj) {
  std::cout << path << '\n';

  auto obj = s21::Object::load_obj(path + "../obj_files/cube.obj");
  for (auto& el : obj.vertices){
    std::cout << "v " << el.X << ' ' << el.Y << ' ' << el.Z << '\n';
  }
  
  for (auto& el : obj.surfaces){
    std::cout << "f " << el.first.vertex_index << '/' << ' '
                      << el.second.vertex_index << '/' << ' '
                      << el.third.vertex_index << '/' << '\n';
  }

}