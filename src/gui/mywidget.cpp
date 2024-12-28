#include "mywidget.h"

MyWidget::MyWidget(QWidget *parent) : QOpenGLWidget(parent) {
    // setFixedSize(800, 600);  // Устанавливаем размер окна
    startTimer(16);
}

MyWidget::~MyWidget() {
}

void MyWidget::initializeGL() {
    initializeOpenGLFunctions();
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);
}

void MyWidget::resizeGL(int w, int h) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    // Перспективная проекция вручную
    double ratio = (float)w / (float)h;
    double my_near = 0.1f, my_far = 100.0f;
    double fov = 45.0f * 3.14159f / 180.0f; // Угол обзора в радианах

    // Матрица перспективы вручную
    double f = 1.0f / tan(fov / 2);
    double mat[16] = {
        f / ratio, 0, 0, 0,
        0, f, 0, 0,
        0, 0, (my_far + my_near) / (my_near - my_far), -1,
        0, 0, (2 * my_far * my_near) / (my_near - my_far), 0
    };

    glLoadMatrixd(mat);  // Загружаем матрицу в OpenGL
    // controller.clrProjectionSetup(w, h);
    glMatrixMode(GL_MODELVIEW);
}

void MyWidget::paintGL() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    controller.clrDrawingSettings();
}

void MyWidget::timerEvent(QTimerEvent* event)
{
    update();
}

void MyWidget::loadOBJ(const QString &filename) {
    controller.clrLoadOBJ(filename);
}

void MyWidget::saveImage(const QString path) {
    QString fileName = QFileDialog::getSaveFileName(this, "Сохранить изображение", path, "(*.bmp);; (*.jpeg)");
    if (!fileName.isEmpty()) {
        // Получаем текущее изображение из OpenGL
        QImage image = grabFramebuffer();
        // Сохраняем изображение в выбранный файл
        if (!image.save(fileName)) {
            QMessageBox::warning(this, "Ошибка", "Не удалось сохранить изображение!");
        }
    }
}

void MyWidget::startGifRecording(const QString &filePath) {
    QGifImage gif;
    gif.setDefaultDelay(100); // 100 мс = 10 FPS
    for (int i = 0; i < 50; ++i) { // 50 кадров
        QImage frame = grabFramebuffer().scaled(640, 480, Qt::IgnoreAspectRatio);
        gif.addFrame(frame);
    }
    gif.save(filePath);
}

void MyWidget::chooseBackgroundColor() {
    QColor color = QColorDialog::getColor(controller.clrGetBackgroundColor(), this, "Выбрать цвет фона");
    controller.clrSetBackgroundColor(color);
    update();
}

void MyWidget::chooseEdgeColor() {
    QColor color = QColorDialog::getColor(controller.clrGetEdgeColor(), this, "Выберите цвет рёбер");
    controller.clrSetEdgeColor(color);
    update();
}

void MyWidget::indexSetProjectionType(const int index)
{
    makeCurrent();
    controller.clrIndexSetProjectionType(index, width(), height());
    update();
}

void MyWidget::indexSetLineType(const int index)
{
    controller.clrIndexSetLineType(index);
    update();
}

void MyWidget::setLineWidht(const int size)
{
    controller.clrSetLineWidht(size);
    update();
}

void MyWidget::indexSetVertexType(const int index)
{
    controller.clrIndexSetVertexType(index);
    update();
}

void MyWidget::chooseVertexColor() {
    QColor color = QColorDialog::getColor(controller.clrGetVertexColor(), this, "Выбрать цвет вершин");
    controller.clrChooseVertexColor(color);
    update();
}

void MyWidget::setVertexWidht(const int size)
{
    controller.clrSetVertexWidht(size);
    update();
}
