#include "mywidget.h"

MyWidget::MyWidget(QWidget *parent) : QOpenGLWidget(parent) {
  // setFixedSize(800, 600);  // Устанавливаем размер окна
  startTimer(16);
}

MyWidget::~MyWidget() {}

void MyWidget::initializeGL() {
  initializeOpenGLFunctions();
  glEnable(GL_DEPTH_TEST);
  glEnable(GL_CULL_FACE);
}

void MyWidget::resizeGL(int w, int h) {
  glViewport(0, 0, w, h);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  controller.clrProjectionSetup(w, h);
  glMatrixMode(GL_MODELVIEW);
}

void MyWidget::paintGL() {
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  controller.clrDrawingSettings();
}

void MyWidget::timerEvent(QTimerEvent *event) { update(); }

void MyWidget::loadOBJ(const QString &filename) {
  controller.clrLoadOBJ(filename);
}

void MyWidget::saveImage(const QString path) {
  QString fileName = QFileDialog::getSaveFileName(this, "Сохранить изображение",
                                                  path, "(*.bmp);; (*.jpeg)");
  if (!fileName.isEmpty()) {
    // Получаем текущее изображение из OpenGL
    QImage image = grabFramebuffer();
    // Сохраняем изображение в выбранный файл
    if (!image.save(fileName)) {
      QMessageBox::warning(this, "Ошибка", "Не удалось сохранить изображение!");
    }
  }
}

void MyWidget::stopAnimate()
{
  controller.clrStopAnimate();
}

void MyWidget::startAnimate()
{
  controller.clrStartAnimate();
  
}

void MyWidget::startGifRecording(const QString &filePath) {
  QGifImage gif;
  gif.setDefaultDelay(100);       // 100 мс = 10 FPS
  for (int i = 0; i < 50; ++i) {  // 50 кадров
    QImage frame = grabFramebuffer().scaled(640, 480, Qt::IgnoreAspectRatio);
    gif.addFrame(frame);
  }
  gif.save(filePath);
}

void MyWidget::chooseBackgroundColor() {
  QColor color1 = QColorDialog::getColor(controller.clrGetBackgroundColor(),
                                         this, "Выбрать цвет фона");
  controller.clrSetBackgroundColor(color1);
  update();
}

void MyWidget::chooseEdgeColor() {
  QColor color = QColorDialog::getColor(controller.clrGetEdgeColor(), this,
                                        "Выберите цвет рёбер");
  controller.clrSetEdgeColor(color);
  update();
}

void MyWidget::indexSetProjectionType(const int index) {
  makeCurrent();
  controller.clrIndexSetProjectionType(index, width(), height());
  update();
}

void MyWidget::indexSetLineType(const int index) {
  controller.clrIndexSetLineType(index);
  update();
}

void MyWidget::setLineWidht(const int size) {
  controller.clrSetLineWidht(size);
  update();
}

void MyWidget::indexSetVertexType(const int index) {
  controller.clrIndexSetVertexType(index);
  update();
}

void MyWidget::chooseVertexColor() {
  QColor color = QColorDialog::getColor(controller.clrGetVertexColor(), this,
                                        "Выбрать цвет вершин");
  controller.clrChooseVertexColor(color);
  update();
}

void MyWidget::setVertexWidht(const int size) {
  controller.clrSetVertexWidht(size);
  update();
}

void MyWidget::setTranslateX(int size) { controller.clrSetTranslateX(size); }

void MyWidget::setTranslateY(int size) { controller.clrSetTranslateY(size); }

void MyWidget::setTranslateZ(int size) { controller.clrSetTranslateZ(size); }

void MyWidget::setRotateX(int size) { controller.clrSetRotateX(size); }

void MyWidget::setRotateY(int size) { controller.clrSetRotateY(size); }

void MyWidget::setRotateZ(int size) { controller.clrSetRotateZ(size); }

void MyWidget::setScale(int size) { controller.clrSetScale(size); }

void MyWidget::setAnimateRotateX(int size)
{
  controller.clrSetAnimateRotateX(size);
}

void MyWidget::setAnimateRotateY(int size)
{
  controller.clrSetAnimateRotateY(size);
  
}

void MyWidget::setAnimateRotateZ(int size)
{
  controller.clrSetAnimateRotateZ(size);
  
}

std::size_t MyWidget::count_vertices() { return controller.count_vertices(); }

std::size_t MyWidget::count_surfaces() { return controller.count_surfaces(); }

std::size_t MyWidget::count_edges() { return controller.count_edges(); }
