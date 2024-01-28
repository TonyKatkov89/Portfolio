#ifndef CPP4_3DViewer_v2_0_1_src_matrix_S21_MATRIX_OOP_H_
#define CPP4_3DViewer_v2_0_1_src_matrix_S21_MATRIX_OOP_H_

#include <cfloat>
#include <cmath>
#include <cstring>
#include <iostream>

static constexpr double const &MY_DBL_EPS = 0.000000001;

/**
 * @brief Business logic. The operations with the 2D matrixes.
 */

class S21Matrix {
private:
  int rows_, cols_; // Rows and columns
  double **matrix_; // pointer to the memory where the matrix will be allocated

  void Resize(int rows, int cols);

public:
  /**
   * @brief COnstructors and destructor.
   */
  S21Matrix();                       // default constructor
  S21Matrix(int rows, int cols);     // parameterized constructor
  S21Matrix(const S21Matrix &other); // copy cnstructor
  S21Matrix(S21Matrix &&other);      // move cnstructor
  ~S21Matrix();                      // destructor

  /**
   * @brief Operations with matrixes: Algebraic ones and to
   * find the parameters of matrixes and to get modified matrixes.
   */
  bool EqMatrix(const S21Matrix &other) noexcept;
  void SumMatrix(const S21Matrix &other);
  void SubMatrix(const S21Matrix &other);
  void MulNumber(const double num) noexcept;
  void MulMatrix(const S21Matrix &other);
  S21Matrix Transpose();
  S21Matrix CalcComplements();
  double Determinant();
  S21Matrix InverseMatrix();

  /**
   * @brief Operators overloading to allow them to be used with
   * matrixes.
   */
  S21Matrix operator+(const S21Matrix &other);
  S21Matrix operator-(const S21Matrix &other);
  S21Matrix operator*(const S21Matrix &other);
  S21Matrix operator*(const double num) noexcept;
  bool operator==(const S21Matrix &other) noexcept;
  S21Matrix &operator=(const S21Matrix &other);
  S21Matrix &operator+=(const S21Matrix &other);
  S21Matrix &operator-=(const S21Matrix &other);
  S21Matrix &operator*=(const S21Matrix &other);
  S21Matrix &operator*=(const double num) noexcept;
  double &operator()(int row, int col);
  const double &operator()(int row, int col) const;

  /**
   * @brief Supporting functions neded for the other calculations.
   */
  void FillMinor(const S21Matrix &origin, int row, int column) noexcept;
  double SmallMatrixDeterminant() noexcept;
  double BigMatrixDeterminant();

  /**
   * @brief Getters and setters to access and modify single elements of
   * matrixes.
   */
  int GetRows() noexcept;
  int GetRows() const noexcept;
  int GetCols() noexcept;
  int GetCols() const noexcept;
  void SetRows(int rows);
  void SetCols(int cols);

  /**
   * @brief Supporting function to print matrix to console.
   */
  void Print() noexcept;
};

#endif // CPP4_3DViewer_v2_0_1_src_matrix_S21_MATRIX_OOP_H_