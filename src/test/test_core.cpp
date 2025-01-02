#include "test.hpp"

TEST(core_test, load_obj) {
  std::cout << path << '\n';

  auto obj = s21::Object::load_obj(path + "../obj_files/cube.obj_test");
  ASSERT_EQ(obj.count_vertices(), 8);
  ASSERT_EQ(obj.count_surfaces(), 12);
  ASSERT_EQ(obj.count_edges(), 18);
  for (auto& el : obj.vertices) {
    std::cout << "v " << el.X << ' ' << el.Y << ' ' << el.Z << '\n';
  }

  for (auto& el : obj.surfaces) {
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

TEST(core_test, matrix) {
  s21::TransformMatrixBuilder builder;
  auto temp = builder.translate(1, 2, 3)
                             .scale(4, 5, 6)
                             .rotate(7, 1, 0, 0)
                             .rotate(8, 0, 1, 0)
                             .rotate(9, 0, 0, 1)
                             .build();
  s21::TransformMatrix t(temp);

  std::array<double, 16> prov = {
      3.9123, 0.8601,  -0.7042, 0, -0.6196, 4.8883, 0.8518, 0,
      0.5566, -0.6034, 5.8973,  0, 1,       2,      3,      1};
  for (int i = 0; i < 16; i++) {
    ASSERT_LT(t._matrix.matrix[i] - prov[i], 0.001);
  }
  // scene.transform(t);

  s21::TransformMatrixBuilder builder2;
  auto t1 = builder2.translate(1., 2., 3.).build();
  t = t1;
  std::array<double, 16> prov2 = {1, 0, 0, 0, 0, 1, 0, 0,
                                  0, 0, 1, 0, 1, 2, 3, 1};
  for (int i = 0; i < 16; i++) {
    ASSERT_LT(t._matrix.matrix[i] - prov2[i], 0.001);
  }
  // scene.set_view(t2);

  s21::TransformMatrixBuilder builder1;
  t = builder1.rotate(5, 0, 1, 0).build();
  std::array<double, 16> prov1 = {0.9961, 0, -0.0871, 0, 0, 1, 0, 0,
                                  0.0871, 0, 0.9961,  0, 0, 0, 0, 1};
  for (int i = 0; i < 16; i++) {
    ASSERT_LT(t._matrix.matrix[i] - prov1[i], 0.001);
  }
  // scene.animate_start(t1);
  std::cout << "asd" << '\n';
}
