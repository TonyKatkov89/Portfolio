#include "test.h"

bool setsAreEqual(s21::set<int> S1, std::set<int> S2) {
  if (S1.size() != S2.size()) return false;
  auto it_S1 = S1.begin();
  auto it_S2 = S2.begin();
  for (; it_S2 != S2.end(); ++it_S1, ++it_S2) {
    if (*it_S1 != *it_S2) return false;
  }
  return true;
}

TEST(S21BtreeTest_SET, CONSTRUCTOR1) {
  s21::set<int> BT1;
  std::set<int> S2;

  ASSERT_EQ(setsAreEqual(BT1, S2), true);
}

TEST(S21BtreeTest_SET, CONSTRUCTOR2) {
  s21::set<int> BT1 = {5, 1, 2, 3};
  std::set<int> S2 = {5, 1, 2, 3};

  ASSERT_EQ(setsAreEqual(BT1, S2), true);
}

TEST(S21BtreeTest_SET, OPERATOR_ASSIGN_1) {
  s21::set<int> BT1 = {5, 1, 2, 3};
  s21::set<int> BT2 = BT1;
  std::set<int> S2 = {5, 1, 2, 3};

  ASSERT_EQ(setsAreEqual(BT2, S2), true);
}

TEST(S21BtreeTest_SET, OPERATOR_ASSIGN_EMPTY) {
  s21::set<int>* BT1 = new s21::set<int>();
  s21::set<int> BT2 = *BT1;
  std::set<int> S2 = {};

  ASSERT_EQ(setsAreEqual(BT2, S2), true);
  delete BT1;
}

TEST(METHOD_SIZE_SET, SIZE_DEFAULT_CONSTRUCTOR) {
  s21::set<int> BT1;
  std::set<int> S2;
  ASSERT_EQ(BT1.size(), S2.size());
}

TEST(METHOD_SIZE_SET, SIZE_LIST_CONSTRUCTOR) {
  s21::set<int> BT1 = {1, 2, 3};
  std::set<int> S2 = {1, 2, 3};
  ASSERT_EQ(BT1.size(), S2.size());
}

TEST(METHOD_EMPTY_SET, EMPTY_DEFAULT_CONSTRUCTOR) {
  s21::set<int> BT1;
  std::set<int> S2;
  ASSERT_EQ(BT1.empty(), S2.empty());
}

TEST(METHOD_EMPTY_SET, EMPTY_LIST_CONSTRUCTOR) {
  s21::set<int> BT1 = {1, 2, 3};
  std::set<int> S2 = {1, 2, 3};
  ASSERT_EQ(BT1.empty(), S2.empty());
  s21::set<int> BT3 = {};
  std::set<int> S4 = {};
  ASSERT_EQ(BT3.empty(), S4.empty());
  s21::set<int> BT5 = {1};
  std::set<int> S6 = {1};
  ASSERT_EQ(BT5.empty(), S6.empty());
}

TEST(METHOD_MAX_SIZE_SET, MAX_SIZE) {
  s21::set<int> BT1 = {1, 2, 3};
  std::set<int> S2 = {1, 2, 3};
  EXPECT_NEAR(BT1.max_size() / S2.max_size(), 1, 1);
}

TEST(METHOD_CLEAR_SET, CLEAR) {
  s21::set<int> BT1 = {1, 2, 3};
  std::set<int> S2 = {1, 2, 3};
  BT1.clear();
  S2.clear();

  ASSERT_EQ(setsAreEqual(BT1, S2), true);
}

TEST(METHOD_SWAP_SET, SWAP1) {
  s21::set<int> BT1{1, 2, 3};
  s21::set<int> BT2{};
  std::set<int> S3 = {1, 2, 3};
  std::set<int> S4 = {};

  BT1.swap(BT2);
  S3.swap(S4);

  ASSERT_EQ(setsAreEqual(BT1, S3), true);
  ASSERT_EQ(setsAreEqual(BT2, S4), true);
}

TEST(METHOD_SWAP_SET, SWAP2) {
  s21::set<int> BT1{};
  s21::set<int> BT2{1, 2, 3};
  std::set<int> S3 = {};
  std::set<int> S4 = {1, 2, 3};

  BT1.swap(BT2);
  S3.swap(S4);

  ASSERT_EQ(setsAreEqual(BT1, S3), true);
  ASSERT_EQ(setsAreEqual(BT2, S4), true);
}

TEST(METHOD_SWAP_SET, SWAP3_NUMBER_OF_ELEMENTS) {
  s21::set<int> BT1 = {1, 2, 3};
  s21::set<int> BT2 = {4, 5, 6};
  std::set<int> S3 = {1, 2, 3};
  std::set<int> S4 = {4, 5, 6};

  BT1.swap(BT2);
  S3.swap(S4);

  ASSERT_EQ(setsAreEqual(BT1, S3), true);
  ASSERT_EQ(setsAreEqual(BT2, S4), true);
}

TEST(METHOD_SWAP_SET, SWAP4_DIFFERENT_NUMBER_OF_ELEMENTS1) {
  s21::set<int> BT1{1, 2, 3, 4, 5};
  s21::set<int> BT2{6, 7, 8};
  std::set<int> S3 = {1, 2, 3, 4, 5};
  std::set<int> S4 = {9, 10, 11};

  BT1.swap(BT2);
  S3.swap(S4);

  ASSERT_EQ(setsAreEqual(BT1, S3), false);
  ASSERT_EQ(setsAreEqual(BT2, S4), true);
}

TEST(METHOD_SWAP_SET, SWAP5_DIFFERENT_NUMBER_OF_ELEMENTS2) {
  s21::set<int> BT1 = {1, 2, 3};
  s21::set<int> BT2 = {4, 5, 6, 77, 88};
  std::set<int> S3 = {1, 2, 3};
  std::set<int> S4 = {4, 5, 6, 99, 111};

  BT1.swap(BT2);
  S3.swap(S4);

  ASSERT_EQ(setsAreEqual(BT1, S3), false);
  ASSERT_EQ(setsAreEqual(BT2, S4), true);
}

TEST(METHOD_INSERT_SET, INSERT_EXISTING_ELEMENT) {
  s21::set<int> BT1 = {1, 2, 3};
  std::set<int> S2 = {1, 2, 3};
  BT1.insert(3);
  S2.insert(3);

  ASSERT_EQ(setsAreEqual(BT1, S2), true);
}

TEST(METHOD_INSERT_SET, INSERT_ZERO_ELEMENTS) {
  s21::set<int> BT1 = {};
  std::set<int> S2 = {};
  BT1.insert(3);
  S2.insert(3);

  ASSERT_EQ(setsAreEqual(BT1, S2), true);
}

TEST(METHOD_INSERT_SET, INSERT_MIDDLE_ELEMENT) {
  s21::set<int> BT1 = {1, 3, 4};
  std::set<int> S2 = {1, 3, 4};
  BT1.insert(2);
  S2.insert(2);

  ASSERT_EQ(setsAreEqual(BT1, S2), true);
}

TEST(METHOD_INSERT_SET, INSERT_INSERT) {
  s21::set<int> BT1 = {1, 2, 3};
  s21::set<int> BT2 = {1, 2, 3, 4};
  BT1.insert(4);

  bool res = true;

  if (BT1.size() != BT2.size()) res = false;

  auto it_S1 = BT1.begin();
  auto it_S2 = BT2.begin();
  for (; it_S2 != BT2.end(); ++it_S1, ++it_S2) {
    if (*it_S1 != *it_S2) res = false;
  }

  ASSERT_EQ(res, true);
}

TEST(METHOD_ERASE_SET, ERASE_ROOT) {
  s21::set<int> BT1 = {45, 11, 27, 51, 35, 9,  86, 22,
                       81, 88, 44, 55, 28, 56, 64};
  std::set<int> S2 = {45, 11, 27, 51, 35, 9,  86, 22,
                      81, 88, 44, 55, 28, 56, 64};
  BT1.erase(BT1.find(45));
  S2.erase(S2.find(45));

  ASSERT_EQ(setsAreEqual(BT1, S2), true);
}

TEST(METHOD_ERASE_SET, ERASE_PARENT_BLACK_SIBLING_BLACK_NAPHEWS_BLACK_1) {
  s21::set<int> BT1 = {45, 11, 27, 51, 35, 9,  86, 22,
                       81, 88, 44, 55, 28, 56, 64};
  std::set<int> S2 = {45, 11, 27, 51, 35, 9,  86, 22,
                      81, 88, 44, 55, 28, 56, 64};
  BT1.erase(BT1.find(81));
  S2.erase(S2.find(81));

  ASSERT_EQ(setsAreEqual(BT1, S2), true);
}

TEST(METHOD_ERASE_SET, ERASE_PARENT_BLACK_SIBLING_BLACK_NAPHEWS_BLACK_2) {
  s21::set<int> BT1 = {45, 11, 27, 51, 35, 9,  86, 22, 81, 88, 44, 55, 28,
                       56, 64, 80, 5,  18, 21, 57, 54, 33, 21, 13, 66, 69,
                       10, 47, 56, 57, 58, 59, 60, 61, 62, 63, 64};
  std::set<int> S2 = {45, 11, 27, 51, 35, 9,  86, 22, 81, 88, 44, 55, 28,
                      56, 64, 80, 5,  18, 21, 57, 54, 33, 21, 13, 66, 69,
                      10, 47, 56, 57, 58, 59, 60, 61, 62, 63, 64};
  BT1.erase(BT1.find(47));
  S2.erase(S2.find(47));
  BT1.erase(BT1.find(54));
  S2.erase(S2.find(54));
  // BT1.print_tree();
  BT1.erase(BT1.find(56));
  S2.erase(S2.find(56));
  // BT1.print_tree();

  ASSERT_EQ(setsAreEqual(BT1, S2), true);
}

TEST(METHOD_ERASE_SET, ERASE_PARENT_BLACK_SIBLING_RED_NAPHEWS_BLACK) {
  s21::set<int> BT1 = {45, 11, 27, 51, 35, 9,  86, 22,
                       81, 88, 44, 55, 28, 56, 64};
  std::set<int> S2 = {45, 11, 27, 51, 35, 9,  86, 22,
                      81, 88, 44, 55, 28, 56, 64};
  BT1.erase(BT1.find(86));
  S2.erase(S2.find(86));

  ASSERT_EQ(setsAreEqual(BT1, S2), true);
}

TEST(METHOD_ERASE_SET, ERASE_RED_NO_CHILDREN) {
  s21::set<int> BT1 = {45, 11, 27, 51, 35, 9,  86, 22,
                       81, 88, 44, 55, 28, 56, 64};
  std::set<int> S2 = {45, 11, 27, 51, 35, 9,  86, 22,
                      81, 88, 44, 55, 28, 56, 64};
  BT1.erase(BT1.find(28));
  S2.erase(S2.find(28));

  ASSERT_EQ(setsAreEqual(BT1, S2), true);
}

TEST(METHOD_ERASE_SET, ERASE_RED_HAS_CHILDREN_DISTANT_NAPHEW_RED) {
  s21::set<int> BT1 = {45, 11, 27, 51, 35, 9,  86, 22,
                       81, 88, 44, 55, 28, 56, 64};
  std::set<int> S2 = {45, 11, 27, 51, 35, 9,  86, 22,
                      81, 88, 44, 55, 28, 56, 64};
  // BT1.print_tree();
  BT1.erase(BT1.find(55));
  S2.erase(S2.find(55));
  // BT1.print_tree();

  ASSERT_EQ(setsAreEqual(BT1, S2), true);
}

TEST(METHOD_ERASE_SET, ERASE_RED_HAS_CHILDREN_CLOSER_NAPHEW_RED) {
  s21::set<int> BT1 = {45, 11, 27, 51, 35, 9,  86, 22,
                       81, 88, 44, 55, 28, 64, 56};
  std::set<int> S2 = {45, 11, 27, 51, 35, 9,  86, 22,
                      81, 88, 44, 55, 28, 64, 56};
  // BT1.print_tree();
  BT1.erase(BT1.find(55));
  S2.erase(S2.find(55));
  // BT1.print_tree();

  ASSERT_EQ(setsAreEqual(BT1, S2), true);
}

TEST(METHOD_ERASE_SET,
     ERASE_PARENT_BLACK_SIBLING_RED_NAPHEWS_BLACK_WITH_NO_RED_CHILDREN) {
  s21::set<int> BT1 = {45, 11, 27, 51, 35, 9,  86, 22,
                       81, 88, 44, 55, 28, 56, 64};
  std::set<int> S2 = {45, 11, 27, 51, 35, 9,  86, 22,
                      81, 88, 44, 55, 28, 56, 64};
  BT1.erase(BT1.find(88));
  S2.erase(S2.find(88));
  BT1.erase(BT1.find(64));
  S2.erase(S2.find(64));
  BT1.erase(BT1.find(86));
  S2.erase(S2.find(86));

  ASSERT_EQ(setsAreEqual(BT1, S2), true);
}

TEST(METHOD_ERASE_SET, ERASE_PARENT_BLACK_SIBLING_BLACK_HAS_RED_NAPHEWS) {
  s21::set<int> BT1 = {45, 11, 27, 51, 35, 9,  86, 22,
                       81, 88, 44, 55, 28, 56, 64};
  std::set<int> S2 = {45, 11, 27, 51, 35, 9,  86, 22,
                      81, 88, 44, 55, 28, 56, 64};
  BT1.erase(BT1.find(9));
  S2.erase(S2.find(9));
  BT1.erase(BT1.find(22));
  S2.erase(S2.find(22));
  // BT1.print_tree();
  BT1.erase(BT1.find(11));
  S2.erase(S2.find(11));
  // BT1.print_tree();

  ASSERT_EQ(setsAreEqual(BT1, S2), true);
}

TEST(METHOD_MERGE_SET, MERGE_DIFFERENT_ELEMENTS1) {
  s21::set<int> BT1 = {1, 3, 5};
  s21::set<int> BT2 = {2, 4, 6};
  std::set<int> S3 = {1, 3, 5, 2, 4, 6};
  BT1.merge(BT2);

  bool res = true;

  if (BT1.size() != S3.size()) res = false;

  auto it_S1 = BT1.begin();
  auto it_S2 = S3.begin();
  for (; it_S2 != S3.end(); ++it_S1, ++it_S2) {
    if (*it_S1 != *it_S2) res = false;
  }

  ASSERT_EQ(res, true);
}

TEST(METHOD_MERGE_SET, MERGE_DIFFERENT_ELEMENTS2) {
  s21::set<int> BT1 = {1, 3, 5};
  s21::set<int> BT2 = {2, 4, 6};
  s21::set<int> BT3 = {1, 2, 3, 4, 5, 6};  // {1, 3, 5, 2, 4, 6};
  BT1.merge(BT2);

  bool res = true;

  if (BT1.size() != BT3.size()) res = false;

  auto it_S1 = BT1.begin();
  auto it_S2 = BT3.begin();
  for (; it_S2 != BT3.end(); ++it_S1, ++it_S2) {
    if (*it_S1 != *it_S2) res = false;
  }

  ASSERT_EQ(res, true);
}

TEST(METHOD_FIND_SET, FIND_EXISTING_ELEMENT) {
  s21::set<int> BT1 = {45, 11, 27, 51, 35, 9,  86, 22,
                       81, 88, 44, 55, 28, 56, 64};
  std::set<int> S2 = {45, 11, 27, 51, 35, 9,  86, 22,
                      81, 88, 44, 55, 28, 56, 64};
  auto it_S1 = BT1.find(88);
  auto it_S2 = S2.find(88);
  ASSERT_EQ(*it_S1, *it_S2);
}

TEST(METHOD_FIND_SET, FIND_NOT_EXISTING_ELEMENT1) {
  s21::set<int> BT1 = {45, 11, 27, 51, 35, 9,  86, 22,
                       81, 88, 44, 55, 28, 56, 64};
  auto it_S1 = BT1.find(101);
  ASSERT_EQ(it_S1, BT1.end());
}

TEST(METHOD_CONTAINS_SET, CONTAINS_EXISTING_ELEMENT) {
  s21::set<int> BT1 = {45, 11, 27, 51, 35, 9,  86, 22,
                       81, 88, 44, 55, 28, 56, 64};
  ASSERT_EQ(BT1.contains(56), true);
}

TEST(METHOD_CONTAINS_SET, CONTAINS_NOT_EXISTING_ELEMENT) {
  s21::set<int> BT1 = {45, 11, 27, 51, 35, 9,  86, 22,
                       81, 88, 44, 55, 28, 56, 64};
  ASSERT_EQ(BT1.contains(1), false);
}
