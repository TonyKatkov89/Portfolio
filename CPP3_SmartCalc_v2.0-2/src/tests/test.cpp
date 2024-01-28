#include "../model/calculator.h"
#include "gtest/gtest.h"

static double EPS = 0.00000005;

TEST(s21_SmartCalc_v2, test_1) {
  std::string input = "((3+2)-x)^2";
  double x = 2.;
  s21::Calculator calc(input);
  double result = calc.Result(x);
  EXPECT_NEAR(result, 9., EPS);
}

TEST(s21_SmartCalc_v2, test_2) {
  std::string input = "tan2x*sinx^2";
  double x = 2.;
  s21::Calculator calc(input);
  double result = calc.Result(x);
  EXPECT_NEAR(result, -0.8762420356, EPS);
}

TEST(s21_SmartCalc_v2, test_3) {
  std::string input = "5/0";
  double x = 2.;
  s21::Calculator calc(input);
  double result = calc.Result(x);
  EXPECT_EQ(result != result, true);
}

TEST(s21_SmartCalc_v2, test_4) {
  std::string input = "tn2x*sinx^2";
  double x = 2.;
  s21::Calculator calc(input);
  double result = calc.Result(x);
  EXPECT_EQ(result != result, true);
}

TEST(s21_SmartCalc_v2, test_5) {
  std::string input = "+some shit";
  double x = 2.;
  s21::Calculator calc(input);
  double result = calc.Result(x);
  EXPECT_EQ(result != result, true);
}

TEST(s21_SmartCalc_v2, test_6) {
  std::string input = "cos(-2*5^6.412)*2.6x^3";
  double x = 2.;
  s21::Calculator calc(input);
  double result = calc.Result(x);
  EXPECT_NEAR(result, -13.9485561566, EPS);
}

TEST(s21_SmartCalc_v2, test_7) {
  std::string input = "acos(cosx)";
  double x = 0.5;
  s21::Calculator calc(input);
  double result = calc.Result(x);
  EXPECT_NEAR(result, 0.5, EPS);
}

TEST(s21_SmartCalc_v2, test_8) {
  std::string input = "atan(tanx)";
  double x = 0.5;
  s21::Calculator calc(input);
  double result = calc.Result(x);
  EXPECT_NEAR(result, 0.5, EPS);
}

TEST(s21_SmartCalc_v2, test_9) {
  std::string input = "ctgx";
  double x = 0.5;
  s21::Calculator calc(input);
  double result = calc.Result(x);
  EXPECT_NEAR(result, 1.83048772171, EPS);
}

TEST(s21_SmartCalc_v2, test_10) {
  std::string input = "asin(sinx)/2";
  double x = 0.5;
  s21::Calculator calc(input);
  double result = calc.Result(x);
  EXPECT_NEAR(result, 0.25, EPS);
}

TEST(s21_SmartCalc_v2, test_11) {
  std::string input = "log(ln(xmod1+1)";
  double x = 3.5;
  s21::Calculator calc(input);
  double result = calc.Result(x);
  EXPECT_NEAR(result, -0.39204651261, EPS);
}

TEST(s21_SmartCalc_v2, test_12) {
  std::string input = "sqrt(+x)";
  double x = 3.5;
  s21::Calculator calc(input);
  double result = calc.Result(x);
  EXPECT_NEAR(result, 1.87082869339, EPS);
}

TEST(s21_SmartCalc_v2, test_13) {
  std::string input = "sqrt(-x)";
  double x = 3.5;
  s21::Calculator calc(input);
  double result = calc.Result(x);
  EXPECT_EQ(result != result, true);
}

TEST(s21_SmartCalc_v2, test_14) {
  std::string input = "mod0";
  double x = 2.;
  s21::Calculator calc(input);
  double result = calc.Result(x);
  EXPECT_EQ(result != result, true);
}

TEST(s21_SmartCalc_v2, test_15) {
  std::string input = "x*cos(-2*5^6.412)*2.6x^3";
  double x = 2.;
  s21::Calculator calc(input);
  double result = calc.Result(x);
  EXPECT_NEAR(result, -27.8971123132, EPS);
}

TEST(s21_SmartCalc_v2, test_16) {
  std::string input = "5+2$";
  double x = 2.;
  s21::Calculator calc(input);
  double result = calc.Result(x);
  EXPECT_EQ(result != result, true);
}

TEST(s21_SmartCalc_v2, test_17) {
  double s = 12000000;
  double p = 5.5 / 100;
  double n = 360;
  double result = s21::Calculator::CAnnuityPayment(s, p, n);
  EXPECT_NEAR(result, 68134.68, 0.005);
}

TEST(s21_SmartCalc_v2, test_18) {
  double s = 60000;
  double p = 5.5 / 100;
  double result = s21::Calculator::CInterestSum(s, p);
  EXPECT_NEAR(result, 275, 0.005);
}

TEST(s21_SmartCalc_v2, test_19) {
  double s = 12000000;
  double p = 0;
  double n = 300;
  double result = s21::Calculator::CAnnuityPayment(s, p, n);
  EXPECT_NEAR(result, 40000, 0.005);
}

TEST(s21_SmartCalc_v2, test_20) {
  std::string input = "x+2";
  double x = 2.;
  s21::Calculator calc(input);
  double result = calc.Result(x);
  EXPECT_NEAR(result, 4, EPS);
}

TEST(s21_SmartCalc_v2, test_21) {
  std::string input{"x + 2"};
  double x = 2.;
  s21::Calculator calc(input);
  double result = calc.Result(x);
  EXPECT_NEAR(result, 4, EPS);
}

TEST(s21_SmartCalc_v2, test_22) {
  std::string input = "((((((((((";
  double x = 2.;
  s21::Calculator calc(input);
  double result = calc.Result(x);
  EXPECT_EQ(result != result, true);
}

TEST(s21_SmartCalc_v2, test_23) {
  std::string input = "3+*6";
  double x = 2.;
  s21::Calculator calc(input);
  double result = calc.Result(x);
  EXPECT_EQ(result != result, true);
}

int main() {
  ::testing::InitGoogleTest();
  return RUN_ALL_TESTS();
}