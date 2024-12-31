#ifndef __CONST_H__
#define __CONST_H__

#include <GL/glu.h>
#include <QOpenGLWidget>
#include <QOpenGLFunctions>
#include <QVector>
#include <QString>
#include <QFile>
#include <QFileDialog>
#include <QColorDialog>
#include <QMessageBox>
#include <gifimage/qgifimage.h>
#include <QTimer>
#include <QImage>
#include <QDebug>

enum ProjectionType { Central, Parallel };
enum LineType { Solid, Dotted };
enum VertexType { None, Circle, Square };

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
};
};  // namespace s21

#endif  // __CONST_H__