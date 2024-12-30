#include "Controller.hpp"

namespace s21 {
void Controller::clrLoadOBJ(const QString &filename)
{
    model.loadOBJ(filename);
}

void Controller::clrSetBackgroundColor(const QColor &color)
{
    model.setBackgroundColor(color);
}

void Controller::clrSetEdgeColor(const QColor &color)
{
    model.setEdgeColor(color);
}

void Controller::clrIndexSetProjectionType(const int index, int w, int h)
{
    model.indexSetProjectionType(index, w, h);
}

void Controller::clrIndexSetLineType(const int index)
{
    model.indexSetLineType(index);
}

void Controller::clrSetLineWidht(const int size)
{
    model.setLineWidht(size);
}

void Controller::clrIndexSetVertexType(const int index)
{
    model.indexSetVertexType(index);
}

void Controller::clrChooseVertexColor(const QColor &color)
{
    model.setVertexColor(color);
}

void Controller::clrSetVertexWidht(const int size)
{
    model.setVertexWidht(size);
}

void Controller::clrSetTranslateX(int size)
{
    model.setTranslateX(size);
}

void Controller::clrSetTranslateY(int size)
{
    model.setTranslateY(size);
}

void Controller::clrSetTranslateZ(int size)
{
    model.setTranslateZ(size);
}

void Controller::clrSetRotateX(int size)
{
    model.setRotateX(size);
}

void Controller::clrSetRotateY(int size)
{
    model.setRotateY(size);
}

void Controller::clrSetRotateZ(int size)
{
    model.setRotateZ(size);
}

void Controller::clrSetScale(int size)
{
    model.setScale(size);
}

void Controller::clrProjectionSetup(int w, int h)
{
    model.projectionSetup(w, h);
}

void Controller::clrDrawingSettings()
{
    model.drawingSettings();
}

QColor Controller::clrGetBackgroundColor()
{
    return model.getBackgroundColor();
}

QColor Controller::clrGetEdgeColor()
{
    return model.getEdgeColor();
}

QColor Controller::clrGetVertexColor()
{
    return model.getVertexColor();
}

} // namespace s21
