#include "desktop.h"

#include "mywidget.h"

int main(int argc, char *argv[]) {
  QApplication a(argc, argv);
  // MainWindow w;
  MyWidget mw;
  mw.show();
  // w.show();
  return a.exec();
}