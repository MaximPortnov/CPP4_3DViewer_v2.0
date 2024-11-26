

#include "desktop.h"

#include <ui_desktop.h>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);

  const int nextRows = 4;
  const int nextColumns = 4;

  ui->nextTableWidget->setRowCount(nextRows);
  ui->nextTableWidget->setColumnCount(nextColumns);

  ui->nextTableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
  ui->nextTableWidget->setSelectionMode(QAbstractItemView::NoSelection);
  ui->nextTableWidget->setFocusPolicy(Qt::NoFocus);
  ui->nextTableWidget->horizontalHeader()->setVisible(false);
  ui->nextTableWidget->verticalHeader()->setVisible(false);
  ui->nextTableWidget->horizontalHeader()->setSectionResizeMode(
      QHeaderView::Stretch);
  ui->nextTableWidget->verticalHeader()->setSectionResizeMode(
      QHeaderView::Stretch);

  for (int i = 0; i < nextRows; ++i) {
    ui->nextTableWidget->setRowHeight(i, 20);
  }
  for (int j = 0; j < nextColumns; ++j) {
    ui->nextTableWidget->setColumnWidth(j, 20);
  }

  for (int i = 0; i < nextRows; ++i) {
    for (int j = 0; j < nextColumns; ++j) {
      QTableWidgetItem *item = new QTableWidgetItem();
      QColor color = QColor::fromRgb(QRandomGenerator::global()->bounded(256),
                                     QRandomGenerator::global()->bounded(256),
                                     QRandomGenerator::global()->bounded(256));
      item->setBackground(color);
      ui->nextTableWidget->setItem(i, j, item);
    }
  }

  const int rows = 20;
  const int columns = 10;

  ui->tableWidget->setRowCount(rows);
  ui->tableWidget->setColumnCount(columns);

  ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
  ui->tableWidget->setSelectionMode(QAbstractItemView::NoSelection);
  ui->tableWidget->setFocusPolicy(Qt::NoFocus);
  ui->tableWidget->horizontalHeader()->setVisible(false);
  ui->tableWidget->verticalHeader()->setVisible(false);
  ui->tableWidget->horizontalHeader()->setSectionResizeMode(
      QHeaderView::Stretch);
  ui->tableWidget->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);

  for (int i = 0; i < rows; ++i) {
    ui->tableWidget->setRowHeight(i, 20);
  }
  for (int j = 0; j < columns; ++j) {
    ui->tableWidget->setColumnWidth(j, 20);
  }

  for (int i = 0; i < rows; ++i) {
    for (int j = 0; j < columns; ++j) {
      QTableWidgetItem *item = new QTableWidgetItem();
      QColor color = QColor::fromRgb(QRandomGenerator::global()->bounded(256),
                                     QRandomGenerator::global()->bounded(256),
                                     QRandomGenerator::global()->bounded(256));
      item->setBackground(color);
      ui->tableWidget->setItem(i, j, item);
    }
  }

  scoreLabel = new QLabel("0", ui->groupBox);
  ui->groupBox->layout()->addWidget(scoreLabel);

  highScoreLabel = new QLabel("0", ui->groupBox_2);
  ui->groupBox_2->layout()->addWidget(highScoreLabel);

  levelLabel = new QLabel("1", ui->groupBox_3);
  ui->groupBox_3->layout()->addWidget(levelLabel);

  speedLabel = new QLabel("1", ui->groupBox_4);
  ui->groupBox_4->layout()->addWidget(speedLabel);

  pauseLabel = new QLabel("0", ui->groupBox_5);
  ui->groupBox_5->layout()->addWidget(pauseLabel);

  startLabel_ = new QLabel("start game", this);
  startLabel_->setAlignment(Qt::AlignCenter);
  startLabel_->setStyleSheet(
      "font-size: 30px; color: green; font-weight: bold;");
  startLabel_->setGeometry(0, 0, this->width(), this->height());

  gameOverLabel_ = new QLabel("gameOver", this);
  gameOverLabel_->setAlignment(Qt::AlignCenter);
  gameOverLabel_->setStyleSheet(
      "font-size: 30px; color: red; font-weight: bold;");
  gameOverLabel_->setGeometry(0, 0, this->width(), this->height());

  pauseLabel_ = new QLabel("pause", this);
  pauseLabel_->setAlignment(Qt::AlignCenter);
  pauseLabel_->setStyleSheet("font-size: 30px; color: red; font-weight: bold;");
  pauseLabel_->setGeometry(0, 0, this->width(), this->height());

  victoryLabel_ = new QLabel("Victory", this);
  victoryLabel_->setAlignment(Qt::AlignCenter);
  victoryLabel_->setStyleSheet(
      "font-size: 30px; color: yellow; font-weight: bold;");
  victoryLabel_->setGeometry(0, 0, this->width(), this->height());
}

void MainWindow::updateGameInfo(const GameInfo_t &gameInfo, bool start,
                                bool gameOver, bool victory) {
  if (start) {
    pauseLabel_->hide();
    gameOverLabel_->hide();
    victoryLabel_->hide();
    startLabel_->show();
    return;
  } else {
    startLabel_->hide();
  }

  if (gameOver) {
    pauseLabel_->hide();
    startLabel_->hide();
    victoryLabel_->hide();
    gameOverLabel_->show();
    return;
  } else {
    gameOverLabel_->hide();
  }

  if (victory) {
    pauseLabel_->hide();
    startLabel_->hide();
    gameOverLabel_->hide();
    victoryLabel_->show();
    return;
  } else {
    victoryLabel_->hide();
  }

  int rows = ui->tableWidget->rowCount();
  int columns = ui->tableWidget->columnCount();

  if (gameInfo.field) {
    for (int i = 0; i < rows; ++i) {
      for (int j = 0; j < columns; ++j) {
        int value = gameInfo.field[j][i];
        QTableWidgetItem *item = ui->tableWidget->item(i, j);
        if (!item) {
          item = new QTableWidgetItem();
          ui->tableWidget->setItem(i, j, item);
        }
        item->setBackground(colors[value]);
      }
    }
  }
  int nextRows = ui->nextTableWidget->rowCount();
  int nextColumns = ui->nextTableWidget->columnCount();

  if (gameInfo.next) {
    for (int i = 0; i < nextRows; ++i) {
      for (int j = 0; j < nextColumns; ++j) {
        int value = gameInfo.next[i][j];
        QTableWidgetItem *item = ui->nextTableWidget->item(i, j);
        if (!item) {
          item = new QTableWidgetItem();
          ui->nextTableWidget->setItem(i, j, item);
        }
        item->setBackground(colors[value]);
      }
    }
  }

  scoreLabel->setText(QString::number(gameInfo.score));
  highScoreLabel->setText(QString::number(gameInfo.high_score));
  levelLabel->setText(QString::number(gameInfo.level));
  speedLabel->setText(QString::number(gameInfo.speed));
  pauseLabel->setText(QString::number(gameInfo.pause));

  if (gameInfo.pause) {
    pauseLabel_->show();
  } else {
    pauseLabel_->hide();
  }
}

UserAction_t MainWindow::getSignal(bool t) {
  UserAction_t action;
  switch (signal) {
    case Qt::Key_Tab:
      action = Pause;
      break;
    case Qt::Key_Escape:
      action = Terminate;
      break;
    case Qt::Key_Return:
      action = Start;
      break;
    case Qt::Key_Up:
      action = Up;
      break;
    case Qt::Key_Left:
      action = Left;
      break;
    case Qt::Key_Right:
      action = Right;
      break;
    case Qt::Key_Down:
      action = Down;
      break;
    case Qt::Key_Space:
      action = Action;
      break;
    default:
      action = None;
      break;
  }
  if (t) {
    signal = -1;
  }
  return action;
}

void MainWindow::nextHide() { ui->groupBox_6->hide(); }

void MainWindow::setLambda(std::function<void(void)> fun) { fun_ = fun; }

MainWindow::~MainWindow() { delete ui; }

void MainWindow::keyPressEvent(QKeyEvent *event) { signal = event->key(); }

void MainWindow::keyReleaseEvent(QKeyEvent *event) { signal = -1; }

void MainWindow::timerEvent(QTimerEvent *event) { fun_(); }
