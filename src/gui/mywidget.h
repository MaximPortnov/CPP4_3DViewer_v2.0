#ifndef MYWIDGET_H
#define MYWIDGET_H

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

#include "../core/Controller.hpp"

class MyWidget : public QOpenGLWidget, protected QOpenGLFunctions {
    Q_OBJECT

public:
    explicit MyWidget(QWidget *parent = nullptr);
    ~MyWidget() override;
    void loadOBJ(const QString &filename);
    void saveImage(const QString path);
    void startGifRecording(const QString &filePath);
    void chooseBackgroundColor();
    void chooseEdgeColor();
    void indexSetProjectionType(const int index);
    void indexSetLineType(const int index);
    void setLineWidht(const int size);
    void indexSetVertexType(const int index);
    void chooseVertexColor();
    void setVertexWidht(const int size);

protected:
    void initializeGL() override;
    void resizeGL(int w, int h) override;
    void paintGL() override;
    void timerEvent(QTimerEvent* event) override;

private:
    s21::Controller controller;

};

#endif // MYWIDGET_H
