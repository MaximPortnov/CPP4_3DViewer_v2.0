#ifndef __DESKTOP_H__
#define __DESKTOP_H__

#include <QtCore/QRandomGenerator>
#include <QtCore/QTimerEvent>
#include <QtCore/QtDebug>
#include <QtGui/QKeyEvent>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidgetItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <array>
#include <functional>
#include <iostream>

#include "../../control/defines.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow {
  Q_OBJECT

 public:
  explicit MainWindow(QWidget *parent = 0);
  void updateGameInfo(const GameInfo_t &gameInfo, bool start, bool gameOver,
                      bool victory = false);
  UserAction_t getSignal(bool t = false);
  void nextHide();
  void setLambda(std::function<void(void)> fun);
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
  std::function<void(void)> fun_;
  std::array<QColor, 11> colors = {
      Qt::white, Qt::red,   Qt::green,  Qt::yellow, Qt::blue,  Qt::magenta,
      Qt::cyan,  Qt::black, Qt::yellow, Qt::white,  Qt::yellow};
  Ui::MainWindow *ui;

  void keyPressEvent(QKeyEvent *event) override;
  void keyReleaseEvent(QKeyEvent *event) override;
  void timerEvent(QTimerEvent *event) override;
};

#endif  // __DESKTOP_H__