#include "desktop.h"

#include "./ui_desktop.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);

  mW = new MyWidget(ui->widget);
  ui->widget->setLayout(new QVBoxLayout());
  ui->widget->layout()->addWidget(mW);

  QPixmap pix(":/resource/img/log2.png");
  int w = ui->image->width();
  int h = ui->image->height();

  ui->image->setPixmap(pix.scaled(w, h, Qt::KeepAspectRatio));
}

MainWindow::~MainWindow() {
  delete ui;
  delete mW;
}

void MainWindow::updateStatusBar(QString &fileName, int vertexCount,
                                 int edgeCount) {
  QString message =
      QString(
          "Название файла: %1 | Количество вершин: %2 | Количество рёбер: %3")
          .arg(fileName)
          .arg(vertexCount)
          .arg(edgeCount);

  ui->statusbar->showMessage(message);
}

void MainWindow::on_action_triggered() {
  QString path = QCoreApplication::applicationDirPath() + "/../../3d_objs";
  QString fileName = QFileDialog::getOpenFileName(this, "Выбрать файл", path,
                                                  "All Files (*.obj)");
  mW->loadOBJ(fileName);
  updateStatusBar(fileName, mW->count_vertices(), mW->count_edges());
}

void MainWindow::on_pushButton_4_clicked() {
  QString path = QCoreApplication::applicationDirPath() + "/../../3d объекты";
  mW->saveImage(path);
}

void MainWindow::on_pushButton_5_clicked() {
  QString path = QCoreApplication::applicationDirPath() + "/../../3d объекты";
  QString fileName =
      QFileDialog::getSaveFileName(this, "Сохранить gif", path, "(*.gif)");
  mW->startGifRecording(fileName);
}

void MainWindow::on_pushButton_3_clicked() { mW->chooseBackgroundColor(); }

void MainWindow::on_pushButton_clicked() { mW->chooseEdgeColor(); }

void MainWindow::on_comboBox_currentIndexChanged(int index) {
  mW->indexSetProjectionType(index);
}

void MainWindow::on_comboBox_2_currentIndexChanged(int index) {
  mW->indexSetLineType(index);
}

void MainWindow::on_spinBox_10_valueChanged(int arg1) {
  mW->setLineWidht(arg1);
}

void MainWindow::on_comboBox_3_currentIndexChanged(int index) {
  mW->indexSetVertexType(index);
}

void MainWindow::on_pushButton_2_clicked() { mW->chooseVertexColor(); }

void MainWindow::on_spinBox_11_valueChanged(int arg1) {
  mW->setVertexWidht(arg1);
}

void MainWindow::on_spinBox_valueChanged(int arg1) { mW->setTranslateX(arg1); }

void MainWindow::on_spinBox_2_valueChanged(int arg1) {
  mW->setTranslateY(arg1);
}

void MainWindow::on_spinBox_4_valueChanged(int arg1) {
  mW->setTranslateZ(arg1);
}

void MainWindow::on_spinBox_5_valueChanged(int arg1) { mW->setRotateX(arg1); }

void MainWindow::on_spinBox_6_valueChanged(int arg1) { mW->setRotateY(arg1); }

void MainWindow::on_spinBox_7_valueChanged(int arg1) { mW->setRotateZ(arg1); }

void MainWindow::on_spinBox_9_valueChanged(int arg1) { mW->setScale(arg1); }

void MainWindow::on_spinBox_3_valueChanged(int arg1) {
  mW->setAnimateRotateX(arg1);
}

void MainWindow::on_spinBox_8_valueChanged(int arg1) {
  mW->setAnimateRotateY(arg1);
}

void MainWindow::on_spinBox_12_valueChanged(int arg1) {
  mW->setAnimateRotateZ(arg1);
}

void MainWindow::on_pushButton_6_clicked()
{
  if (animate){
    mW->startAnimate();
    ui->pushButton_6->setText("Анимация");
    animate = false;
  } else {
    mW->stopAnimate();
    ui->pushButton_6->setText("Стоп");
    animate = true;
  }
}
