#include "test.hpp"

TEST(core_test, load_obj) {
  std::cout << path << '\n';

  auto obj = s21::Object::load_obj(path + "../obj_files/cube.obj_test");
  
  for (auto& el : obj.vertices){
    std::cout << "v " << el.X << ' ' << el.Y << ' ' << el.Z << '\n';
  }
  
  for (auto& el : obj.surfaces){
    std::cout << "f " << el.nodes[0].vertex_index << '/' << ' '
                      << el.nodes[1].vertex_index << '/' << ' '
                      << el.nodes[2].vertex_index << '/' << '\n';
  }

}

TEST(core_test, save_settings) {
  s21::Settings t;
  t.backgroundColor = QColor(101, 102, 103);
  t.edgeColor = QColor(104, 105, 106);
  t.vertexColor = QColor(107, 108, 109);
  t.projectionType = ProjectionType::Parallel;
  t.lineType = LineType::Dotted;
  t.lineWidth = 2;
  t.vertexType = VertexType::Circle;
  t.vertexWidth = 7;


  s21::Settings::save(t);

  auto r = s21::Settings::load();
  
  ASSERT_EQ(t.backgroundColor.red(), r.backgroundColor.red());
  ASSERT_EQ(t.backgroundColor.green(), r.backgroundColor.green());
  ASSERT_EQ(t.backgroundColor.blue(), r.backgroundColor.blue());
  
  ASSERT_EQ(t.edgeColor.red(), r.edgeColor.red());
  ASSERT_EQ(t.edgeColor.green(), r.edgeColor.green());
  ASSERT_EQ(t.edgeColor.blue(), r.edgeColor.blue());

  ASSERT_EQ(t.vertexColor.red(), r.vertexColor.red());
  ASSERT_EQ(t.vertexColor.green(), r.vertexColor.green());
  ASSERT_EQ(t.vertexColor.blue(), r.vertexColor.blue());

  ASSERT_EQ(t.projectionType, r.projectionType);
  ASSERT_EQ(t.lineType, r.lineType);
  ASSERT_EQ(t.vertexType, r.vertexType);

  ASSERT_EQ(t.lineWidth, r.lineWidth);
  ASSERT_EQ(t.vertexWidth, r.vertexWidth);
}
