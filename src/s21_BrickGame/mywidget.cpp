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
    if (projectionType == Central) {
        gluPerspective(45.0f, (float)w / (float)h, 0.1f, 100.0f);  // центральная проекция
    }
    else if (projectionType == Parallel) {
        glOrtho(-2, 2, -2, 2, 1, 100); // параллельная проекция
    }
    glMatrixMode(GL_MODELVIEW);
}

void MyWidget::paintGL() {
    glClearColor(backgroundColor.redF(), backgroundColor.greenF(), backgroundColor.blueF(), 1.0f);  // Цвет фона
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    glTranslatef(0.0f, 0.0f, -5.0f);  // Двигаем камеру назад
    glRotatef(rotationX, 1.0f, 0.0f, 0.0f);  // Вращение по X
    glRotatef(rotationY, 0.0f, 1.0f, 0.0f);  // Вращение по Y

    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE); // Включаем каркасный режим
    glColor3f(edgeColor.redF(), edgeColor.greenF(), edgeColor.blueF());  // Цвет ребер
    glLineWidth(lineWidth); // толщина

    if (lineType == Dotted) {
        // Включаем пунктирные линии
        glEnable(GL_LINE_STIPPLE);
        glLineStipple(1, 0x0101);
    }

    // Отображаем полигоны (треугольники)
    glBegin(GL_TRIANGLES);
    for (const Face &face : faces) {
        // Отображаем каждый треугольник
        glVertex3f(vertices[face.v1].x, vertices[face.v1].y, vertices[face.v1].z);
        glVertex3f(vertices[face.v2].x, vertices[face.v2].y, vertices[face.v2].z);
        glVertex3f(vertices[face.v3].x, vertices[face.v3].y, vertices[face.v3].z);
    }
    glEnd();

    if (lineType == Dotted) {
        // Выключаем пунктирные линии
        glDisable(GL_LINE_STIPPLE);
    }

    if (vertexType != None) {
        glColor3f(vertexColor.redF(), vertexColor.greenF(), vertexColor.blueF());
        glPointSize(vertexWidth);
        glEnable(GL_POINT_SMOOTH);
        if (vertexType == Square)
            glDisable(GL_POINT_SMOOTH);
        glBegin(GL_POINTS);
        for (const Vertex &vertex : vertices) {
            glVertex3f(vertex.x, vertex.y, vertex.z);
        }
        glEnd();
    }

    rotationX += 1.0f; // Вращение по X
    rotationY += 1.0f;  // Вращение по Y
}

void MyWidget::timerEvent(QTimerEvent* event)
{
    update();
}

void MyWidget::loadOBJ(const QString &filename) {
    QFile file(filename);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qWarning("Cannot open the file.");
        return;
    }

    QTextStream in(&file);
    QString line;

    // Чтение строк файла
    while (!in.atEnd()) {
        line = in.readLine();
        if (line.startsWith("v ")) {  // Вершины
            QStringList parts = line.split(' ');
            Vertex vertex = { parts[1].toFloat(), parts[2].toFloat(), parts[3].toFloat() };
            vertices.append(vertex);
        } else if (line.startsWith("f ")) {  // Полигоны
            QStringList parts = line.split(' ');
            Face face;
            // Формат в obj файле может быть разным, например "f 1/1 2/2 3/3". Нам интересует только индексы вершин
            face.v1 = parts[1].split('/')[0].toInt() - 1;
            face.v2 = parts[2].split('/')[0].toInt() - 1;
            face.v3 = parts[3].split('/')[0].toInt() - 1;
            faces.append(face);
        }
    }
    file.close();
}

void MyWidget::saveImage(const QString path) {
    // Открываем диалог для выбора имени файла
    QString fileName = QFileDialog::getSaveFileName(this, "Сохранить изображение", path, "(*.bmp);; (*.jpeg)");
    // Если пользователь выбрал файл
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

    // Добавление кадров
    for (int i = 0; i < 50; ++i) { // Пример: 50 кадров
        QImage frame = grabFramebuffer().scaled(640, 480, Qt::IgnoreAspectRatio);
        gif.addFrame(frame);
    }

    // Сохранение GIF
    gif.save(filePath);
}

void MyWidget::setBackgroundColor(const QColor &color) {
    backgroundColor = color;
    update();
}

void MyWidget::chooseBackgroundColor() {
    QColor color = QColorDialog::getColor(backgroundColor, this, "Выбрать цвет фона");
    if (color.isValid()) {
        setBackgroundColor(color);
    }
}

void MyWidget::setEdgeColor(const QColor &color) {
    edgeColor = color;
    update();
}

void MyWidget::chooseEdgeColor() {
    QColor color = QColorDialog::getColor(edgeColor, this, "Выберите цвет рёбер");
    if (color.isValid()) {
        setEdgeColor(color);
    }
}

void MyWidget::setProjectionType(const ProjectionType type) {
    projectionType = type;

    makeCurrent();
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    if (projectionType == Central) {
        gluPerspective(45.0f, (float)width() / (float)height(), 0.1f, 100.0f);  // центральная проекция
    }
    else if (projectionType == Parallel) {
        glOrtho(-2, 2, -2, 2, 1, 100); // параллельная проекция
    }
    glMatrixMode(GL_MODELVIEW);

    update();
}

void MyWidget::setLineType(const LineType type) {
    lineType = type;
    update();
}

void MyWidget::setLineWidht(const int size)
{
    lineWidth = size;
    update();
}

void MyWidget::setVertexType(const VertexType type) {
    vertexType = type;
    update();
}

void MyWidget::setVertexColor(const QColor &color) {
    vertexColor = color;
    update();
}

void MyWidget::chooseVertexColor() {
    QColor color = QColorDialog::getColor(vertexColor, this, "Выбрать цвет вершин");
    if (color.isValid()) {
        setVertexColor(color);
    }
}

void MyWidget::setVertexWidht(const int size)
{
    vertexWidth = size;
}

