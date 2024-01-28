#include "command.h"

namespace s21 {

RotateCommand::RotateCommand(OGLWidget *widget, Transform *transformer,
                             coords_t transformVector)
    : transformVector_(transformVector) {
  widget_ = widget;
  receiver_ = transformer;
}

void RotateCommand::Execute() const {
  *widget_->arrayOfCoords =
      receiver_->Rotate(*widget_->arrayOfCoords, transformVector_);
  widget_->update();
  widget_->rotateX += transformVector_.x;
  widget_->rotateY += transformVector_.y;
  widget_->rotateZ += transformVector_.z;
}

void RotateCommand::Undo() const {
  *widget_->arrayOfCoords =
      receiver_->Rotate(*widget_->arrayOfCoords, undoVector_);
  widget_->update();
  widget_->rotateX += undoVector_.x;
  widget_->rotateY += undoVector_.y;
  widget_->rotateZ += undoVector_.z;
}

MoveCommand::MoveCommand(OGLWidget *widget, Transform *transformer,
                         coords_t transformVector)
    : transformVector_(transformVector) {
  widget_ = widget;
  receiver_ = transformer;
}
void MoveCommand::Execute() const {
  *widget_->arrayOfCoords =
      receiver_->Move(*widget_->arrayOfCoords, transformVector_);
  widget_->update();
  widget_->moveX += transformVector_.x;
  widget_->moveY += transformVector_.y;
  widget_->moveZ += transformVector_.z;
}
void MoveCommand::Undo() const {
  *widget_->arrayOfCoords =
      receiver_->Move(*widget_->arrayOfCoords, undoVector_);
  widget_->update();
  widget_->moveX += undoVector_.x;
  widget_->moveY += undoVector_.y;
  widget_->moveZ += undoVector_.z;
}

ScaleCommand::ScaleCommand(OGLWidget *widget, Transform *transformer,
                           double ratio) {
  widget_ = widget;
  receiver_ = transformer;
  ratio_ = ratio / widget_->scaleRatio;
}
void ScaleCommand::Execute() const {
  *widget_->arrayOfCoords = receiver_->Resize(*widget_->arrayOfCoords, ratio_);
  widget_->update();
  widget_->scaleRatio = widget_->scaleRatio * ratio_;
}
void ScaleCommand::Undo() const {
  *widget_->arrayOfCoords =
      receiver_->Resize(*widget_->arrayOfCoords, 1 / ratio_);
  widget_->update();
  widget_->scaleRatio = widget_->scaleRatio / ratio_;
}

} // namespace s21
