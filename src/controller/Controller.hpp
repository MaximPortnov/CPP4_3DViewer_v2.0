#ifndef __CONTROLLER_H__
#define __CONTROLLER_H__

#include "../model/Model.hpp"

namespace s21 {
class Controller {
 public:
  void clrStopAnimate(); 
  void clrStartAnimate(); 
  void clrLoadOBJ(const QString &filename);
  void clrSetBackgroundColor(const QColor &color);
  void clrSetEdgeColor(const QColor &color);
  void clrIndexSetProjectionType(const int index, int w, int h);
  void clrIndexSetLineType(const int index);
  void clrSetLineWidht(const int size);
  void clrIndexSetVertexType(const int index);
  void clrChooseVertexColor(const QColor &color);
  void clrSetVertexWidht(const int size);
  void clrSetTranslateX(int size);
  void clrSetTranslateY(int size);
  void clrSetTranslateZ(int size);
  void clrSetRotateX(int size);
  void clrSetRotateY(int size);
  void clrSetRotateZ(int size);
  void clrSetScale(int size);

  void clrSetAnimateRotateX(int size);
  void clrSetAnimateRotateY(int size);
  void clrSetAnimateRotateZ(int size);

  void clrProjectionSetup(int w, int h);
  void clrDrawingSettings();

  QColor clrGetBackgroundColor();
  QColor clrGetEdgeColor();
  QColor clrGetVertexColor();

  std::size_t count_vertices();
  std::size_t count_surfaces();
  std::size_t count_edges();

 private:
  s21::Model model;
};
}  // namespace s21
#endif  // __CONTROLLER_H__
