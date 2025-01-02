#ifndef __MODEL_H__
#define __MODEL_H__
#ifdef _WIN32
#include <windows.h>
#endif
#include <GL/glu.h>
#include <gifimage/qgifimage.h>

#include <QColorDialog>
#include <QDebug>
#include <QFile>
#include <QFileDialog>
#include <QImage>
#include <QMessageBox>
#include <QOpenGLFunctions>
#include <QOpenGLWidget>
#include <QString>
#include <QTimer>
#include <QVector>

#include "../core/Scene.hpp"
#include "../core/Settings.hpp"
#include "../core/TransformMatrix.hpp"

namespace s21 {

class Model {
 public:
  Model();
  void stopAnimate();
  void startAnimate();
  void loadOBJ(const QString &filename);
  void setBackgroundColor(const QColor &color);
  void setEdgeColor(const QColor &color);
  void indexSetProjectionType(const int index, int w, int h);
  void setProjectionType(const ProjectionType type, int w, int h);
  void indexSetLineType(const int index);
  void setLineType(const LineType type);
  void setLineWidht(const int size);
  void indexSetVertexType(const int index);
  void setVertexType(const VertexType type);
  void setVertexColor(const QColor &color);
  void setVertexWidht(const int size);
  void setTranslateX(int size);
  void setTranslateY(int size);
  void setTranslateZ(int size);
  void setRotateX(int size);
  void setRotateY(int size);
  void setRotateZ(int size);
  void setScale(int size);
  void setAnimateRotateX(int size);
  void setAnimateRotateY(int size);
  void setAnimateRotateZ(int size);
  void updateTranslate();

  void projectionSetup(int w, int h);
  void drawingSettings();

  QColor getBackgroundColor();
  QColor getEdgeColor();
  QColor getVertexColor();

  std::size_t count_vertices();
  std::size_t count_surfaces();
  std::size_t count_edges();

 private:
  Settings settings;
  s21::Scene scene;
};
}  // namespace s21
#endif  // __MODEL_H__
