#include "test.h"

template <typename T>
bool array_comparision(s21::array<T, 15> &a1, std::array<T, 15> &a2) {
  for (std::size_t i = 0; i < 14; ++i) {
    if (a1[i] != a2[i]) {
      return false;
    }
  }
  return true;
}

TEST(ARRAY_CONSTR, DEFAULT_CONSTR1) {
  s21::array<int, 5> a1;

  ASSERT_NO_THROW(a1[0]);
}

TEST(ARRAY_CONSTR, DEFAULT_CONSTR2) {
  s21::array<int, 55> a1;

  ASSERT_NO_THROW(a1[0]);
}

TEST(ARRAY_CONSTR, LIST_CONSTR1) {
  s21::array<int, 15> a1{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14};
  std::array<int, 15> a2{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14};

  ASSERT_EQ(array_comparision(a1, a2), true);
}

TEST(ARRAY_CONSTR, LIST_CONSTR2) {
  s21::array<std::string, 15> a1{"h", "e", "l", "l", "l", "o", " ", "w",
                                 "o", "r", "l", "d", "!", " ", " "};
  std::array<std::string, 15> a2{"h", "e", "l", "l", "l", "o", " ", "w",
                                 "o", "r", "l", "d", "!", " ", " "};

  ASSERT_EQ(array_comparision(a1, a2), true);
}

TEST(ARRAY_CONSTR, COPY_CONSTR1) {
  s21::array<int, 15> a1{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14};
  s21::array<int, 15> a2(a1);
  std::array<int, 15> a3{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14};
  std::array<int, 15> a4(a3);

  ASSERT_EQ(array_comparision(a2, a4), true);
}

TEST(ARRAY_CONSTR, MOVE_CONSTR1) {
  s21::array<int, 15> a1{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14};
  s21::array<int, 15> a2(std::move(a1));
  std::array<int, 15> a3{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14};
  std::array<int, 15> a4(std::move(a3));

  ASSERT_EQ(array_comparision(a1, a3), true);
  ASSERT_EQ(array_comparision(a2, a4), true);
}

TEST(ARRAY_METHODS, ARRAY_BEGIN1) {
  s21::array<int, 15> a1{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14};
  std::array<int, 15> a2{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14};

  ASSERT_EQ(*a1.begin(), *a2.begin());
}

TEST(ARRAY_METHODS, ARRAY_END1) {
  s21::array<int, 15> a1{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14};
  std::array<int, 15> a2{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14};

  s21::array<int, 15>::iterator it = a1.end();
  --it;
  std::array<int, 15>::iterator std_it = a2.end();
  --std_it;

  ASSERT_EQ(*it, *std_it);
}

TEST(ARRAY_METHODS, ARRAY_DATA) {
  s21::array<int, 15> a1{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14};
  std::array<int, 15> a2{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14};

  ASSERT_EQ(*a1.data(), *a2.data());
}

TEST(ARRAY_METHODS, ARRAY_AT_BOUNDS) {
  s21::array<int, 15> a1{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14};
  std::array<int, 15> a2{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14};

  ASSERT_EQ(a1.at(2), a2.at(2));
}

TEST(ARRAY_METHODS, ARRAY_AT_OUT_OF_BOUNDS) {
  s21::array<int, 15> a1{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14};
  std::array<int, 15> a2{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14};

  ASSERT_THROW(a1.at(87), std::out_of_range);
  ASSERT_THROW(a2.at(87), std::out_of_range);
}

TEST(ARRAY_METHODS, ARRAY_FRONT) {
  s21::array<int, 15> a1{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14};
  std::array<int, 15> a2{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14};

  ASSERT_EQ(a1.front(), a2.front());
}

TEST(ARRAY_METHODS, ARRAY_BACK) {
  s21::array<int, 15> a1{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14};
  std::array<int, 15> a2{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14};

  ASSERT_EQ(a1.back(), a2.back());
}

TEST(ARRAY_METHODS, ARRAY_IS_EMPTY) {
  s21::array<int, 15> a1;
  std::array<int, 15> a2;

  ASSERT_EQ(a1.empty(), a2.empty());
}

TEST(ARRAY_METHODS, ARRAY_IS_NOT_EMPTY) {
  s21::array<int, 15> a1{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14};
  std::array<int, 15> a2{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14};

  ASSERT_EQ(a1.empty(), a2.empty());
}

TEST(ARRAY_METHODS, ARRAY_SIZE) {
  s21::array<int, 15> a1{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14};
  std::array<int, 15> a2{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14};

  ASSERT_EQ(a1.size(), a2.size());
}

TEST(ARRAY_METHODS, ARRAY_SIZE_ZERO) {
  s21::array<int, 0> a1;
  std::array<int, 0> a2;

  ASSERT_EQ(a1.size(), a2.size());
}

TEST(ARRAY_METHODS, ARRAY_MAX_SIZE) {
  s21::array<int, 15> a1{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14};
  std::array<int, 15> a2{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14};

  ASSERT_EQ(a1.max_size(), a2.max_size());
}

TEST(ARRAY_METHODS, ARRAY_MAX_SIZE_ZERO) {
  s21::array<int, 0> a1;
  std::array<int, 0> a2;

  ASSERT_EQ(a1.max_size(), a2.max_size());
}

TEST(ARRAY_METHODS, ARRAY_SWAP_SAME_SIZE) {
  s21::array<int, 15> a1{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14};
  s21::array<int, 15> a2{9, 1, 1, 1, 1, 1, 1, 1, 1, 1, 10, 11, 12, 13, 14};

  std::array<int, 15> a3{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14};
  std::array<int, 15> a4{9, 1, 1, 1, 1, 1, 1, 1, 1, 1, 10, 11, 12, 13, 14};

  a1.swap(a2);
  a3.swap(a4);
  ASSERT_EQ(array_comparision(a1, a3), true);
  ASSERT_EQ(array_comparision(a2, a4), true);
}

TEST(ARRAY_METHODS, ARRAY_FILL) {
  s21::array<int, 15> a1;
  std::array<int, 15> a2;

  a1.fill(1);
  a2.fill(1);
  ASSERT_EQ(array_comparision(a1, a2), true);
}

TEST(ARRAY_ASSIGNMENT, ARRAY_COPY_OPERATOR) {
  s21::array<int, 15> a1{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14};
  s21::array<int, 15> a2{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};

  std::array<int, 15> a3{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14};
  std::array<int, 15> a4{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};

  a1 = a2;
  a3 = a4;
  ASSERT_EQ(array_comparision(a1, a3), true);
}

TEST(ARRAY_ASSIGNMENT, ARRAY_MOVE_OPERATOR) {
  s21::array<int, 15> a1{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14};
  s21::array<int, 15> a2{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};

  std::array<int, 15> a3{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14};
  std::array<int, 15> a4{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};

  a1 = std::move(a2);
  a3 = std::move(a4);
  ASSERT_EQ(array_comparision(a1, a3), true);
}

TEST(ARRAY_OPERATOR, ARRAY_INDEXATION1) {
  s21::array<int, 15> a1{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14};
  std::array<int, 15> a2{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14};

  ASSERT_EQ(a1[1], a2[1]);
}

TEST(ARRAY_OPERATOR, ARRAY_INDEXATION2) {
  const s21::array<int, 15> a1{0, 1, 2,  3,  4,  5,  6, 7,
                               8, 9, 10, 11, 12, 13, 14};
  const std::array<int, 15> a2{0, 1, 2,  3,  4,  5,  6, 7,
                               8, 9, 10, 11, 12, 13, 14};

  ASSERT_EQ(a1[1], a2[1]);
}

TEST(ARRAY_OPERATOR, ARRAY_INDEXATION3) {
  const s21::array<int, 15> a1{0, 1, 2,  3,  4,  5,  6, 7,
                               8, 9, 10, 11, 12, 13, 14};

  ASSERT_THROW(a1[99], std::out_of_range);
}

TEST(ARRAY_OPERATOR, ARRAY_ASSERTION) {
  s21::array<int, 15> a1{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14};
  std::array<int, 15> a2{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14};

  a1[1] = 15;
  a2[1] = 15;
  ASSERT_EQ(a1[1], a2[1]);
}
