#ifndef __SETTINGS_H__
#define __SETTINGS_H__

#include <fstream>
#include <sstream>
#include <string>

#include "const.hpp"
#include <QCoreApplication>

namespace s21 {
struct Settings {
  QColor backgroundColor = QColor(Qt::black);
  QColor edgeColor = QColor(Qt::white);
  ProjectionType projectionType = Central;
  LineType lineType = Solid;
  int lineWidth = 1;
  QColor vertexColor = QColor(Qt::red);
  VertexType vertexType = None;
  int vertexWidth = 0;

  double tx = 0;
  double ty = 0;
  double tz = 0;
  double sx = 0.5;
  double sy = 0.5;
  double sz = 0.5;
  double rx = 0;
  double ry = 0;
  double rz = 0;

  static void save(Settings a);
  static Settings load();
};



};  // namespace s21

#endif  // __SETTINGS_H__