#include "transform.h"

namespace s21 {

vector_type &Transform::FitToWindow(const vector_type &arrayOfCoords) {
  vector_type *centeredCoords = new vector_type();
  coords_t origin = {0, 0, 0};
  double scale = FindScale(arrayOfCoords, origin);
  for (size_t i = 0; i < arrayOfCoords.size(); i++) {
    coords_t centeredPoint;
    centeredPoint.x = (arrayOfCoords[i].x - origin.x) / scale;
    centeredPoint.y = (arrayOfCoords[i].y - origin.y) / scale;
    centeredPoint.z = (arrayOfCoords[i].z - origin.z) / scale;
    centeredCoords->push_back(centeredPoint);
  }
  return *centeredCoords;
}

vector_type &Transform::Move(const vector_type &arrayOfCoords,
                             coords_t moveVector) {
  vector_type *movedCoords = new vector_type();
  for (size_t i = 0; i < arrayOfCoords.size(); i++) {
    coords_t movedPoint;
    movedPoint.x = arrayOfCoords[i].x + moveVector.x;
    movedPoint.y = arrayOfCoords[i].y + moveVector.y;
    movedPoint.z = arrayOfCoords[i].z + moveVector.z;
    movedCoords->push_back(movedPoint);
  }
  return *movedCoords;
}

vector_type &Transform::Resize(const vector_type &arrayOfCoords, double ratio) {
  vector_type *resizedCoords = new vector_type();
  for (size_t i = 0; i < arrayOfCoords.size(); i++) {
    coords_t resizedPoint;
    resizedPoint.x = arrayOfCoords[i].x * ratio;
    resizedPoint.y = arrayOfCoords[i].y * ratio;
    resizedPoint.z = arrayOfCoords[i].z * ratio;
    resizedCoords->push_back(resizedPoint);
  }
  return *resizedCoords;
}

vector_type &Transform::Rotate(const vector_type &arrayOfCoords,
                               coords_t rotateVector) {
  coords_t origin = {1, 1, 1};
  vector_type *rotatedCoords = new vector_type();
  S21Matrix rotateMatrix =
      RotateMatrix(rotateVector.x, rotateVector.y, rotateVector.z);
  FindScale(arrayOfCoords, origin);
  for (size_t i = 0; i < arrayOfCoords.size(); i++) {
    S21Matrix mVector(3, 1);
    mVector(0, 0) = arrayOfCoords[i].x - origin.x;
    mVector(1, 0) = arrayOfCoords[i].y - origin.y;
    mVector(2, 0) = arrayOfCoords[i].z - origin.z;
    S21Matrix rotatedVector = rotateMatrix * mVector;
    coords_t rotatedPoint = origin;
    rotatedPoint.x += rotatedVector(0, 0);
    rotatedPoint.y += rotatedVector(1, 0);
    rotatedPoint.z += rotatedVector(2, 0);
    rotatedCoords->push_back(rotatedPoint);
  }
  return *rotatedCoords;
}

double Transform::FindScale(const vector_type &arrayOfCoords,
                            coords_t &origin) {
  double scale = 1;
  if (!arrayOfCoords.empty()) {
    coords_t max, min;
    max.x = min.x = arrayOfCoords[0].x;
    max.y = min.y = arrayOfCoords[0].y;
    max.z = min.z = arrayOfCoords[0].z;

    for (size_t i = 1; i < arrayOfCoords.size(); i++) {
      if (arrayOfCoords[i].x > max.x)
        max.x = arrayOfCoords[i].x;
      if (arrayOfCoords[i].x < min.x)
        min.x = arrayOfCoords[i].x;
      if (arrayOfCoords[i].y > max.y)
        max.y = arrayOfCoords[i].y;
      if (arrayOfCoords[i].y < min.y)
        min.y = arrayOfCoords[i].y;
      if (arrayOfCoords[i].z > max.z)
        max.z = arrayOfCoords[i].z;
      if (arrayOfCoords[i].z < min.z)
        min.z = arrayOfCoords[i].z;
    }

    origin.x = (max.x + min.x) / 2;
    origin.y = (max.y + min.y) / 2;
    origin.z = (max.z + min.z) / 2;

    if (max.x - min.x >= max.y - min.y) {
      scale = max.x - min.x;
    } else {
      scale = max.y - min.y;
    }
    if (max.z - min.z > scale) {
      scale = max.z - min.z;
    }
  }
  return scale / 2;
}

S21Matrix &Transform::RotateMatrix(double rotateX, double rotateY,
                                   double rotateZ) {
  S21Matrix *rotateMatrix = new S21Matrix(3, 3);
  double a = cos(rotateX);
  double b = sin(rotateX);
  double c = cos(rotateY);
  double d = sin(rotateY);
  double e = cos(rotateZ);
  double f = sin(rotateZ);
  (*rotateMatrix)(0, 0) = c * e;
  (*rotateMatrix)(0, 1) = -c * f;
  (*rotateMatrix)(0, 2) = -d;
  (*rotateMatrix)(1, 0) = -b * d * e + a * f;
  (*rotateMatrix)(1, 1) = b * d * f + a * e;
  (*rotateMatrix)(1, 2) = -b * c;
  (*rotateMatrix)(2, 0) = a * d * e + b * f;
  (*rotateMatrix)(2, 1) = -a * d * f + b * e;
  (*rotateMatrix)(2, 2) = a * c;

  return *rotateMatrix;
}

} // namespace s21