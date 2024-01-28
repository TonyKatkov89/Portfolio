#ifndef CPP4_3DViewer_v2_0_1_SRC_COMMAND_COMMAND_H
#define CPP4_3DViewer_v2_0_1_SRC_COMMAND_COMMAND_H

#include <stack>

#include "../oglwidget.h"
#include "../transform/transform.h"

namespace s21 {

class Command {
public:
  virtual void Execute() const = 0;
  virtual void Undo() const = 0;

protected:
  OGLWidget *widget_;
  s21::Transform *receiver_;
};

class RotateCommand : public Command {
public:
  RotateCommand(OGLWidget *widget, Transform *transformer,
                coords_t transformVector);
  void Execute() const override;
  void Undo() const override;

private:
  coords_t transformVector_;
  coords_t undoVector_ = {-transformVector_.x, -transformVector_.y,
                          -transformVector_.z};
};

class MoveCommand : public Command {
public:
  MoveCommand(OGLWidget *widget, Transform *transformer,
              coords_t transformVector);
  void Execute() const override;
  void Undo() const override;

private:
  coords_t transformVector_;
  coords_t undoVector_ = {-transformVector_.x, -transformVector_.y,
                          -transformVector_.z};
};

class ScaleCommand : public Command {
public:
  ScaleCommand(OGLWidget *widget, Transform *transformer, double ratio);
  void Execute() const override;
  void Undo() const override;

private:
  double ratio_;
};

} // namespace s21

#endif // CPP4_3DViewer_v2_0_1_SRC_COMMAND_COMMAND_H
