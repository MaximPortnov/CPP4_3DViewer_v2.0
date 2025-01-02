#include "Model.hpp"

namespace s21 {
Model::Model() {
  s21::TransformMatrixBuilder builder2;
  auto t2 = builder2.translate(0., 0., -5.).build();
  scene.set_view(t2);
  updateTranslate();
}

void Model::stopAnimate() {
  s21::TransformMatrixBuilder builder1;
  auto t1 = builder1.rotate(settings.ax, 1, 0, 0)
                .rotate(settings.ay, 0, 1, 0)
                .rotate(settings.az, 0, 0, 1)
                .build();
  scene.animate_start(t1);
  // scene.animate_start();
}

void Model::startAnimate() { scene.animate_stop(); }

void Model::loadOBJ(const QString &filename) {
  scene.load_obj(filename.toStdString());
}

void Model::setBackgroundColor(const QColor &color) {
  if (color.isValid()) {
    settings.backgroundColor = color;
  }
}

void Model::setEdgeColor(const QColor &color) {
  if (color.isValid()) {
    settings.edgeColor = color;
  }
}

void Model::indexSetProjectionType(const int index, int w, int h) {
  if (index == 0) {
    setProjectionType(Central, w, h);
  } else if (index == 1) {
    setProjectionType(Parallel, w, h);
  }
}

void Model::setProjectionType(const ProjectionType type, int w, int h) {
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  settings.projectionType = type;
  if (settings.projectionType == Central) {
    gluPerspective(45.0f, (float)w / (float)h, 0.1f,
                   100.0f);  // центральная проекция
  } else if (settings.projectionType == Parallel) {
    glOrtho(-2, 2, -2, 2, 1, 100);  // параллельная проекция
  }
  glMatrixMode(GL_MODELVIEW);
}

void Model::indexSetLineType(const int index) {
  if (index == 0) {
    setLineType(Solid);
  } else if (index == 1) {
    setLineType(Dotted);
  }
}

void Model::setLineType(const LineType type) { settings.lineType = type; }

void Model::setLineWidht(const int size) { settings.lineWidth = size; }

void Model::indexSetVertexType(const int index) {
  if (index == 0) {
    setVertexType(None);
  } else if (index == 1) {
    setVertexType(Circle);
  } else if (index == 2) {
    setVertexType(Square);
  }
}

void Model::setVertexType(const VertexType type) { settings.vertexType = type; }

void Model::setVertexColor(const QColor &color) {
  if (color.isValid()) {
    settings.vertexColor = color;
  }
}

void Model::setVertexWidht(const int size) { settings.vertexWidth = size; }

void Model::setTranslateX(int size) {
  settings.tx = (double)size / 10;
  updateTranslate();
}

void Model::setTranslateY(int size) {
  settings.ty = (double)size / 10;
  updateTranslate();
}

void Model::setTranslateZ(int size) {
  settings.tz = (double)size / 10;
  updateTranslate();
}

void Model::setRotateX(int size) {
  settings.rx = (double)size;
  updateTranslate();
}

void Model::setRotateY(int size) {
  settings.ry = (double)size;
  updateTranslate();
}

void Model::setRotateZ(int size) {
  settings.rz = (double)size;
  updateTranslate();
}

void Model::setScale(int size) {
  settings.sx = (double)(size + 5) / 10;
  settings.sy = (double)(size + 5) / 10;
  settings.sz = (double)(size + 5) / 10;
  // qDebug() << sz;
  updateTranslate();
}

void Model::setAnimateRotateX(int size) { settings.ax = size; }

void Model::setAnimateRotateY(int size) { settings.ay = size; }

void Model::setAnimateRotateZ(int size) { settings.az = size; }

void Model::updateTranslate() {
  s21::TransformMatrixBuilder builder;
  auto t = builder.translate(settings.tx, settings.ty, settings.tz)
               .scale(settings.sx, settings.sy, settings.sz)
               .rotate(settings.rx, 1, 0, 0)
               .rotate(settings.ry, 0, 1, 0)
               .rotate(settings.rz, 0, 0, 1)
               .build();
  scene.transform(t);
}

void Model::projectionSetup(int w, int h) {
  if (settings.projectionType == Central) {
    gluPerspective(45.0f, (float)w / (float)h, 0.1f,
                   100.0f);  // центральная проекция
  } else if (settings.projectionType == Parallel) {
    glOrtho(-2, 2, -2, 2, 1, 100);  // параллельная проекция
  }
}

void Model::drawingSettings() {
  glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);  // Включаем каркасный режим
  glClearColor(settings.backgroundColor.redF(),
               settings.backgroundColor.greenF(),
               settings.backgroundColor.blueF(), 1.0f);  // Цвет фона
  glColor3f(settings.edgeColor.redF(), settings.edgeColor.greenF(),
            settings.edgeColor.blueF());  // Цвет ребер
  glLineWidth(settings.lineWidth);        // толщина

  if (settings.lineType == Dotted) {
    // Включаем пунктирные линии
    glEnable(GL_LINE_STIPPLE);
    glLineStipple(1, 0x0101);
  }

  // Отображаем полигоны (треугольники)
  // glBegin(GL_TRIANGLES);
  // for (const Face &face : faces) {
  //     // Отображаем каждый треугольник
  //     glVertex3f(vertices[face.v1].x, vertices[face.v1].y,
  //     vertices[face.v1].z); glVertex3f(vertices[face.v2].x,
  //     vertices[face.v2].y, vertices[face.v2].z);
  //     glVertex3f(vertices[face.v3].x, vertices[face.v3].y,
  //     vertices[face.v3].z);
  // }
  // glEnd();

  scene.render(settings.vertexType, settings.vertexColor, settings.vertexWidth);

  if (settings.lineType == Dotted) {
    // Выключаем пунктирные линии
    glDisable(GL_LINE_STIPPLE);
  }

  // if (vertexType != None) {
  //     glColor3f(vertexColor.redF(), vertexColor.greenF(),
  //     vertexColor.blueF()); glPointSize(vertexWidth);
  //     glEnable(GL_POINT_SMOOTH);
  //     if (vertexType == Square)
  //         glDisable(GL_POINT_SMOOTH);
  //     glBegin(GL_POINTS);
  //     for (const Vertex &vertex : vertices) {
  //         glVertex3f(vertex.x, vertex.y, vertex.z);
  //     }
  //     glEnd();
  // }
}

QColor Model::getBackgroundColor() { return settings.backgroundColor; }

QColor Model::getEdgeColor() { return settings.edgeColor; }

QColor Model::getVertexColor() { return settings.vertexColor; }

std::size_t Model::count_vertices() { return scene.count_vertices(); }

std::size_t Model::count_surfaces() { return scene.count_surfaces(); }

std::size_t Model::count_edges() { return scene.count_edges(); }

}  // namespace s21
