#include "Model.hpp"

namespace s21 {
Model::Model()
{
    s21::TransformMatrixBuilder builder;
    auto t = builder.translate(0,0,0).scale(1.,1.9,1.0).rotate(45, 0,1,0).build();
    scene.transform(t);

    s21::TransformMatrixBuilder builder1;
    auto t1 = builder1.rotate(5, 0,1,0).build();
    scene.animate_start(t1);

    s21::TransformMatrixBuilder builder2;
    auto t2 = builder2.translate(0.5,0.,-5.).build();
    scene.set_view(t2);
}

void Model::loadOBJ(const QString &filename) {
    // QFile file(filename);
    // if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
    //     qWarning("Cannot open the file.");
    //     return;
    // }

    // QTextStream in(&file);
    // QString line;

    // // Чтение строк файла
    // while (!in.atEnd()) {
    //     line = in.readLine();
    //     if (line.startsWith("v ")) {  // Вершины
    //         QStringList parts = line.split(' ');
    //         Vertex vertex = { parts[1].toFloat(), parts[2].toFloat(), parts[3].toFloat() };
    //         vertices.append(vertex);
    //     } else if (line.startsWith("f ")) {  // Полигоны
    //         QStringList parts = line.split(' ');
    //         Face face;
    //         // Формат в obj файле может быть разным, например "f 1/1 2/2 3/3". Нам интересует только индексы вершин
    //         face.v1 = parts[1].split('/')[0].toInt() - 1;
    //         face.v2 = parts[2].split('/')[0].toInt() - 1;
    //         face.v3 = parts[3].split('/')[0].toInt() - 1;
    //         faces.append(face);
    //     }
    // }
    // file.close();
    scene.load_obj(filename.toStdString());
}

void Model::setBackgroundColor(const QColor &color) {
    if (color.isValid()) {
        backgroundColor = color;
    }
}

void Model::setEdgeColor(const QColor &color) {
    if (color.isValid()) {
        edgeColor = color;
    }
}

void Model::indexSetProjectionType(const int index, int w, int h)
{
    if (index == 0) {
        setProjectionType(Central, w, h);
    } else if (index == 1) {
        setProjectionType(Parallel, w, h);
    }
}

void Model::setProjectionType(const ProjectionType type, int w, int h) {
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    projectionType = type;
    if (projectionType == Central) {
        gluPerspective(45.0f, (float)w / (float)h, 0.1f, 100.0f);  // центральная проекция
    }
    else if (projectionType == Parallel) {
        glOrtho(-2, 2, -2, 2, 1, 100); // параллельная проекция
    }
    glMatrixMode(GL_MODELVIEW);
}

void Model::indexSetLineType(const int index)
{
    if (index == 0) {
        setLineType(Solid);
    } else if (index == 1) {
        setLineType(Dotted);
    }
}

void Model::setLineType(const LineType type) {
    lineType = type;
}

void Model::setLineWidht(const int size)
{
    lineWidth = size;
}

void Model::indexSetVertexType(const int index)
{
    if (index == 0) {
        setVertexType(None);
    } else if (index == 1) {
        setVertexType(Circle);
    } else if (index == 2) {
        setVertexType(Square);
    }
}

void Model::setVertexType(const VertexType type) {
    vertexType = type;
}

void Model::setVertexColor(const QColor &color) {
    if (color.isValid()) {
        vertexColor = color;
    }
}

void Model::setVertexWidht(const int size)
{
    vertexWidth = size;
}

void Model::projectionSetup(int w, int h)
{
    if (projectionType == Central) {
        gluPerspective(45.0f, (float)w / (float)h, 0.1f, 100.0f);  // центральная проекция
    }
    else if (projectionType == Parallel) {
        glOrtho(-2, 2, -2, 2, 1, 100); // параллельная проекция
    }
}

void Model::drawingSettings()
{
    // glTranslatef(0.0f, 0.0f, -5.0f);  // Двигаем камеру назад
    // glRotatef(rotationX, 1.0f, 0.0f, 0.0f);  // Вращение по X
    // glRotatef(rotationY, 0.0f, 1.0f, 0.0f);  // Вращение по Y

    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE); // Включаем каркасный режим
    glClearColor(backgroundColor.redF(), backgroundColor.greenF(), backgroundColor.blueF(), 1.0f); // Цвет фона
    glColor3f(edgeColor.redF(), edgeColor.greenF(), edgeColor.blueF());  // Цвет ребер
    glLineWidth(lineWidth); // толщина

    if (lineType == Dotted) {
        // Включаем пунктирные линии
        glEnable(GL_LINE_STIPPLE);
        glLineStipple(1, 0x0101);
    }

    // Отображаем полигоны (треугольники)
    // glBegin(GL_TRIANGLES);
    // for (const Face &face : faces) {
    //     // Отображаем каждый треугольник
    //     glVertex3f(vertices[face.v1].x, vertices[face.v1].y, vertices[face.v1].z);
    //     glVertex3f(vertices[face.v2].x, vertices[face.v2].y, vertices[face.v2].z);
    //     glVertex3f(vertices[face.v3].x, vertices[face.v3].y, vertices[face.v3].z);
    // }
    // glEnd();

    scene.render();

    if (lineType == Dotted) {
        // Выключаем пунктирные линии
        glDisable(GL_LINE_STIPPLE);
    }

    // if (vertexType != None) {
    //     glColor3f(vertexColor.redF(), vertexColor.greenF(), vertexColor.blueF());
    //     glPointSize(vertexWidth);
    //     glEnable(GL_POINT_SMOOTH);
    //     if (vertexType == Square)
    //         glDisable(GL_POINT_SMOOTH);
    //     glBegin(GL_POINTS);
    //     for (const Vertex &vertex : vertices) {
    //         glVertex3f(vertex.x, vertex.y, vertex.z);
    //     }
    //     glEnd();
    // }

    // rotationX += 1.0f; // Вращение по X
    // rotationY += 1.0f;  // Вращение по Y
}

QColor Model::getBackgroundColor()
{
    return backgroundColor;
}

QColor Model::getEdgeColor()
{
    return edgeColor;
}

QColor Model::getVertexColor()
{
    return vertexColor;
}

} // namespace s21
