#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QOpenGLWidget>
#include <QOpenGLFunctions>
#include <QOpenGLContext>
#include <QOpenGLShaderProgram>
#include <QTimer>
// #include <qt6/QOpenGLFunctions>
// #include <QMatrix4x4>
// #include <QVector3D>

class MyWidget : public QOpenGLWidget, protected QOpenGLFunctions
{
    Q_OBJECT
public:
    explicit MyWidget(QWidget *parent = nullptr);
    // ~MyWidget();

protected:
    void initializeGL() override;
    void resizeGL(int w, int h) override;
    void paintGL() override;
    void timerEvent(QTimerEvent* event) override;

private:
    float rotationX = 0.0f;
    float rotationY = 0.0f;
};

#endif // MYWIDGET_H
