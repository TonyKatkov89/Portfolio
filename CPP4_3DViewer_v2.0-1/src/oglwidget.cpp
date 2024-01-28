#include "oglwidget.h"

#include "mainwindow.h"

OGLWidget::OGLWidget(QWidget *parent) : QOpenGLWidget(parent) {}

OGLWidget::~OGLWidget() {
  QSettings settings("settings.ini", QSettings::IniFormat);
  settings.beginGroup("Scaling");
  settings.setValue("value", 123);
  settings.endGroup();
}

void OGLWidget::initializeGL() {
  initializeOpenGLFunctions();
  glEnable(GL_DEPTH_TEST);
}

void OGLWidget::resizeGL(int w, int h) { glViewport(0, 0, w, h); }

void OGLWidget::paintGL() {
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  int size = 3;
  float far = 150;
  float fov = 60.0 * M_PI / 180;
  float heapHeight = size / (2 * tan(fov / 2));
  if (projectionType == 0) {
    glOrtho(-size, size, -size, size, -far, far);
  } else {
    glFrustum(-size, size, -size, size, heapHeight, far);
  }
  glClearColor(backgroundR, backgroundG, backgroundB, 1);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  glTranslatef(0, 0, -3 * heapHeight);
  drawObject();
}

void OGLWidget::drawObject() {
  glEnable(GL_LINE);

  if (edgeType) {
    glEnable(GL_LINE_STIPPLE);
    glLineStipple(1, 0x00F0);
  } else
    glDisable(GL_LINE_STIPPLE);

  glColor3f(edgeColorR, edgeColorG, edgeColorB);

  glLineWidth(edgeSize * 1.5);
  glPointSize(pointSize);

  isCorrupted = false;
  for (int i = 0; i < countF; i++) {
    glBegin(GL_LINE_LOOP);
    for (unsigned int j = 0; j < arrayOfEdges[i].size(); j++) {
      if (abs(arrayOfEdges[i][j] - 1) < countV) {
        glVertex3d(arrayOfCoords->at(abs(arrayOfEdges[i][j] - 1)).x,
                   arrayOfCoords->at(abs(arrayOfEdges[i][j] - 1)).y,
                   arrayOfCoords->at(abs(arrayOfEdges[i][j] - 1)).z);
      } else {
        isCorrupted = true;
      }
    }
    glEnd();
  }

  if (pointType > 0) {
    glColor3f(pointColorR, pointColorG, pointColorB);

    if (pointType == 1)
      glEnable(GL_POINT_SMOOTH);
    else
      glDisable(GL_POINT_SMOOTH);

    glPointSize(pointSize * 10);

    glBegin(GL_POINTS);
    for (auto i : *arrayOfCoords)
      glVertex3d(i.x, i.y, i.z);
    glEnd();
  }
}
