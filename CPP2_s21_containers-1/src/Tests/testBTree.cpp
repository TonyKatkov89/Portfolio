#include "test.h"

bool mapsAreEqual(s21::BinaryTree<int, char> S1, std::map<int, char> S2) {
  if (S1.size() != S2.size()) return false;
  auto it_S1 = S1.begin();
  auto it_S2 = S2.begin();
  for (; it_S2 != S2.end(); ++it_S1, ++it_S2) {
    if (*it_S1 != *it_S2) return false;
  }
  return true;
}

TEST(S21BtreeTest, CONSTRUCTOR1) {
  s21::BinaryTree<int, char> BT1;
  std::map<int, char> S2;

  ASSERT_EQ(mapsAreEqual(BT1, S2), true);
}

TEST(S21BtreeTest, CONSTRUCTOR2) {
  s21::BinaryTree<int, char> BT1 = {{5, 'a'}, {1, 'b'}, {2, 'c'}, {3, 'd'}};
  std::map<int, char> S2 = {{5, 'a'}, {1, 'b'}, {2, 'c'}, {3, 'd'}};

  ASSERT_EQ(mapsAreEqual(BT1, S2), true);
}

TEST(S21BtreeTest, OPERATOR_ASSIGN_1) {
  s21::BinaryTree<int, char> BT1 = {{5, 'a'}, {1, 'b'}, {2, 'c'}, {3, 'd'}};
  s21::BinaryTree<int, char> BT2 = BT1;
  std::map<int, char> S2 = {{5, 'a'}, {1, 'b'}, {2, 'c'}, {3, 'd'}};

  ASSERT_EQ(mapsAreEqual(BT2, S2), true);
}

TEST(S21BtreeTest, OPERATOR_ASSIGN_EMPTY) {
  s21::BinaryTree<int, char>* BT1 = new s21::BinaryTree<int, char>();
  s21::BinaryTree<int, char> BT2 = *BT1;
  std::map<int, char> S2 = {};

  ASSERT_EQ(mapsAreEqual(BT2, S2), true);
  delete BT1;
}

TEST(METHOD_SIZE, SIZE_DEFAULT_CONSTRUCTOR) {
  s21::BinaryTree<int, char> BT1;
  std::map<int, char> S2;
  ASSERT_EQ(BT1.size(), S2.size());
}

TEST(METHOD_SIZE, SIZE_LIST_CONSTRUCTOR) {
  s21::BinaryTree<int, char> BT1 = {{1, 'b'}, {2, 'c'}, {3, 'd'}};
  std::map<int, char> S2 = {{1, 'b'}, {2, 'c'}, {3, 'd'}};
  ASSERT_EQ(BT1.size(), S2.size());
}

TEST(METHOD_EMPTY, EMPTY_DEFAULT_CONSTRUCTOR) {
  s21::BinaryTree<int, char> BT1;
  std::map<int, char> S2;
  ASSERT_EQ(BT1.empty(), S2.empty());
}

TEST(METHOD_EMPTY, EMPTY_LIST_CONSTRUCTOR) {
  s21::BinaryTree<int, char> BT1 = {{1, 'b'}, {2, 'c'}, {3, 'd'}};
  std::map<int, char> S2 = {{1, 'b'}, {2, 'c'}, {3, 'd'}};
  ASSERT_EQ(BT1.empty(), S2.empty());
  s21::BinaryTree<int, char> BT3 = {};
  std::map<int, char> S4 = {};
  ASSERT_EQ(BT3.empty(), S4.empty());
  s21::BinaryTree<int, char> BT5 = {{1, 'b'}};
  std::map<int, char> S6 = {{1, 'b'}};
  ASSERT_EQ(BT5.empty(), S6.empty());
}

TEST(METHOD_MAX_SIZE, MAX_SIZE) {
  s21::BinaryTree<int, char> BT1 = {{1, 'b'}, {2, 'c'}, {3, 'd'}};
  std::map<int, char> S2 = {{1, 'b'}, {2, 'c'}, {3, 'd'}};
  EXPECT_NEAR(BT1.max_size() / S2.max_size(), 1, 1);
}

TEST(METHOD_CLEAR, CLEAR) {
  s21::BinaryTree<int, char> BT1 = {{1, 'b'}, {2, 'c'}, {3, 'd'}};
  std::map<int, char> S2 = {{1, 'b'}, {2, 'c'}, {3, 'd'}};
  BT1.clear();
  S2.clear();

  ASSERT_EQ(mapsAreEqual(BT1, S2), true);
}

TEST(METHOD_SWAP, SWAP1) {
  s21::BinaryTree<int, char> BT1{{1, 'b'}, {2, 'c'}, {3, 'd'}};
  s21::BinaryTree<int, char> BT2{};
  std::map<int, char> S3 = {{1, 'b'}, {2, 'c'}, {3, 'd'}};
  std::map<int, char> S4 = {};

  BT1.swap(BT2);
  S3.swap(S4);

  ASSERT_EQ(mapsAreEqual(BT1, S3), true);
  ASSERT_EQ(mapsAreEqual(BT2, S4), true);
}

TEST(METHOD_SWAP, SWAP2) {
  s21::BinaryTree<int, char> BT1{};
  s21::BinaryTree<int, char> BT2{{1, 'b'}, {2, 'c'}, {3, 'd'}};
  std::map<int, char> S3 = {};
  std::map<int, char> S4 = {{1, 'b'}, {2, 'c'}, {3, 'd'}};

  BT1.swap(BT2);
  S3.swap(S4);

  ASSERT_EQ(mapsAreEqual(BT1, S3), true);
  ASSERT_EQ(mapsAreEqual(BT2, S4), true);
}

TEST(METHOD_SWAP, SWAP3_NUMBER_OF_ELEMENTS) {
  s21::BinaryTree<int, char> BT1 = {{1, 'b'}, {2, 'c'}, {3, 'd'}};
  s21::BinaryTree<int, char> BT2 = {{4, 'e'}, {5, 'f'}, {6, 'g'}};
  std::map<int, char> S3 = {{1, 'b'}, {2, 'c'}, {3, 'd'}};
  std::map<int, char> S4 = {{4, 'e'}, {5, 'f'}, {6, 'g'}};

  BT1.swap(BT2);
  S3.swap(S4);

  ASSERT_EQ(mapsAreEqual(BT1, S3), true);
  ASSERT_EQ(mapsAreEqual(BT2, S4), true);
}

TEST(METHOD_SWAP, SWAP4_DIFFERENT_NUMBER_OF_ELEMENTS1) {
  s21::BinaryTree<int, char> BT1{
      {1, 'b'}, {2, 'c'}, {3, 'd'}, {4, 'e'}, {5, 'f'}};
  s21::BinaryTree<int, char> BT2{{6, 'g'}, {7, 'h'}, {8, 'i'}};
  std::map<int, char> S3 = {{1, 'b'}, {2, 'c'}, {3, 'd'}, {4, 'e'}, {5, 'f'}};
  std::map<int, char> S4 = {{9, 'j'}, {10, 'k'}, {11, 'l'}};

  BT1.swap(BT2);
  S3.swap(S4);

  ASSERT_EQ(mapsAreEqual(BT1, S3), false);
  ASSERT_EQ(mapsAreEqual(BT2, S4), true);
}

TEST(METHOD_SWAP, SWAP5_DIFFERENT_NUMBER_OF_ELEMENTS2) {
  s21::BinaryTree<int, char> BT1 = {{1, 'b'}, {2, 'c'}, {3, 'd'}};
  s21::BinaryTree<int, char> BT2 = {
      {4, 'e'}, {5, 'f'}, {6, 'g'}, {77, '@'}, {88, '#'}};
  std::map<int, char> S3 = {{1, 'b'}, {2, 'c'}, {3, 'd'}};
  std::map<int, char> S4 = {
      {4, 'e'}, {5, 'f'}, {6, 'g'}, {99, '^'}, {111, '&'}};

  BT1.swap(BT2);
  S3.swap(S4);

  ASSERT_EQ(mapsAreEqual(BT1, S3), false);
  ASSERT_EQ(mapsAreEqual(BT2, S4), true);
}

TEST(METHOD_INSERT, INSERT_EXISTING_ELEMENT) {
  s21::BinaryTree<int, char> BT1 = {{1, 'b'}, {2, 'c'}, {3, 'd'}};
  std::map<int, char> S2 = {{1, 'b'}, {2, 'c'}, {3, 'd'}};
  BT1.insert({3, 'd'});
  S2.insert({3, 'd'});

  ASSERT_EQ(mapsAreEqual(BT1, S2), true);
}

TEST(METHOD_INSERT, INSERT_ZERO_ELEMENTS) {
  s21::BinaryTree<int, char> BT1 = {};
  std::map<int, char> S2 = {};
  BT1.insert({3, 'd'});
  S2.insert({3, 'd'});

  ASSERT_EQ(mapsAreEqual(BT1, S2), true);
}

TEST(METHOD_INSERT, INSERT_MIDDLE_ELEMENT) {
  s21::BinaryTree<int, char> BT1 = {{1, 'b'}, {3, 'd'}, {4, 'e'}};
  std::map<int, char> S2 = {{1, 'b'}, {3, 'd'}, {4, 'e'}};
  BT1.insert({2, 'c'});
  S2.insert({2, 'c'});

  ASSERT_EQ(mapsAreEqual(BT1, S2), true);
}

TEST(METHOD_INSERT, INSERT_INSERT) {
  s21::BinaryTree<int, char> BT1 = {{1, 'b'}, {2, 'c'}, {3, 'd'}};
  s21::BinaryTree<int, char> BT2 = {{1, 'b'}, {2, 'c'}, {3, 'd'}, {4, 'e'}};
  BT1.insert({4, 'e'});

  bool res = true;

  if (BT1.size() != BT2.size()) res = false;

  auto it_S1 = BT1.begin();
  auto it_S2 = BT2.begin();
  for (; it_S2 != BT2.end(); ++it_S1, ++it_S2) {
    if (*it_S1 != *it_S2) res = false;
  }

  ASSERT_EQ(res, true);
}

TEST(METHOD_ERASE, ERASE_ROOT) {
  s21::BinaryTree<int, char> BT1 = {{45, 'e'}, {11, 'k'}, {27, '&'}, {51, 'x'},
                                    {35, 'i'}, {9, 'j'},  {86, 'e'}, {22, 'v'},
                                    {81, '&'}, {88, 'g'}, {44, 'q'}, {55, 'o'},
                                    {28, 'a'}, {56, 'p'}, {64, 'b'}};
  std::map<int, char> S2 = {{45, 'e'}, {11, 'k'}, {27, '&'}, {51, 'x'},
                            {35, 'i'}, {9, 'j'},  {86, 'e'}, {22, 'v'},
                            {81, '&'}, {88, 'g'}, {44, 'q'}, {55, 'o'},
                            {28, 'a'}, {56, 'p'}, {64, 'b'}};
  BT1.erase(BT1.find(45));
  S2.erase(S2.find(45));

  ASSERT_EQ(mapsAreEqual(BT1, S2), true);
}

TEST(METHOD_ERASE, ERASE_PARENT_BLACK_SIBLING_BLACK_NAPHEWS_BLACK_1) {
  s21::BinaryTree<int, char> BT1 = {{45, 'e'}, {11, 'k'}, {27, '&'}, {51, 'x'},
                                    {35, 'i'}, {9, 'j'},  {86, 'e'}, {22, 'v'},
                                    {81, '&'}, {88, 'g'}, {44, 'q'}, {55, 'o'},
                                    {28, 'a'}, {56, 'p'}, {64, 'b'}};
  std::map<int, char> S2 = {{45, 'e'}, {11, 'k'}, {27, '&'}, {51, 'x'},
                            {35, 'i'}, {9, 'j'},  {86, 'e'}, {22, 'v'},
                            {81, '&'}, {88, 'g'}, {44, 'q'}, {55, 'o'},
                            {28, 'a'}, {56, 'p'}, {64, 'b'}};
  BT1.erase(BT1.find(81));
  S2.erase(S2.find(81));

  ASSERT_EQ(mapsAreEqual(BT1, S2), true);
}

TEST(METHOD_ERASE, ERASE_PARENT_BLACK_SIBLING_BLACK_NAPHEWS_BLACK_2) {
  s21::BinaryTree<int, char> BT1 = {
      {45, 'e'}, {11, 'k'}, {27, '&'}, {51, 'x'}, {35, 'i'}, {9, 'j'},
      {86, 'e'}, {22, 'v'}, {81, '&'}, {88, 'g'}, {44, 'q'}, {55, 'o'},
      {28, 'a'}, {56, 'p'}, {64, 'b'}, {80, 'y'}, {5, 'j'},  {18, 'z'},
      {21, 'o'}, {57, 'w'}, {54, 's'}, {33, 'f'}, {21, 'u'}, {13, 'a'},
      {66, 'p'}, {69, 't'}, {10, 'm'}, {47, '$'}, {56, 'r'}, {57, 'h'},
      {58, 'd'}, {59, 'c'}, {60, 'g'}, {61, 't'}, {62, 'y'}, {63, 'n'},
      {64, 'w'}};
  std::map<int, char> S2 = {
      {45, 'e'}, {11, 'k'}, {27, '&'}, {51, 'x'}, {35, 'i'}, {9, 'j'},
      {86, 'e'}, {22, 'v'}, {81, '&'}, {88, 'g'}, {44, 'q'}, {55, 'o'},
      {28, 'a'}, {56, 'p'}, {64, 'b'}, {80, 'y'}, {5, 'j'},  {18, 'z'},
      {21, 'o'}, {57, 'w'}, {54, 's'}, {33, 'f'}, {21, 'u'}, {13, 'a'},
      {66, 'p'}, {69, 't'}, {10, 'm'}, {47, '$'}, {56, 'r'}, {57, 'h'},
      {58, 'd'}, {59, 'c'}, {60, 'g'}, {61, 't'}, {62, 'y'}, {63, 'n'},
      {64, 'w'}};
  BT1.erase(BT1.find(47));
  S2.erase(S2.find(47));
  BT1.erase(BT1.find(54));
  S2.erase(S2.find(54));
  // BT1.print_tree();
  BT1.erase(BT1.find(56));
  S2.erase(S2.find(56));
  // BT1.print_tree();

  ASSERT_EQ(mapsAreEqual(BT1, S2), true);
}

TEST(METHOD_ERASE, ERASE_PARENT_BLACK_SIBLING_RED_NAPHEWS_BLACK) {
  s21::BinaryTree<int, char> BT1 = {{45, 'e'}, {11, 'k'}, {27, '&'}, {51, 'x'},
                                    {35, 'i'}, {9, 'j'},  {86, 'e'}, {22, 'v'},
                                    {81, '&'}, {88, 'g'}, {44, 'q'}, {55, 'o'},
                                    {28, 'a'}, {56, 'p'}, {64, 'b'}};
  std::map<int, char> S2 = {{45, 'e'}, {11, 'k'}, {27, '&'}, {51, 'x'},
                            {35, 'i'}, {9, 'j'},  {86, 'e'}, {22, 'v'},
                            {81, '&'}, {88, 'g'}, {44, 'q'}, {55, 'o'},
                            {28, 'a'}, {56, 'p'}, {64, 'b'}};
  BT1.erase(BT1.find(86));
  S2.erase(S2.find(86));

  ASSERT_EQ(mapsAreEqual(BT1, S2), true);
}

TEST(METHOD_ERASE, ERASE_RED_NO_CHILDREN) {
  s21::BinaryTree<int, char> BT1 = {{45, 'e'}, {11, 'k'}, {27, '&'}, {51, 'x'},
                                    {35, 'i'}, {9, 'j'},  {86, 'e'}, {22, 'v'},
                                    {81, '&'}, {88, 'g'}, {44, 'q'}, {55, 'o'},
                                    {28, 'a'}, {56, 'p'}, {64, 'b'}};
  std::map<int, char> S2 = {{45, 'e'}, {11, 'k'}, {27, '&'}, {51, 'x'},
                            {35, 'i'}, {9, 'j'},  {86, 'e'}, {22, 'v'},
                            {81, '&'}, {88, 'g'}, {44, 'q'}, {55, 'o'},
                            {28, 'a'}, {56, 'p'}, {64, 'b'}};
  BT1.erase(BT1.find(28));
  S2.erase(S2.find(28));

  ASSERT_EQ(mapsAreEqual(BT1, S2), true);
}

TEST(METHOD_ERASE, ERASE_RED_HAS_CHILDREN_DISTANT_NAPHEW_RED) {
  s21::BinaryTree<int, char> BT1 = {{45, 'e'}, {11, 'k'}, {27, '&'}, {51, 'x'},
                                    {35, 'i'}, {9, 'j'},  {86, 'e'}, {22, 'v'},
                                    {81, '&'}, {88, 'g'}, {44, 'q'}, {55, 'o'},
                                    {28, 'a'}, {56, 'p'}, {64, 'b'}};
  std::map<int, char> S2 = {{45, 'e'}, {11, 'k'}, {27, '&'}, {51, 'x'},
                            {35, 'i'}, {9, 'j'},  {86, 'e'}, {22, 'v'},
                            {81, '&'}, {88, 'g'}, {44, 'q'}, {55, 'o'},
                            {28, 'a'}, {56, 'p'}, {64, 'b'}};
  // BT1.print_tree();
  BT1.erase(BT1.find(55));
  S2.erase(S2.find(55));
  // BT1.print_tree();

  ASSERT_EQ(mapsAreEqual(BT1, S2), true);
}

TEST(METHOD_ERASE, ERASE_RED_HAS_CHILDREN_CLOSER_NAPHEW_RED) {
  s21::BinaryTree<int, char> BT1 = {{45, 'e'}, {11, 'k'}, {27, '&'}, {51, 'x'},
                                    {35, 'i'}, {9, 'j'},  {86, 'e'}, {22, 'v'},
                                    {81, '&'}, {88, 'g'}, {44, 'q'}, {55, 'o'},
                                    {28, 'a'}, {64, 'b'}, {56, 'p'}};
  std::map<int, char> S2 = {{45, 'e'}, {11, 'k'}, {27, '&'}, {51, 'x'},
                            {35, 'i'}, {9, 'j'},  {86, 'e'}, {22, 'v'},
                            {81, '&'}, {88, 'g'}, {44, 'q'}, {55, 'o'},
                            {28, 'a'}, {64, 'b'}, {56, 'p'}};
  // BT1.print_tree();
  BT1.erase(BT1.find(55));
  S2.erase(S2.find(55));
  // BT1.print_tree();

  ASSERT_EQ(mapsAreEqual(BT1, S2), true);
}

TEST(METHOD_ERASE,
     ERASE_PARENT_BLACK_SIBLING_RED_NAPHEWS_BLACK_WITH_NO_RED_CHILDREN) {
  s21::BinaryTree<int, char> BT1 = {{45, 'e'}, {11, 'k'}, {27, '&'}, {51, 'x'},
                                    {35, 'i'}, {9, 'j'},  {86, 'e'}, {22, 'v'},
                                    {81, '&'}, {88, 'g'}, {44, 'q'}, {55, 'o'},
                                    {28, 'a'}, {56, 'p'}, {64, 'b'}};
  std::map<int, char> S2 = {{45, 'e'}, {11, 'k'}, {27, '&'}, {51, 'x'},
                            {35, 'i'}, {9, 'j'},  {86, 'e'}, {22, 'v'},
                            {81, '&'}, {88, 'g'}, {44, 'q'}, {55, 'o'},
                            {28, 'a'}, {56, 'p'}, {64, 'b'}};
  BT1.erase(BT1.find(88));
  S2.erase(S2.find(88));
  BT1.erase(BT1.find(64));
  S2.erase(S2.find(64));
  BT1.erase(BT1.find(86));
  S2.erase(S2.find(86));

  ASSERT_EQ(mapsAreEqual(BT1, S2), true);
}

TEST(METHOD_ERASE, ERASE_PARENT_BLACK_SIBLING_BLACK_HAS_RED_NAPHEWS) {
  s21::BinaryTree<int, char> BT1 = {{45, 'e'}, {11, 'k'}, {27, '&'}, {51, 'x'},
                                    {35, 'i'}, {9, 'j'},  {86, 'e'}, {22, 'v'},
                                    {81, '&'}, {88, 'g'}, {44, 'q'}, {55, 'o'},
                                    {28, 'a'}, {56, 'p'}, {64, 'b'}};
  std::map<int, char> S2 = {{45, 'e'}, {11, 'k'}, {27, '&'}, {51, 'x'},
                            {35, 'i'}, {9, 'j'},  {86, 'e'}, {22, 'v'},
                            {81, '&'}, {88, 'g'}, {44, 'q'}, {55, 'o'},
                            {28, 'a'}, {56, 'p'}, {64, 'b'}};
  BT1.erase(BT1.find(9));
  S2.erase(S2.find(9));
  BT1.erase(BT1.find(22));
  S2.erase(S2.find(22));
  // BT1.print_tree();
  BT1.erase(BT1.find(11));
  S2.erase(S2.find(11));
  // BT1.print_tree();

  ASSERT_EQ(mapsAreEqual(BT1, S2), true);
}

TEST(METHOD_MERGE, MERGE_DIFFERENT_ELEMENTS1) {
  s21::BinaryTree<int, char> BT1 = {{1, 'b'}, {3, 'd'}, {5, 'f'}};
  s21::BinaryTree<int, char> BT2 = {{2, 'c'}, {4, 'e'}, {6, 'g'}};
  std::map<int, char> S3 = {{1, 'b'}, {3, 'd'}, {5, 'f'},
                            {2, 'c'}, {4, 'e'}, {6, 'g'}};
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

TEST(METHOD_MERGE, MERGE_DIFFERENT_ELEMENTS2) {
  s21::BinaryTree<int, char> BT1 = {{1, 'b'}, {3, 'd'}, {5, 'f'}};
  s21::BinaryTree<int, char> BT2 = {{2, 'c'}, {4, 'e'}, {6, 'g'}};
  s21::BinaryTree<int, char> BT3 = {{1, 'b'}, {2, 'c'}, {3, 'd'}, {4, 'e'},
                                    {5, 'f'}, {6, 'g'}};  // {1, 3, 5, 2, 4, 6};
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

TEST(METHOD_FIND, FIND_EXISTING_ELEMENT) {
  s21::BinaryTree<int, char> BT1 = {{45, 'e'}, {11, 'k'}, {27, '&'}, {51, 'x'},
                                    {35, 'i'}, {9, 'j'},  {86, 'e'}, {22, 'v'},
                                    {81, '&'}, {88, 'g'}, {44, 'q'}, {55, 'o'},
                                    {28, 'a'}, {56, 'p'}, {64, 'b'}};
  std::map<int, char> S2 = {{45, 'e'}, {11, 'k'}, {27, '&'}, {51, 'x'},
                            {35, 'i'}, {9, 'j'},  {86, 'e'}, {22, 'v'},
                            {81, '&'}, {88, 'g'}, {44, 'q'}, {55, 'o'},
                            {28, 'a'}, {56, 'p'}, {64, 'b'}};
  auto it_S1 = BT1.find(88);
  auto it_S2 = S2.find(88);
  ASSERT_EQ(*it_S1, *it_S2);
}

TEST(METHOD_FIND, FIND_NOT_EXISTING_ELEMENT1) {
  s21::BinaryTree<int, char> BT1 = {{45, 'e'}, {11, 'k'}, {27, '&'}, {51, 'x'},
                                    {35, 'i'}, {9, 'j'},  {86, 'e'}, {22, 'v'},
                                    {81, '&'}, {88, 'g'}, {44, 'q'}, {55, 'o'},
                                    {28, 'a'}, {56, 'p'}, {64, 'b'}};
  auto it_S1 = BT1.find(101);
  ASSERT_EQ(it_S1, BT1.end());
}

TEST(METHOD_CONTAINS, CONTAINS_EXISTING_ELEMENT) {
  s21::BinaryTree<int, char> BT1 = {{45, 'e'}, {11, 'k'}, {27, '&'}, {51, 'x'},
                                    {35, 'i'}, {9, 'j'},  {86, 'e'}, {22, 'v'},
                                    {81, '&'}, {88, 'g'}, {44, 'q'}, {55, 'o'},
                                    {28, 'a'}, {56, 'p'}, {64, 'b'}};
  ASSERT_EQ(BT1.contains(56), true);
}

TEST(METHOD_CONTAINS, CONTAINS_NOT_EXISTING_ELEMENT) {
  s21::BinaryTree<int, char> BT1 = {{45, 'e'}, {11, 'k'}, {27, '&'}, {51, 'x'},
                                    {35, 'i'}, {9, 'j'},  {86, 'e'}, {22, 'v'},
                                    {81, '&'}, {88, 'g'}, {44, 'q'}, {55, 'o'},
                                    {28, 'a'}, {56, 'p'}, {64, 'b'}};
  ASSERT_EQ(BT1.contains(1), false);
}
