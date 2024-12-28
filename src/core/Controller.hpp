#ifndef __CONTROLLER_H__
#define __CONTROLLER_H__

#include "Model.hpp"

namespace s21 {
class Controller {
    public:
        void clrLoadOBJ(const QString &filename);
        void clrSetBackgroundColor(const QColor &color);
        void clrSetEdgeColor(const QColor &color);
        void clrIndexSetProjectionType(const int index, int w, int h);
        void clrIndexSetLineType(const int index);
        void clrSetLineWidht(const int size);
        void clrIndexSetVertexType(const int index);
        void clrChooseVertexColor(const QColor &color);
        void clrSetVertexWidht(const int size);

        void clrProjectionSetup(int w, int h);
        void clrDrawingSettings();

        QColor clrGetBackgroundColor();
        QColor clrGetEdgeColor();
        QColor clrGetVertexColor();

    private:
        s21::Model model;

};
}  // namespace s21
#endif  // __CONTROLLER_H__
