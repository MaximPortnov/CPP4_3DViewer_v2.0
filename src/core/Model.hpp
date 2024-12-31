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

#include "const.hpp"
#include "Scene.hpp"
#include "TransformMatrix.hpp"


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
        void setTranslateX(int size);
        void setTranslateY(int size);
        void setTranslateZ(int size);
        void setRotateX(int size);
        void setRotateY(int size);
        void setRotateZ(int size);
        void setScale(int size);

        void projectionSetup(int w, int h);
        void drawingSettings();

        QColor getBackgroundColor();
        QColor getEdgeColor();
        QColor getVertexColor();

    private:
        Settings settings;
        s21::Scene scene;

};
}  // namespace s21
#endif  // __MODEL_H__
