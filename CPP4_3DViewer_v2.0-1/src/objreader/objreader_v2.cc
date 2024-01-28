#include "objreader_v2.h"

// #include <QDebug>

namespace s21 {

void OBJREADERV2::fileRead(std::string fileName) {
  std::ifstream file(fileName);
  if (file.is_open()) {
    std::string line;
    while (std::getline(file, line)) {
      //   qDebug() << QString::fromUtf8(line.c_str());
      if (line.substr(0, 2) == "v ") {
        parseVLine(line);
      } else if (line.substr(0, 2) == "f ") {
        parseFLine(line);
      }
    }
    file.close();
  } else {
    throw std::runtime_error("Corrupted file");
  }

  if (vertices_number_ == 0 || edges_number_ == 0) {
    throw std::runtime_error("Corrupted file");
  }
}

void OBJREADERV2::parseVLine(std::string line) {
  std::istringstream vvv(line.substr(2));
  double x = 0, y = 0, z = 0;

  if (vvv >> x && vvv >> y && vvv >> z) {
    //   qDebug() << "x = " << x << "; y = " << y << "; z = " << z;

    coords_t points;
    points.x = x;
    points.y = y;
    points.z = z;
    arrayOfCoords->push_back(points);

    vertices_number_++;
  } else {
    this->IsFileCorrupted = true;
  }
}

void OBJREADERV2::parseFLine(std::string line) {
  std::stringstream ss;
  ss << line;
  std::string temp;
  int found;

  std::vector<int> vect;

  while (!ss.eof()) {
    ss >> temp;
    if (std::stringstream(temp) >> found) {
      vect.push_back(found);
    }
    temp = "";
  }

  vec.push_back(vect);

  edges_number_++;
}

int OBJREADERV2::GetVerticesNumber() noexcept { return vertices_number_; }

int OBJREADERV2::GetEdgesNumber() noexcept { return edges_number_; }

std::string OBJREADERV2::GetFileName() noexcept { return file_name_; }

std::vector<coords_t> *OBJREADERV2::GetArrayOfCoords() { return arrayOfCoords; }

std::vector<std::vector<int>> OBJREADERV2::GetArrayOfEdges() { return vec; }

void OBJREADERV2::clear() {
  vertices_number_ = 0;
  edges_number_ = 0;
  file_name_ = "";
  this->IsFileCorrupted = false;

  arrayOfCoords->clear();
  vec.clear();
}

} // namespace s21
