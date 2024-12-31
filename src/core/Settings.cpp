#include "Settings.hpp"

#include <iostream>
namespace s21 {

void Settings::save(Settings a) {
  std::ofstream file(QCoreApplication::applicationDirPath().toStdString() +
                     "./save.settings");
  std::cout << QCoreApplication::applicationDirPath().toStdString() +
                   "./save.settings"
            << '\n';
  file << a.backgroundColor.red() << ' ' << a.backgroundColor.green() << ' '
       << a.backgroundColor.blue() << ' ';
  file << a.edgeColor.red() << ' ' << a.edgeColor.green() << ' '
       << a.edgeColor.blue() << ' ';
  file << a.projectionType << ' ';

  file << a.lineType << ' ';
  file << a.lineWidth << ' ';
  file << a.vertexColor.red() << ' ' << a.vertexColor.green() << ' '
       << a.vertexColor.blue() << ' ';
  file << a.vertexType << ' ';
  file << a.vertexWidth << ' ';
}

Settings Settings::load() {
  s21::Settings set;
  std::ifstream file(QCoreApplication::applicationDirPath().toStdString() +
                     "./save.settings");
  if (!file.is_open()) {
    return set;
  }
  std::cout << QCoreApplication::applicationDirPath().toStdString() +
                   "./save.settings"
            << '\n';
  int x, y, z;
  file >> x >> y >> z;
  set.backgroundColor.setRed(x);
  set.backgroundColor.setGreen(y);
  set.backgroundColor.setBlue(z);
  file >> x >> y >> z;
  set.edgeColor.setRed(x);
  set.edgeColor.setGreen(y);
  set.edgeColor.setBlue(z);
  std::size_t s;
  file >> s;
  set.projectionType = static_cast<ProjectionType>(s);
  file >> s;
  set.lineType = static_cast<LineType>(s);
  file >> set.lineWidth;
  file >> x >> y >> z;
  set.vertexColor.setRed(x);
  set.vertexColor.setGreen(y);
  set.vertexColor.setBlue(z);
  file >> s;
  set.vertexType = static_cast<VertexType>(s);
  file >> set.vertexWidth;
  return set;
}
};  // namespace s21