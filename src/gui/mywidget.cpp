#include "mywidget.h"


MyWidget::MyWidget(QWidget *parent) : QOpenGLWidget(parent) {
startTimer(16);
qDebug() << QCoreApplication::applicationDirPath();
  // obj = s21::Object::load_obj();
  scene.load_obj(QCoreApplication::applicationDirPath().toStdString() + "/obj_files/monkey.obj_test");
  s21::TransformMatrixBuilder builder;
  auto t = builder.translate(0.,0.,-5.).scale(1.,1.9,1.0).rotate(45, 0,1,0).build();
  scene.transform(t);
  
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
        double ratio = (float)w / (float)h;
        double near = 0.1f, far = 100.0f;
        double fov = 45.0f * 3.14159f / 180.0f; // Угол обзора в радианах

        // Матрица перспективы вручную
        double f = 1.0f / tan(fov / 2);
        double mat[16] = {
            f / ratio, 0, 0, 0,
            0, f, 0, 0,
            0, 0, (far + near) / (near - far), -1,
            0, 0, (2 * far * near) / (near - far), 0
        };

        glLoadMatrixd(mat);  // Загружаем матрицу в OpenGL
  glMatrixMode(GL_MODELVIEW);
}

void printMatrix() {
    double current[16];
    glGetDoublev(GL_MODELVIEW_MATRIX, current);
    qDebug() << "Current ModelView Matrix:" << '\n';
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            qDebug() << current[i * 4 + j] << " ";
        }
        qDebug() << '\n';
    }
}

void MyWidget::paintGL() {
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);  // Очистка буферов
  glMatrixMode(GL_MODELVIEW);
  // glLoadIdentity();
  // glTranslatef(0.0f, 0.0f, -5.0f);  // Перемещение "камеры" назад
  // glRotatef(rotationX, 1.0f, 0.0f, 0.0f);  // Вращение по X
  // glRotatef(rotationY, 0.0f, 1.0f, 0.0f);  // Вращение по Y
  // glPushMatrix(); 
  // glLoadIdentity();
  // float temp[16] = {
  //   1,0,0,0,
  //   0,1,0,0,
  //   0,0,1,+5,
  //   0,0,0,1,
  // };
  // glLoadMatrixf(temp);
  // printMatrix();
    //   glBegin(GL_TRIANGLES);
    //     glColor3d(1, 0, 0);
    //     glVertex3d(-1.0, -1.0, 0.0);
    //     glVertex3d(1.0, -1.0, 0.0);
    //     glVertex3d(0.0, 1.0, 0.0);
    // glEnd();
  scene.render();
  // glPopMatrix();

}

void MyWidget::timerEvent(QTimerEvent* event)
{
  update();
}
