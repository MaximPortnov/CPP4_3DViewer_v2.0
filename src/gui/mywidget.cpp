#include "mywidget.h"


MyWidget::MyWidget(QWidget *parent) : QOpenGLWidget(parent) {
startTimer(16);
qDebug() << QCoreApplication::applicationDirPath();
  obj = s21::Object::load_obj(QCoreApplication::applicationDirPath().toStdString() + "/obj_files/monkey.obj_test");
}

void MyWidget::initializeGL() {
  initializeOpenGLFunctions();
  glEnable(GL_DEPTH_TEST);  // Включаем тест глубины
  glClearColor(0.0f, 0.1f, 0.1f, 1.0f);  // Установка цвета фона
}

void MyWidget::resizeGL(int w, int h) {
  glViewport(0, 0, w, h);  // Установка области отображения
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
        // Перспективная проекция вручную
        float ratio = (float)w / (float)h;
        float near = 0.1f, far = 100.0f;
        float fov = 45.0f * 3.14159f / 180.0f; // Угол обзора в радианах

        // Матрица перспективы вручную
        float f = 1.0f / tan(fov / 2);
        float mat[16] = {
            f / ratio, 0, 0, 0,
            0, f, 0, 0,
            0, 0, (far + near) / (near - far), -1,
            0, 0, (2 * far * near) / (near - far), 0
        };

        glLoadMatrixf(mat);  // Загружаем матрицу в OpenGL
  glMatrixMode(GL_MODELVIEW);
}

void MyWidget::paintGL() {
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);  // Очистка буферов

  glLoadIdentity();

  glTranslatef(0.0f, 0.0f, -5.0f);  // Перемещение "камеры" назад
  glRotatef(rotationX, 1.0f, 0.0f, 0.0f);  // Вращение по X
  glRotatef(rotationY, 0.0f, 1.0f, 0.0f);  // Вращение по Y

  // Рисование куба
  // glBegin(GL_QUADS);
  obj.render();
  // glColor3f(1.0f, 0.0f, 0.0f);
  // glVertex3f(-1.0f, -1.0f, -1.0f);  // Пример вершины
  // glColor3f(0.0f, 1.0f, 0.0f);
  // glVertex3f(1.0f, -1.0f, -1.0f);
  // glColor3f(0.0f, 0.0f, 1.0f);
  // glVertex3f(1.0f, 1.0f, -1.0f);
  // glColor3f(1.0f, 1.0f, 0.0f);
  // glVertex3f(-1.0f, 1.0f, -1.0f);
  // glEnd();
          rotationX += 1.0f;  // Вращение по X
        rotationY += 1.f;  // Вращение по Y
}

void MyWidget::timerEvent(QTimerEvent* event)
{
  update();
}
