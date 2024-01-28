#include "s21_matrix_oop.h"

S21Matrix::S21Matrix() : S21Matrix::S21Matrix(0, 0) {}

S21Matrix::S21Matrix(int rows, int cols) : rows_(rows), cols_(cols) {
  if (rows_ > 0 && cols_ > 0) {
    matrix_ = new double *[rows_]();
    matrix_[0] = new double[rows_ * cols_]();
    for (int i = 1; i < rows_; ++i)
      matrix_[i] = matrix_[0] + i * cols_;
  } else if (rows_ < 0 || cols_ < 0) {
    throw std::out_of_range("Incorrect input, dimentions can't be negative.");
  } else {
    matrix_ = nullptr;
  }
}

S21Matrix::S21Matrix(const S21Matrix &other)
    : S21Matrix::S21Matrix(other.GetRows(), other.GetCols()) {
  std::memcpy(matrix_[0], other.matrix_[0], rows_ * cols_ * sizeof(double));
}

S21Matrix::S21Matrix(S21Matrix &&other) : S21Matrix::S21Matrix(0, 0) {
  std::swap(rows_, other.rows_);
  std::swap(cols_, other.cols_);
  std::swap(matrix_, other.matrix_);
  other.~S21Matrix();
}

S21Matrix::~S21Matrix() noexcept {
  if (matrix_) {
    delete[] matrix_[0];
    delete[] matrix_;
    rows_ = 0;
    cols_ = 0;
  }
}

bool S21Matrix::EqMatrix(const S21Matrix &other) noexcept {
  if (other.GetCols() != cols_ || other.GetRows() != rows_)
    return false;
  for (int i = 0; i < rows_ * cols_; ++i) {
    if (fabs(this->matrix_[0][i] - other.matrix_[0][i]) > MY_DBL_EPS) {
      return false;
    }
  }
  return true;
}

void S21Matrix::SumMatrix(const S21Matrix &other) {
  if (rows_ != other.GetRows() || cols_ != other.GetCols()) {
    throw std::out_of_range(
        "Incorrect input, matrices should have the same size");
  }
  for (int i = 0; i < rows_ * cols_; ++i) {
    this->matrix_[0][i] = this->matrix_[0][i] + other.matrix_[0][i];
  }
}

void S21Matrix::SubMatrix(const S21Matrix &other) {
  if (rows_ != other.GetRows() || cols_ != other.GetCols()) {
    throw std::logic_error(
        "Dimentions of the matrixes do not match to be multiplied");
  }
  for (int i = 0; i < rows_ * cols_; ++i) {
    this->matrix_[0][i] = this->matrix_[0][i] - other.matrix_[0][i];
  }
}

void S21Matrix::MulNumber(const double num) noexcept {
  for (int i = 0; i < rows_ * cols_; ++i) {
    this->matrix_[0][i] *= num;
  }
}

void S21Matrix::MulMatrix(const S21Matrix &other) {
  if (cols_ != other.GetRows()) {
    throw std::logic_error(
        "Incorrect input, matrices should have the same size");
  }
  S21Matrix tmp(rows_, other.GetCols());
  for (int i = 0; i < rows_; ++i) {
    for (int j = 0; j < other.GetCols(); ++j) {
      tmp(i, j) = 0;
      for (int k = 0; k < cols_; k++) {
        tmp(i, j) += (*this)(i, k) * other(k, j);
      }
    }
  }
  std::swap(rows_, tmp.rows_);
  std::swap(cols_, tmp.cols_);
  std::swap(matrix_, tmp.matrix_);
}

S21Matrix S21Matrix::Transpose() {
  if (cols_ != rows_) {
    throw std::logic_error("Non-square matrix cannot be transposed");
  }
  S21Matrix result(rows_, cols_);
  for (int i = 0; i < rows_; ++i) {
    for (int j = 0; j < cols_; ++j) {
      result(i, j) = (*this)(j, i);
    }
  }
  return result;
}

S21Matrix S21Matrix::CalcComplements() {
  if (cols_ != rows_ || cols_ < 2) {
    throw std::logic_error("Non-square matrix cannot have complements");
  }
  S21Matrix result(rows_, cols_);
  for (int i = 0; i < rows_; ++i) {
    for (int j = 0; j < cols_; ++j) {
      double minor_det = 0;
      S21Matrix m(rows_ - 1, cols_ - 1);
      m.FillMinor(*this, i, j);
      minor_det = m.Determinant();
      result(i, j) = minor_det * std::pow(-1, i + j);
    }
  }
  return result;
}

double S21Matrix::Determinant() {
  double result = 0;
  if (cols_ != rows_) {
    throw std::logic_error("Non-square matrix does not have a determinant");
  }
  if (cols_ == 1 || cols_ == 2) {
    result = this->SmallMatrixDeterminant();
  } else {
    result = this->BigMatrixDeterminant();
  }
  return result;
}

S21Matrix S21Matrix::InverseMatrix() {
  if (cols_ != rows_ || cols_ < 1) {
    throw std::logic_error(
        "Non-square or too small matrix does not have an inverse matrix");
  }
  S21Matrix result(rows_, cols_);
  if (cols_ == 1) {
    if (abs((*this)(0, 0)) < MY_DBL_EPS) {
      throw std::logic_error("There is no complements matrix for 0 matrix");
    } else {
      result(0, 0) = 1 / (*this)(0, 0);
    }
  } else {
    double det = 0;
    det = this->Determinant();
    if (fabs(det) < MY_DBL_EPS) {
      throw std::logic_error("Determinant is 0");
    }
    S21Matrix complements_matrix(this->CalcComplements());
    result = complements_matrix.Transpose();
    det = 1 / det;
    result.MulNumber(det);
  }
  return result;
}

S21Matrix S21Matrix::operator+(const S21Matrix &other) {
  S21Matrix res = *this;
  res.SumMatrix(other);
  return res;
}

S21Matrix S21Matrix::operator-(const S21Matrix &other) {
  S21Matrix res = *this;
  res.SubMatrix(other);
  return res;
}

S21Matrix S21Matrix::operator*(const S21Matrix &other) {
  S21Matrix res = *this;
  res.MulMatrix(other);
  return res;
}

S21Matrix S21Matrix::operator*(const double num) noexcept {
  S21Matrix res = *this;
  res.MulNumber(num);
  return res;
}

bool S21Matrix::operator==(const S21Matrix &other) noexcept {
  return this->EqMatrix(other);
}

S21Matrix &S21Matrix::operator=(const S21Matrix &other) {
  S21Matrix tmp(other);
  std::swap(rows_, tmp.rows_);
  std::swap(cols_, tmp.cols_);
  std::swap(matrix_, tmp.matrix_);
  return *this;
}

S21Matrix &S21Matrix::operator+=(const S21Matrix &other) {
  this->SumMatrix(other);
  return *this;
}

S21Matrix &S21Matrix::operator-=(const S21Matrix &other) {
  this->SubMatrix(other);
  return *this;
}

S21Matrix &S21Matrix::operator*=(const S21Matrix &other) {
  this->MulMatrix(other);
  return *this;
}

S21Matrix &S21Matrix::operator*=(const double num) noexcept {
  this->MulNumber(num);
  return *this;
}

double &S21Matrix::operator()(int row, int col) {
  if (row >= rows_ || col >= cols_ || row < 0 || col < 0) {
    throw std::out_of_range("Incorrect input, index is out of range");
  }
  return matrix_[row][col];
}

const double &S21Matrix::operator()(int row, int col) const {
  if (row >= rows_ || col >= cols_ || row < 0 || col < 0) {
    throw std::out_of_range("Incorrect input, index is out of range");
  }
  return matrix_[row][col];
}

void S21Matrix::FillMinor(const S21Matrix &origin, int row,
                          int column) noexcept {
  int m = 0;
  for (int i = 0; i < origin.GetRows(); ++i) {
    int n = 0;
    if (i != row) {
      for (int j = 0; j < origin.GetCols(); ++j) {
        if (j != column) {
          (*this)(m, n) = origin(i, j);
          ++n;
        }
      }
      ++m;
    }
  }
}

double S21Matrix::SmallMatrixDeterminant() noexcept {
  double result = 0;
  if (cols_ == 1) {
    result = matrix_[0][0];
  } else if (cols_ == 2) {
    result = (*this)(0, 0) * (*this)(1, 1) - (*this)(0, 1) * (*this)(1, 0);
  }
  return result;
}

double S21Matrix::BigMatrixDeterminant() {
  double result = 0;
  for (int i = 0; i < cols_; ++i) {
    double minor_det = 0;
    S21Matrix m(rows_ - 1, cols_ - 1);
    m.FillMinor(*this, 0, i);
    minor_det = m.Determinant();
    result += (*this)(0, i) * minor_det * pow(-1, i);
  }
  return result;
}

int S21Matrix::GetRows() noexcept { return rows_; }

int S21Matrix::GetRows() const noexcept { return rows_; }

int S21Matrix::GetCols() noexcept { return cols_; }

int S21Matrix::GetCols() const noexcept { return cols_; }

void S21Matrix::SetRows(int rows) { this->Resize(rows, cols_); }

void S21Matrix::SetCols(int cols) { this->Resize(rows_, cols); }

void S21Matrix::Print() noexcept {
  for (int i = 0; i < rows_; ++i) {
    for (int j = 0; j < cols_; ++j) {
      std::cout << (*this)(i, j) << ' ';
    }
    std::cout << '\n';
  }
}

void S21Matrix::Resize(int rows, int cols) {
  S21Matrix tmp(rows, cols);
  memset(tmp.matrix_[0], 0, rows * cols * __SIZEOF_DOUBLE__);
  for (int i = 0; i < rows && i < rows_; ++i) {
    for (int j = 0; j < cols && j < cols_; ++j) {
      tmp(i, j) = (*this)(i, j);
    }
  }
  *this = tmp;
}
