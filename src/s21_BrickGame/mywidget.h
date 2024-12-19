#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <GL/glu.h>
#include <GL/gl.h>
#include <qt6/QtOpenGLWidgets/QOpenGLWidget>
#include <qt6/QtGui/QOpenGLFunctions>
#include <qt6/QtCore/QVector>
#include <qt6/QtCore/QString>
#include <qt6/QtCore/QFile>
#include <qt6/QtWidgets/QFileDialog>
#include <qt6/QtWidgets/QColorDialog>
#include <qt6/QtWidgets/QMessageBox>
#include <gifimage/qgifimage.h> 
#include <qt6/QtCore/QTimer>
#include <qt6/QtGui/QImage>
#include <qt6/QtCore/QDebug>

enum ProjectionType {Central, Parallel};
enum LineType {Solid, Dotted};
enum VertexType {None, Circle, Square};

// Структура для хранения вершины
struct Vertex {
    float x, y, z;
};

// Структура для хранения полигона (треугольника)
struct Face {
    int v1, v2, v3;
};

class MyWidget : public QOpenGLWidget, protected QOpenGLFunctions {
    Q_OBJECT

public:
    explicit MyWidget(QWidget *parent = nullptr);
    ~MyWidget() override;
    void loadOBJ(const QString &filename);  // Загрузка .obj файла
    void saveImage(const QString path);
    void startGifRecording(const QString &filePath);
    void setBackgroundColor(const QColor &color);
    void chooseBackgroundColor();
    void setEdgeColor(const QColor &color);
    void chooseEdgeColor();
    void setProjectionType(const ProjectionType type);
    void setLineType(const LineType type);
    void setLineWidht(const int size);
    void setVertexType(const VertexType type);
    void setVertexColor(const QColor &color);
    void chooseVertexColor();
    void setVertexWidht(const int size);

protected:
    void initializeGL() override;
    void resizeGL(int w, int h) override;
    void paintGL() override;
    void timerEvent(QTimerEvent* event) override;

private:
    QVector<Vertex> vertices; // Хранение вершин модели
    QVector<Face> faces;      // Хранение полигонов модели
    float rotationX = 0.0f;
    float rotationY = 0.0f;
    QColor backgroundColor = QColor(Qt::black);
    QColor edgeColor = QColor(Qt::white);
    ProjectionType projectionType = Central;
    LineType lineType = Solid;
    int lineWidth = 1;
    QColor vertexColor = QColor(Qt::red);
    VertexType vertexType = None;
    int vertexWidth = 0;
};

#endif // MYWIDGET_H
