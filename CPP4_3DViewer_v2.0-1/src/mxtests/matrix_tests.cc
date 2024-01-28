#include <gtest/gtest.h>

#include "../matrix/s21_matrix_oop.h"

class S21MatrixTest : public testing::Test {
protected:
  S21Matrix *matrix_3x3;
  S21Matrix *matrix_4x3;
  S21Matrix *matrix_temp;

  void SetUp() {
    matrix_3x3 = new S21Matrix(3, 3);
    (*matrix_3x3)(0, 0) = 0;
    (*matrix_3x3)(0, 1) = 1;
    (*matrix_3x3)(0, 2) = 2;
    (*matrix_3x3)(1, 0) = 3;
    (*matrix_3x3)(1, 1) = 4;
    (*matrix_3x3)(1, 2) = 5;
    (*matrix_3x3)(2, 0) = 6;
    (*matrix_3x3)(2, 1) = 7;
    (*matrix_3x3)(2, 2) = 8;

    matrix_4x3 = new S21Matrix(4, 3);
    (*matrix_4x3)(0, 0) = 0;
    (*matrix_4x3)(0, 1) = 1;
    (*matrix_4x3)(0, 2) = 2;
    (*matrix_4x3)(1, 0) = 3;
    (*matrix_4x3)(1, 1) = 4;
    (*matrix_4x3)(1, 2) = 5;
    (*matrix_4x3)(2, 0) = 6;
    (*matrix_4x3)(2, 1) = 7;
    (*matrix_4x3)(2, 2) = 8;
    (*matrix_4x3)(3, 0) = 9;
    (*matrix_4x3)(3, 1) = 10;
    (*matrix_4x3)(3, 2) = 11;
  }

  void TearDown() {
    delete matrix_3x3;
    delete matrix_4x3;
  }
};

TEST_F(S21MatrixTest, constructor) {
  S21Matrix matrix;
  EXPECT_EQ(0, matrix.GetRows());
  EXPECT_EQ(0, matrix.GetCols());
}

TEST_F(S21MatrixTest, constructorWithParameters0) {
  S21Matrix matrix(15, 6);
  EXPECT_EQ(15, matrix.GetRows());
  EXPECT_EQ(6, matrix.GetCols());
}

TEST_F(S21MatrixTest, constructorWithParameters1) {
  S21Matrix matrix(10, 10);
  EXPECT_EQ(10, matrix.GetRows());
  EXPECT_EQ(10, matrix.GetCols());
}

TEST_F(S21MatrixTest, constructorWithParametersError) {
  EXPECT_THROW(matrix_temp = new S21Matrix(-1, -1), std::out_of_range);
}

TEST_F(S21MatrixTest, constructorCopy) {
  S21Matrix matrix(*matrix_4x3);
  EXPECT_EQ(4, matrix.GetRows());
  EXPECT_EQ(3, matrix.GetCols());
  EXPECT_EQ(4, matrix_4x3->GetRows());
  EXPECT_EQ(3, matrix_4x3->GetCols());
  EXPECT_EQ(1, *matrix_4x3 == matrix);
}

TEST_F(S21MatrixTest, constructorMove) {
  S21Matrix matrix_copy(*matrix_4x3);
  S21Matrix matrix(std::move(*matrix_4x3));
  EXPECT_EQ(4, matrix.GetRows());
  EXPECT_EQ(3, matrix.GetCols());
  EXPECT_EQ(1, matrix_copy == matrix);
  EXPECT_EQ(0, matrix_4x3->GetRows());
  EXPECT_EQ(0, matrix_4x3->GetCols());
}

TEST_F(S21MatrixTest, GetColsAndRows) {
  EXPECT_EQ(3, matrix_3x3->GetRows());
  EXPECT_EQ(3, matrix_3x3->GetCols());
  EXPECT_EQ(4, matrix_4x3->GetRows());
  EXPECT_EQ(3, matrix_4x3->GetCols());
}

TEST_F(S21MatrixTest, SetColsAndRows) {
  matrix_3x3->SetRows(4);
  EXPECT_EQ(4, matrix_3x3->GetRows());
  EXPECT_THROW(matrix_3x3->SetRows(-1), std::out_of_range);
  matrix_3x3->SetCols(4);
  EXPECT_EQ(4, matrix_3x3->GetCols());
  EXPECT_THROW(matrix_3x3->SetCols(-2), std::out_of_range);
}

TEST_F(S21MatrixTest, EqualityOperator) {
  S21Matrix matrix, empty_matrix;
  EXPECT_EQ(0, *matrix_3x3 == *matrix_4x3);
  EXPECT_EQ(0, *matrix_3x3 == matrix);
  EXPECT_EQ(1, *matrix_3x3 == *matrix_3x3);
}

TEST_F(S21MatrixTest, equalsOperator) {
  S21Matrix matrix;
  matrix = *matrix_3x3;
  EXPECT_EQ(1, *matrix_3x3 == matrix);
  matrix = *matrix_4x3;
  EXPECT_EQ(1, *matrix_4x3 == matrix);
}

TEST_F(S21MatrixTest, plusAndEqualsOperator) {
  S21Matrix result(3, 3);
  result(0, 0) = 0;
  result(0, 1) = 2;
  result(0, 2) = 4;
  result(1, 0) = 6;
  result(1, 1) = 8;
  result(1, 2) = 10;
  result(2, 0) = 12;
  result(2, 1) = 14;
  result(2, 2) = 16;
  S21Matrix test_result;
  test_result = *matrix_3x3 + *matrix_3x3;
  *matrix_3x3 += *matrix_3x3;
  EXPECT_EQ(1, result == *matrix_3x3 && result == test_result);
}

TEST_F(S21MatrixTest, plusAndEqualsOperatorError) {
  EXPECT_THROW(*matrix_3x3 + *matrix_4x3, std::logic_error);
}

TEST_F(S21MatrixTest, minusAndEqualsOperatorError) {
  EXPECT_THROW(*matrix_3x3 - *matrix_4x3, std::logic_error);
}

TEST_F(S21MatrixTest, mulMatrixAndEqualsOperatorError) {
  EXPECT_THROW(*matrix_3x3 * *matrix_4x3, std::logic_error);
}

TEST_F(S21MatrixTest, mulNumberAndEqualsOperator) {
  S21Matrix result(3, 3);
  result(0, 0) = 0;
  result(0, 1) = 5;
  result(0, 2) = 10;
  result(1, 0) = 15;
  result(1, 1) = 20;
  result(1, 2) = 25;
  result(2, 0) = 30;
  result(2, 1) = 35;
  result(2, 2) = 40;
  S21Matrix test_result;
  test_result = *matrix_3x3 * 5;
  *matrix_3x3 *= 5;
  EXPECT_EQ(1, result == *matrix_3x3 && result == test_result);
}

TEST_F(S21MatrixTest, bracketsOperator) {
  EXPECT_EQ(0, (*matrix_3x3)(0, 0));
  EXPECT_EQ(1, (*matrix_3x3)(0, 1));
  EXPECT_EQ(2, (*matrix_3x3)(0, 2));
  EXPECT_EQ(3, (*matrix_3x3)(1, 0));
  EXPECT_EQ(4, (*matrix_3x3)(1, 1));
  EXPECT_EQ(5, (*matrix_3x3)(1, 2));
  EXPECT_EQ(6, (*matrix_3x3)(2, 0));
  EXPECT_EQ(7, (*matrix_3x3)(2, 1));
  EXPECT_EQ(8, (*matrix_3x3)(2, 2));
}

TEST_F(S21MatrixTest, bracketsOperatorError) {
  EXPECT_THROW((*matrix_3x3)(-1, 0), std::out_of_range);
  EXPECT_THROW((*matrix_3x3)(1, 4), std::out_of_range);
}

TEST_F(S21MatrixTest, bracketsOperatorConstError) {
  S21Matrix const matrix;
  EXPECT_THROW(matrix.operator()(-1, 0), std::out_of_range);
  EXPECT_THROW(matrix.operator()(1, 4), std::out_of_range);
}

TEST_F(S21MatrixTest, trans) {
  S21Matrix result;
  S21Matrix temp(3, 3);
  temp(0, 0) = 1;
  temp(0, 1) = 2;
  temp(0, 2) = 3;
  temp(1, 0) = 4;
  temp(1, 1) = 5;
  temp(1, 2) = 6;
  temp(2, 0) = 7;
  temp(2, 1) = 8;
  temp(2, 2) = 9;
  result = temp.Transpose();
  EXPECT_EQ(0, (temp == result));
}

TEST_F(S21MatrixTest, complements) {
  (*matrix_3x3)(0, 0) = -5;
  S21Matrix result(3, 3);
  result(0, 0) = -3;
  result(0, 1) = 6;
  result(0, 2) = -3;
  result(1, 0) = 6;
  result(1, 1) = -52;
  result(1, 2) = 41;
  result(2, 0) = -3;
  result(2, 1) = 31;
  result(2, 2) = -23;
  S21Matrix test_result;
  test_result = matrix_3x3->CalcComplements();
  EXPECT_EQ(1, result == test_result);
}

TEST_F(S21MatrixTest, complementsError) {
  EXPECT_THROW(matrix_4x3->CalcComplements(), std::logic_error);
}

TEST_F(S21MatrixTest, Determinant) {
  EXPECT_EQ(0, matrix_3x3->Determinant());
  (*matrix_3x3)(0, 0) = -5;
  EXPECT_EQ(15, matrix_3x3->Determinant());
  S21Matrix matrix_1x1(1, 1);
  matrix_1x1(0, 0) = 5;
  EXPECT_EQ(5, matrix_1x1.Determinant());
}

TEST_F(S21MatrixTest, DeterminantError) {
  EXPECT_THROW(matrix_4x3->Determinant(), std::logic_error);
}

TEST_F(S21MatrixTest, inverse) {
  (*matrix_3x3)(0, 0) = 2;
  (*matrix_3x3)(0, 1) = 5;
  (*matrix_3x3)(0, 2) = 7;
  (*matrix_3x3)(1, 0) = 6;
  (*matrix_3x3)(1, 1) = 3;
  (*matrix_3x3)(1, 2) = 4;
  (*matrix_3x3)(2, 0) = 5;
  (*matrix_3x3)(2, 1) = -2;
  (*matrix_3x3)(2, 2) = -3;
  S21Matrix result(3, 3);
  result(0, 0) = 1;
  result(0, 1) = -1;
  result(0, 2) = 1;
  result(1, 0) = -38;
  result(1, 1) = 41;
  result(1, 2) = -34;
  result(2, 0) = 27;
  result(2, 1) = -29;
  result(2, 2) = 24;
  S21Matrix test_result;
  test_result = matrix_3x3->InverseMatrix();
  EXPECT_EQ(1, result == test_result);
}

TEST_F(S21MatrixTest, inverseError) {
  EXPECT_THROW(matrix_3x3->InverseMatrix(), std::logic_error);
}

TEST(TestSum, TestSumFunctionException1) {
  S21Matrix matrix1{2, 2};
  S21Matrix matrix2{2, 3};

  S21Matrix matrix1_before = matrix1;
  S21Matrix matrix2_before = matrix2;

  EXPECT_ANY_THROW(matrix1.SumMatrix(matrix2));
  EXPECT_ANY_THROW(matrix2.SumMatrix(matrix1));
  EXPECT_TRUE(matrix1 == matrix1_before);
  EXPECT_TRUE(matrix2 == matrix2_before);
}

TEST(TestSum, TestSumFunctionException2) {
  S21Matrix matrix1{2, 2};
  S21Matrix matrix2{3, 2};

  S21Matrix matrix1_before = matrix1;
  S21Matrix matrix2_before = matrix2;

  EXPECT_ANY_THROW(matrix1.SumMatrix(matrix2));
  EXPECT_ANY_THROW(matrix2.SumMatrix(matrix1));
  EXPECT_TRUE(matrix1 == matrix1_before);
  EXPECT_TRUE(matrix2 == matrix2_before);
}

TEST(TestSum, TestSumFunctionException3) {
  S21Matrix matrix1{3, 2};
  S21Matrix matrix2{2, 2};

  S21Matrix matrix1_before = matrix1;
  S21Matrix matrix2_before = matrix2;

  EXPECT_ANY_THROW(matrix1.SumMatrix(matrix2));
  EXPECT_ANY_THROW(matrix2.SumMatrix(matrix1));
  EXPECT_TRUE(matrix1 == matrix1_before);
  EXPECT_TRUE(matrix2 == matrix2_before);
}

TEST(TestSum, TestSumFunctionException4) {
  S21Matrix matrix1{2, 3};
  S21Matrix matrix2{2, 2};

  S21Matrix matrix1_before = matrix1;
  S21Matrix matrix2_before = matrix2;

  EXPECT_ANY_THROW(matrix1.SumMatrix(matrix2));
  EXPECT_ANY_THROW(matrix2.SumMatrix(matrix1));
  EXPECT_TRUE(matrix1 == matrix1_before);
  EXPECT_TRUE(matrix2 == matrix2_before);
}

TEST(TestSum, TestSumOperatorException1) {
  S21Matrix matrix1{2, 2};
  S21Matrix matrix2{2, 3};

  S21Matrix matrix1_before = matrix1;
  S21Matrix matrix2_before = matrix2;

  EXPECT_ANY_THROW(matrix1 + matrix2);
  EXPECT_ANY_THROW(matrix2 + matrix1);
  EXPECT_TRUE(matrix1 == matrix1_before);
  EXPECT_TRUE(matrix2 == matrix2_before);
}

TEST(TestSum, TestSumOperatorException2) {
  S21Matrix matrix1{2, 2};
  S21Matrix matrix2{3, 2};

  S21Matrix matrix1_before = matrix1;
  S21Matrix matrix2_before = matrix2;

  EXPECT_ANY_THROW(matrix1 + matrix2);
  EXPECT_ANY_THROW(matrix2 + matrix1);
  EXPECT_TRUE(matrix1 == matrix1_before);
  EXPECT_TRUE(matrix2 == matrix2_before);
}

TEST(TestSum, TestSumOperatorException3) {
  S21Matrix matrix1{3, 2};
  S21Matrix matrix2{2, 2};

  S21Matrix matrix1_before = matrix1;
  S21Matrix matrix2_before = matrix2;

  EXPECT_ANY_THROW(matrix1 + matrix2);
  EXPECT_ANY_THROW(matrix2 + matrix1);
  EXPECT_TRUE(matrix1 == matrix1_before);
  EXPECT_TRUE(matrix2 == matrix2_before);
}

TEST(TestSum, TestSumOperatorException4) {
  S21Matrix matrix1{2, 3};
  S21Matrix matrix2{2, 2};

  S21Matrix matrix1_before = matrix1;
  S21Matrix matrix2_before = matrix2;

  EXPECT_ANY_THROW(matrix1 + matrix2);
  EXPECT_ANY_THROW(matrix2 + matrix1);
  EXPECT_TRUE(matrix1 == matrix1_before);
  EXPECT_TRUE(matrix2 == matrix2_before);
}

TEST(TestSum, TestSumOperatorException5) {
  S21Matrix matrix1{2, 2};
  S21Matrix matrix2{2, 3};

  S21Matrix matrix1_before = matrix1;
  S21Matrix matrix2_before = matrix2;

  EXPECT_ANY_THROW(matrix1 += matrix2);
  EXPECT_ANY_THROW(matrix2 += matrix1);
  EXPECT_TRUE(matrix1 == matrix1_before);
  EXPECT_TRUE(matrix2 == matrix2_before);
}

TEST(TestSum, TestSumOperatorException6) {
  S21Matrix matrix1{2, 2};
  S21Matrix matrix2{3, 2};

  S21Matrix matrix1_before = matrix1;
  S21Matrix matrix2_before = matrix2;

  EXPECT_ANY_THROW(matrix1 += matrix2);
  EXPECT_ANY_THROW(matrix2 += matrix1);
  EXPECT_TRUE(matrix1 == matrix1_before);
  EXPECT_TRUE(matrix2 == matrix2_before);
}

TEST(TestSum, TestSumOperatorException7) {
  S21Matrix matrix1{3, 2};
  S21Matrix matrix2{2, 2};

  S21Matrix matrix1_before = matrix1;
  S21Matrix matrix2_before = matrix2;

  EXPECT_ANY_THROW(matrix1 += matrix2);
  EXPECT_ANY_THROW(matrix2 += matrix1);
  EXPECT_TRUE(matrix1 == matrix1_before);
  EXPECT_TRUE(matrix2 == matrix2_before);
}

TEST(TestSum, TestSumOperatorException8) {
  S21Matrix matrix1{2, 3};
  S21Matrix matrix2{2, 2};

  S21Matrix matrix1_before = matrix1;
  S21Matrix matrix2_before = matrix2;

  EXPECT_ANY_THROW(matrix1 += matrix2);
  EXPECT_ANY_THROW(matrix2 += matrix1);
  EXPECT_TRUE(matrix1 == matrix1_before);
  EXPECT_TRUE(matrix2 == matrix2_before);
}

TEST(TestSum, TestSum1) {
  S21Matrix matrix1{4, 3};
  EXPECT_EQ(matrix1.GetRows(), 4);
  EXPECT_EQ(matrix1.GetCols(), 3);

  S21Matrix matrix2{4, 3};
  EXPECT_EQ(matrix2.GetRows(), 4);
  EXPECT_EQ(matrix2.GetCols(), 3);

  S21Matrix check_matrix{4, 3};
  EXPECT_EQ(matrix2.GetRows(), 4);
  EXPECT_EQ(matrix2.GetCols(), 3);

  matrix1(0, 0) = 1.5;
  matrix1(0, 1) = 2.5;
  matrix1(0, 2) = 3.5;
  matrix1(1, 0) = -1.5;
  matrix1(1, 1) = -2.5;
  matrix1(1, 2) = -3.5;
  matrix1(2, 0) = 0.0;
  matrix1(2, 1) = 0.0;
  matrix1(2, 2) = 0.0;
  matrix1(3, 0) = 1.0;
  matrix1(3, 1) = 1.0;
  matrix1(3, 2) = 1.0;

  matrix2(0, 0) = 0.0;
  matrix2(0, 1) = 1.0;
  matrix2(0, 2) = 2.0;
  matrix2(1, 0) = 3.0;
  matrix2(1, 1) = 0.0;
  matrix2(1, 2) = 4.0;
  matrix2(2, 0) = -1.0;
  matrix2(2, 1) = -2.0;
  matrix2(2, 2) = 0.0;
  matrix2(3, 0) = -3.0;
  matrix2(3, 1) = 0.0;
  matrix2(3, 2) = 4.0;

  check_matrix(0, 0) = 1.5;
  check_matrix(0, 1) = 3.5;
  check_matrix(0, 2) = 5.5;
  check_matrix(1, 0) = 1.5;
  check_matrix(1, 1) = -2.5;
  check_matrix(1, 2) = 0.5;
  check_matrix(2, 0) = -1.0;
  check_matrix(2, 1) = -2.0;
  check_matrix(2, 2) = 0.0;
  check_matrix(3, 0) = -2.0;
  check_matrix(3, 1) = 1.0;
  check_matrix(3, 2) = 5.0;

  matrix1.SumMatrix(matrix2);

  EXPECT_TRUE(matrix1 == check_matrix);
}

TEST(TestSum, TestSum2) {
  S21Matrix matrix1{2, 2};
  EXPECT_EQ(matrix1.GetRows(), 2);
  EXPECT_EQ(matrix1.GetCols(), 2);

  S21Matrix matrix2{2, 2};
  EXPECT_EQ(matrix2.GetRows(), 2);
  EXPECT_EQ(matrix2.GetCols(), 2);

  S21Matrix check_matrix{2, 2};
  EXPECT_EQ(matrix2.GetRows(), 2);
  EXPECT_EQ(matrix2.GetCols(), 2);

  matrix1(0, 0) = 145678000.588;
  matrix1(0, 1) = -4542;
  matrix1(1, 0) = 673552.54545324;
  matrix1(1, 1) = 145678000.588;

  matrix2(0, 0) = 14567800.777;
  matrix2(0, 1) = -4542;
  matrix2(1, 0) = 3.0;
  matrix2(1, 1) = 0.0;

  check_matrix(0, 0) = 160245801.365;
  check_matrix(0, 1) = -9084;
  check_matrix(1, 0) = 673555.54545324;
  check_matrix(1, 1) = 145678000.588;

  matrix1.SumMatrix(matrix2);

  EXPECT_TRUE(matrix1 == check_matrix);
}

TEST(TestSum, TestSumOperation1) {
  S21Matrix matrix1{4, 3};
  EXPECT_EQ(matrix1.GetRows(), 4);
  EXPECT_EQ(matrix1.GetCols(), 3);

  S21Matrix matrix2{4, 3};
  EXPECT_EQ(matrix2.GetRows(), 4);
  EXPECT_EQ(matrix2.GetCols(), 3);

  S21Matrix check_matrix{4, 3};
  EXPECT_EQ(matrix2.GetRows(), 4);
  EXPECT_EQ(matrix2.GetCols(), 3);

  matrix1(0, 0) = 1.5;
  matrix1(0, 1) = 2.5;
  matrix1(0, 2) = 3.5;
  matrix1(1, 0) = -1.5;
  matrix1(1, 1) = -2.5;
  matrix1(1, 2) = -3.5;
  matrix1(2, 0) = 0.0;
  matrix1(2, 1) = 0.0;
  matrix1(2, 2) = 0.0;
  matrix1(3, 0) = 1.0;
  matrix1(3, 1) = 1.0;
  matrix1(3, 2) = 1.0;

  matrix2(0, 0) = 0.0;
  matrix2(0, 1) = 1.0;
  matrix2(0, 2) = 2.0;
  matrix2(1, 0) = 3.0;
  matrix2(1, 1) = 0.0;
  matrix2(1, 2) = 4.0;
  matrix2(2, 0) = -1.0;
  matrix2(2, 1) = -2.0;
  matrix2(2, 2) = 0.0;
  matrix2(3, 0) = -3.0;
  matrix2(3, 1) = 0.0;
  matrix2(3, 2) = 4.0;

  check_matrix(0, 0) = 1.5;
  check_matrix(0, 1) = 3.5;
  check_matrix(0, 2) = 5.5;
  check_matrix(1, 0) = 1.5;
  check_matrix(1, 1) = -2.5;
  check_matrix(1, 2) = 0.5;
  check_matrix(2, 0) = -1.0;
  check_matrix(2, 1) = -2.0;
  check_matrix(2, 2) = 0.0;
  check_matrix(3, 0) = -2.0;
  check_matrix(3, 1) = 1.0;
  check_matrix(3, 2) = 5.0;

  S21Matrix matrix1_before = matrix1;
  S21Matrix matrix2_before = matrix2;
  S21Matrix result = matrix1 + matrix2;

  EXPECT_EQ(result.GetRows(), 4);
  EXPECT_EQ(result.GetCols(), 3);

  EXPECT_TRUE(result == check_matrix);
  EXPECT_TRUE(matrix1_before == matrix1);
  EXPECT_TRUE(matrix2_before == matrix2);
}

TEST(TestSum, TestSumOperation2) {
  S21Matrix matrix1{2, 2};
  EXPECT_EQ(matrix1.GetRows(), 2);
  EXPECT_EQ(matrix1.GetCols(), 2);

  S21Matrix matrix2{2, 2};
  EXPECT_EQ(matrix2.GetRows(), 2);
  EXPECT_EQ(matrix2.GetCols(), 2);

  S21Matrix check_matrix{2, 2};
  EXPECT_EQ(matrix2.GetRows(), 2);
  EXPECT_EQ(matrix2.GetCols(), 2);

  matrix1(0, 0) = 145678000.588;
  matrix1(0, 1) = -4542;
  matrix1(1, 0) = 673552.54545324;
  matrix1(1, 1) = 145678000.588;

  matrix2(0, 0) = 14567800.777;
  matrix2(0, 1) = -4542;
  matrix2(1, 0) = 3.0;
  matrix2(1, 1) = 0.0;

  check_matrix(0, 0) = 160245801.365;
  check_matrix(0, 1) = -9084;
  check_matrix(1, 0) = 673555.54545324;
  check_matrix(1, 1) = 145678000.588;

  S21Matrix matrix1_before = matrix1;
  S21Matrix matrix2_before = matrix2;
  S21Matrix result = matrix1 + matrix2;

  EXPECT_EQ(result.GetRows(), 2);
  EXPECT_EQ(result.GetCols(), 2);

  EXPECT_TRUE(result == check_matrix);
  EXPECT_TRUE(matrix1_before == matrix1);
  EXPECT_TRUE(matrix2_before == matrix2);
}

TEST(TestSum, TestSumOperation3) {
  S21Matrix matrix1{4, 3};
  EXPECT_EQ(matrix1.GetRows(), 4);
  EXPECT_EQ(matrix1.GetCols(), 3);

  S21Matrix matrix2{4, 3};
  EXPECT_EQ(matrix2.GetRows(), 4);
  EXPECT_EQ(matrix2.GetCols(), 3);

  S21Matrix check_matrix{4, 3};
  EXPECT_EQ(matrix2.GetRows(), 4);
  EXPECT_EQ(matrix2.GetCols(), 3);

  matrix1(0, 0) = 1.5;
  matrix1(0, 1) = 2.5;
  matrix1(0, 2) = 3.5;
  matrix1(1, 0) = -1.5;
  matrix1(1, 1) = -2.5;
  matrix1(1, 2) = -3.5;
  matrix1(2, 0) = 0.0;
  matrix1(2, 1) = 0.0;
  matrix1(2, 2) = 0.0;
  matrix1(3, 0) = 1.0;
  matrix1(3, 1) = 1.0;
  matrix1(3, 2) = 1.0;

  matrix2(0, 0) = 0.0;
  matrix2(0, 1) = 1.0;
  matrix2(0, 2) = 2.0;
  matrix2(1, 0) = 3.0;
  matrix2(1, 1) = 0.0;
  matrix2(1, 2) = 4.0;
  matrix2(2, 0) = -1.0;
  matrix2(2, 1) = -2.0;
  matrix2(2, 2) = 0.0;
  matrix2(3, 0) = -3.0;
  matrix2(3, 1) = 0.0;
  matrix2(3, 2) = 4.0;

  check_matrix(0, 0) = 1.5;
  check_matrix(0, 1) = 3.5;
  check_matrix(0, 2) = 5.5;
  check_matrix(1, 0) = 1.5;
  check_matrix(1, 1) = -2.5;
  check_matrix(1, 2) = 0.5;
  check_matrix(2, 0) = -1.0;
  check_matrix(2, 1) = -2.0;
  check_matrix(2, 2) = 0.0;
  check_matrix(3, 0) = -2.0;
  check_matrix(3, 1) = 1.0;
  check_matrix(3, 2) = 5.0;

  S21Matrix matrix1_before = matrix1;
  S21Matrix matrix2_before = matrix2;
  S21Matrix result = matrix1;
  result += matrix2;

  EXPECT_EQ(result.GetRows(), 4);
  EXPECT_EQ(result.GetCols(), 3);

  EXPECT_TRUE(result == check_matrix);
  EXPECT_TRUE(matrix1_before == matrix1);
  EXPECT_TRUE(matrix2_before == matrix2);
}

TEST(TestSum, TestSumOperation4) {
  S21Matrix matrix1{2, 2};
  EXPECT_EQ(matrix1.GetRows(), 2);
  EXPECT_EQ(matrix1.GetCols(), 2);

  S21Matrix matrix2{2, 2};
  EXPECT_EQ(matrix2.GetRows(), 2);
  EXPECT_EQ(matrix2.GetCols(), 2);

  S21Matrix check_matrix{2, 2};
  EXPECT_EQ(matrix2.GetRows(), 2);
  EXPECT_EQ(matrix2.GetCols(), 2);

  matrix1(0, 0) = 145678000.588;
  matrix1(0, 1) = -4542;
  matrix1(1, 0) = 673552.54545324;
  matrix1(1, 1) = 145678000.588;

  matrix2(0, 0) = 14567800.777;
  matrix2(0, 1) = -4542;
  matrix2(1, 0) = 3.0;
  matrix2(1, 1) = 0.0;

  check_matrix(0, 0) = 160245801.365;
  check_matrix(0, 1) = -9084;
  check_matrix(1, 0) = 673555.54545324;
  check_matrix(1, 1) = 145678000.588;

  S21Matrix matrix1_before = matrix1;
  S21Matrix matrix2_before = matrix2;
  S21Matrix result = matrix1;
  result += matrix2;

  EXPECT_EQ(result.GetRows(), 2);
  EXPECT_EQ(result.GetCols(), 2);

  EXPECT_TRUE(result == check_matrix);
  EXPECT_TRUE(matrix1_before == matrix1);
  EXPECT_TRUE(matrix2_before == matrix2);
}

TEST(TestSum, TestSumOperation5) {
  S21Matrix matrix1{1, 1};
  EXPECT_EQ(matrix1.GetRows(), 1);
  EXPECT_EQ(matrix1.GetCols(), 1);

  S21Matrix matrix2{1, 1};
  EXPECT_EQ(matrix2.GetRows(), 1);
  EXPECT_EQ(matrix2.GetCols(), 1);

  S21Matrix check_matrix{1, 1};
  EXPECT_EQ(matrix2.GetRows(), 1);
  EXPECT_EQ(matrix2.GetCols(), 1);

  matrix1(0, 0) = 1.0;
  matrix2(0, 0) = 0.5;
  check_matrix(0, 0) = 1.5;

  S21Matrix matrix1_before = matrix1;
  S21Matrix matrix2_before = matrix2;
  S21Matrix result1 = matrix1;
  S21Matrix result2 = matrix1 + matrix2;
  result1 += matrix2;

  EXPECT_EQ(result1.GetRows(), 1);
  EXPECT_EQ(result1.GetCols(), 1);
  EXPECT_TRUE(result1 == check_matrix);

  EXPECT_EQ(result2.GetRows(), 1);
  EXPECT_EQ(result2.GetCols(), 1);
  EXPECT_TRUE(result2 == check_matrix);

  EXPECT_TRUE(matrix1_before == matrix1);
  EXPECT_TRUE(matrix2_before == matrix2);
}

TEST(TestTranspose, TestTranspose1) {
  S21Matrix matrix1{7, 7};
  EXPECT_EQ(matrix1.GetRows(), 7);
  EXPECT_EQ(matrix1.GetCols(), 7);

  S21Matrix result_check{7, 7};
  EXPECT_EQ(result_check.GetRows(), 7);
  EXPECT_EQ(result_check.GetCols(), 7);

  matrix1(0, 0) = 1.91308;
  matrix1(0, 1) = 0.60095;
  matrix1(0, 2) = -0.44777;
  matrix1(0, 3) = -0.50040;
  matrix1(0, 4) = -1.12823;
  matrix1(0, 5) = -1.81865;
  matrix1(0, 6) = -0.70084;
  matrix1(1, 0) = 1.95162;
  matrix1(1, 1) = 1.16720;
  matrix1(1, 2) = 1.28391;
  matrix1(1, 3) = -1.83298;
  matrix1(1, 4) = 1.30395;
  matrix1(1, 5) = -1.94659;
  matrix1(1, 6) = 0.92036;
  matrix1(2, 0) = -1.49041;
  matrix1(2, 1) = 1.08027;
  matrix1(2, 2) = 1.69253;
  matrix1(2, 3) = 0.59772;
  matrix1(2, 4) = 0.36828;
  matrix1(2, 5) = -0.47550;
  matrix1(2, 6) = 0.17188;
  matrix1(3, 0) = -0.41712;
  matrix1(3, 1) = -0.57195;
  matrix1(3, 2) = -1.52959;
  matrix1(3, 3) = 0.79822;
  matrix1(3, 4) = -0.81870;
  matrix1(3, 5) = -0.71609;
  matrix1(3, 6) = -1.58015;
  matrix1(4, 0) = -0.90661;
  matrix1(4, 1) = -0.09334;
  matrix1(4, 2) = 0.63205;
  matrix1(4, 3) = 1.27734;
  matrix1(4, 4) = 0.34700;
  matrix1(4, 5) = -0.91391;
  matrix1(4, 6) = 0.63581;
  matrix1(5, 0) = 1.30982;
  matrix1(5, 1) = 1.27461;
  matrix1(5, 2) = 0.56120;
  matrix1(5, 3) = -0.54912;
  matrix1(5, 4) = 1.28915;
  matrix1(5, 5) = 0.63719;
  matrix1(5, 6) = 0.38849;
  matrix1(6, 0) = -0.53430;
  matrix1(6, 1) = -0.10767;
  matrix1(6, 2) = 1.19456;
  matrix1(6, 3) = 0.05376;
  matrix1(6, 4) = 0.83746;
  matrix1(6, 5) = -0.85603;
  matrix1(6, 6) = -0.73690;

  result_check(0, 0) = 1.91308;
  result_check(0, 1) = 1.95162;
  result_check(0, 2) = -1.49041;
  result_check(0, 3) = -0.41712;
  result_check(0, 4) = -0.90661;
  result_check(0, 5) = 1.30982;
  result_check(0, 6) = -0.5343;
  result_check(1, 0) = 0.60095;
  result_check(1, 1) = 1.1672;
  result_check(1, 2) = 1.08027;
  result_check(1, 3) = -0.57195;
  result_check(1, 4) = -0.09334;
  result_check(1, 5) = 1.27461;
  result_check(1, 6) = -0.10767;
  result_check(2, 0) = -0.44777;
  result_check(2, 1) = 1.28391;
  result_check(2, 2) = 1.69253;
  result_check(2, 3) = -1.52959;
  result_check(2, 4) = 0.63205;
  result_check(2, 5) = 0.56120;
  result_check(2, 6) = 1.19456;
  result_check(3, 0) = -0.5004;
  result_check(3, 1) = -1.83298;
  result_check(3, 2) = 0.59772;
  result_check(3, 3) = 0.79822;
  result_check(3, 4) = 1.27734;
  result_check(3, 5) = -0.54912;
  result_check(3, 6) = 0.05376;
  result_check(4, 0) = -1.12823;
  result_check(4, 1) = 1.30395;
  result_check(4, 2) = 0.36828;
  result_check(4, 3) = -0.81870;
  result_check(4, 4) = 0.347;
  result_check(4, 5) = 1.28915;
  result_check(4, 6) = 0.83746;
  result_check(5, 0) = -1.81865;
  result_check(5, 1) = -1.94659;
  result_check(5, 2) = -0.47550;
  result_check(5, 3) = -0.71609;
  result_check(5, 4) = -0.91391;
  result_check(5, 5) = 0.63719;
  result_check(5, 6) = -0.85603;
  result_check(6, 0) = -0.70084;
  result_check(6, 1) = 0.92036;
  result_check(6, 2) = 0.17188;
  result_check(6, 3) = -1.58015;
  result_check(6, 4) = 0.63581;
  result_check(6, 5) = 0.38849;
  result_check(6, 6) = -0.73690;

  S21Matrix matrix_before = matrix1;
  S21Matrix result = matrix1.Transpose();

  EXPECT_TRUE(result == result_check);
  EXPECT_TRUE(matrix1 == matrix_before);
}

TEST(TestSub, TestSubFunctionException1) {
  S21Matrix matrix1{2, 2};
  S21Matrix matrix2{2, 3};

  S21Matrix matrix1_before = matrix1;
  S21Matrix matrix2_before = matrix2;

  EXPECT_ANY_THROW(matrix1.SubMatrix(matrix2));
  EXPECT_ANY_THROW(matrix2.SubMatrix(matrix1));
  EXPECT_TRUE(matrix1 == matrix1_before);
  EXPECT_TRUE(matrix2 == matrix2_before);
}

TEST(TestSub, TestSubFunctionException2) {
  S21Matrix matrix1{2, 2};
  S21Matrix matrix2{3, 2};

  S21Matrix matrix1_before = matrix1;
  S21Matrix matrix2_before = matrix2;

  EXPECT_ANY_THROW(matrix1.SubMatrix(matrix2));
  EXPECT_ANY_THROW(matrix2.SubMatrix(matrix1));
  EXPECT_TRUE(matrix1 == matrix1_before);
  EXPECT_TRUE(matrix2 == matrix2_before);
}

TEST(TestSub, TestSubFunctionException3) {
  S21Matrix matrix1{3, 2};
  S21Matrix matrix2{2, 2};

  S21Matrix matrix1_before = matrix1;
  S21Matrix matrix2_before = matrix2;

  EXPECT_ANY_THROW(matrix1.SubMatrix(matrix2));
  EXPECT_ANY_THROW(matrix2.SubMatrix(matrix1));
  EXPECT_TRUE(matrix1 == matrix1_before);
  EXPECT_TRUE(matrix2 == matrix2_before);
}

TEST(TestSub, TestSubFunctionException4) {
  S21Matrix matrix1{2, 3};
  S21Matrix matrix2{2, 2};

  S21Matrix matrix1_before = matrix1;
  S21Matrix matrix2_before = matrix2;

  EXPECT_ANY_THROW(matrix1.SubMatrix(matrix2));
  EXPECT_ANY_THROW(matrix2.SubMatrix(matrix1));
  EXPECT_TRUE(matrix1 == matrix1_before);
  EXPECT_TRUE(matrix2 == matrix2_before);
}

TEST(TestSub, TestSubOperatorException1) {
  S21Matrix matrix1{2, 2};
  S21Matrix matrix2{2, 3};

  S21Matrix matrix1_before = matrix1;
  S21Matrix matrix2_before = matrix2;

  EXPECT_ANY_THROW(matrix1 - matrix2);
  EXPECT_ANY_THROW(matrix2 - matrix1);
  EXPECT_TRUE(matrix1 == matrix1_before);
  EXPECT_TRUE(matrix2 == matrix2_before);
}

TEST(TestSub, TestSubOperatorException2) {
  S21Matrix matrix1{2, 2};
  S21Matrix matrix2{3, 2};

  S21Matrix matrix1_before = matrix1;
  S21Matrix matrix2_before = matrix2;

  EXPECT_ANY_THROW(matrix1 - matrix2);
  EXPECT_ANY_THROW(matrix2 - matrix1);
  EXPECT_TRUE(matrix1 == matrix1_before);
  EXPECT_TRUE(matrix2 == matrix2_before);
}

TEST(TestSub, TestSubOperatorException3) {
  S21Matrix matrix1{3, 2};
  S21Matrix matrix2{2, 2};

  S21Matrix matrix1_before = matrix1;
  S21Matrix matrix2_before = matrix2;

  EXPECT_ANY_THROW(matrix1 - matrix2);
  EXPECT_ANY_THROW(matrix2 - matrix1);
  EXPECT_TRUE(matrix1 == matrix1_before);
  EXPECT_TRUE(matrix2 == matrix2_before);
}

TEST(TestSub, TestSubOperatorException4) {
  S21Matrix matrix1{2, 3};
  S21Matrix matrix2{2, 2};

  S21Matrix matrix1_before = matrix1;
  S21Matrix matrix2_before = matrix2;

  EXPECT_ANY_THROW(matrix1 - matrix2);
  EXPECT_ANY_THROW(matrix2 - matrix1);
  EXPECT_TRUE(matrix1 == matrix1_before);
  EXPECT_TRUE(matrix2 == matrix2_before);
}

TEST(TestSub, TestSubOperatorException5) {
  S21Matrix matrix1{2, 2};
  S21Matrix matrix2{2, 3};

  S21Matrix matrix1_before = matrix1;
  S21Matrix matrix2_before = matrix2;

  EXPECT_ANY_THROW(matrix1 -= matrix2);
  EXPECT_ANY_THROW(matrix2 -= matrix1);
  EXPECT_TRUE(matrix1 == matrix1_before);
  EXPECT_TRUE(matrix2 == matrix2_before);
}

TEST(TestSub, TestSubOperatorException6) {
  S21Matrix matrix1{2, 2};
  S21Matrix matrix2{3, 2};

  S21Matrix matrix1_before = matrix1;
  S21Matrix matrix2_before = matrix2;

  EXPECT_ANY_THROW(matrix1 -= matrix2);
  EXPECT_ANY_THROW(matrix2 -= matrix1);
  EXPECT_TRUE(matrix1 == matrix1_before);
  EXPECT_TRUE(matrix2 == matrix2_before);
}

TEST(TestSub, TestSubOperatorException7) {
  S21Matrix matrix1{3, 2};
  S21Matrix matrix2{2, 2};

  S21Matrix matrix1_before = matrix1;
  S21Matrix matrix2_before = matrix2;

  EXPECT_ANY_THROW(matrix1 -= matrix2);
  EXPECT_ANY_THROW(matrix2 -= matrix1);
  EXPECT_TRUE(matrix1 == matrix1_before);
  EXPECT_TRUE(matrix2 == matrix2_before);
}

TEST(TestSub, TestSubOperatorException8) {
  S21Matrix matrix1{2, 3};
  S21Matrix matrix2{2, 2};

  S21Matrix matrix1_before = matrix1;
  S21Matrix matrix2_before = matrix2;

  EXPECT_ANY_THROW(matrix1 -= matrix2);
  EXPECT_ANY_THROW(matrix2 -= matrix1);
  EXPECT_TRUE(matrix1 == matrix1_before);
  EXPECT_TRUE(matrix2 == matrix2_before);
}

TEST(TestSub, TestSub1) {
  S21Matrix matrix1{4, 3};
  EXPECT_EQ(matrix1.GetRows(), 4);
  EXPECT_EQ(matrix1.GetCols(), 3);

  S21Matrix matrix2{4, 3};
  EXPECT_EQ(matrix2.GetRows(), 4);
  EXPECT_EQ(matrix2.GetCols(), 3);

  S21Matrix check_matrix{4, 3};
  EXPECT_EQ(matrix2.GetRows(), 4);
  EXPECT_EQ(matrix2.GetCols(), 3);

  matrix1(0, 0) = 1.5;
  matrix1(0, 1) = 2.5;
  matrix1(0, 2) = 3.5;
  matrix1(1, 0) = -1.5;
  matrix1(1, 1) = -2.5;
  matrix1(1, 2) = -3.5;
  matrix1(2, 0) = 0.0;
  matrix1(2, 1) = 0.0;
  matrix1(2, 2) = 0.0;
  matrix1(3, 0) = 1.0;
  matrix1(3, 1) = 1.0;
  matrix1(3, 2) = 1.0;

  matrix2(0, 0) = 0.0;
  matrix2(0, 1) = 1.0;
  matrix2(0, 2) = 2.0;
  matrix2(1, 0) = 3.0;
  matrix2(1, 1) = 0.0;
  matrix2(1, 2) = 4.0;
  matrix2(2, 0) = -1.0;
  matrix2(2, 1) = -2.0;
  matrix2(2, 2) = 0.0;
  matrix2(3, 0) = -3.0;
  matrix2(3, 1) = 0.0;
  matrix2(3, 2) = 4.0;

  check_matrix(0, 0) = 1.5;
  check_matrix(0, 1) = 1.5;
  check_matrix(0, 2) = 1.5;
  check_matrix(1, 0) = -4.5;
  check_matrix(1, 1) = -2.5;
  check_matrix(1, 2) = -7.5;
  check_matrix(2, 0) = 1.0;
  check_matrix(2, 1) = 2.0;
  check_matrix(2, 2) = 0.0;
  check_matrix(3, 0) = 4.0;
  check_matrix(3, 1) = 1.0;
  check_matrix(3, 2) = -3.0;

  matrix1.SubMatrix(matrix2);

  EXPECT_TRUE(matrix1 == check_matrix);
}

TEST(TestSub, TestSub2) {
  S21Matrix matrix1{2, 2};
  EXPECT_EQ(matrix1.GetRows(), 2);
  EXPECT_EQ(matrix1.GetCols(), 2);

  S21Matrix matrix2{2, 2};
  EXPECT_EQ(matrix2.GetRows(), 2);
  EXPECT_EQ(matrix2.GetCols(), 2);

  S21Matrix check_matrix{2, 2};
  EXPECT_EQ(matrix2.GetRows(), 2);
  EXPECT_EQ(matrix2.GetCols(), 2);

  matrix1(0, 0) = 145678000.588;
  matrix1(0, 1) = -4542;
  matrix1(1, 0) = 673552.54545324;
  matrix1(1, 1) = 145678000.588;

  matrix2(0, 0) = 14567800.777;
  matrix2(0, 1) = -4542;
  matrix2(1, 0) = 3.0;
  matrix2(1, 1) = 0.0;

  check_matrix(0, 0) = 131110199.811;
  check_matrix(0, 1) = 0.0;
  check_matrix(1, 0) = 673549.54545324;
  check_matrix(1, 1) = 145678000.588;

  matrix1.SubMatrix(matrix2);

  EXPECT_TRUE(matrix1 == check_matrix);
}

TEST(TestSub, TestSubOperation1) {
  S21Matrix matrix1{4, 3};
  EXPECT_EQ(matrix1.GetRows(), 4);
  EXPECT_EQ(matrix1.GetCols(), 3);

  S21Matrix matrix2{4, 3};
  EXPECT_EQ(matrix2.GetRows(), 4);
  EXPECT_EQ(matrix2.GetCols(), 3);

  S21Matrix check_matrix{4, 3};
  EXPECT_EQ(matrix2.GetRows(), 4);
  EXPECT_EQ(matrix2.GetCols(), 3);

  matrix1(0, 0) = 1.5;
  matrix1(0, 1) = 2.5;
  matrix1(0, 2) = 3.5;
  matrix1(1, 0) = -1.5;
  matrix1(1, 1) = -2.5;
  matrix1(1, 2) = -3.5;
  matrix1(2, 0) = 0.0;
  matrix1(2, 1) = 0.0;
  matrix1(2, 2) = 0.0;
  matrix1(3, 0) = 1.0;
  matrix1(3, 1) = 1.0;
  matrix1(3, 2) = 1.0;

  matrix2(0, 0) = 0.0;
  matrix2(0, 1) = 1.0;
  matrix2(0, 2) = 2.0;
  matrix2(1, 0) = 3.0;
  matrix2(1, 1) = 0.0;
  matrix2(1, 2) = 4.0;
  matrix2(2, 0) = -1.0;
  matrix2(2, 1) = -2.0;
  matrix2(2, 2) = 0.0;
  matrix2(3, 0) = -3.0;
  matrix2(3, 1) = 0.0;
  matrix2(3, 2) = 4.0;

  check_matrix(0, 0) = 1.5;
  check_matrix(0, 1) = 1.5;
  check_matrix(0, 2) = 1.5;
  check_matrix(1, 0) = -4.5;
  check_matrix(1, 1) = -2.5;
  check_matrix(1, 2) = -7.5;
  check_matrix(2, 0) = 1.0;
  check_matrix(2, 1) = 2.0;
  check_matrix(2, 2) = 0.0;
  check_matrix(3, 0) = 4.0;
  check_matrix(3, 1) = 1.0;
  check_matrix(3, 2) = -3.0;

  S21Matrix matrix1_before = matrix1;
  S21Matrix matrix2_before = matrix2;
  S21Matrix result = matrix1 - matrix2;

  EXPECT_EQ(result.GetRows(), 4);
  EXPECT_EQ(result.GetCols(), 3);

  EXPECT_TRUE(result == check_matrix);
  EXPECT_TRUE(matrix1_before == matrix1);
  EXPECT_TRUE(matrix2_before == matrix2);
}

TEST(TestSub, TestSubOperation2) {
  S21Matrix matrix1{2, 2};
  EXPECT_EQ(matrix1.GetRows(), 2);
  EXPECT_EQ(matrix1.GetCols(), 2);

  S21Matrix matrix2{2, 2};
  EXPECT_EQ(matrix2.GetRows(), 2);
  EXPECT_EQ(matrix2.GetCols(), 2);

  S21Matrix check_matrix{2, 2};
  EXPECT_EQ(matrix2.GetRows(), 2);
  EXPECT_EQ(matrix2.GetCols(), 2);

  matrix1(0, 0) = 145678000.588;
  matrix1(0, 1) = -4542;
  matrix1(1, 0) = 673552.54545324;
  matrix1(1, 1) = 145678000.588;

  matrix2(0, 0) = 14567800.777;
  matrix2(0, 1) = -4542;
  matrix2(1, 0) = 3.0;
  matrix2(1, 1) = 0.0;

  check_matrix(0, 0) = 131110199.811;
  check_matrix(0, 1) = 0.0;
  check_matrix(1, 0) = 673549.54545324;
  check_matrix(1, 1) = 145678000.588;

  S21Matrix matrix1_before = matrix1;
  S21Matrix matrix2_before = matrix2;
  S21Matrix result = matrix1 - matrix2;

  EXPECT_EQ(result.GetRows(), 2);
  EXPECT_EQ(result.GetCols(), 2);

  EXPECT_TRUE(result == check_matrix);
  EXPECT_TRUE(matrix1_before == matrix1);
  EXPECT_TRUE(matrix2_before == matrix2);
}

TEST(TestSub, TestSubOperation3) {
  S21Matrix matrix1{4, 3};
  EXPECT_EQ(matrix1.GetRows(), 4);
  EXPECT_EQ(matrix1.GetCols(), 3);

  S21Matrix matrix2{4, 3};
  EXPECT_EQ(matrix2.GetRows(), 4);
  EXPECT_EQ(matrix2.GetCols(), 3);

  S21Matrix check_matrix{4, 3};
  EXPECT_EQ(matrix2.GetRows(), 4);
  EXPECT_EQ(matrix2.GetCols(), 3);

  matrix1(0, 0) = 1.5;
  matrix1(0, 1) = 2.5;
  matrix1(0, 2) = 3.5;
  matrix1(1, 0) = -1.5;
  matrix1(1, 1) = -2.5;
  matrix1(1, 2) = -3.5;
  matrix1(2, 0) = 0.0;
  matrix1(2, 1) = 0.0;
  matrix1(2, 2) = 0.0;
  matrix1(3, 0) = 1.0;
  matrix1(3, 1) = 1.0;
  matrix1(3, 2) = 1.0;

  matrix2(0, 0) = 0.0;
  matrix2(0, 1) = 1.0;
  matrix2(0, 2) = 2.0;
  matrix2(1, 0) = 3.0;
  matrix2(1, 1) = 0.0;
  matrix2(1, 2) = 4.0;
  matrix2(2, 0) = -1.0;
  matrix2(2, 1) = -2.0;
  matrix2(2, 2) = 0.0;
  matrix2(3, 0) = -3.0;
  matrix2(3, 1) = 0.0;
  matrix2(3, 2) = 4.0;

  check_matrix(0, 0) = 1.5;
  check_matrix(0, 1) = 1.5;
  check_matrix(0, 2) = 1.5;
  check_matrix(1, 0) = -4.5;
  check_matrix(1, 1) = -2.5;
  check_matrix(1, 2) = -7.5;
  check_matrix(2, 0) = 1.0;
  check_matrix(2, 1) = 2.0;
  check_matrix(2, 2) = 0.0;
  check_matrix(3, 0) = 4.0;
  check_matrix(3, 1) = 1.0;
  check_matrix(3, 2) = -3.0;

  S21Matrix matrix1_before = matrix1;
  S21Matrix matrix2_before = matrix2;
  S21Matrix result = matrix1;
  result -= matrix2;

  EXPECT_EQ(result.GetRows(), 4);
  EXPECT_EQ(result.GetCols(), 3);

  EXPECT_TRUE(result == check_matrix);
  EXPECT_TRUE(matrix1_before == matrix1);
  EXPECT_TRUE(matrix2_before == matrix2);
}

TEST(TestSub, TestSubOperation4) {
  S21Matrix matrix1{2, 2};
  EXPECT_EQ(matrix1.GetRows(), 2);
  EXPECT_EQ(matrix1.GetCols(), 2);

  S21Matrix matrix2{2, 2};
  EXPECT_EQ(matrix2.GetRows(), 2);
  EXPECT_EQ(matrix2.GetCols(), 2);

  S21Matrix check_matrix{2, 2};
  EXPECT_EQ(matrix2.GetRows(), 2);
  EXPECT_EQ(matrix2.GetCols(), 2);

  matrix1(0, 0) = 145678000.588;
  matrix1(0, 1) = -4542;
  matrix1(1, 0) = 673552.54545324;
  matrix1(1, 1) = 145678000.588;

  matrix2(0, 0) = 14567800.777;
  matrix2(0, 1) = -4542;
  matrix2(1, 0) = 3.0;
  matrix2(1, 1) = 0.0;

  check_matrix(0, 0) = 131110199.811;
  check_matrix(0, 1) = 0.0;
  check_matrix(1, 0) = 673549.54545324;
  check_matrix(1, 1) = 145678000.588;

  S21Matrix matrix1_before = matrix1;
  S21Matrix matrix2_before = matrix2;
  S21Matrix result = matrix1;
  result -= matrix2;

  EXPECT_EQ(result.GetRows(), 2);
  EXPECT_EQ(result.GetCols(), 2);

  EXPECT_TRUE(result == check_matrix);
  EXPECT_TRUE(matrix1_before == matrix1);
  EXPECT_TRUE(matrix2_before == matrix2);
}

TEST(TestSub, TestSubOperation5) {
  S21Matrix matrix1{1, 1};
  EXPECT_EQ(matrix1.GetRows(), 1);
  EXPECT_EQ(matrix1.GetCols(), 1);

  S21Matrix matrix2{1, 1};
  EXPECT_EQ(matrix2.GetRows(), 1);
  EXPECT_EQ(matrix2.GetCols(), 1);

  S21Matrix check_matrix{1, 1};
  EXPECT_EQ(matrix2.GetRows(), 1);
  EXPECT_EQ(matrix2.GetCols(), 1);

  matrix1(0, 0) = 1.0;
  matrix2(0, 0) = 0.5;
  check_matrix(0, 0) = 0.5;

  S21Matrix matrix1_before = matrix1;
  S21Matrix matrix2_before = matrix2;
  S21Matrix result1 = matrix1;
  S21Matrix result2 = matrix1 - matrix2;
  result1 -= matrix2;

  EXPECT_EQ(result1.GetRows(), 1);
  EXPECT_EQ(result1.GetCols(), 1);
  EXPECT_TRUE(result1 == check_matrix);

  EXPECT_EQ(result2.GetRows(), 1);
  EXPECT_EQ(result2.GetCols(), 1);
  EXPECT_TRUE(result2 == check_matrix);

  EXPECT_TRUE(matrix1_before == matrix1);
  EXPECT_TRUE(matrix2_before == matrix2);
}

TEST(TestOperatorBrackets, TestOperatorBracketsException1) {
  S21Matrix matrix_check{99, 99};
  EXPECT_ANY_THROW(matrix_check(100, 99));
}

TEST(TestOperatorBrackets, TestOperatorBracketsException2) {
  S21Matrix matrix_check{99, 99};
  EXPECT_ANY_THROW(matrix_check(99, 100));
}

TEST(TestOperatorBrackets, TestOperatorBracketsException3) {
  S21Matrix matrix_check{99, 99};
  EXPECT_ANY_THROW(matrix_check(100, 100));
}

TEST(TestOperatorBrackets, TestOperatorBracketsException4) {
  S21Matrix matrix_check{5, 5};
  EXPECT_ANY_THROW(matrix_check(6, 5));
}

TEST(TestOperatorBrackets, TestOperatorBracketsException5) {
  S21Matrix matrix_check{5, 5};
  EXPECT_ANY_THROW(matrix_check(5, 6));
}

TEST(TestOperatorBrackets, TestOperatorBracketsException6) {
  S21Matrix matrix_check{5, 5};
  EXPECT_ANY_THROW(matrix_check(999, 999));
}

TEST(TestOperatorBrackets, TestOperatorBracketsException7) {
  S21Matrix matrix_check{5, 5};
  EXPECT_ANY_THROW(matrix_check(-1, 0));
}

TEST(TestOperatorBrackets, TestOperatorBracketsException8) {
  S21Matrix matrix_check{5, 5};
  EXPECT_ANY_THROW(matrix_check(0, -1));
}

TEST(TestOperatorBrackets, TestOperatorBracketsException9) {
  S21Matrix matrix_check{5, 5};
  EXPECT_ANY_THROW(matrix_check(-1, -1));
}

TEST(TestOperatorBrackets, TestOperatorBracketsException10) {
  S21Matrix matrix_check{5, 5};
  EXPECT_ANY_THROW(matrix_check(-99, -99));
}

TEST(TestMutators, TestMutatorsException1) {
  S21Matrix test_matrix(2, 3);
  S21Matrix matrix_before = test_matrix;

  EXPECT_ANY_THROW(test_matrix.SetRows(-1));
  EXPECT_TRUE(test_matrix == matrix_before);
}

TEST(TestMutators, TestMutatorsException2) {
  S21Matrix test_matrix(3, 2);
  S21Matrix matrix_before = test_matrix;

  EXPECT_ANY_THROW(test_matrix.SetRows(-1));
  EXPECT_TRUE(test_matrix == matrix_before);
}

TEST(TestMutators, TestMutatorsException3) {
  S21Matrix test_matrix(2, 3);
  S21Matrix matrix_before = test_matrix;

  EXPECT_ANY_THROW(test_matrix.SetCols(-1));
  EXPECT_TRUE(test_matrix == matrix_before);
}

TEST(TestMutators, TestMutatorsException4) {
  S21Matrix test_matrix(3, 2);
  S21Matrix matrix_before = test_matrix;

  EXPECT_ANY_THROW(test_matrix.SetCols(-1));
  EXPECT_TRUE(test_matrix == matrix_before);
}

TEST(TestMutators, TestMutatorsException5) {
  S21Matrix test_matrix(2, 2);
  S21Matrix matrix_before = test_matrix;

  EXPECT_ANY_THROW(test_matrix.SetCols(-9999));
  EXPECT_TRUE(test_matrix == matrix_before);
}

TEST(TestMutators, TestMutatorsException6) {
  S21Matrix test_matrix(3, 2);
  S21Matrix matrix_before = test_matrix;

  EXPECT_ANY_THROW(test_matrix.SetCols(-9999));
  EXPECT_TRUE(test_matrix == matrix_before);
}

TEST(TestMutators, TestMutators1) {
  S21Matrix matrix1{2, 2};
  EXPECT_EQ(matrix1.GetRows(), 2);
  EXPECT_EQ(matrix1.GetCols(), 2);

  matrix1(0, 0) = 1;
  matrix1(0, 1) = 2;
  matrix1(1, 0) = 3;
  matrix1(1, 1) = 4;

  matrix1.SetRows(1);

  EXPECT_EQ(matrix1.GetRows(), 1);
  EXPECT_EQ(matrix1.GetCols(), 2);

  EXPECT_NEAR(matrix1(0, 0), 1, 1e-7);
  EXPECT_NEAR(matrix1(0, 1), 2, 1e-7);
}

TEST(TestMutators, TestMutators2) {
  S21Matrix matrix1{2, 2};
  EXPECT_EQ(matrix1.GetRows(), 2);
  EXPECT_EQ(matrix1.GetCols(), 2);

  matrix1(0, 0) = 1;
  matrix1(0, 1) = 2;
  matrix1(1, 0) = 3;
  matrix1(1, 1) = 4;

  matrix1.SetCols(1);

  EXPECT_EQ(matrix1.GetRows(), 2);
  EXPECT_EQ(matrix1.GetCols(), 1);

  EXPECT_NEAR(matrix1(0, 0), 1, 1e-7);
  EXPECT_NEAR(matrix1(1, 0), 3, 1e-7);
}

TEST(TestMutators, TestMutators3) {
  S21Matrix matrix1{2, 2};
  EXPECT_EQ(matrix1.GetRows(), 2);
  EXPECT_EQ(matrix1.GetCols(), 2);

  matrix1(0, 0) = 1;
  matrix1(0, 1) = 2;
  matrix1(1, 0) = 3;
  matrix1(1, 1) = 4;

  matrix1.SetRows(3);

  EXPECT_EQ(matrix1.GetRows(), 3);
  EXPECT_EQ(matrix1.GetCols(), 2);

  EXPECT_NEAR(matrix1(0, 0), 1, 1e-7);
  EXPECT_NEAR(matrix1(0, 1), 2, 1e-7);
  EXPECT_NEAR(matrix1(1, 0), 3, 1e-7);
  EXPECT_NEAR(matrix1(1, 1), 4, 1e-7);
  EXPECT_NEAR(matrix1(2, 0), 0, 1e-7);
  EXPECT_NEAR(matrix1(2, 1), 0, 1e-7);
}

TEST(TestMutators, TestMutators4) {
  S21Matrix matrix1{2, 2};
  EXPECT_EQ(matrix1.GetRows(), 2);
  EXPECT_EQ(matrix1.GetCols(), 2);

  matrix1(0, 0) = 1;
  matrix1(0, 1) = 2;
  matrix1(1, 0) = 3;
  matrix1(1, 1) = 4;

  matrix1.SetCols(3);

  EXPECT_EQ(matrix1.GetRows(), 2);
  EXPECT_EQ(matrix1.GetCols(), 3);

  EXPECT_NEAR(matrix1(0, 0), 1, 1e-7);
  EXPECT_NEAR(matrix1(0, 1), 2, 1e-7);
  EXPECT_NEAR(matrix1(0, 2), 0, 1e-7);
  EXPECT_NEAR(matrix1(1, 0), 3, 1e-7);
  EXPECT_NEAR(matrix1(1, 1), 4, 1e-7);
  EXPECT_NEAR(matrix1(1, 2), 0, 1e-7);
}

TEST(TestMulNumber, TestMulNumber1) {
  S21Matrix matrix1{4, 3};
  EXPECT_EQ(matrix1.GetRows(), 4);
  EXPECT_EQ(matrix1.GetCols(), 3);

  S21Matrix check_matrix = matrix1;
  EXPECT_EQ(check_matrix.GetRows(), 4);
  EXPECT_EQ(check_matrix.GetCols(), 3);

  double number = 1.99;

  matrix1(0, 0) = 1.5;
  matrix1(0, 1) = 2.5;
  matrix1(0, 2) = 3.5;
  matrix1(1, 0) = -1.5;
  matrix1(1, 1) = -2.5;
  matrix1(1, 2) = -3.5;
  matrix1(2, 0) = 0.0;
  matrix1(2, 1) = 0.0;
  matrix1(2, 2) = 0.0;
  matrix1(3, 0) = 1.0;
  matrix1(3, 1) = 1.0;
  matrix1(3, 2) = 1.0;

  check_matrix(0, 0) = 2.985;
  check_matrix(0, 1) = 4.975;
  check_matrix(0, 2) = 6.965;
  check_matrix(1, 0) = -2.985;
  check_matrix(1, 1) = -4.975;
  check_matrix(1, 2) = -6.965;
  check_matrix(2, 0) = 0.0;
  check_matrix(2, 1) = 0.0;
  check_matrix(2, 2) = 0.0;
  check_matrix(3, 0) = 1.99;
  check_matrix(3, 1) = 1.99;
  check_matrix(3, 2) = 1.99;

  matrix1.MulNumber(number);

  EXPECT_TRUE(matrix1 == check_matrix);
}

TEST(TestMulNumber, TestMulNumber2) {
  S21Matrix matrix1{2, 2};
  EXPECT_EQ(matrix1.GetRows(), 2);
  EXPECT_EQ(matrix1.GetCols(), 2);

  S21Matrix check_matrix = matrix1;
  EXPECT_EQ(check_matrix.GetRows(), 2);
  EXPECT_EQ(check_matrix.GetCols(), 2);

  double number = -9.87;

  matrix1(0, 0) = 145678000.588;
  matrix1(0, 1) = -4542;
  matrix1(1, 0) = 673552.54545324;
  matrix1(1, 1) = 145678000.588;

  check_matrix(0, 0) = -1437841865.8035598;
  check_matrix(0, 1) = 44829.54;
  check_matrix(1, 0) = -6647963.6236234788;
  check_matrix(1, 1) = -1437841865.80355978;

  matrix1.MulNumber(number);

  EXPECT_TRUE(matrix1 == check_matrix);
}

TEST(TestMulNumber, TestMulNumberOperator1) {
  S21Matrix matrix1{4, 3};
  EXPECT_EQ(matrix1.GetRows(), 4);
  EXPECT_EQ(matrix1.GetCols(), 3);

  S21Matrix check_matrix = matrix1;
  EXPECT_EQ(check_matrix.GetRows(), 4);
  EXPECT_EQ(check_matrix.GetCols(), 3);

  double number = 1.99;

  matrix1(0, 0) = 1.5;
  matrix1(0, 1) = 2.5;
  matrix1(0, 2) = 3.5;
  matrix1(1, 0) = -1.5;
  matrix1(1, 1) = -2.5;
  matrix1(1, 2) = -3.5;
  matrix1(2, 0) = 0.0;
  matrix1(2, 1) = 0.0;
  matrix1(2, 2) = 0.0;
  matrix1(3, 0) = 1.0;
  matrix1(3, 1) = 1.0;
  matrix1(3, 2) = 1.0;

  check_matrix(0, 0) = 2.985;
  check_matrix(0, 1) = 4.975;
  check_matrix(0, 2) = 6.965;
  check_matrix(1, 0) = -2.985;
  check_matrix(1, 1) = -4.975;
  check_matrix(1, 2) = -6.965;
  check_matrix(2, 0) = 0.0;
  check_matrix(2, 1) = 0.0;
  check_matrix(2, 2) = 0.0;
  check_matrix(3, 0) = 1.99;
  check_matrix(3, 1) = 1.99;
  check_matrix(3, 2) = 1.99;

  S21Matrix matrix1_before = matrix1;
  S21Matrix result1 = matrix1 * number;
  S21Matrix result3 = matrix1;
  result3 *= number;

  EXPECT_TRUE(result1 == check_matrix);
  EXPECT_TRUE(result3 == check_matrix);
  EXPECT_TRUE(matrix1 == matrix1_before);
}

TEST(TestMulNumber, TestMulNumberOperator2) {
  S21Matrix matrix1{2, 2};
  EXPECT_EQ(matrix1.GetRows(), 2);
  EXPECT_EQ(matrix1.GetCols(), 2);

  S21Matrix check_matrix = matrix1;
  EXPECT_EQ(check_matrix.GetRows(), 2);
  EXPECT_EQ(check_matrix.GetCols(), 2);

  double number = -9.87;

  matrix1(0, 0) = 145678000.588;
  matrix1(0, 1) = -4542;
  matrix1(1, 0) = 673552.54545324;
  matrix1(1, 1) = 145678000.588;

  check_matrix(0, 0) = -1437841865.8035598;
  check_matrix(0, 1) = 44829.54;
  check_matrix(1, 0) = -6647963.62362348;
  check_matrix(1, 1) = -1437841865.80355978;

  S21Matrix matrix1_before = matrix1;
  S21Matrix result1 = matrix1 * number;
  S21Matrix result3 = matrix1;
  result3 *= number;

  EXPECT_TRUE(result1 == check_matrix);
  EXPECT_TRUE(result3 == check_matrix);
  EXPECT_TRUE(matrix1 == matrix1_before);
}

TEST(TestMulMatrix, TestMulMatrixFunctionException1) {
  S21Matrix matrix1{3, 2};
  S21Matrix matrix2{3, 2};

  S21Matrix matrix1_before = matrix1;
  S21Matrix matrix2_before = matrix2;

  EXPECT_ANY_THROW(matrix1.MulMatrix(matrix2));
  EXPECT_ANY_THROW(matrix2.MulMatrix(matrix1));
  EXPECT_TRUE(matrix1 == matrix1_before);
  EXPECT_TRUE(matrix2 == matrix2_before);
}

TEST(TestMulMatrix, TestMulMatrixFunctionException2) {
  S21Matrix matrix1{2, 3};
  S21Matrix matrix2{2, 3};

  S21Matrix matrix1_before = matrix1;
  S21Matrix matrix2_before = matrix2;

  EXPECT_ANY_THROW(matrix1.MulMatrix(matrix2));
  EXPECT_ANY_THROW(matrix2.MulMatrix(matrix1));
  EXPECT_TRUE(matrix1 == matrix1_before);
  EXPECT_TRUE(matrix2 == matrix2_before);
}

TEST(TestMulMatrix, TestMulMatrixFunctionException3) {
  S21Matrix matrix1{2, 2};
  S21Matrix matrix2{3, 3};

  S21Matrix matrix1_before = matrix1;
  S21Matrix matrix2_before = matrix2;

  EXPECT_ANY_THROW(matrix1.MulMatrix(matrix2));
  EXPECT_ANY_THROW(matrix2.MulMatrix(matrix1));
  EXPECT_TRUE(matrix1 == matrix1_before);
  EXPECT_TRUE(matrix2 == matrix2_before);
}

TEST(TestMulMatrix, TestMulMatrixFunctionException4) {
  S21Matrix matrix1{3, 3};
  S21Matrix matrix2{2, 2};

  S21Matrix matrix1_before = matrix1;
  S21Matrix matrix2_before = matrix2;

  EXPECT_ANY_THROW(matrix1.MulMatrix(matrix2));
  EXPECT_ANY_THROW(matrix2.MulMatrix(matrix1));
  EXPECT_TRUE(matrix1 == matrix1_before);
  EXPECT_TRUE(matrix2 == matrix2_before);
}

TEST(TestMulMatrix, TestMulMatrixOperatorException1) {
  S21Matrix matrix1{3, 2};
  S21Matrix matrix2{3, 2};

  S21Matrix matrix1_before = matrix1;
  S21Matrix matrix2_before = matrix2;

  EXPECT_ANY_THROW(matrix1 * matrix2);
  EXPECT_ANY_THROW(matrix2 * matrix1);
  EXPECT_TRUE(matrix1 == matrix1_before);
  EXPECT_TRUE(matrix2 == matrix2_before);
}

TEST(TestMulMatrix, TestMulMatrixOperatorException2) {
  S21Matrix matrix1{2, 3};
  S21Matrix matrix2{2, 3};

  S21Matrix matrix1_before = matrix1;
  S21Matrix matrix2_before = matrix2;

  EXPECT_ANY_THROW(matrix1 * matrix2);
  EXPECT_ANY_THROW(matrix2 * matrix1);
  EXPECT_TRUE(matrix1 == matrix1_before);
  EXPECT_TRUE(matrix2 == matrix2_before);
}

TEST(TestMulMatrix, TestMulMatrixOperatorException3) {
  S21Matrix matrix1{3, 3};
  S21Matrix matrix2{2, 2};

  S21Matrix matrix1_before = matrix1;
  S21Matrix matrix2_before = matrix2;

  EXPECT_ANY_THROW(matrix1 * matrix2);
  EXPECT_ANY_THROW(matrix2 * matrix1);
  EXPECT_TRUE(matrix1 == matrix1_before);
  EXPECT_TRUE(matrix2 == matrix2_before);
}

TEST(TestMulMatrix, TestMulMatrixOperatorException4) {
  S21Matrix matrix1{2, 2};
  S21Matrix matrix2{3, 3};

  S21Matrix matrix1_before = matrix1;
  S21Matrix matrix2_before = matrix2;

  EXPECT_ANY_THROW(matrix1 * matrix2);
  EXPECT_ANY_THROW(matrix2 * matrix1);
  EXPECT_TRUE(matrix1 == matrix1_before);
  EXPECT_TRUE(matrix2 == matrix2_before);
}

TEST(TestMulMatrix, TestMulMatrixOperatorException5) {
  S21Matrix matrix1{3, 2};
  S21Matrix matrix2{3, 2};

  S21Matrix matrix1_before = matrix1;
  S21Matrix matrix2_before = matrix2;

  EXPECT_ANY_THROW(matrix1 *= matrix2);
  EXPECT_ANY_THROW(matrix2 *= matrix1);
  EXPECT_TRUE(matrix1 == matrix1_before);
  EXPECT_TRUE(matrix2 == matrix2_before);
}

TEST(TestMulMatrix, TestMulMatrixOperatorException6) {
  S21Matrix matrix1{2, 3};
  S21Matrix matrix2{2, 3};

  S21Matrix matrix1_before = matrix1;
  S21Matrix matrix2_before = matrix2;

  EXPECT_ANY_THROW(matrix1 *= matrix2);
  EXPECT_ANY_THROW(matrix2 *= matrix1);
  EXPECT_TRUE(matrix1 == matrix1_before);
  EXPECT_TRUE(matrix2 == matrix2_before);
}

TEST(TestMulMatrix, TestMulMatrixOperatorException7) {
  S21Matrix matrix1{3, 3};
  S21Matrix matrix2{2, 2};

  S21Matrix matrix1_before = matrix1;
  S21Matrix matrix2_before = matrix2;

  EXPECT_ANY_THROW(matrix1 *= matrix2);
  EXPECT_ANY_THROW(matrix2 *= matrix1);
  EXPECT_TRUE(matrix1 == matrix1_before);
  EXPECT_TRUE(matrix2 == matrix2_before);
}

TEST(TestMulMatrix, TestMulMatrixOperatorException8) {
  S21Matrix matrix1{2, 2};
  S21Matrix matrix2{3, 3};

  S21Matrix matrix1_before = matrix1;
  S21Matrix matrix2_before = matrix2;

  EXPECT_ANY_THROW(matrix1 *= matrix2);
  EXPECT_ANY_THROW(matrix2 *= matrix1);
  EXPECT_TRUE(matrix1 == matrix1_before);
  EXPECT_TRUE(matrix2 == matrix2_before);
}

TEST(TestMulMatrix, TestMulMatrix3) {
  S21Matrix matrix1{2, 2};
  EXPECT_EQ(matrix1.GetRows(), 2);
  EXPECT_EQ(matrix1.GetCols(), 2);

  S21Matrix matrix2{2, 2};
  EXPECT_EQ(matrix2.GetRows(), 2);
  EXPECT_EQ(matrix2.GetCols(), 2);

  S21Matrix check_matrix{2, 2};
  EXPECT_EQ(check_matrix.GetRows(), 2);
  EXPECT_EQ(check_matrix.GetCols(), 2);

  matrix1(0, 0) = 1;
  matrix1(0, 1) = 2;
  matrix1(1, 0) = 3;
  matrix1(1, 1) = 4;

  matrix2(0, 0) = 2;
  matrix2(0, 1) = 3;
  matrix2(1, 0) = 4;
  matrix2(1, 1) = 5;

  check_matrix(0, 0) = 10;
  check_matrix(0, 1) = 13;
  check_matrix(1, 0) = 22;
  check_matrix(1, 1) = 29;

  S21Matrix matrix2_before = matrix2;
  matrix1.MulMatrix(matrix2);

  EXPECT_EQ(matrix1.GetRows(), 2);
  EXPECT_EQ(matrix1.GetCols(), 2);

  ASSERT_TRUE(matrix1 == check_matrix);
  ASSERT_TRUE(matrix2 == matrix2_before);
}

TEST(TestMulMatrix, TestMulMatrix1) {
  S21Matrix matrix1{2, 3};
  EXPECT_EQ(matrix1.GetRows(), 2);
  EXPECT_EQ(matrix1.GetCols(), 3);

  S21Matrix matrix2{3, 2};
  EXPECT_EQ(matrix2.GetRows(), 3);
  EXPECT_EQ(matrix2.GetCols(), 2);

  S21Matrix check_matrix{2, 2};
  EXPECT_EQ(check_matrix.GetRows(), 2);
  EXPECT_EQ(check_matrix.GetCols(), 2);

  matrix1(0, 0) = 14567.588;
  matrix1(0, 1) = -4542;
  matrix1(0, 2) = -2.0;
  matrix1(1, 0) = 673.545453;
  matrix1(1, 1) = 14567.588;
  matrix1(1, 2) = 3.0;

  matrix2(0, 0) = 14567.777;
  matrix2(0, 1) = -4542;
  matrix2(1, 0) = 3.0;
  matrix2(1, 1) = 0.0;
  matrix2(2, 0) = 2.0;
  matrix2(2, 1) = -3.0;

  check_matrix(0, 0) = 212203743.411876;
  check_matrix(0, 1) = -66165978.696;
  check_matrix(1, 0) = 9855768.722667981;
  check_matrix(1, 1) = -3059252.447526;

  S21Matrix matrix2_before = matrix2;
  matrix1.MulMatrix(matrix2);

  EXPECT_EQ(matrix1.GetRows(), 2);
  EXPECT_EQ(matrix1.GetCols(), 2);

  ASSERT_TRUE(matrix1 == check_matrix);
  ASSERT_TRUE(matrix2 == matrix2_before);
}

TEST(TestMulMatrix, TestMulMatrix2) {
  S21Matrix matrix1{1, 1};
  EXPECT_EQ(matrix1.GetRows(), 1);
  EXPECT_EQ(matrix1.GetCols(), 1);

  S21Matrix matrix2{1, 1};
  EXPECT_EQ(matrix2.GetRows(), 1);
  EXPECT_EQ(matrix2.GetCols(), 1);

  S21Matrix check_matrix{1, 1};
  EXPECT_EQ(check_matrix.GetRows(), 1);
  EXPECT_EQ(check_matrix.GetCols(), 1);

  matrix1(0, 0) = 1.456;

  matrix2(0, 0) = 12.987;

  check_matrix(0, 0) = 18.909072;

  S21Matrix matrix2_before = matrix2;
  matrix1.MulMatrix(matrix2);

  EXPECT_EQ(matrix1.GetRows(), 1);
  EXPECT_EQ(matrix1.GetCols(), 1);

  ASSERT_TRUE(matrix1 == check_matrix);
  ASSERT_TRUE(matrix2 == matrix2_before);
}

TEST(TestMulMatrix, TestMulMatrixOperator1) {
  S21Matrix matrix1{1, 1};
  EXPECT_EQ(matrix1.GetRows(), 1);
  EXPECT_EQ(matrix1.GetCols(), 1);

  S21Matrix matrix2{1, 1};
  EXPECT_EQ(matrix2.GetRows(), 1);
  EXPECT_EQ(matrix2.GetCols(), 1);

  S21Matrix check_matrix{1, 1};
  EXPECT_EQ(check_matrix.GetRows(), 1);
  EXPECT_EQ(check_matrix.GetCols(), 1);

  matrix1(0, 0) = 1.456;

  matrix2(0, 0) = 12.987;

  check_matrix(0, 0) = 18.909072;

  S21Matrix matrix1_before = matrix1;
  S21Matrix matrix2_before = matrix2;

  S21Matrix result1 = matrix1 * matrix2;
  S21Matrix result2 = matrix1;
  result2 *= matrix2;

  ASSERT_TRUE(result1 == check_matrix);
  ASSERT_TRUE(result2 == check_matrix);
  ASSERT_TRUE(matrix1_before == matrix1);
  ASSERT_TRUE(matrix2_before == matrix2);
}

TEST(TestInverse, TestInverseException1) {
  S21Matrix test_matrix(2, 3);
  S21Matrix matrix_before = test_matrix;

  EXPECT_ANY_THROW(test_matrix.InverseMatrix());
  EXPECT_TRUE(test_matrix == matrix_before);
}

TEST(TestInverse, TestInverseException2) {
  S21Matrix test_matrix(3, 2);
  S21Matrix matrix_before = test_matrix;

  EXPECT_ANY_THROW(test_matrix.InverseMatrix());
  EXPECT_TRUE(test_matrix == matrix_before);
}

TEST(TestInverse, TestInverseException3) {
  S21Matrix test_matrix(1, 5);
  S21Matrix matrix_before = test_matrix;

  EXPECT_ANY_THROW(test_matrix.InverseMatrix());
  EXPECT_TRUE(test_matrix == matrix_before);
}

TEST(TestInverse, TestInverseException4) {
  S21Matrix test_matrix(5, 1);
  S21Matrix matrix_before = test_matrix;

  EXPECT_ANY_THROW(test_matrix.InverseMatrix());
  EXPECT_TRUE(test_matrix == matrix_before);
}

TEST(TestInverse, TestInverseZero1) {
  S21Matrix matrix1{1, 1};
  EXPECT_EQ(matrix1.GetCols(), 1);
  EXPECT_EQ(matrix1.GetRows(), 1);

  matrix1(0, 0) = 0.0;

  S21Matrix matrix_before = matrix1;

  EXPECT_ANY_THROW(matrix1.InverseMatrix());
  EXPECT_TRUE(matrix1 == matrix_before);
}

TEST(TestInverse, TestInverseZero2) {
  S21Matrix matrix1{3, 3};
  EXPECT_EQ(matrix1.GetCols(), 3);
  EXPECT_EQ(matrix1.GetRows(), 3);

  matrix1(0, 0) = 1.1;
  matrix1(0, 1) = 12;
  matrix1(0, 2) = 0.0;
  matrix1(1, 0) = 14;
  matrix1(1, 1) = 1.5;
  matrix1(1, 2) = 0.0;
  matrix1(2, 0) = 1.7;
  matrix1(2, 1) = 18;
  matrix1(2, 2) = 0.0;

  S21Matrix matrix_before = matrix1;

  EXPECT_ANY_THROW(matrix1.InverseMatrix());
  EXPECT_TRUE(matrix1 == matrix_before);
}

TEST(TestInverse, TestInverseZero3) {
  S21Matrix matrix1{3, 3};
  EXPECT_EQ(matrix1.GetCols(), 3);
  EXPECT_EQ(matrix1.GetRows(), 3);

  matrix1(0, 0) = 1.1;
  matrix1(0, 1) = 1.2;
  matrix1(0, 2) = 1.3;
  matrix1(1, 0) = 1.4;
  matrix1(1, 1) = 1.5;
  matrix1(1, 2) = 1.6;
  matrix1(2, 0) = 1.7;
  matrix1(2, 1) = 1.8;
  matrix1(2, 2) = 1.9;

  S21Matrix matrix_before = matrix1;

  EXPECT_ANY_THROW(matrix1.InverseMatrix());
  EXPECT_TRUE(matrix1 == matrix_before);
}

TEST(TestInverse, TestInverseZero4) {
  S21Matrix matrix1{3, 3};
  EXPECT_EQ(matrix1.GetCols(), 3);
  EXPECT_EQ(matrix1.GetRows(), 3);

  matrix1(0, 0) = -66;
  matrix1(0, 1) = -66;
  matrix1(0, 2) = -66;
  matrix1(1, 0) = -66;
  matrix1(1, 1) = -66;
  matrix1(1, 2) = -66;
  matrix1(2, 0) = -66;
  matrix1(2, 1) = -66;
  matrix1(2, 2) = -66;

  S21Matrix matrix_before = matrix1;

  EXPECT_ANY_THROW(matrix1.InverseMatrix());
  EXPECT_TRUE(matrix1 == matrix_before);
}

TEST(TestInverse, TestInverseZero5) {
  S21Matrix matrix1{1, 1};
  EXPECT_EQ(matrix1.GetCols(), 1);
  EXPECT_EQ(matrix1.GetRows(), 1);

  matrix1(0, 0) = 5;

  S21Matrix matrix_before = matrix1;
  S21Matrix result(1, 1);

  EXPECT_NO_THROW(result = matrix1.InverseMatrix());
  EXPECT_TRUE(matrix1 == matrix_before);
  EXPECT_EQ(0.2, result(0, 0));
}

TEST(TestEq, TestEq1) {
  S21Matrix matrix1{1, 1};
  S21Matrix matrix2{1, 1};

  matrix1(0, 0) = -1;
  matrix2(0, 0) = 2;
  EXPECT_FALSE(matrix1 == matrix2);
}

TEST(TestEq, TestEq2) {
  S21Matrix matrix1{1, 1};
  S21Matrix matrix2{1, 1};

  matrix1(0, 0) = 1;
  matrix2(0, 0) = -2;
  EXPECT_FALSE(matrix1 == matrix2);
}

TEST(TestEq, TestEq3) {
  S21Matrix matrix1{2, 2};
  EXPECT_EQ(matrix1.GetCols(), 2);
  EXPECT_EQ(matrix1.GetRows(), 2);

  S21Matrix matrix2{2, 2};
  EXPECT_EQ(matrix2.GetCols(), 2);
  EXPECT_EQ(matrix2.GetRows(), 2);

  bool result1 = matrix1.EqMatrix(matrix2);
  EXPECT_TRUE(result1);
  EXPECT_TRUE(matrix1 == matrix2);

  matrix1(0, 0) = 1;
  matrix1(0, 1) = 2;
  matrix1(1, 0) = 3;
  matrix1(1, 1) = 4;

  matrix2(0, 0) = 4;
  matrix2(0, 1) = 3;
  matrix2(1, 0) = 2;
  matrix2(1, 1) = 1;

  bool result2 = matrix1.EqMatrix(matrix2);
  EXPECT_FALSE(result2);
  EXPECT_FALSE(matrix1 == matrix2);
}

TEST(TestEq, TestEq4) {
  S21Matrix matrix1{2, 2};
  EXPECT_EQ(matrix1.GetCols(), 2);
  EXPECT_EQ(matrix1.GetRows(), 2);

  S21Matrix matrix2{2, 2};
  EXPECT_EQ(matrix2.GetCols(), 2);
  EXPECT_EQ(matrix2.GetRows(), 2);

  bool result1 = matrix1.EqMatrix(matrix2);
  EXPECT_TRUE(result1);
  EXPECT_TRUE(matrix1 == matrix2);

  matrix1(0, 0) = 1;
  matrix1(0, 1) = 2;
  matrix1(1, 0) = 3;
  matrix1(1, 1) = 4;

  matrix2(0, 0) = 1;
  matrix2(0, 1) = 2;
  matrix2(1, 0) = 3;
  matrix2(1, 1) = 4;

  bool result2 = matrix1.EqMatrix(matrix2);
  EXPECT_TRUE(result2);
  EXPECT_TRUE(matrix1 == matrix2);
}

TEST(TestEq, TestEq5) {
  S21Matrix matrix1{1, 1};
  EXPECT_EQ(matrix1.GetCols(), 1);
  EXPECT_EQ(matrix1.GetRows(), 1);

  S21Matrix matrix2{1, 1};
  EXPECT_EQ(matrix2.GetCols(), 1);
  EXPECT_EQ(matrix2.GetRows(), 1);

  bool result1 = matrix1.EqMatrix(matrix2);
  EXPECT_TRUE(result1);
  EXPECT_TRUE(matrix1 == matrix2);

  matrix1(0, 0) = 2.5;
  matrix2(0, 0) = 2.5;

  bool result2 = matrix1.EqMatrix(matrix2);
  EXPECT_TRUE(result2);
  EXPECT_TRUE(matrix1 == matrix2);

  matrix1(0, 0) = 2.5000001;
  matrix2(0, 0) = 2.5;

  bool result3 = matrix1.EqMatrix(matrix2);
  EXPECT_FALSE(result3);
  EXPECT_FALSE(matrix1 == matrix2);
}

TEST(TestEq, TestEq6) {
  S21Matrix matrix1{2, 2};
  EXPECT_EQ(matrix1.GetCols(), 2);
  EXPECT_EQ(matrix1.GetRows(), 2);

  S21Matrix matrix2{2, 2};
  EXPECT_EQ(matrix2.GetCols(), 2);
  EXPECT_EQ(matrix2.GetRows(), 2);

  matrix2(0, 0) = 0.0000001;

  bool result1 = matrix1.EqMatrix(matrix2);
  EXPECT_FALSE(result1);
  EXPECT_FALSE(matrix1 == matrix2);

  matrix1(0, 0) = 0.0000001;

  bool result2 = matrix1.EqMatrix(matrix2);
  EXPECT_TRUE(result2);
  EXPECT_TRUE(matrix1 == matrix2);
}

TEST(TestDeterminant, TestDeterminantException1) {
  S21Matrix test_matrix(2, 3);
  S21Matrix matrix_before = test_matrix;

  EXPECT_ANY_THROW(test_matrix.Determinant());
  EXPECT_TRUE(test_matrix == matrix_before);
}

TEST(TestDeterminant, TestDeterminantException2) {
  S21Matrix test_matrix(3, 2);
  S21Matrix matrix_before = test_matrix;

  EXPECT_ANY_THROW(test_matrix.Determinant());
  EXPECT_TRUE(test_matrix == matrix_before);
}

TEST(TestDeterminant, TestDeterminantException3) {
  S21Matrix test_matrix(55, 2);
  S21Matrix matrix_before = test_matrix;

  EXPECT_ANY_THROW(test_matrix.Determinant());
  EXPECT_TRUE(test_matrix == matrix_before);
}

TEST(TestDeterminant, TestDeterminantException4) {
  S21Matrix test_matrix(3, 55);
  S21Matrix matrix_before = test_matrix;

  EXPECT_ANY_THROW(test_matrix.Determinant());
  EXPECT_TRUE(test_matrix == matrix_before);
}

TEST(TestDeterminant, TestDeterminantZero1) {
  S21Matrix matrix1{1, 1};
  EXPECT_EQ(matrix1.GetCols(), 1);
  EXPECT_EQ(matrix1.GetRows(), 1);

  matrix1(0, 0) = 0.0;

  double result_check = 0.0;
  S21Matrix matrix_before = matrix1;
  double result = matrix1.Determinant();

  EXPECT_NEAR(result_check, result, 1e-7);
  EXPECT_TRUE(matrix1 == matrix_before);
}

TEST(TestDeterminant, TestDeterminantZero2) {
  S21Matrix matrix1{3, 3};
  EXPECT_EQ(matrix1.GetCols(), 3);
  EXPECT_EQ(matrix1.GetRows(), 3);

  matrix1(0, 0) = 1.1;
  matrix1(0, 1) = 1.2;
  matrix1(0, 2) = 1.3;
  matrix1(1, 0) = 1.4;
  matrix1(1, 1) = 1.5;
  matrix1(1, 2) = 1.6;
  matrix1(2, 0) = 1.7;
  matrix1(2, 1) = 1.8;
  matrix1(2, 2) = 1.9;

  double result_check = 0.0;
  S21Matrix matrix_before = matrix1;
  double result = matrix1.Determinant();

  EXPECT_NEAR(result_check, result, 1e-7);
  EXPECT_TRUE(matrix1 == matrix_before);
}

TEST(TestDeterminant, TestDeterminantZero3) {
  S21Matrix matrix1{3, 3};
  EXPECT_EQ(matrix1.GetCols(), 3);
  EXPECT_EQ(matrix1.GetRows(), 3);

  matrix1(0, 0) = -66;
  matrix1(0, 1) = -66;
  matrix1(0, 2) = -66;
  matrix1(1, 0) = -66;
  matrix1(1, 1) = -66;
  matrix1(1, 2) = -66;
  matrix1(2, 0) = -66;
  matrix1(2, 1) = -66;
  matrix1(2, 2) = -66;

  double result_check = 0.0;
  S21Matrix matrix_before = matrix1;
  double result = matrix1.Determinant();

  EXPECT_NEAR(result_check, result, 1e-7);
  EXPECT_TRUE(matrix1 == matrix_before);
}

TEST(TestDeterminant, TestDeterminantZero4) {
  S21Matrix matrix1{3, 3};
  EXPECT_EQ(matrix1.GetCols(), 3);
  EXPECT_EQ(matrix1.GetRows(), 3);

  matrix1(0, 0) = 9.89841e+07;
  matrix1(0, 1) = 7.57375e+07;
  matrix1(0, 2) = 7.57375e+07;

  matrix1(1, 0) = 1.90939e+07;
  matrix1(1, 1) = 7.57375e+07;
  matrix1(1, 2) = 7.57375e+07;

  matrix1(2, 0) = -4.32978e+07;
  matrix1(2, 1) = 7.57375e+07;
  matrix1(2, 2) = 7.57375e+07;

  double result_check = 0.0;
  S21Matrix matrix_before = matrix1;
  double result = matrix1.Determinant();

  EXPECT_NEAR(result_check, result, 1e-7);
  EXPECT_TRUE(matrix1 == matrix_before);
}

TEST(TestDeterminant, TestDeterminantZero5) {
  S21Matrix matrix1{5, 5};
  EXPECT_EQ(matrix1.GetCols(), 5);
  EXPECT_EQ(matrix1.GetRows(), 5);

  matrix1(0, 0) = 5.61395e+07;
  matrix1(0, 1) = 3.56219e+07;
  matrix1(0, 2) = 3.56219e+07;
  matrix1(0, 3) = -9.52484e+07;
  matrix1(0, 4) = -5.06042e+07;

  matrix1(1, 0) = 3.70469e+07;
  matrix1(1, 1) = 3.56219e+07;
  matrix1(1, 2) = 3.56219e+07;
  matrix1(1, 3) = 4.41733e+07;
  matrix1(1, 4) = 9.19346e+07;

  matrix1(2, 0) = 1.1319e+07;
  matrix1(2, 1) = 3.56219e+07;
  matrix1(2, 2) = 3.56219e+07;
  matrix1(2, 3) = 5.77491e+07;
  matrix1(2, 4) = -7.70006e+07;

  matrix1(3, 0) = -6.29533e+07;
  matrix1(3, 1) = 3.56219e+07;
  matrix1(3, 2) = 3.56219e+07;
  matrix1(3, 3) = 3.70425e+07;
  matrix1(3, 4) = -2.26376e+07;

  matrix1(4, 0) = 9.64659e+07;
  matrix1(4, 1) = 3.56219e+07;
  matrix1(4, 2) = 3.56219e+07;
  matrix1(4, 3) = 9.07791e+07;
  matrix1(4, 4) = 6.79804e+07;

  double result_check = 0.0;
  S21Matrix matrix_before = matrix1;
  double result = matrix1.Determinant();

  EXPECT_NEAR(result_check, result, 1e-7);
  EXPECT_TRUE(matrix1 == matrix_before);
}

TEST(TestDeterminant, TestDeterminantZero6) {
  S21Matrix matrix1{5, 5};

  EXPECT_EQ(matrix1.GetCols(), 5);
  EXPECT_EQ(matrix1.GetRows(), 5);

  matrix1(0, 0) = 490126999929252.0;
  matrix1(0, 1) = 342540400593534.0;
  matrix1(0, 2) = 342540400593534.0;
  matrix1(0, 3) = 957907041856159.0;
  matrix1(0, 4) = 161144864560551.0;

  matrix1(1, 0) = 904879303508081.0;
  matrix1(1, 1) = 342540400593534.0;
  matrix1(1, 2) = 342540400593534.0;
  matrix1(1, 3) = 872222433389614.0;
  matrix1(1, 4) = 517528813858064.0;

  matrix1(2, 0) = 164529895900761.0;
  matrix1(2, 1) = 342540400593534.0;
  matrix1(2, 2) = 342540400593534.0;
  matrix1(2, 3) = 115755924305184.0;
  matrix1(2, 4) = 744137398335045.0;

  matrix1(3, 0) = 295628643374509.0;
  matrix1(3, 1) = 342540400593534.0;
  matrix1(3, 2) = 342540400593534.0;
  matrix1(3, 3) = 172783313833962.0;
  matrix1(3, 4) = 245717847641320.0;

  matrix1(4, 0) = 549097439356132.0;
  matrix1(4, 1) = 342540400593534.0;
  matrix1(4, 2) = 342540400593534.0;
  matrix1(4, 3) = 718487106520757.0;
  matrix1(4, 4) = 429858960118645.0;

  double result_check = 0.0;
  S21Matrix matrix_before = matrix1;
  double result = matrix1.Determinant();

  EXPECT_NEAR(result_check, result, 1e-7);
  EXPECT_TRUE(matrix1 == matrix_before);
}

TEST(TestDeterminant, TestDeterminantZero7) {
  S21Matrix matrix1{5, 5};

  EXPECT_EQ(matrix1.GetCols(), 5);
  EXPECT_EQ(matrix1.GetRows(), 5);

  matrix1(0, 0) = 490126999929252.0;
  matrix1(0, 1) = 0.342540400593534;
  matrix1(0, 2) = 0.342540400593534;
  matrix1(0, 3) = 957907041856159.0;
  matrix1(0, 4) = 161144864560551.0;
  matrix1(1, 0) = 904879303508081.0;
  matrix1(1, 1) = 0.342540400593534;
  matrix1(1, 2) = 0.342540400593534;
  matrix1(1, 3) = 872222433389614.0;
  matrix1(1, 4) = 517528813858064.0;
  matrix1(2, 0) = 164529895900761.0;
  matrix1(2, 1) = 0.342540400593534;
  matrix1(2, 2) = 0.342540400593534;
  matrix1(2, 3) = 115755924305184.0;
  matrix1(2, 4) = 744137398335045.0;
  matrix1(3, 0) = 295628643374509.0;
  matrix1(3, 1) = 0.342540400593534;
  matrix1(3, 2) = 0.342540400593534;
  matrix1(3, 3) = 172783313833962.0;
  matrix1(3, 4) = 245717847641320.0;
  matrix1(4, 0) = 549097439356132.0;
  matrix1(4, 1) = 0.342540400593534;
  matrix1(4, 2) = 0.342540400593534;
  matrix1(4, 3) = 718487106520757.0;
  matrix1(4, 4) = 429858960118645.0;

  double result_check = 0.0;
  S21Matrix matrix_before = matrix1;
  double result = matrix1.Determinant();

  EXPECT_NEAR(result_check, result, 1e-7);
  EXPECT_TRUE(matrix1 == matrix_before);
}

TEST(TestDeterminant, TestDeterminantZero8) {
  S21Matrix matrix1{5, 5};

  EXPECT_EQ(matrix1.GetCols(), 5);
  EXPECT_EQ(matrix1.GetRows(), 5);

  matrix1(0, 0) = 0.490126999929252;
  matrix1(0, 1) = 342540400593534.0;
  matrix1(0, 2) = 342540400593534.0;
  matrix1(0, 3) = 0.957907041856159;
  matrix1(0, 4) = 0.161144864560551;
  matrix1(1, 0) = 0.904879303508081;
  matrix1(1, 1) = 342540400593534.0;
  matrix1(1, 2) = 342540400593534.0;
  matrix1(1, 3) = 0.872222433389614;
  matrix1(1, 4) = 0.517528813858064;
  matrix1(2, 0) = 0.164529895900761;
  matrix1(2, 1) = 342540400593534.0;
  matrix1(2, 2) = 342540400593534.0;
  matrix1(2, 3) = 0.115755924305184;
  matrix1(2, 4) = 0.744137398335045;
  matrix1(3, 0) = 0.295628643374509;
  matrix1(3, 1) = 342540400593534.0;
  matrix1(3, 2) = 342540400593534.0;
  matrix1(3, 3) = 0.172783313833962;
  matrix1(3, 4) = 0.245717847641320;
  matrix1(4, 0) = 0.549097439356132;
  matrix1(4, 1) = 342540400593534.0;
  matrix1(4, 2) = 342540400593534.0;
  matrix1(4, 3) = 0.718487106520757;
  matrix1(4, 4) = 0.429858960118645;

  double result_check = 0.0;
  S21Matrix matrix_before = matrix1;
  double result = matrix1.Determinant();

  EXPECT_NEAR(result_check, result, 1e-7);
  EXPECT_TRUE(matrix1 == matrix_before);
}

TEST(TestDeterminant, TestDeterminantZero9) {
  S21Matrix matrix1{5, 5};
  EXPECT_EQ(matrix1.GetCols(), 5);
  EXPECT_EQ(matrix1.GetRows(), 5);

  matrix1(0, 0) = 342540400593534.0;
  matrix1(0, 1) = 0.490126999929252;
  matrix1(0, 2) = 0.957907041856159;
  matrix1(0, 3) = 0.161144864560551;
  matrix1(0, 4) = 342540400593534.0;
  matrix1(1, 0) = 342540400593534.0;
  matrix1(1, 1) = 0.904879303508081;
  matrix1(1, 2) = 0.872222433389614;
  matrix1(1, 3) = 0.517528813858064;
  matrix1(1, 4) = 342540400593534.0;
  matrix1(2, 0) = 342540400593534.0;
  matrix1(2, 1) = 0.164529895900761;
  matrix1(2, 2) = 0.115755924305184;
  matrix1(2, 3) = 0.744137398335045;
  matrix1(2, 4) = 342540400593534.0;
  matrix1(3, 0) = 342540400593534.0;
  matrix1(3, 1) = 0.295628643374509;
  matrix1(3, 2) = 0.172783313833962;
  matrix1(3, 3) = 0.245717847641320;
  matrix1(3, 4) = 342540400593534.0;
  matrix1(4, 0) = 342540400593534.0;
  matrix1(4, 1) = 0.549097439356132;
  matrix1(4, 2) = 0.718487106520757;
  matrix1(4, 3) = 0.429858960118645;
  matrix1(4, 4) = 342540400593534.0;

  double result_check = 0.0;
  S21Matrix matrix_before = matrix1;
  double result = matrix1.Determinant();

  EXPECT_NEAR(result_check, result, 1e-7);
  EXPECT_TRUE(matrix1 == matrix_before);
}

TEST(TestDeterminant, TestDeterminantZero10) {
  S21Matrix matrix1{5, 5};

  EXPECT_EQ(matrix1.GetCols(), 5);
  EXPECT_EQ(matrix1.GetRows(), 5);

  matrix1(0, 0) = 4901269.0;
  matrix1(0, 1) = 342540400593534.0;
  matrix1(0, 2) = 342540400593534.0;
  matrix1(0, 3) = 9.0;
  matrix1(0, 4) = 161144851.0;
  matrix1(1, 0) = 9048793031.0;
  matrix1(1, 1) = 342540400593534.0;
  matrix1(1, 2) = 342540400593534.0;
  matrix1(1, 3) = 87223389614.0;
  matrix1(1, 4) = 517528813858064.0;
  matrix1(2, 0) = 1645298951.0;
  matrix1(2, 1) = 342540400593534.0;
  matrix1(2, 2) = 342540400593534.0;
  matrix1(2, 3) = 115755924305184.0;
  matrix1(2, 4) = 744137398.0;
  matrix1(3, 0) = 295628643374509.0;
  matrix1(3, 1) = 342540400593534.0;
  matrix1(3, 2) = 342540400593534.0;
  matrix1(3, 3) = 17278333962.0;
  matrix1(3, 4) = 245717847641320.0;
  matrix1(4, 0) = 5490974393.0;
  matrix1(4, 1) = 342540400593534.0;
  matrix1(4, 2) = 342540400593534.0;
  matrix1(4, 3) = 71848710.0;
  matrix1(4, 4) = 429.0;

  double result_check = 0.0;
  S21Matrix matrix_before = matrix1;
  double result = matrix1.Determinant();

  EXPECT_NEAR(result_check, result, 1e-7);
  EXPECT_TRUE(matrix1 == matrix_before);
}

TEST(TestDeterminant, TestDeterminantZero11) {
  S21Matrix matrix1{5, 5};
  EXPECT_EQ(matrix1.GetCols(), 5);
  EXPECT_EQ(matrix1.GetRows(), 5);

  matrix1(0, 0) = 342540400593534.0;
  matrix1(0, 1) = 0.0;
  matrix1(0, 2) = 95790704185619.0;
  matrix1(0, 3) = 16114486456051.0;
  matrix1(0, 4) = 342540400593534.0;
  matrix1(1, 0) = 342540400593534.0;
  matrix1(1, 1) = 90487930350881.0;
  matrix1(1, 2) = 0.0;
  matrix1(1, 3) = 51752881385804.0;
  matrix1(1, 4) = 342540400593534.0;
  matrix1(2, 0) = 342540400593534.0;
  matrix1(2, 1) = 16452989590071.0;
  matrix1(2, 2) = 0.0;
  matrix1(2, 3) = 744137398335045.0;
  matrix1(2, 4) = 342540400593534.0;
  matrix1(3, 0) = 342540400593534.0;
  matrix1(3, 1) = 29562864337459.0;
  matrix1(3, 2) = 17278331383392.0;
  matrix1(3, 3) = 0.0;
  matrix1(3, 4) = 342540400593534.0;
  matrix1(4, 0) = 342540400593534.0;
  matrix1(4, 1) = 54909749356132.0;
  matrix1(4, 2) = 71848710652757.0;
  matrix1(4, 3) = 42985860118645.0;
  matrix1(4, 4) = 342540400593534.0;

  double result_check = 0.0;
  S21Matrix matrix_before = matrix1;
  double result = matrix1.Determinant();

  EXPECT_NEAR(result_check, result, 1e-7);
  EXPECT_TRUE(matrix1 == matrix_before);
}

TEST(TestDeterminant, TestDeterminantZero12) {
  S21Matrix matrix1{2, 2};
  EXPECT_EQ(matrix1.GetCols(), 2);
  EXPECT_EQ(matrix1.GetRows(), 2);

  matrix1(0, 0) = 1;
  matrix1(0, 1) = 3;
  matrix1(1, 0) = 2;
  matrix1(1, 1) = 6;

  double result_check = 0.0;
  S21Matrix matrix_before = matrix1;
  double result = matrix1.Determinant();

  EXPECT_NEAR(result_check, result, 1e-7);
  EXPECT_TRUE(matrix1 == matrix_before);
}

TEST(TestDeterminant, TestDeterminantZero13) {
  S21Matrix matrix1{2, 2};
  EXPECT_EQ(matrix1.GetCols(), 2);
  EXPECT_EQ(matrix1.GetRows(), 2);

  matrix1(0, 0) = 1;
  matrix1(0, 1) = 2;
  matrix1(1, 0) = 3;
  matrix1(1, 1) = 6;

  double result_check = 0.0;
  S21Matrix matrix_before = matrix1;
  double result = matrix1.Determinant();

  EXPECT_NEAR(result_check, result, 1e-7);
  EXPECT_TRUE(matrix1 == matrix_before);
}

TEST(TestDeterminant, TestDeterminantZero14) {
  S21Matrix matrix1{2, 2};
  EXPECT_EQ(matrix1.GetCols(), 2);
  EXPECT_EQ(matrix1.GetRows(), 2);

  matrix1(0, 0) = 0;
  matrix1(0, 1) = 0;
  matrix1(1, 0) = 0;
  matrix1(1, 1) = 0;

  double result_check = 0.0;
  S21Matrix matrix_before = matrix1;
  double result = matrix1.Determinant();

  EXPECT_NEAR(result_check, result, 1e-7);
  EXPECT_TRUE(matrix1 == matrix_before);
}

TEST(TestDeterminant, TestDeterminantZero15) {
  S21Matrix matrix1{2, 2};
  EXPECT_EQ(matrix1.GetCols(), 2);
  EXPECT_EQ(matrix1.GetRows(), 2);

  matrix1(0, 0) = 62003758.14000639319420;
  matrix1(0, 1) = 124007516.28001278638840;
  matrix1(1, 0) = 7533129.83762268722057;
  matrix1(1, 1) = 15066259.67524537444115;

  double result_check = 0.0;
  S21Matrix matrix_before = matrix1;
  double result = matrix1.Determinant();

  EXPECT_NEAR(result_check, result, 1e-7);
  EXPECT_TRUE(matrix1 == matrix_before);
}

TEST(TestDeterminant, TestDeterminantZero16) {
  S21Matrix matrix1{3, 3};
  EXPECT_EQ(matrix1.GetCols(), 3);
  EXPECT_EQ(matrix1.GetRows(), 3);

  matrix1(0, 0) = -63581647.38773362338543;
  matrix1(0, 1) = 9756267.74286703765392;
  matrix1(0, 2) = -127163294.77546724677086;
  matrix1(1, 0) = 68655950.09263044595718;
  matrix1(1, 1) = 35162340.60234943032265;
  matrix1(1, 2) = 137311900.18526089191437;
  matrix1(2, 0) = -49642926.54292698949575;
  matrix1(2, 1) = -50026132.37590176612139;
  matrix1(2, 2) = -99285853.08585397899151;

  double result_check = 0.0;
  S21Matrix matrix_before = matrix1;
  double result = matrix1.Determinant();

  EXPECT_NEAR(result_check, result, 1e-7);
  EXPECT_TRUE(matrix1 == matrix_before);
}

TEST(TestDeterminant, TestDeterminantZero17) {
  S21Matrix matrix1{4, 4};
  EXPECT_EQ(matrix1.GetCols(), 4);
  EXPECT_EQ(matrix1.GetRows(), 4);

  matrix1(0, 0) = 37521102.68191075325012;
  matrix1(0, 1) = -7366955.30483770370483;
  matrix1(0, 2) = -89234691.49498392641544;
  matrix1(0, 3) = 59685924.85609406232834;
  matrix1(1, 0) = -93989600.59850479662418;
  matrix1(1, 1) = -32273535.81015090644360;
  matrix1(1, 2) = 59293048.74089393019676;
  matrix1(1, 3) = 78694654.87947669625282;
  matrix1(2, 0) = 75042205.36382150650024;
  matrix1(2, 1) = -14733910.60967540740967;
  matrix1(2, 2) = -178469382.98996785283089;
  matrix1(2, 3) = 119371849.71218812465668;
  matrix1(3, 0) = 97988947.16184711456299;
  matrix1(3, 1) = 97257934.17296910285950;
  matrix1(3, 2) = 98991136.73402935266495;
  matrix1(3, 3) = 71803366.44616046547890;

  double result_check = 0.0;
  S21Matrix matrix_before = matrix1;
  double result = matrix1.Determinant();

  EXPECT_NEAR(result_check, result, 1e-7);
  EXPECT_TRUE(matrix1 == matrix_before);
}

TEST(TestDeterminant, TestDeterminantZero18) {
  S21Matrix matrix1{1, 1};
  EXPECT_EQ(matrix1.GetCols(), 1);
  EXPECT_EQ(matrix1.GetRows(), 1);

  matrix1(0, 0) = -0.0;

  double result_check = -0.0;
  S21Matrix matrix_before = matrix1;
  double result = matrix1.Determinant();

  EXPECT_NEAR(result_check, result, 1e-7);
  EXPECT_TRUE(matrix1 == matrix_before);
}

TEST(TestDeterminant, TestDeterminantZero19) {
  S21Matrix matrix1{5, 5};
  EXPECT_EQ(matrix1.GetCols(), 5);
  EXPECT_EQ(matrix1.GetRows(), 5);

  matrix1(0, 0) = 561.395;
  matrix1(0, 1) = 356.219;
  matrix1(0, 2) = 356.219;
  matrix1(0, 3) = -952.484;
  matrix1(0, 4) = -506.042;

  matrix1(1, 0) = 370.469;
  matrix1(1, 1) = 356.219;
  matrix1(1, 2) = 356.219;
  matrix1(1, 3) = 441.733;
  matrix1(1, 4) = 919.346;

  matrix1(2, 0) = 113.190;
  matrix1(2, 1) = 356.219;
  matrix1(2, 2) = 356.219;
  matrix1(2, 3) = 577.491;
  matrix1(2, 4) = -770.006;

  matrix1(3, 0) = -629.533;
  matrix1(3, 1) = 356.219;
  matrix1(3, 2) = 356.219;
  matrix1(3, 3) = 370.425;
  matrix1(3, 4) = -226.376;

  matrix1(4, 0) = 964.659;
  matrix1(4, 1) = 356.219;
  matrix1(4, 2) = 356.219;
  matrix1(4, 3) = 907.791;
  matrix1(4, 4) = 679.804;

  double result_check = 0.0;
  S21Matrix matrix_before = matrix1;
  double result = matrix1.Determinant();

  EXPECT_NEAR(result_check, result, 1e-7);
  EXPECT_TRUE(matrix1 == matrix_before);
}

TEST(TestDeterminant, TestDeterminantZero20) {
  S21Matrix matrix1{5, 5};
  EXPECT_EQ(matrix1.GetCols(), 5);
  EXPECT_EQ(matrix1.GetRows(), 5);

  matrix1(0, 0) = 561;
  matrix1(0, 1) = 356;
  matrix1(0, 2) = 356;
  matrix1(0, 3) = -952;
  matrix1(0, 4) = -506;

  matrix1(1, 0) = 370;
  matrix1(1, 1) = 356;
  matrix1(1, 2) = 356;
  matrix1(1, 3) = 441;
  matrix1(1, 4) = 919;

  matrix1(2, 0) = 113;
  matrix1(2, 1) = 356;
  matrix1(2, 2) = 356;
  matrix1(2, 3) = 577;
  matrix1(2, 4) = -770;

  matrix1(3, 0) = -629;
  matrix1(3, 1) = 356;
  matrix1(3, 2) = 356;
  matrix1(3, 3) = 370;
  matrix1(3, 4) = -226;

  matrix1(4, 0) = 964;
  matrix1(4, 1) = 356;
  matrix1(4, 2) = 356;
  matrix1(4, 3) = 907;
  matrix1(4, 4) = 679;

  double result_check = 0.0;
  S21Matrix matrix_before = matrix1;
  double result = matrix1.Determinant();

  EXPECT_NEAR(result_check, result, 1e-7);
  EXPECT_TRUE(matrix1 == matrix_before);
}

TEST(TestDeterminant, TestDeterminant21) {
  S21Matrix matrix1{1, 1};
  EXPECT_EQ(matrix1.GetCols(), 1);
  EXPECT_EQ(matrix1.GetRows(), 1);

  matrix1(0, 0) = 1.5;

  double result_check = 1.5;
  S21Matrix matrix_before = matrix1;
  double result = matrix1.Determinant();

  EXPECT_NEAR(result_check, result, 1e-7);
  EXPECT_TRUE(matrix1 == matrix_before);
}

TEST(TestDeterminant, TestDeterminant22) {
  S21Matrix matrix1{2, 2};
  EXPECT_EQ(matrix1.GetCols(), 2);
  EXPECT_EQ(matrix1.GetRows(), 2);

  matrix1(0, 0) = 1.1;
  matrix1(0, 1) = 1.2;
  matrix1(1, 0) = 1.3;
  matrix1(1, 1) = 1.4;

  double result_check = -0.02;
  S21Matrix matrix_before = matrix1;
  double result = matrix1.Determinant();

  EXPECT_NEAR(result_check, result, 1e-7);
  EXPECT_TRUE(matrix1 == matrix_before);
}

TEST(TestDeterminant, TestDeterminant23) {
  S21Matrix matrix1{2, 2};
  EXPECT_EQ(matrix1.GetCols(), 2);
  EXPECT_EQ(matrix1.GetRows(), 2);

  matrix1(0, 0) = 7.72122069261968;
  matrix1(1, 0) = -7.3629210004583;
  matrix1(0, 1) = 8.93235725676641;
  matrix1(1, 1) = 2.69165195827372;

  double result_check = 86.5510796270;
  S21Matrix matrix_before = matrix1;
  double result = matrix1.Determinant();

  EXPECT_NEAR(result_check, result, 1e-7);
  EXPECT_TRUE(matrix1 == matrix_before);
}

TEST(TestDeterminant, TestDeterminant24) {
  S21Matrix matrix1{3, 3};
  EXPECT_EQ(matrix1.GetCols(), 3);
  EXPECT_EQ(matrix1.GetRows(), 3);

  matrix1(0, 0) = 0;
  matrix1(0, 1) = 1;
  matrix1(0, 2) = 2;
  matrix1(1, 0) = 3;
  matrix1(1, 1) = 4;
  matrix1(1, 2) = 5;
  matrix1(2, 0) = 6;
  matrix1(2, 1) = 0;
  matrix1(2, 2) = 7;

  double result_check = -39;
  S21Matrix matrix_before = matrix1;
  double result = matrix1.Determinant();

  EXPECT_NEAR(result_check, result, 1e-7);
  EXPECT_TRUE(matrix1 == matrix_before);
}

TEST(TestDeterminant, TestDeterminant25) {
  S21Matrix matrix1{3, 3};
  EXPECT_EQ(matrix1.GetCols(), 3);
  EXPECT_EQ(matrix1.GetRows(), 3);

  matrix1(0, 0) = 5.34922476788051;
  matrix1(1, 0) = 1.65522041497752;
  matrix1(2, 0) = -8.68382598599419;
  matrix1(0, 1) = -3.25669884728268;
  matrix1(1, 1) = 10.8967615629081;
  matrix1(2, 1) = 4.55130848893896;
  matrix1(0, 2) = -2.14478276530281;
  matrix1(1, 2) = -2.7382052554749;
  matrix1(2, 2) = 5.7808097708039;

  double result_check = 138.2380038449;
  S21Matrix matrix_before = matrix1;
  double result = matrix1.Determinant();

  EXPECT_NEAR(result_check, result, 1e-7);
  EXPECT_TRUE(matrix1 == matrix_before);
}

TEST(TestDeterminant, TestDeterminant26) {
  S21Matrix matrix1{4, 4};
  EXPECT_EQ(matrix1.GetCols(), 4);
  EXPECT_EQ(matrix1.GetRows(), 4);

  matrix1(0, 0) = 1.1;
  matrix1(0, 1) = 1.2;
  matrix1(0, 2) = 1.3;
  matrix1(0, 3) = 1.4;
  matrix1(1, 0) = 1.5;
  matrix1(1, 1) = 1.6;
  matrix1(1, 2) = 1.7;
  matrix1(1, 3) = 1.8;
  matrix1(2, 0) = 1.9;
  matrix1(2, 1) = 2.0;
  matrix1(2, 2) = 2.1;
  matrix1(2, 3) = 2.2;
  matrix1(3, 0) = 2.3;
  matrix1(3, 1) = 2.4;
  matrix1(3, 2) = 2.5;
  matrix1(3, 3) = 2.6;

  double result_check = -5.1347814888913e-17;
  S21Matrix matrix_before = matrix1;
  double result = matrix1.Determinant();

  EXPECT_NEAR(result_check, result, 1e-7);
  EXPECT_TRUE(matrix1 == matrix_before);
}

TEST(TestDeterminant, TestDeterminant27) {
  S21Matrix matrix1{4, 4};
  EXPECT_EQ(matrix1.GetCols(), 4);
  EXPECT_EQ(matrix1.GetRows(), 4);

  matrix1(0, 0) = -7.00037610391155;
  matrix1(1, 0) = -6.32839397341013;
  matrix1(2, 0) = 10.222164043691;
  matrix1(3, 0) = 7.95983747509308;
  matrix1(0, 1) = -9.82599597726949;
  matrix1(1, 1) = 3.03237457247451;
  matrix1(2, 1) = 0.587724786484614;
  matrix1(3, 1) = -3.41600720770657;
  matrix1(0, 2) = 8.27683520526625;
  matrix1(1, 2) = -4.28063526446931;
  matrix1(2, 2) = -6.93227237439714;
  matrix1(3, 2) = -10.6065054496285;
  matrix1(0, 3) = 0.586602877592668;
  matrix1(1, 3) = 10.6546861075331;
  matrix1(2, 3) = 4.33103069034405;
  matrix1(3, 3) = 8.75408579711802;

  double result_check = -6618.5495718153;
  S21Matrix matrix_before = matrix1;
  double result = matrix1.Determinant();

  EXPECT_NEAR(result_check, result, 1e-7);
  EXPECT_TRUE(matrix1 == matrix_before);
}

TEST(TestDeterminant, TestDeterminant28) {
  S21Matrix matrix1{5, 5};
  EXPECT_EQ(matrix1.GetCols(), 5);
  EXPECT_EQ(matrix1.GetRows(), 5);

  matrix1(0, 0) = 5.543;
  matrix1(0, 1) = 25.425;
  matrix1(0, 2) = 24.4325;
  matrix1(0, 3) = 23.52;
  matrix1(0, 4) = 0.0;
  matrix1(1, 0) = 52.3;
  matrix1(1, 1) = 53.2;
  matrix1(1, 2) = 34.434;
  matrix1(1, 3) = 0.0;
  matrix1(1, 4) = 53.352;
  matrix1(2, 0) = 54.23512;
  matrix1(2, 1) = 34.325;
  matrix1(2, 2) = 0.0;
  matrix1(2, 3) = 24.343;
  matrix1(2, 4) = 34.422;
  matrix1(3, 0) = 36.22;
  matrix1(3, 1) = 0.0;
  matrix1(3, 2) = 32.0;
  matrix1(3, 3) = 24.432;
  matrix1(3, 4) = 43.21;
  matrix1(4, 0) = 0.0;
  matrix1(4, 1) = 23.21;
  matrix1(4, 2) = 23.234;
  matrix1(4, 3) = 12.1231;
  matrix1(4, 4) = 21.2232;

  double result_check = 74346939.8940858;

  S21Matrix matrix_before = matrix1;
  double result = matrix1.Determinant();

  EXPECT_NEAR(result_check, result, 1e-7);
  EXPECT_TRUE(matrix1 == matrix_before);
}

TEST(TestDeterminant, TestDeterminant29) {
  S21Matrix matrix1{6, 6};
  EXPECT_EQ(matrix1.GetCols(), 6);
  EXPECT_EQ(matrix1.GetRows(), 6);

  matrix1(0, 0) = -8.25324401422404;
  matrix1(1, 0) = 7.73323425720446;
  matrix1(2, 0) = 1.84863350028172;
  matrix1(3, 0) = -10.0115760930348;
  matrix1(4, 0) = -5.15668712323532;
  matrix1(5, 0) = 0.833224474685267;
  matrix1(0, 1) = 6.72777522937395;
  matrix1(1, 1) = -5.02706401585601;
  matrix1(2, 1) = -0.966418515890837;
  matrix1(3, 1) = 7.74789611180313;
  matrix1(4, 1) = 0.869955397676677;
  matrix1(5, 1) = -2.01394975557923;
  matrix1(0, 2) = -4.55829650838859;
  matrix1(1, 2) = 3.51532235136256;
  matrix1(2, 2) = -7.3990064188838;
  matrix1(3, 2) = 0.485122002195567;
  matrix1(4, 2) = 9.88733662408777;
  matrix1(5, 2) = -3.07178143155761;
  matrix1(0, 3) = -6.01939426595345;
  matrix1(1, 3) = -7.33630517800339;
  matrix1(2, 3) = -3.09628330147825;
  matrix1(3, 3) = 8.41876223543659;
  matrix1(4, 3) = -3.80699184164405;
  matrix1(5, 3) = 1.82289709686302;
  matrix1(0, 4) = 9.28037635562941;
  matrix1(1, 4) = 8.25562612293288;
  matrix1(2, 4) = 3.07955321925692;
  matrix1(3, 4) = 1.94713557977229;
  matrix1(4, 4) = 7.41955809853971;
  matrix1(5, 4) = -9.39580690651201;
  matrix1(0, 5) = 2.73021495575085;
  matrix1(1, 5) = -5.90446221316233;
  matrix1(2, 5) = 5.84046185878105;
  matrix1(3, 5) = -2.47668161639012;
  matrix1(4, 5) = 1.28693996206857;
  matrix1(5, 5) = 4.85558348917402;

  double result_check = -109019.85742181906954580110;
  S21Matrix matrix_before = matrix1;
  double result = matrix1.Determinant();

  EXPECT_NEAR(result_check, result, 1e-7);
  EXPECT_TRUE(matrix1 == matrix_before);
}

TEST(TestDeterminant, TestDeterminant30) {
  S21Matrix matrix1{9, 9};
  EXPECT_EQ(matrix1.GetCols(), 9);
  EXPECT_EQ(matrix1.GetRows(), 9);

  matrix1(0, 0) = -0.93;
  matrix1(0, 1) = 0.96;
  matrix1(0, 2) = 0.56;
  matrix1(0, 3) = 0.05;
  matrix1(0, 4) = -0.94;
  matrix1(0, 5) = 0.01;
  matrix1(0, 6) = 0.69;
  matrix1(0, 7) = -1.70;
  matrix1(0, 8) = 0.21;
  matrix1(1, 0) = -1.68;
  matrix1(1, 1) = 0.11;
  matrix1(1, 2) = -0.34;
  matrix1(1, 3) = -1.74;
  matrix1(1, 4) = -0.13;
  matrix1(1, 5) = -0.79;
  matrix1(1, 6) = -0.56;
  matrix1(1, 7) = -1.84;
  matrix1(1, 8) = 1.86;
  matrix1(2, 0) = -1.37;
  matrix1(2, 1) = 0.23;
  matrix1(2, 2) = -0.60;
  matrix1(2, 3) = -1.65;
  matrix1(2, 4) = -1.91;
  matrix1(2, 5) = -0.90;
  matrix1(2, 6) = -0.38;
  matrix1(2, 7) = 0.82;
  matrix1(2, 8) = 1.05;
  matrix1(3, 0) = -1.77;
  matrix1(3, 1) = 1.66;
  matrix1(3, 2) = 0.17;
  matrix1(3, 3) = 0.55;
  matrix1(3, 4) = 1.93;
  matrix1(3, 5) = -0.89;
  matrix1(3, 6) = -0.08;
  matrix1(3, 7) = 1.34;
  matrix1(3, 8) = 1.74;
  matrix1(4, 0) = 0.23;
  matrix1(4, 1) = 1.96;
  matrix1(4, 2) = -0.33;
  matrix1(4, 3) = -1.73;
  matrix1(4, 4) = 0.25;
  matrix1(4, 5) = 1.22;
  matrix1(4, 6) = -0.36;
  matrix1(4, 7) = 1.16;
  matrix1(4, 8) = 1.07;
  matrix1(5, 0) = 0.25;
  matrix1(5, 1) = -0.83;
  matrix1(5, 2) = -1.90;
  matrix1(5, 3) = 0.10;
  matrix1(5, 4) = 0.26;
  matrix1(5, 5) = -1.38;
  matrix1(5, 6) = -0.52;
  matrix1(5, 7) = -0.97;
  matrix1(5, 8) = -0.01;
  matrix1(6, 0) = 1.28;
  matrix1(6, 1) = -1.70;
  matrix1(6, 2) = 1.32;
  matrix1(6, 3) = -1.35;
  matrix1(6, 4) = 0.18;
  matrix1(6, 5) = -0.66;
  matrix1(6, 6) = 1.16;
  matrix1(6, 7) = -0.81;
  matrix1(6, 8) = -1.06;
  matrix1(7, 0) = 0.87;
  matrix1(7, 1) = 1.66;
  matrix1(7, 2) = 0.12;
  matrix1(7, 3) = -1.83;
  matrix1(7, 4) = -1.25;
  matrix1(7, 5) = 0.41;
  matrix1(7, 6) = 1.21;
  matrix1(7, 7) = -1.95;
  matrix1(7, 8) = 0.08;
  matrix1(8, 0) = 1.92;
  matrix1(8, 1) = 1.96;
  matrix1(8, 2) = -1.64;
  matrix1(8, 3) = -0.44;
  matrix1(8, 4) = 1.36;
  matrix1(8, 5) = 0.74;
  matrix1(8, 6) = -0.67;
  matrix1(8, 7) = -1.03;
  matrix1(8, 8) = 1.60;

  double result_check = -63.322314761722227635;
  S21Matrix matrix_before = matrix1;
  double result = matrix1.Determinant();

  EXPECT_NEAR(result_check, result, 1e-7);
  EXPECT_TRUE(matrix1 == matrix_before);
}

TEST(TestCalcComplements, TestCalcComplementsException1) {
  S21Matrix test_matrix(2, 3);
  S21Matrix matrix_before = test_matrix;

  EXPECT_ANY_THROW(test_matrix.CalcComplements());
  EXPECT_TRUE(test_matrix == matrix_before);
}

TEST(TestCalcComplements, TestCalcComplementsException2) {
  S21Matrix test_matrix(3, 2);

  EXPECT_EQ(test_matrix.GetRows(), 3);
  EXPECT_EQ(test_matrix.GetCols(), 2);

  S21Matrix matrix_before = test_matrix;

  EXPECT_ANY_THROW(test_matrix.CalcComplements());
  EXPECT_TRUE(test_matrix == matrix_before);
}

TEST(TestCalcComplements, TestCalcComplementsException3) {
  S21Matrix test_matrix(1, 5);

  EXPECT_EQ(test_matrix.GetRows(), 1);
  EXPECT_EQ(test_matrix.GetCols(), 5);

  S21Matrix matrix_before = test_matrix;

  EXPECT_ANY_THROW(test_matrix.CalcComplements());
  EXPECT_TRUE(test_matrix == matrix_before);
}

TEST(TestCalcComplements, TestCalcComplementsException4) {
  S21Matrix test_matrix(5, 1);

  EXPECT_EQ(test_matrix.GetRows(), 5);
  EXPECT_EQ(test_matrix.GetCols(), 1);

  S21Matrix matrix_before = test_matrix;

  EXPECT_ANY_THROW(test_matrix.CalcComplements());
  EXPECT_TRUE(test_matrix == matrix_before);
}

TEST(TestCalcComplements, TestCalcComplementsOne1) {
  S21Matrix test_matrix(1, 1);

  EXPECT_EQ(test_matrix.GetRows(), 1);
  EXPECT_EQ(test_matrix.GetCols(), 1);

  S21Matrix matrix_before = test_matrix;
  S21Matrix result;

  EXPECT_ANY_THROW(result = test_matrix.CalcComplements());
  EXPECT_TRUE(test_matrix == matrix_before);
}

TEST(TestCalcComplements, TestCalcComplementsOne2) {
  S21Matrix test_matrix(1, 1);

  EXPECT_EQ(test_matrix.GetRows(), 1);
  EXPECT_EQ(test_matrix.GetCols(), 1);

  test_matrix(0, 0) = 5.0;
  S21Matrix matrix_before = test_matrix;
  S21Matrix result;

  EXPECT_ANY_THROW(result = test_matrix.CalcComplements());
  EXPECT_TRUE(test_matrix == matrix_before);
}

TEST(TestCalcComplements, TestCalcComplements3) {
  S21Matrix matrix1{2, 2};
  EXPECT_EQ(matrix1.GetCols(), 2);
  EXPECT_EQ(matrix1.GetRows(), 2);

  S21Matrix result_check{2, 2};
  EXPECT_EQ(result_check.GetCols(), 2);
  EXPECT_EQ(result_check.GetRows(), 2);

  matrix1(0, 0) = 1;
  matrix1(0, 1) = 2;
  matrix1(1, 0) = 3;
  matrix1(1, 1) = 4;

  result_check(0, 0) = 4;
  result_check(0, 1) = -3;
  result_check(1, 0) = -2;
  result_check(1, 1) = 1;

  S21Matrix matrix_before = matrix1;
  S21Matrix result = matrix1.CalcComplements();

  EXPECT_TRUE(result == result_check);
  EXPECT_TRUE(matrix1 == matrix_before);
}

TEST(TestCalcComplements, TestCalcComplements4) {
  S21Matrix matrix1{2, 2};
  EXPECT_EQ(matrix1.GetCols(), 2);
  EXPECT_EQ(matrix1.GetRows(), 2);

  S21Matrix result_check{2, 2};
  EXPECT_EQ(result_check.GetCols(), 2);
  EXPECT_EQ(result_check.GetRows(), 2);

  matrix1(0, 0) = 12.452;
  matrix1(0, 1) = 3.34245;
  matrix1(1, 0) = 3.356;
  matrix1(1, 1) = 3.543;

  result_check(0, 0) = 3.543;
  result_check(0, 1) = -3.356;
  result_check(1, 0) = -3.34245;
  result_check(1, 1) = 12.452;

  S21Matrix matrix_before = matrix1;
  S21Matrix result = matrix1.CalcComplements();

  EXPECT_TRUE(result == result_check);
  EXPECT_TRUE(matrix1 == matrix_before);
}

TEST(TestCalcComplements, TestCalcComplements5) {
  S21Matrix matrix1{3, 3};
  EXPECT_EQ(matrix1.GetCols(), 3);
  EXPECT_EQ(matrix1.GetRows(), 3);

  S21Matrix result_check{3, 3};
  EXPECT_EQ(result_check.GetCols(), 3);
  EXPECT_EQ(result_check.GetRows(), 3);

  matrix1(0, 0) = 1;
  matrix1(1, 0) = 2;
  matrix1(2, 0) = 3;
  matrix1(0, 1) = 4;
  matrix1(1, 1) = 5;
  matrix1(2, 1) = 6;
  matrix1(0, 2) = 7;
  matrix1(1, 2) = 8;
  matrix1(2, 2) = 9;

  result_check(0, 0) = -3;
  result_check(1, 0) = 6;
  result_check(2, 0) = -3;
  result_check(0, 1) = 6;
  result_check(1, 1) = -12;
  result_check(2, 1) = 6;
  result_check(0, 2) = -3;
  result_check(1, 2) = 6;
  result_check(2, 2) = -3;

  S21Matrix matrix_before = matrix1;
  S21Matrix result = matrix1.CalcComplements();

  EXPECT_TRUE(result == result_check);
  EXPECT_TRUE(matrix1 == matrix_before);
}

TEST(TestCalcComplements, TestCalcComplements6) {
  S21Matrix matrix1{4, 4};
  EXPECT_EQ(matrix1.GetCols(), 4);
  EXPECT_EQ(matrix1.GetRows(), 4);

  S21Matrix result_check{4, 4};
  EXPECT_EQ(result_check.GetCols(), 4);
  EXPECT_EQ(result_check.GetRows(), 4);

  matrix1(0, 0) = -3.86;
  matrix1(1, 0) = -8.48;
  matrix1(2, 0) = -8.36;
  matrix1(3, 0) = 2.82;
  matrix1(0, 1) = 7.02;
  matrix1(1, 1) = 7.17;
  matrix1(2, 1) = -4.87;
  matrix1(3, 1) = -1.54;
  matrix1(0, 2) = 4.23;
  matrix1(1, 2) = 7.84;
  matrix1(2, 2) = 3.56;
  matrix1(3, 2) = -8.62;
  matrix1(0, 3) = 4.82;
  matrix1(1, 3) = -7.78;
  matrix1(2, 3) = 3.62;
  matrix1(3, 3) = 3.71;

  result_check(0, 0) = 11781393.0 / 250000.0;
  result_check(1, 0) = -593383083.0 / 1000000.0;
  result_check(2, 0) = -113629541.0 / 200000.0;
  result_check(3, 0) = -187801277.0 / 250000.0;
  result_check(0, 1) = 3349777.0 / 6250.0;
  result_check(1, 1) = 1886893.0 / 6250.0;
  result_check(2, 1) = -108158171.0 / 250000.0;
  result_check(3, 1) = 44864781.0 / 125000.0;
  result_check(0, 2) = 48626797.0 / 250000.0;
  result_check(1, 2) = -46586467.0 / 100000.0;
  result_check(2, 2) = -2410461.0 / 100000.0;
  result_check(3, 2) = -18845574.0 / 15625.0;
  result_check(0, 3) = 39911437.0 / 62500.0;
  result_check(1, 3) = -253030017.0 / 500000.0;
  result_check(2, 3) = 98132137.0 / 500000.0;
  result_check(3, 3) = -16461827.0 / 250000.0;

  S21Matrix matrix_before = matrix1;
  S21Matrix result = matrix1.CalcComplements();

  EXPECT_TRUE(result == result_check);
  EXPECT_TRUE(matrix1 == matrix_before);
}

TEST(TestCalcComplements, TestCalcComplements7) {
  S21Matrix matrix1{5, 5};
  EXPECT_EQ(matrix1.GetCols(), 5);
  EXPECT_EQ(matrix1.GetRows(), 5);

  S21Matrix result_check{5, 5};
  EXPECT_EQ(result_check.GetCols(), 5);
  EXPECT_EQ(result_check.GetRows(), 5);

  matrix1(0, 0) = 3.3402;
  matrix1(0, 1) = -7.8838;
  matrix1(0, 2) = 1.4603;
  matrix1(0, 3) = -1.3716;
  matrix1(0, 4) = 6.0723;
  matrix1(1, 0) = -7.8846;
  matrix1(1, 1) = 7.8416;
  matrix1(1, 2) = -4.2679;
  matrix1(1, 3) = 9.8356;
  matrix1(1, 4) = -2.3961;
  matrix1(2, 0) = 4.1176;
  matrix1(2, 1) = 2.0162;
  matrix1(2, 2) = 4.7337;
  matrix1(2, 3) = 6.3434;
  matrix1(2, 4) = -9.7277;
  matrix1(3, 0) = -7.4141;
  matrix1(3, 1) = -6.0886;
  matrix1(3, 2) = 3.0417;
  matrix1(3, 3) = 4.7122;
  matrix1(3, 4) = 3.8023;
  matrix1(4, 0) = -2.4891;
  matrix1(4, 1) = -5.7155;
  matrix1(4, 2) = -1.7409;
  matrix1(4, 3) = -5.2048;
  matrix1(4, 4) = -6.8199;

  result_check(0, 0) = -1465690149213583.0 / 152587890625;
  result_check(0, 1) = 1272307326797681.0 / 122070312500;
  result_check(0, 2) = 8908235542058123.0 / 610351562500;
  result_check(0, 3) = -3051493103944107.0 / 305175781250;
  result_check(0, 4) = -6463308694007859.0 / 4882812500000;
  result_check(1, 0) = -1311111307169479.0 / 610351562500;
  result_check(1, 1) = 4013698343237797.0 / 1220703125000;
  result_check(1, 2) = 1879307039061624.0 / 152587890625;
  result_check(1, 3) = -2346277736890227.0 / 305175781250;
  result_check(1, 4) = 918022536110711.0 / 1220703125000;
  result_check(2, 0) = -2046840259044663.0 / 610351562500;
  result_check(2, 1) = 4228464572521883.0 / 2441406250000;
  result_check(2, 2) = -6621800960129521.0 / 2441406250000;
  result_check(2, 3) = -2641705482122563.0 / 610351562500;
  result_check(2, 4) = 7359340653769.0 / 1953125000;
  result_check(3, 0) = 4563655460607809.0 / 610351562500;
  result_check(3, 1) = 431856638931077.0 / 1953125000000;
  result_check(3, 2) = -6291617971140427.0 / 610351562500;
  result_check(3, 3) = 1313171371096307.0 / 1220703125000;
  result_check(3, 4) = -5390167833396221.0 / 4882812500000;
  result_check(4, 0) = 2817957903551703.0 / 2441406250000;
  result_check(4, 1) = 3526500249653419.0 / 610351562500;
  result_check(4, 2) = 414413005838107.0 / 61035156250;
  result_check(4, 3) = 348820831855181.0 / 610351562500;
  result_check(4, 4) = 327320067348047.0 / 61035156250;

  S21Matrix matrix_before = matrix1;
  S21Matrix result = matrix1.CalcComplements();

  EXPECT_TRUE(result == result_check);
  EXPECT_TRUE(matrix1 == matrix_before);
}

TEST(TestCalcComplements, TestCalcComplements8) {
  S21Matrix matrix1{4, 4};
  EXPECT_EQ(matrix1.GetCols(), 4);
  EXPECT_EQ(matrix1.GetRows(), 4);

  S21Matrix result_check{4, 4};
  EXPECT_EQ(result_check.GetCols(), 4);
  EXPECT_EQ(result_check.GetRows(), 4);

  matrix1(0, 0) = 1.01;
  matrix1(0, 1) = 15;
  matrix1(0, 2) = 1;
  matrix1(0, 3) = 1;
  matrix1(1, 0) = 2;
  matrix1(1, 1) = 16;
  matrix1(1, 2) = 2;
  matrix1(1, 3) = 2;
  matrix1(2, 0) = 3;
  matrix1(2, 1) = 17;
  matrix1(2, 2) = 3;
  matrix1(2, 3) = 3;
  matrix1(3, 0) = 4;
  matrix1(3, 1) = 18;
  matrix1(3, 2) = 4;
  matrix1(3, 3) = 4;

  result_check(0, 0) = 0;
  result_check(0, 1) = 0;
  result_check(0, 2) = 0;
  result_check(0, 3) = 0;
  result_check(1, 0) = 0;
  result_check(1, 1) = 0;
  result_check(1, 2) = -0.14;
  result_check(1, 3) = 0.14;
  result_check(2, 0) = 0;
  result_check(2, 1) = 0;
  result_check(2, 2) = 0.28;
  result_check(2, 3) = -0.28;
  result_check(3, 0) = 0;
  result_check(3, 1) = 0;
  result_check(3, 2) = -0.14;
  result_check(3, 3) = 0.14;

  S21Matrix matrix_before = matrix1;
  S21Matrix result = matrix1.CalcComplements();

  EXPECT_TRUE(result == result_check);
  EXPECT_TRUE(matrix1 == matrix_before);
}

TEST(TestCalcComplements, TestCalcComplements9) {
  S21Matrix matrix1{4, 4};
  EXPECT_EQ(matrix1.GetCols(), 4);
  EXPECT_EQ(matrix1.GetRows(), 4);

  S21Matrix result_check{4, 4};
  EXPECT_EQ(result_check.GetCols(), 4);
  EXPECT_EQ(result_check.GetRows(), 4);

  matrix1(0, 0) = 1.000001;
  matrix1(0, 1) = 15;
  matrix1(0, 2) = 1;
  matrix1(0, 3) = 1;
  matrix1(1, 0) = 2;
  matrix1(1, 1) = 16;
  matrix1(1, 2) = 2;
  matrix1(1, 3) = 2;
  matrix1(2, 0) = 3;
  matrix1(2, 1) = 17;
  matrix1(2, 2) = 3;
  matrix1(2, 3) = 3;
  matrix1(3, 0) = 4;
  matrix1(3, 1) = 18;
  matrix1(3, 2) = 4;
  matrix1(3, 3) = 4;

  result_check(0, 0) = 0;
  result_check(0, 1) = 0;
  result_check(0, 2) = 0;
  result_check(0, 3) = 0;
  result_check(1, 0) = 0;
  result_check(1, 1) = 0;
  result_check(1, 2) = -1.4e-5;
  result_check(1, 3) = 1.4e-5;
  result_check(2, 0) = 0;
  result_check(2, 1) = 0;
  result_check(2, 2) = 2.8e-5;
  result_check(2, 3) = -2.8e-5;
  result_check(3, 0) = 0;
  result_check(3, 1) = 0;
  result_check(3, 2) = -1.4e-5;
  result_check(3, 3) = 1.4e-5;

  S21Matrix matrix_before = matrix1;
  S21Matrix result = matrix1.CalcComplements();

  EXPECT_TRUE(result == result_check);
  EXPECT_TRUE(matrix1 == matrix_before);
}

TEST(TestConstructor, TestConstructorException1) {
  EXPECT_ANY_THROW(S21Matrix(-1, 99));
}

TEST(TestConstructor, TestConstructorException2) {
  EXPECT_ANY_THROW(S21Matrix(99, -1));
}

TEST(TestConstructor, TestConstructorException3) {
  EXPECT_ANY_THROW(S21Matrix(-1, -1));
}

TEST(TestConstructor, TestConstructorException4) {
  EXPECT_ANY_THROW(S21Matrix(-99, -99));
}

TEST(TestConstructor, TestConstructorParams1) {
  S21Matrix matrix_check(5, 4);
  EXPECT_EQ(matrix_check.GetRows(), 5);
  EXPECT_EQ(matrix_check.GetCols(), 4);
}

TEST(TestConstructor, TestConstructorParams2) {
  S21Matrix matrix_check(999, 1999);
  EXPECT_EQ(matrix_check.GetRows(), 999);
  EXPECT_EQ(matrix_check.GetCols(), 1999);
}

TEST(TestConstructor, TestConstructorCopy1) {
  S21Matrix matrix_check = S21Matrix(2, 2);

  matrix_check(0, 0) = 4.0;
  matrix_check(0, 1) = 4.0;
  matrix_check(1, 0) = 4.0;
  matrix_check(1, 1) = 4.0;

  S21Matrix matrix_copy = matrix_check;

  EXPECT_EQ(matrix_check.GetCols(), 2);
  EXPECT_EQ(matrix_check.GetRows(), 2);

  EXPECT_EQ(matrix_copy.GetCols(), 2);
  EXPECT_EQ(matrix_copy.GetRows(), 2);
}

TEST(TestConstructor, TestConstructorCopy2) {
  S21Matrix matrix_check = S21Matrix(2, 2);

  matrix_check(0, 0) = 4.0;
  matrix_check(0, 1) = 4.0;
  matrix_check(1, 0) = 4.0;
  matrix_check(1, 1) = 4.0;

  S21Matrix matrix_copy(matrix_check);

  EXPECT_EQ(matrix_check.GetCols(), 2);
  EXPECT_EQ(matrix_check.GetRows(), 2);

  EXPECT_EQ(matrix_copy.GetCols(), 2);
  EXPECT_EQ(matrix_copy.GetRows(), 2);
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
