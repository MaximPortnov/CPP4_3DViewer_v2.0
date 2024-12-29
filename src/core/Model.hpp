#ifndef __MODEL_H__
#define __MODEL_H__
#ifdef _WIN32
#include <windows.h>
#endif
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

#include "Scene.hpp"
#include "TransformMatrix.hpp"

enum ProjectionType {Central, Parallel};
enum LineType {Solid, Dotted};
enum VertexType {None, Circle, Square};

// // Структура для хранения вершины
// struct Vertex {
//     float x, y, z;
// };

// // Структура для хранения полигона (треугольника)
// struct Face {
//     int v1, v2, v3;
// };

namespace s21 {
class Model {
    public:
        Model();
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

        void projectionSetup(int w, int h);
        void drawingSettings();

        QColor getBackgroundColor();
        QColor getEdgeColor();
        QColor getVertexColor();

    private:
        // QVector<Vertex> vertices; // Хранение вершин модели
        // QVector<Face> faces;      // Хранение полигонов модели
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

        s21::Scene scene;
};
}  // namespace s21
#endif  // __MODEL_H__
