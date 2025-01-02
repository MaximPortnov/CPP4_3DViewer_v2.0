#ifndef MYWIDGET_H
#define MYWIDGET_H

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

#include "../controller/Controller.hpp"


class MyWidget : public QOpenGLWidget, protected QOpenGLFunctions {
  Q_OBJECT

 public:
  explicit MyWidget(QWidget *parent = nullptr);
  ~MyWidget() override;
  void loadOBJ(const QString &filename);
  void saveImage(const QString path);
  void stopAnimate();
  void startAnimate();
  void startGifRecording(const QString &filePath);
  void chooseBackgroundColor();
  void chooseEdgeColor();
  void indexSetProjectionType(const int index);
  void indexSetLineType(const int index);
  void setLineWidht(const int size);
  void indexSetVertexType(const int index);
  void chooseVertexColor();
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
  

  std::size_t count_vertices();
  std::size_t count_surfaces();
  std::size_t count_edges();

 protected:
  void initializeGL() override;
  void resizeGL(int w, int h) override;
  void paintGL() override;
  void timerEvent(QTimerEvent *event) override;

 private:
  s21::Controller controller;
};

#endif  // MYWIDGET_H
