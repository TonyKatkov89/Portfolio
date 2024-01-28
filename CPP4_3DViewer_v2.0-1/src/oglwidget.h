#ifndef OGLWIDGET_H
#define OGLWIDGET_H

#define GL_SILENCE_DEPRECATION
#include <QOpenGLFunctions>
#include <QOpenGLWidget>
#include <QWidget>
#include <QtOpenGL>

#include "objreader/objreader_v2.h"
#include "qgifimage.h"

class OGLWidget : public QOpenGLWidget, protected QOpenGLFunctions {
  Q_OBJECT
public:
  OGLWidget(QWidget *parent = nullptr);

  std::vector<s21::coords_t> *arrayOfCoords;
  std::vector<std::vector<int>> arrayOfEdges;

  int countV = 0;
  int countF = 0;

  double rotateX = 0;
  double rotateY = 0;
  double rotateZ = 0;

  int projectionType = 0; // 0 - parallel; 1 - central;

  double scaleRatio = 1;

  double moveX = 0;
  double moveY = 0;
  double moveZ = 0;

  QTimer *timer = NULL;
  int time = 0;
  QGifImage *gif = NULL;

  int edgeType = 0; // 0 - solid; 1 - dashed;
  double edgeSize = 1;
  float edgeColorR = 0, edgeColorG = 0, edgeColorB = 0;

  int pointType = 0; // 0 - none; 1 - circle; 2 - square;
  double pointSize = 1;
  float pointColorR = 0, pointColorG = 0, pointColorB = 0;

  float backgroundR = 0.92549, backgroundG = 0.925475, backgroundB = 0.92549;

  bool isCorrupted = false;

  ~OGLWidget();

  void drawObject();

private:
  void initializeGL() override;
  void paintGL() override;
  void resizeGL(int w, int h) override;
};

#endif // OGLWIDGET_H
