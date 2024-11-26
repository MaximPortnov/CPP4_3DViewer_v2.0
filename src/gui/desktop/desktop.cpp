

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

void MainWindow::nextHide() { ui->groupBox_6->hide(); }

MainWindow::~MainWindow() { delete ui; }

void MainWindow::keyPressEvent(QKeyEvent *event) { signal = event->key(); }

void MainWindow::keyReleaseEvent(QKeyEvent *event) { signal = -1; }

int main(int argc, char *argv[]) {
  QApplication a(argc, argv);
  MainWindow w;
  w.show();
  return a.exec();
}