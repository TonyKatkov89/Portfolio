#ifndef CPP4_3DViewer_v2_0_1_SRC_SINGLETON_FACADE_FACADE_H
#define CPP4_3DViewer_v2_0_1_SRC_SINGLETON_FACADE_FACADE_H

#include "objreader/objreader_v2.h"
#include "oglwidget.h"
#include "transform/transform.h"

namespace s21 {

class Facade {
protected:
  inline static Facade *instance{nullptr};
  Facade() = default;
  ~Facade() = default;

  s21::OBJREADERV2 reader_;
  s21::Transform transformer_;
  //  OGLWidget* widget_;
public:
  //  void setValues(OGLWidget* widget) { this->widget_ = widget; }

  Facade(const Facade &) = delete;
  Facade &operator=(const Facade &) = delete;

  static Facade *getInstance() {
    if (!instance) {
      instance = new Facade();
    }
    return instance;
  }

  void clear() { reader_.clear(); }

  void fileRead(std::string fileName) { reader_.fileRead(fileName); }

  int GetVerticesNumber() { return reader_.GetVerticesNumber(); }

  int GetEdgesNumber() { return reader_.GetEdgesNumber(); }

  vector_type &FitToWindow() {
    return transformer_.FitToWindow(*reader_.GetArrayOfCoords());
  }

  std::vector<std::vector<int>> GetArrayOfEdges() {
    return reader_.GetArrayOfEdges();
  }

  s21::Transform &GetTransformer() { return transformer_; }

  void SetTransformArray(double x, double y, double z) {
    transform_array_ = {x, y, z};
  }

  s21::coords_t GetTransformArray() { return transform_array_; }

  bool IsFileCorrupted() { return reader_.IsFileCorrupted; }

private:
  s21::coords_t transform_array_;
};

} // namespace s21

#endif // CPP4_3DViewer_v2_0_1_SRC_SINGLETON_FACADE_FACADE_H
