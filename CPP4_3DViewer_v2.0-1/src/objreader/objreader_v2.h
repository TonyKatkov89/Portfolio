#ifndef SRC_OBJREADER_OBJREADER_V2_H
#define SRC_OBJREADER_OBJREADER_V2_H

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
// #include <QDebug>

namespace s21 {

struct coords_t {
  double x;
  double y;
  double z;
};

using vector_type = std::vector<coords_t>;

class OBJREADERV2 {
public:
  OBJREADERV2() = default;
  ~OBJREADERV2() = default;

  void fileRead(std::string fileName);

  int GetVerticesNumber() noexcept;
  int GetEdgesNumber() noexcept;
  std::string GetFileName() noexcept;
  std::vector<coords_t> *GetArrayOfCoords();
  std::vector<std::vector<int>> GetArrayOfEdges();

  void clear();

  bool IsFileCorrupted = false;

private:
  int vertices_number_ = 0; // vCount
  int edges_number_ = 0;    // fCount
  std::string file_name_ = "";

  std::vector<coords_t> *arrayOfCoords = new std::vector<coords_t>();
  std::vector<std::vector<int>> vec;

  void parseVLine(std::string line);
  void parseFLine(std::string line);
};

} // namespace s21

#endif // SRC_OBJREADER_OBJREADER_V2_H
