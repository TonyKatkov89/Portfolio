#ifndef CPP4_3DViewer_v2_0_1_SRC_TRANSFORM_TRANSFORM_H
#define CPP4_3DViewer_v2_0_1_SRC_TRANSFORM_TRANSFORM_H

#include <cmath>
#include <vector>

#include "../matrix/s21_matrix_oop.h"
#include "../objreader/objreader_v2.h"

namespace s21 {

using vector_type = std::vector<s21::coords_t>;

/**
 * @brief Business logic. The transformations applied to the
 * coordinates of the objects in order to move, rotate
 * or change their scale.
 */

class Transform {
public:
  /**
   * @brief Function used to fit the different-sized objects to
   * window. Makes sense to use immidiately after loading
   * an object.
   */
  vector_type &FitToWindow(const vector_type &arrayOfCoords);
  /**
   * @brief Functions used to adjust object's position and size.
   */
  vector_type &Move(const vector_type &arrayOfCoords, coords_t moveVector);
  vector_type &Resize(const vector_type &arrayOfCoords, double ratio);
  vector_type &Rotate(const vector_type &arrayOfCoords, coords_t rotateVector);

private:
  /**
   * @brief Private supporting function.
   */
  double FindScale(const vector_type &arrayOfCoords, coords_t &origin);
  S21Matrix &RotateMatrix(double rotateX, double rotateY, double rotateZ);
};

} // namespace s21

#endif // CPP4_3DViewer_v2_0_1_SRC_TRANSFORM_TRANSFORM_H
