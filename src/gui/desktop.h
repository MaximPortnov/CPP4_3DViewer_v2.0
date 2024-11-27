#ifndef __DESKTOP_H__
#define __DESKTOP_H__

#include <qt6/QtCore/QRandomGenerator>
#include <qt6/QtCore/QTimerEvent>
#include <qt6/QtCore/QtDebug>
#include <qt6/QtGui/QKeyEvent>
#include <qt6/QtWidgets/QApplication>
#include <qt6/QtWidgets/QLabel>
#include <qt6/QtWidgets/QMainWindow>
#include <qt6/QtWidgets/QPushButton>
#include <qt6/QtWidgets/QTableWidgetItem>
#include <qt6/QtWidgets/QVBoxLayout>
#include <qt6/QtWidgets/QWidget>

#include <array>
#include <functional>
#include <iostream>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow {
  Q_OBJECT

 public:
  explicit MainWindow(QWidget *parent = 0);
  void nextHide();
  ~MainWindow();

 private:
  QLabel *scoreLabel;
  QLabel *highScoreLabel;
  QLabel *levelLabel;
  QLabel *speedLabel;
  QLabel *pauseLabel;
  int signal;
  QLabel *startLabel_;
  QLabel *gameOverLabel_;
  QLabel *pauseLabel_;
  QLabel *victoryLabel_;
  std::array<QColor, 11> colors = {
       Qt::white, Qt::red,   Qt::green,  Qt::yellow, Qt::blue,  Qt::magenta,
      Qt::cyan,  Qt::black, Qt::yellow, Qt::white,  Qt::yellow};
  Ui::MainWindow *ui;

  void keyPressEvent(QKeyEvent *event) override;
  void keyReleaseEvent(QKeyEvent *event) override;
};

#endif  // __DESKTOP_H__