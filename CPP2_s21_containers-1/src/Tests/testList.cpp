#include "test.h"

/*
 ---------------------------------------
|                                       |
|           Constructors Test           |
|                                       |
 ---------------------------------------
*/

TEST(List, ConstructorSimpleCustom) {
  s21::list<TeslaTypeTest> test;
  std::list<TeslaTypeTest> example;
  EXPECT_EQ(test.size(), example.size());
  EXPECT_EQ(test.empty(), example.empty());
}

TEST(List, ConstructorSimpleInt) {
  s21::list<int> test;
  std::list<int> example;
  EXPECT_EQ(example.size(), test.size());
}

TEST(List, ConstructorSimpleString) {
  s21::list<std::string> test;
  std::list<std::string> example;
  EXPECT_EQ(example.size(), test.size());
}

TEST(List, ConstructorCompareCustom) {
  s21::list<TeslaTypeTest> test;
  std::list<TeslaTypeTest> example;
  EXPECT_EQ(example.size(), test.size());
}

TEST(List, ConstructorEmptySizedInt) {
  s21::list<int> test(7);
  std::list<int> example(7);
  EXPECT_EQ(example.size(), test.size());
}

TEST(List, ConstructorEmptySizedString) {
  s21::list<std::string> test(7);
  std::list<std::string> example(7);
  EXPECT_EQ(example.size(), test.size());
}

TEST(List, ConstructorEmptySizedCustom) {
  s21::list<TeslaTypeTest> test(7);
  std::list<TeslaTypeTest> example(7);
  EXPECT_EQ(example.size(), test.size());
}

TEST(List, ConstructorInitializerInt) {
  s21::list<int> test{12, 23, 45, 56, 67, 45, 13, 2, 4, 5};
  std::list<int> example{12, 23, 45, 56, 67, 45, 13, 2, 4, 5};
  EXPECT_EQ(example.size(), test.size());
  auto it_test = test.begin();
  auto it_example = example.begin();
  for (size_t i = 0; i < example.size(); i++) {
    EXPECT_EQ(*it_test, *it_example);
    ++it_test;
    ++it_example;
  }
}

TEST(List, ConstructorInitializerString) {
  s21::list<std::string> test{"lol", "kek", "cheburek"};
  std::list<std::string> example{"lol", "kek", "cheburek"};
  EXPECT_EQ(example.size(), test.size());
  auto it_test = test.begin();
  auto it_example = example.begin();
  for (size_t i = 0; i < example.size(); i++) {
    EXPECT_EQ(*it_test, *it_example);
    ++it_test;
    ++it_example;
  }
}

TEST(List, ConstructorInitializerCustom) {
  s21::list<TeslaTypeTest> test{
      {0, 1, 9, "boba"}, {12, 34.34, 14, "Musk"}, {153, 11, 92.78, "gew"}};
  std::list<TeslaTypeTest> example{
      {0, 1, 9, "boba"}, {12, 34.34, 14, "Musk"}, {153, 11, 92.78, "gew"}};
  EXPECT_EQ(example.size(), test.size());
  auto it_test = test.begin();
  auto it_example = example.begin();
  for (size_t i = 0; i < example.size(); i++) {
    CompareTesla(it_test, it_example);
    ++it_test;
    ++it_example;
  }
}

TEST(List, ConstructorCopyInt) {
  s21::list<int> copy_from_t{12, 23, 45, 56, 67, 45, 13, 2, 4, 5};
  std::list<int> copy_from_e{12, 23, 45, 56, 67, 45, 13, 2, 4, 5};

  s21::list<int> test(copy_from_t);
  std::list<int> example(copy_from_e);
  EXPECT_EQ(example.size(), test.size());
  EXPECT_EQ(copy_from_t.size(), copy_from_e.size());
  auto it_test = test.begin();
  auto it_example = example.begin();

  auto it_test_c = copy_from_t.begin();
  auto it_example_c = copy_from_e.begin();
  for (size_t i = 0; i < example.size(); i++) {
    EXPECT_EQ(*it_test, *it_example);
    EXPECT_EQ(*it_test_c, *it_example_c);
    ++it_test;
    ++it_example;
    ++it_test_c;
    ++it_example_c;
  }
}

TEST(List, ConstructorCopyString) {
  s21::list<std::string> copy_from_t{"lol", "kek", "cheburek"};
  std::list<std::string> copy_from_e{"lol", "kek", "cheburek"};

  s21::list<std::string> test(copy_from_t);
  std::list<std::string> example(copy_from_e);
  EXPECT_EQ(example.size(), test.size());
  EXPECT_EQ(copy_from_t.size(), copy_from_e.size());
  auto it_test = test.begin();
  auto it_example = example.begin();

  auto it_test_c = copy_from_t.begin();
  auto it_example_c = copy_from_e.begin();
  for (size_t i = 0; i < example.size(); i++) {
    EXPECT_EQ(*it_test, *it_example);
    EXPECT_EQ(*it_test_c, *it_example_c);
    ++it_test;
    ++it_example;
    ++it_test_c;
    ++it_example_c;
  }
}

TEST(List, ConstructorCopyCustom) {
  s21::list<TeslaTypeTest> copy_from_t{
      {0, 1, 9, "boba"}, {12, 34.34, 14, "Musk"}, {153, 11, 92.78, "gew"}};
  std::list<TeslaTypeTest> copy_from_e{
      {0, 1, 9, "boba"}, {12, 34.34, 14, "Musk"}, {153, 11, 92.78, "gew"}};

  s21::list<TeslaTypeTest> test(copy_from_t);
  std::list<TeslaTypeTest> example(copy_from_e);
  EXPECT_EQ(example.size(), test.size());
  EXPECT_EQ(copy_from_t.size(), copy_from_e.size());
  auto it_test = test.begin();
  auto it_example = example.begin();
  auto it_test_c = copy_from_t.begin();
  auto it_example_c = copy_from_e.begin();
  for (size_t i = 0; i < example.size(); i++) {
    CompareTesla(it_test, it_example);
    CompareTesla(it_test_c, it_example_c);
    ++it_test;
    ++it_example;
    ++it_test_c;
    ++it_example_c;
  }
}

TEST(List, ConstructorMoveInt) {
  s21::list<int> move_from_t{12, 23, 45, 56, 67, 45, 13, 2, 4, 5};
  std::list<int> move_from_e{12, 23, 45, 56, 67, 45, 13, 2, 4, 5};

  s21::list<int> test(std::move(move_from_t));
  std::list<int> example(std::move(move_from_e));
  EXPECT_EQ(example.size(), test.size());
  EXPECT_EQ(move_from_t.size(), move_from_e.size());
  EXPECT_EQ(move_from_t.empty(), move_from_e.empty());
  auto it_test = test.begin();
  auto it_example = example.begin();
  for (size_t i = 0; i < example.size(); i++) {
    EXPECT_EQ(*it_test, *it_example);
    ++it_test;
    ++it_example;
  }
}

TEST(List, ConstructorMoveString) {
  s21::list<std::string> move_from_t{"lol", "kek", "cheburek"};
  std::list<std::string> move_from_e{"lol", "kek", "cheburek"};

  s21::list<std::string> test(std::move(move_from_t));
  std::list<std::string> example(std::move(move_from_e));
  EXPECT_EQ(example.size(), test.size());
  EXPECT_EQ(move_from_t.size(), move_from_e.size());
  EXPECT_EQ(move_from_t.empty(), move_from_e.empty());
  auto it_test = test.begin();
  auto it_example = example.begin();
  for (size_t i = 0; i < example.size(); i++) {
    EXPECT_EQ(*it_test, *it_example);
    ++it_test;
    ++it_example;
  }
}

TEST(List, ConstructorMoveCustom) {
  s21::list<TeslaTypeTest> move_from_t{
      {0, 1, 9, "boba"}, {12, 34.34, 14, "Musk"}, {153, 11, 92.78, "gew"}};
  std::list<TeslaTypeTest> move_from_e{
      {0, 1, 9, "boba"}, {12, 34.34, 14, "Musk"}, {153, 11, 92.78, "gew"}};

  s21::list<TeslaTypeTest> test(std::move(move_from_t));
  std::list<TeslaTypeTest> example(std::move(move_from_e));
  EXPECT_EQ(example.size(), test.size());
  EXPECT_EQ(move_from_t.empty(), move_from_e.empty());
  auto it_test = test.begin();
  auto it_example = example.begin();

  for (size_t i = 0; i < example.size(); i++) {
    CompareTesla(it_test, it_example);

    ++it_test;
    ++it_example;
  }
}

TEST(List, AssignMoveInt) {
  s21::list<int> move_from_t{12, 23, 45, 56, 67, 45, 13, 2, 4, 5};
  std::list<int> move_from_e{12, 23, 45, 56, 67, 45, 13, 2, 4, 5};

  s21::list<int> test{13, 2, 4, 5};
  std::list<int> example{13, 2, 4, 5};
  test = std::move(move_from_t);
  example = std::move(move_from_e);
  EXPECT_EQ(example.size(), test.size());
  EXPECT_EQ(move_from_t.size(), move_from_e.size());
  EXPECT_EQ(move_from_t.empty(), move_from_e.empty());
  auto it_test = test.begin();
  auto it_example = example.begin();
  for (size_t i = 0; i < example.size(); i++) {
    EXPECT_EQ(*it_test, *it_example);
    ++it_test;
    ++it_example;
  }
}

TEST(List, AssignMoveString) {
  s21::list<std::string> move_from_t{"lol", "kek", "cheburek"};
  std::list<std::string> move_from_e{"lol", "kek", "cheburek"};

  s21::list<std::string> test{"peepee poopoo"};
  std::list<std::string> example{"peepee poopoo"};
  test = std::move(move_from_t);
  example = std::move(move_from_e);
  EXPECT_EQ(example.size(), test.size());
  EXPECT_EQ(move_from_t.size(), move_from_e.size());
  EXPECT_EQ(move_from_t.empty(), move_from_e.empty());
  auto it_test = test.begin();
  auto it_example = example.begin();
  for (size_t i = 0; i < example.size(); i++) {
    EXPECT_EQ(*it_test, *it_example);
    ++it_test;
    ++it_example;
  }
}

TEST(List, AssignMoveCustom) {
  s21::list<TeslaTypeTest> move_from_t{
      {0, 1, 9, "boba"}, {12, 34.34, 14, "Musk"}, {153, 11, 92.78, "gew"}};
  std::list<TeslaTypeTest> move_from_e{
      {0, 1, 9, "boba"}, {12, 34.34, 14, "Musk"}, {153, 11, 92.78, "gew"}};

  s21::list<TeslaTypeTest> test{{153, 11, 92.78, "gew"}};
  std::list<TeslaTypeTest> example{{153, 11, 92.78, "gew"}};
  test = std::move(move_from_t);
  example = std::move(move_from_e);
  EXPECT_EQ(example.size(), test.size());
  EXPECT_EQ(move_from_t.empty(), move_from_e.empty());
  auto it_test = test.begin();
  auto it_example = example.begin();

  for (size_t i = 0; i < example.size(); i++) {
    CompareTesla(it_test, it_example);

    ++it_test;
    ++it_example;
  }
}

TEST(List, IteratorMove) {
  s21::list<int> test{8, 7, 5, 9, 0, 1, 3, 2, 6, 4};
  std::list<int> example{8, 7, 5, 9, 0, 1, 3, 2, 6, 4};
  auto it_test_move = test.begin();
  auto it_example_move = example.begin();
  for (int i = 0; i < 5; i++) {
    it_test_move++;
    it_example_move++;
  }
  s21::list<int>::iterator it_test(std::move(it_test_move));
  std::list<int>::iterator it_example(std::move(it_example_move));
  EXPECT_EQ(example.size(), test.size());
  for (size_t i = 0; i < example.size(); i++) {
    if (it_example == example.end()) {
      ++it_test;
      ++it_example;
    }
    EXPECT_EQ(*it_test, *it_example);
    ++it_test;
    ++it_example;
  }
}

/*
 ---------------------------------------
|                                       |
|           Front/Back Access           |
|                                       |
 ---------------------------------------
*/

TEST(List, FrontValidInt) {
  s21::list<int> test{12, 23, 45, 56, 67, 45, 13, 2, 4, 5};
  std::list<int> example{12, 23, 45, 56, 67, 45, 13, 2, 4, 5};
  auto val_test = test.front();
  auto val_example = example.front();
  EXPECT_EQ(example.size(), test.size());
  EXPECT_EQ(val_test, val_example);
}

TEST(List, FrontValidString) {
  s21::list<std::string> test{"lol", "kek", "cheburek"};
  std::list<std::string> example{"lol", "kek", "cheburek"};
  auto val_test = test.front();
  auto val_example = example.front();
  EXPECT_EQ(example.size(), test.size());
  EXPECT_EQ(val_test, val_example);
}

TEST(List, FrontValidCustom) {
  s21::list<TeslaTypeTest> test{
      {0, 1, 9, "boba"}, {12, 34.34, 14, "Musk"}, {153, 11, 92.78, "gew"}};
  std::list<TeslaTypeTest> example{
      {0, 1, 9, "boba"}, {12, 34.34, 14, "Musk"}, {153, 11, 92.78, "gew"}};
  EXPECT_EQ(example.size(), test.size());
  auto val_test = test.front();
  auto val_example = example.front();
  EXPECT_EQ(example.size(), test.size());
  EXPECT_EQ(val_test.battery, val_example.battery);
  EXPECT_EQ(val_test.distance, val_example.distance);
  EXPECT_EQ(val_test.name, val_example.name);
  EXPECT_EQ(val_test.speed, val_example.speed);
}

TEST(List, BackValidInt) {
  s21::list<int> test{12, 23, 45, 56, 67, 45, 13, 2, 4, 5};
  std::list<int> example{12, 23, 45, 56, 67, 45, 13, 2, 4, 5};
  auto val_test = test.back();
  auto val_example = example.back();
  EXPECT_EQ(example.size(), test.size());
  EXPECT_EQ(val_test, val_example);
}

TEST(List, BackValidString) {
  s21::list<std::string> test{"lol", "kek", "cheburek"};
  std::list<std::string> example{"lol", "kek", "cheburek"};
  auto val_test = test.back();
  auto val_example = example.back();
  EXPECT_EQ(example.size(), test.size());
  EXPECT_EQ(val_test, val_example);
}

TEST(List, BackValidCustom) {
  s21::list<TeslaTypeTest> test{
      {0, 1, 9, "boba"}, {12, 34.34, 14, "Musk"}, {153, 11, 92.78, "gew"}};
  std::list<TeslaTypeTest> example{
      {0, 1, 9, "boba"}, {12, 34.34, 14, "Musk"}, {153, 11, 92.78, "gew"}};
  EXPECT_EQ(example.size(), test.size());
  auto val_test = test.back();
  auto val_example = example.back();
  EXPECT_EQ(example.size(), test.size());
  EXPECT_EQ(val_test.battery, val_example.battery);
  EXPECT_EQ(val_test.distance, val_example.distance);
  EXPECT_EQ(val_test.name, val_example.name);
  EXPECT_EQ(val_test.speed, val_example.speed);
}

/*
 ---------------------------------------
|                                       |
|            List Modifiers             |
|                                       |
 ---------------------------------------
*/

TEST(List, PushBackTest) {
  TeslaTypeTest teslaTest{12, 100, 0, "Model Y"};
  std::list<TeslaTypeTest> example;
  s21::list<TeslaTypeTest> test;
  example.push_back(teslaTest);
  test.push_back(teslaTest);

  auto it_test = test.begin();
  auto it_example = example.begin();

  CompareTesla(it_test, it_example);
  EXPECT_EQ(example.size(), test.size());
}

TEST(List, PushBackTest_2) {
  TeslaTypeTest teslaTest{12, 100, 0, "Model Y"};
  std::list<TeslaTypeTest> example;
  s21::list<TeslaTypeTest> test;
  example.push_back(teslaTest);
  test.push_back(teslaTest);
  auto it_test = test.begin();
  auto it_example = example.begin();

  CompareTesla(it_test, it_example);
  EXPECT_EQ(example.size(), test.size());
  teslaTest.battery += 12;
  teslaTest.speed -= 12;
  teslaTest.name = "Model X";
  example.push_back(teslaTest);
  test.push_back(teslaTest);
  ++it_test;
  ++it_example;
  CompareTesla(it_test, it_example);
  EXPECT_EQ(example.size(), test.size());
}

TEST(List, PushFrontTest) {
  TeslaTypeTest teslaTest{12, 100, 0, "Model Y"};
  std::list<TeslaTypeTest> example;
  s21::list<TeslaTypeTest> test;
  example.push_front(teslaTest);
  test.push_front(teslaTest);

  auto it_test = test.begin();
  auto it_example = example.begin();

  CompareTesla(it_test, it_example);
  EXPECT_EQ(example.size(), test.size());
}

TEST(List, PushFrontTest_2) {
  TeslaTypeTest teslaTest{12, 100, 0, "Model Y"};
  std::list<TeslaTypeTest> example;
  s21::list<TeslaTypeTest> test;
  example.push_front(teslaTest);
  test.push_front(teslaTest);
  auto it_test = test.begin();
  auto it_example = example.begin();

  CompareTesla(it_test, it_example);
  EXPECT_EQ(example.size(), test.size());
  teslaTest.battery += 12;
  teslaTest.speed -= 12;
  teslaTest.name = "Model X";
  example.push_front(teslaTest);
  test.push_front(teslaTest);
  --it_test;
  --it_example;
  CompareTesla(it_test, it_example);
  EXPECT_EQ(example.size(), test.size());
}

TEST(List, UniqueInt) {
  s21::list<int> test{1, 2, 2, 2, 3, 3, 2, 1, 1, 2};
  std::list<int> example{1, 2, 2, 2, 3, 3, 2, 1, 1, 2};
  test.unique();
  example.unique();
  EXPECT_EQ(example.size(), test.size());
  auto it_test = test.begin();
  auto it_example = example.begin();
  for (size_t i = 0; i < example.size(); i++) {
    EXPECT_EQ(*it_test, *it_example);
    ++it_test;
    ++it_example;
  }
}

TEST(List, SingleUniqueInt) {
  s21::list<int> test{1};
  std::list<int> example{1};
  test.unique();
  example.unique();
  EXPECT_EQ(example.size(), test.size());
  auto it_test = test.begin();
  auto it_example = example.begin();
  for (size_t i = 0; i < example.size(); i++) {
    EXPECT_EQ(*it_test, *it_example);
    ++it_test;
    ++it_example;
  }
}

TEST(List, DoubleNoneUniqueInt) {
  s21::list<int> test{1, 1};
  std::list<int> example{1, 1};
  test.unique();
  example.unique();
  EXPECT_EQ(example.size(), test.size());
  auto it_test = test.begin();
  auto it_example = example.begin();
  for (size_t i = 0; i < example.size(); i++) {
    EXPECT_EQ(*it_test, *it_example);
    ++it_test;
    ++it_example;
  }
}

TEST(List, AllUniqueInt) {
  s21::list<int> test{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  std::list<int> example{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  test.unique();
  example.unique();
  EXPECT_EQ(example.size(), test.size());
  auto it_test = test.begin();
  auto it_example = example.begin();
  for (size_t i = 0; i < example.size(); i++) {
    EXPECT_EQ(*it_test, *it_example);
    ++it_test;
    ++it_example;
  }
}

TEST(List, NoneUniqueInt) {
  s21::list<int> test{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
  std::list<int> example{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
  test.unique();
  example.unique();
  EXPECT_EQ(example.size(), test.size());
  auto it_test = test.begin();
  auto it_example = example.begin();
  for (size_t i = 0; i < example.size(); i++) {
    EXPECT_EQ(*it_test, *it_example);
    ++it_test;
    ++it_example;
  }
}

TEST(List, ReverseInt) {
  s21::list<int> test{8, 7, 5, 9, 0, 1, 3, 2, 6, 4};
  std::list<int> example{8, 7, 5, 9, 0, 1, 3, 2, 6, 4};
  test.reverse();
  example.reverse();
  EXPECT_EQ(example.size(), test.size());
  auto it_test = test.begin();
  auto it_example = example.begin();
  for (size_t i = 0; i < example.size(); i++) {
    EXPECT_EQ(*it_test, *it_example);
    ++it_test;
    ++it_example;
  }
}

TEST(List, SingleReverseInt) {
  s21::list<int> test{1};
  std::list<int> example{1};
  test.reverse();
  example.reverse();
  EXPECT_EQ(example.size(), test.size());
  auto it_test = test.begin();
  auto it_example = example.begin();
  for (size_t i = 0; i < example.size(); i++) {
    EXPECT_EQ(*it_test, *it_example);
    ++it_test;
    ++it_example;
  }
}

TEST(List, ReverseNoneUniqueInt) {
  s21::list<int> test{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
  std::list<int> example{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
  test.reverse();
  example.reverse();
  EXPECT_EQ(example.size(), test.size());
  auto it_test = test.begin();
  auto it_example = example.begin();
  for (size_t i = 0; i < example.size(); i++) {
    EXPECT_EQ(*it_test, *it_example);
    ++it_test;
    ++it_example;
  }
}

TEST(List, InsertBeginInt) {
  s21::list<int> test{8, 7, 5, 9, 0, 1, 3, 2, 6, 4};
  std::list<int> example{8, 7, 5, 9, 0, 1, 3, 2, 6, 4};
  auto it_test = test.begin();
  auto it_example = example.begin();
  it_test = test.insert(it_test, 120);
  it_example = example.insert(it_example, 120);
  EXPECT_EQ(example.size(), test.size());
  for (size_t i = 0; i < example.size(); i++) {
    EXPECT_EQ(*it_test, *it_example);
    ++it_test;
    ++it_example;
  }
}

TEST(List, InsertEndInt) {
  s21::list<int> test{8, 7, 5, 9, 0, 1, 3, 2, 6, 4};
  std::list<int> example{8, 7, 5, 9, 0, 1, 3, 2, 6, 4};
  auto it_test = test.begin();
  auto it_example = example.begin();
  test.insert(test.end(), 120);
  example.insert(example.end(), 120);
  EXPECT_EQ(example.size(), test.size());
  for (size_t i = 0; i < example.size(); i++) {
    EXPECT_EQ(*it_test, *it_example);
    ++it_test;
    ++it_example;
  }
}

TEST(List, InsertMiddleInt) {
  s21::list<int> test{8, 7, 5, 9, 0, 1, 3, 2, 6, 4};
  std::list<int> example{8, 7, 5, 9, 0, 1, 3, 2, 6, 4};
  auto it_test = test.begin();
  auto it_example = example.begin();
  for (int i = 0; i < 6; i++) {
    ++it_test;
    ++it_example;
  }
  it_test = test.insert(it_test, 120);
  it_example = example.insert(it_example, 120);
  EXPECT_EQ(example.size(), test.size());
  for (size_t i = 0; i < example.size(); i++) {
    if (it_example == example.end()) {
      ++it_test;
      ++it_example;
    }
    EXPECT_EQ(*it_test, *it_example);
    ++it_test;
    ++it_example;
  }
}

TEST(List, InsertEachPlaceInt) {
  s21::list<int> test{8, 7, 5, 9, 0, 1, 3, 2, 6, 4};
  std::list<int> example{8, 7, 5, 9, 0, 1, 3, 2, 6, 4};
  auto it_test = test.begin();
  auto it_example = example.begin();
  it_test = test.insert(it_test, 99);
  it_example = example.insert(it_example, 99);
  for (int i = 0; i < 6; i++) {
    ++it_test;
    ++it_example;
  }
  it_test = test.insert(it_test, 120);
  it_example = example.insert(it_example, 120);
  test.insert(test.end(), 56);
  example.insert(example.end(), 56);
  EXPECT_EQ(example.size(), test.size());
  for (size_t i = 0; i < example.size(); i++) {
    if (it_example == example.end()) {
      ++it_test;
      ++it_example;
    }
    EXPECT_EQ(*it_test, *it_example);
    ++it_test;
    ++it_example;
  }
}

TEST(List, InsertEmptyInt) {
  s21::list<int> test;
  std::list<int> example;
  auto it_test = test.begin();
  auto it_example = example.begin();
  it_test = test.insert(it_test, 99);
  it_example = example.insert(it_example, 99);
  EXPECT_EQ(example.size(), test.size());
  for (size_t i = 0; i < example.size(); i++) {
    if (it_example == example.end()) {
      ++it_test;
      ++it_example;
    }
    EXPECT_EQ(*it_test, *it_example);
    ++it_test;
    ++it_example;
  }
}

TEST(List, EraseBeginInt) {
  s21::list<int> test{8, 7, 5, 9, 0, 1, 3, 2, 6, 4};
  std::list<int> example{8, 7, 5, 9, 0, 1, 3, 2, 6, 4};
  auto it_test = test.begin();
  auto it_example = example.begin();
  test.erase(it_test);
  example.erase(it_example);
  it_test = test.begin();
  it_example = example.begin();
  EXPECT_EQ(example.size(), test.size());
  for (size_t i = 0; i < example.size(); i++) {
    EXPECT_EQ(*it_test, *it_example);
    ++it_test;
    ++it_example;
  }
}

TEST(List, EraseEndInt) {
  s21::list<int> test{8, 7, 5, 9, 0, 1, 3, 2, 6, 4};
  std::list<int> example{8, 7, 5, 9, 0, 1, 3, 2, 6, 4};
  auto it_test = test.end();
  auto it_example = example.end();
  it_test--;
  it_example--;
  test.erase(it_test);
  example.erase(it_example);
  it_test = test.begin();
  it_example = example.begin();
  EXPECT_EQ(example.size(), test.size());
  for (size_t i = 0; i < example.size(); i++) {
    EXPECT_EQ(*it_test, *it_example);
    ++it_test;
    ++it_example;
  }
}

TEST(List, EraseMiddleInt) {
  s21::list<int> test{8, 7, 5, 9, 0, 1, 3, 2, 6, 4};
  std::list<int> example{8, 7, 5, 9, 0, 1, 3, 2, 6, 4};
  auto it_test = test.begin();
  auto it_example = example.begin();
  for (int i = 0; i < 6; i++) {
    ++it_test;
    ++it_example;
  }
  test.erase(it_test);
  example.erase(it_example);
  EXPECT_EQ(example.size(), test.size());
  it_test = test.begin();
  it_example = example.begin();
  for (size_t i = 0; i < example.size(); i++) {
    if (it_example == example.end()) {
      ++it_test;
      ++it_example;
    }
    EXPECT_EQ(*it_test, *it_example);
    ++it_test;
    ++it_example;
  }
}

TEST(List, PopBackInt) {
  s21::list<int> test{8, 7, 5, 9, 0, 1, 3, 2, 6, 4};
  std::list<int> example{8, 7, 5, 9, 0, 1, 3, 2, 6, 4};
  test.pop_back();
  example.pop_back();
  auto it_test = test.begin();
  auto it_example = example.begin();
  EXPECT_EQ(example.size(), test.size());
  for (size_t i = 0; i < example.size(); i++) {
    EXPECT_EQ(*it_test, *it_example);
    ++it_test;
    ++it_example;
  }
}

TEST(List, PopBackToSingleInt) {
  s21::list<int> test{8, 7, 5, 9, 0, 1, 3, 2, 6, 4};
  std::list<int> example{8, 7, 5, 9, 0, 1, 3, 2, 6, 4};
  for (int i = 0; i < 9; i++) {
    test.pop_back();
    example.pop_back();
  }
  auto it_test = test.begin();
  auto it_example = example.begin();
  EXPECT_EQ(example.size(), test.size());
  for (size_t i = 0; i < example.size(); i++) {
    EXPECT_EQ(*it_test, *it_example);
    ++it_test;
    ++it_example;
  }
}

TEST(List, PopFrontInt) {
  s21::list<int> test{8, 7, 5, 9, 0, 1, 3, 2, 6, 4};
  std::list<int> example{8, 7, 5, 9, 0, 1, 3, 2, 6, 4};
  test.pop_front();
  example.pop_front();
  auto it_test = test.begin();
  auto it_example = example.begin();
  EXPECT_EQ(example.size(), test.size());
  for (size_t i = 0; i < example.size(); i++) {
    EXPECT_EQ(*it_test, *it_example);
    ++it_test;
    ++it_example;
  }
}

TEST(List, PopFrontToSingleInt) {
  s21::list<int> test{8, 7, 5, 9, 0, 1, 3, 2, 6, 4};
  std::list<int> example{8, 7, 5, 9, 0, 1, 3, 2, 6, 4};
  for (int i = 0; i < 9; i++) {
    test.pop_front();
    example.pop_front();
  }
  auto it_test = test.begin();
  auto it_example = example.begin();
  EXPECT_EQ(example.size(), test.size());
  for (size_t i = 0; i < example.size(); i++) {
    EXPECT_EQ(*it_test, *it_example);
    ++it_test;
    ++it_example;
  }
}

TEST(List, SwapInt) {
  s21::list<int> test{8, 7, 5, 9, 0, 1, 3, 2, 6, 4};
  s21::list<int> test2{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
  std::list<int> example{8, 7, 5, 9, 0, 1, 3, 2, 6, 4};
  std::list<int> example2{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
  test.swap(test2);
  example.swap(example2);
  auto it_test = test.begin();
  auto it_example = example.begin();
  auto it_test2 = test2.begin();
  auto it_example2 = example2.begin();
  EXPECT_EQ(example.size(), test.size());
  EXPECT_EQ(example2.size(), test2.size());
  for (size_t i = 0; i < example.size(); i++) {
    EXPECT_EQ(*it_test, *it_example);
    ++it_test;
    ++it_example;
  }
  for (size_t i = 0; i < example2.size(); i++) {
    EXPECT_EQ(*it_test2, *it_example2);
    ++it_test2;
    ++it_example2;
  }
}

TEST(List, MergeEqualSizeInt) {
  s21::list<int> test{1, 2, 4, 6, 9};
  s21::list<int> merge_test{3, 4, 5, 8, 10};
  std::list<int> example{1, 2, 4, 6, 9};
  std::list<int> merge_example{3, 4, 5, 8, 10};
  test.merge(merge_test);
  example.merge(merge_example);
  auto it_test = test.begin();
  auto it_example = example.begin();
  EXPECT_EQ(example.size(), test.size());
  EXPECT_EQ(merge_example.size(), merge_test.size());
  for (size_t i = 0; i < example.size(); i++) {
    EXPECT_EQ(*it_test, *it_example);
    ++it_test;
    ++it_example;
  }
}

TEST(List, MergeToEmptyInt) {
  s21::list<int> test;
  s21::list<int> merge_test{3, 4, 5, 8, 10};
  std::list<int> example;
  std::list<int> merge_example{3, 4, 5, 8, 10};
  test.merge(merge_test);
  example.merge(merge_example);
  auto it_test = test.begin();
  auto it_example = example.begin();
  EXPECT_EQ(example.size(), test.size());
  EXPECT_EQ(merge_example.size(), merge_test.size());
  for (size_t i = 0; i < example.size(); i++) {
    EXPECT_EQ(*it_test, *it_example);
    ++it_test;
    ++it_example;
  }
}

TEST(List, MergeFromEmptyInt) {
  s21::list<int> test{3, 4, 5, 8, 10};
  s21::list<int> merge_test;
  std::list<int> example{3, 4, 5, 8, 10};
  std::list<int> merge_example;
  test.merge(merge_test);
  example.merge(merge_example);
  auto it_test = test.begin();
  auto it_example = example.begin();
  EXPECT_EQ(example.size(), test.size());
  EXPECT_EQ(merge_example.size(), merge_test.size());
  for (size_t i = 0; i < example.size(); i++) {
    EXPECT_EQ(*it_test, *it_example);
    ++it_test;
    ++it_example;
  }
}

TEST(List, MergeSameListInt) {
  s21::list<int> test{1, 2, 4, 6, 9};
  std::list<int> example{1, 2, 4, 6, 9};
  test.merge(test);
  example.merge(example);
  auto it_test = test.begin();
  auto it_example = example.begin();
  EXPECT_EQ(example.size(), test.size());
  for (size_t i = 0; i < example.size(); i++) {
    EXPECT_EQ(*it_test, *it_example);
    ++it_test;
    ++it_example;
  }
}

TEST(List, MergeIdenticalInt) {
  s21::list<int> test{1, 2, 4, 6, 9};
  s21::list<int> merge_test{1, 2, 4, 6, 9};
  std::list<int> example{1, 2, 4, 6, 9};
  std::list<int> merge_example{1, 2, 4, 6, 9};
  test.merge(merge_test);
  example.merge(merge_example);
  auto it_test = test.begin();
  auto it_example = example.begin();
  EXPECT_EQ(example.size(), test.size());
  EXPECT_EQ(merge_example.size(), merge_test.size());
  for (size_t i = 0; i < example.size(); i++) {
    EXPECT_EQ(*it_test, *it_example);
    ++it_test;
    ++it_example;
  }
}

TEST(List, MergeSameValuesInt) {
  s21::list<int> test{1, 1, 1, 1, 1, 1};
  s21::list<int> merge_test{1, 1, 1, 1, 1, 1};
  std::list<int> example{1, 1, 1, 1, 1, 1};
  std::list<int> merge_example{1, 1, 1, 1, 1, 1};
  test.merge(merge_test);
  example.merge(merge_example);
  auto it_test = test.begin();
  auto it_example = example.begin();
  EXPECT_EQ(example.size(), test.size());
  EXPECT_EQ(merge_example.size(), merge_test.size());
  for (size_t i = 0; i < example.size(); i++) {
    EXPECT_EQ(*it_test, *it_example);
    ++it_test;
    ++it_example;
  }
}

TEST(List, MergeDstSmallerInt) {
  s21::list<int> test{1, 2, 4, 6, 9};
  s21::list<int> merge_test{3, 4, 5, 8, 10, 12, 15, 15, 17};
  std::list<int> example{1, 2, 4, 6, 9};
  std::list<int> merge_example{3, 4, 5, 8, 10, 12, 15, 15, 17};
  test.merge(merge_test);
  example.merge(merge_example);
  auto it_test = test.begin();
  auto it_example = example.begin();
  EXPECT_EQ(example.size(), test.size());
  EXPECT_EQ(merge_example.size(), merge_test.size());
  for (size_t i = 0; i < example.size(); i++) {
    EXPECT_EQ(*it_test, *it_example);
    ++it_test;
    ++it_example;
  }
}

TEST(List, MergeDstLargerInt) {
  s21::list<int> test{3, 4, 5, 8, 10, 12, 15, 15, 17};
  s21::list<int> merge_test{1, 2, 4, 6, 9};
  std::list<int> example{3, 4, 5, 8, 10, 12, 15, 15, 17};
  std::list<int> merge_example{1, 2, 4, 6, 9};
  test.merge(merge_test);
  example.merge(merge_example);
  auto it_test = test.begin();
  auto it_example = example.begin();
  EXPECT_EQ(example.size(), test.size());
  EXPECT_EQ(merge_example.size(), merge_test.size());
  for (size_t i = 0; i < example.size(); i++) {
    EXPECT_EQ(*it_test, *it_example);
    ++it_test;
    ++it_example;
  }
}

TEST(List, MergeUnorderedInt) {
  s21::list<int> test{1, 8, 5, 6, 7, 81, 5, 3, 1, 5};
  s21::list<int> merge_test{3, 5, 84, 6, 5, 4, 1};
  std::list<int> example{1, 8, 5, 6, 7, 81, 5, 3, 1, 5};
  std::list<int> merge_example{3, 5, 84, 6, 5, 4, 1};
  test.merge(merge_test);
  example.merge(merge_example);
  auto it_test = test.begin();
  auto it_example = example.begin();
  EXPECT_EQ(example.size(), test.size());
  EXPECT_EQ(merge_example.size(), merge_test.size());
  for (size_t i = 0; i < example.size(); i++) {
    EXPECT_EQ(*it_test, *it_example);
    ++it_test;
    ++it_example;
  }
}

TEST(List, SpliceBeginInt) {
  s21::list<int> test{1, 2, 4, 6, 9};
  s21::list<int> merge_test{3, 4, 5, 8, 10};
  std::list<int> example{1, 2, 4, 6, 9};
  std::list<int> merge_example{3, 4, 5, 8, 10};
  auto it_test = test.begin();
  auto it_example = example.begin();
  test.splice(test.cbegin(), merge_test);
  example.splice(example.cbegin(), merge_example);

  EXPECT_EQ(example.size(), test.size());
  EXPECT_EQ(merge_example.size(), merge_test.size());
  for (size_t i = 0; i < example.size(); i++) {
    if (it_example == example.end()) {
      ++it_test;
      ++it_example;
    }
    EXPECT_EQ(*it_test, *it_example);
    ++it_test;
    ++it_example;
  }
}

TEST(List, SpliceTailInt) {
  s21::list<int> test{1, 2, 4, 6, 9};
  s21::list<int> merge_test{3, 4, 5, 8, 10};
  std::list<int> example{1, 2, 4, 6, 9};
  std::list<int> merge_example{3, 4, 5, 8, 10};
  auto it_test = test.begin();
  auto it_example = example.begin();
  test.splice(--(test.cend()), merge_test);
  example.splice(--(example.cend()), merge_example);

  EXPECT_EQ(example.size(), test.size());
  EXPECT_EQ(merge_example.size(), merge_test.size());
  for (size_t i = 0; i < example.size(); i++) {
    if (it_example == example.end()) {
      ++it_test;
      ++it_example;
    }
    EXPECT_EQ(*it_test, *it_example);
    ++it_test;
    ++it_example;
  }
}

TEST(List, SpliceDummyInt) {
  s21::list<int> test{1, 2, 4, 6, 9};
  s21::list<int> merge_test{3, 4, 5, 8, 10};
  std::list<int> example{1, 2, 4, 6, 9};
  std::list<int> merge_example{3, 4, 5, 8, 10};
  auto it_test = test.begin();
  auto it_example = example.begin();
  test.splice(test.cend(), merge_test);
  example.splice(example.cend(), merge_example);

  EXPECT_EQ(example.size(), test.size());
  EXPECT_EQ(merge_example.size(), merge_test.size());
  for (size_t i = 0; i < example.size(); i++) {
    if (it_example == example.end()) {
      ++it_test;
      ++it_example;
    }
    EXPECT_EQ(*it_test, *it_example);
    ++it_test;
    ++it_example;
  }
}

TEST(List, SpliceModdleInt) {
  s21::list<int> test{1, 2, 4, 6, 9};
  s21::list<int> merge_test{3, 4, 5, 8, 10};
  std::list<int> example{1, 2, 4, 6, 9};
  std::list<int> merge_example{3, 4, 5, 8, 10};
  auto it_test = test.begin();
  auto it_example = example.begin();
  auto cit_test = test.cbegin();
  auto cit_example = example.cbegin();
  for (int i = 0; i < 3; i++) {
    cit_test++;
    cit_example++;
  }
  test.splice(cit_test, merge_test);
  example.splice(cit_example, merge_example);

  EXPECT_EQ(example.size(), test.size());
  EXPECT_EQ(merge_example.size(), merge_test.size());
  for (size_t i = 0; i < example.size(); i++) {
    if (it_example == example.end()) {
      ++it_test;
      ++it_example;
    }
    EXPECT_EQ(*it_test, *it_example);
    ++it_test;
    ++it_example;
  }
}

TEST(List, SortBasicInt) {
  s21::list<int> test{8, 7, 5, 9, 0, 1, 3, 2};
  std::list<int> example{8, 7, 5, 9, 0, 1, 3, 2};
  test.sort();
  example.sort();
  auto it_test = test.begin();
  auto it_example = example.begin();
  EXPECT_EQ(example.size(), test.size());
  for (size_t i = 0; i < example.size(); i++) {
    EXPECT_EQ(*it_test, *it_example);
    ++it_test;
    ++it_example;
  }
}

TEST(List, SortSortOddInt) {
  s21::list<int> test{8, 7, 5, 9, 0, 1, 3, 2, 10};
  std::list<int> example{8, 7, 5, 9, 0, 1, 3, 2, 10};
  test.sort();
  example.sort();
  auto it_test = test.begin();
  auto it_example = example.begin();
  EXPECT_EQ(example.size(), test.size());
  for (size_t i = 0; i < example.size(); i++) {
    EXPECT_EQ(*it_test, *it_example);
    ++it_test;
    ++it_example;
  }
}

TEST(List, SortSortWithDuplicatesInt) {
  s21::list<int> test{8, 7, 5, 9, 0, 1, 3, 2, 10, 2, 2, 1, 1, 0, 0, 7};
  std::list<int> example{8, 7, 5, 9, 0, 1, 3, 2, 10, 2, 2, 1, 1, 0, 0, 7};
  test.sort();
  example.sort();
  auto it_test = test.begin();
  auto it_example = example.begin();
  EXPECT_EQ(example.size(), test.size());
  for (size_t i = 0; i < example.size(); i++) {
    EXPECT_EQ(*it_test, *it_example);
    ++it_test;
    ++it_example;
  }
}

TEST(List, SortSortWithNegativeInt) {
  s21::list<int> test{8, 7, 5, 9, 0, -1, 3, 2, -10, 2, 2, -1, 1, 0, 0, -7};
  std::list<int> example{8, 7, 5, 9, 0, -1, 3, 2, -10, 2, 2, -1, 1, 0, 0, -7};
  test.sort();
  example.sort();
  auto it_test = test.begin();
  auto it_example = example.begin();
  EXPECT_EQ(example.size(), test.size());
  for (size_t i = 0; i < example.size(); i++) {
    EXPECT_EQ(*it_test, *it_example);
    ++it_test;
    ++it_example;
  }
}

TEST(List, SortSortSortedInt) {
  s21::list<int> test{1, 2, 3, 4, 5, 6, 7, 8, 9};
  std::list<int> example{1, 2, 3, 4, 5, 6, 7, 8, 9};
  test.sort();
  example.sort();
  auto it_test = test.begin();
  auto it_example = example.begin();
  EXPECT_EQ(example.size(), test.size());
  for (size_t i = 0; i < example.size(); i++) {
    EXPECT_EQ(*it_test, *it_example);
    ++it_test;
    ++it_example;
  }
}

TEST(List, SortSortSortedBackInt) {
  s21::list<int> test{9, 8, 7, 6, 5, 4, 3, 2, 1};
  std::list<int> example{9, 8, 7, 6, 5, 4, 3, 2, 1};
  test.sort();
  example.sort();
  auto it_test = test.begin();
  auto it_example = example.begin();
  EXPECT_EQ(example.size(), test.size());
  for (size_t i = 0; i < example.size(); i++) {
    EXPECT_EQ(*it_test, *it_example);
    ++it_test;
    ++it_example;
  }
}

TEST(List, SortEmpty) {
  s21::list<int> test;
  std::list<int> example;
  test.sort();
  example.sort();
  auto it_test = test.begin();
  auto it_example = example.begin();
  EXPECT_EQ(example.size(), test.size());
  for (size_t i = 0; i < example.size(); i++) {
    EXPECT_EQ(*it_test, *it_example);
    ++it_test;
    ++it_example;
  }
}

TEST(List, SortSingle) {
  s21::list<int> test{10};
  std::list<int> example{10};
  test.sort();
  example.sort();
  auto it_test = test.begin();
  auto it_example = example.begin();
  EXPECT_EQ(example.size(), test.size());
  for (size_t i = 0; i < example.size(); i++) {
    EXPECT_EQ(*it_test, *it_example);
    ++it_test;
    ++it_example;
  }
}

TEST(List, SortTwo) {
  s21::list<int> test{10, 0};
  std::list<int> example{10, 0};
  test.sort();
  example.sort();
  auto it_test = test.begin();
  auto it_example = example.begin();
  EXPECT_EQ(example.size(), test.size());
  for (size_t i = 0; i < example.size(); i++) {
    EXPECT_EQ(*it_test, *it_example);
    ++it_test;
    ++it_example;
  }
}

TEST(List, StressSort) {
  s21::list<int> test;
  std::list<int> example;
  for (int i = 0; i < 10000; i++) {
    int random = (std::rand() % 10000) - 5000;
    test.push_back(random);
    example.push_back(random);
  }
  test.sort();
  example.sort();
  auto it_test = test.begin();
  auto it_example = example.begin();
  EXPECT_EQ(example.size(), test.size());
  for (size_t i = 0; i < example.size(); i++) {
    EXPECT_EQ(*it_test, *it_example);
    ++it_test;
    ++it_example;
  }
}

TEST(List, StressTeslaTest) {
  s21::list<TeslaTypeTest> test = S21GenerateTesla();
  std::list<TeslaTypeTest> example = StdGenerateTesla();
  TeslaTypeTest tesla{56, 31.5, 45.45, "Model GG"};
  EXPECT_EQ(example.size(), test.size());
  auto it_test = test.begin();
  auto it_example = example.begin();
  for (size_t i = 0; i < example.size(); i++) {
    CompareTesla(it_test, it_example);
    ++it_test;
    ++it_example;
  }
  test.reverse();
  example.reverse();
  it_test = test.begin();
  it_example = example.begin();
  for (size_t i = 0; i < example.size(); i++) {
    CompareTesla(it_test, it_example);
    ++it_test;
    ++it_example;
  }
  test.unique();
  example.unique();
  it_test = test.begin();
  it_example = example.begin();
  for (size_t i = 0; i < example.size(); i++) {
    CompareTesla(it_test, it_example);
    ++it_test;
    ++it_example;
  }
  for (int i = 0; i < 100; i++) {
    test.pop_back();
    test.pop_front();
    example.pop_back();
    example.pop_front();
  }

  for (int i = 0; i < 700; i++) {
    ++it_test;
    ++it_example;
  }
  test.erase(it_test);
  example.erase(it_example);
  it_test = test.begin();
  it_example = example.begin();
  for (size_t i = 0; i < example.size(); i++) {
    CompareTesla(it_test, it_example);
    ++it_test;
    ++it_example;
  }
  for (int i = 0; i < 500; i++) {
    ++it_test;
    ++it_example;
  }
  for (int i = 0; i < 130; i++) {
    it_test = test.insert(it_test, tesla);
    it_example = example.insert(it_example, tesla);
  }
  test.reverse();
  example.reverse();
  test.unique();
  example.unique();
  it_test = test.begin();
  it_example = example.begin();
  for (size_t i = 0; i < example.size(); i++) {
    CompareTesla(it_test, it_example);
    ++it_test;
    ++it_example;
  }
}

/*
 ---------------------------------------
|                                       |
|          Bonus Insert Many            |
|                                       |
 ---------------------------------------
*/

TEST(List, InsertManyBeginInt) {
  s21::list<int> test{8, 7, 5, 9, 0, 1, 3, 2, 6, 4};
  std::list<int> example{8, 7, 5, 9, 0, 1, 3, 2, 6, 4};
  std::vector<int> to_insert{5, 9, 7, 7, 7, 6, 3};

  test.insert_many(test.cbegin(), 5, 9, 7, 7, 7, 6, 3);
  auto it_target = example.cbegin();
  for (auto val : to_insert) {
    example.insert(it_target, val);
  }
  auto it_test = test.begin();
  auto it_example = example.begin();
  EXPECT_EQ(example.size(), test.size());
  for (size_t i = 0; i < example.size(); i++) {
    EXPECT_EQ(*it_test, *it_example);
    ++it_test;
    ++it_example;
  }
}

TEST(List, InsertManyEndInt) {
  s21::list<int> test{8, 7, 5, 9, 0, 1, 3, 2, 6, 4};
  std::list<int> example{8, 7, 5, 9, 0, 1, 3, 2, 6, 4};
  std::vector<int> to_insert{5, 9, 7, 7, 7, 6, 3};

  test.insert_many(test.cend(), 5, 9, 7, 7, 7, 6, 3);
  auto it_target = example.cend();
  for (auto val : to_insert) {
    example.insert(it_target, val);
  }
  auto it_test = test.begin();
  auto it_example = example.begin();
  EXPECT_EQ(example.size(), test.size());
  for (size_t i = 0; i < example.size(); i++) {
    EXPECT_EQ(*it_test, *it_example);
    ++it_test;
    ++it_example;
  }
}

TEST(List, InsertManyTailInt) {
  s21::list<int> test{8, 7, 5, 9, 0, 1, 3, 2, 6, 4};
  std::list<int> example{8, 7, 5, 9, 0, 1, 3, 2, 6, 4};
  std::vector<int> to_insert{5, 9, 7, 7, 7, 6, 3};

  test.insert_many(--(test.cend()), 5, 9, 7, 7, 7, 6, 3);
  auto it_target = --(example.cend());
  for (auto val : to_insert) {
    example.insert(it_target, val);
  }
  auto it_test = test.begin();
  auto it_example = example.begin();
  EXPECT_EQ(example.size(), test.size());
  for (size_t i = 0; i < example.size(); i++) {
    EXPECT_EQ(*it_test, *it_example);
    ++it_test;
    ++it_example;
  }
}

TEST(List, InsertManyMidInt) {
  s21::list<int> test{8, 7, 5, 9, 0, 1, 3, 2, 6, 4};
  std::list<int> example{8, 7, 5, 9, 0, 1, 3, 2, 6, 4};
  std::vector<int> to_insert{5, 9, 7, 7, 7, 6, 3};
  auto cit_test = test.cbegin();
  auto cit_example = example.cbegin();
  for (int i = 0; i < 5; i++) {
    cit_test++;
    cit_example++;
  }
  test.insert_many(cit_test, 5, 9, 7, 7, 7, 6, 3);
  for (auto val : to_insert) {
    example.insert(cit_example, val);
  }
  auto it_test = test.begin();
  auto it_example = example.begin();
  EXPECT_EQ(example.size(), test.size());
  for (size_t i = 0; i < example.size(); i++) {
    EXPECT_EQ(*it_test, *it_example);
    ++it_test;
    ++it_example;
  }
}

TEST(List, InsertManyNoneInt) {
  s21::list<int> test{8, 7, 5, 9, 0, 1, 3, 2, 6, 4};
  std::list<int> example{8, 7, 5, 9, 0, 1, 3, 2, 6, 4};

  test.insert_many(test.cbegin());
  auto it_test = test.begin();
  auto it_example = example.begin();
  EXPECT_EQ(example.size(), test.size());
  for (size_t i = 0; i < example.size(); i++) {
    EXPECT_EQ(*it_test, *it_example);
    ++it_test;
    ++it_example;
  }
}

TEST(List, InsertManyBackInt) {
  s21::list<int> test{8, 7, 5, 9, 0, 1, 3, 2, 6, 4};
  std::list<int> example{8, 7, 5, 9, 0, 1, 3, 2, 6, 4};
  std::vector<int> to_insert{5, 9, 7, 7, 7, 6, 3};
  test.insert_many_back(5, 9, 7, 7, 7, 6, 3);
  for (auto val : to_insert) {
    example.push_back(val);
  }
  auto it_test = test.begin();
  auto it_example = example.begin();
  EXPECT_EQ(example.size(), test.size());
  for (size_t i = 0; i < example.size(); i++) {
    EXPECT_EQ(*it_test, *it_example);
    ++it_test;
    ++it_example;
  }
}
TEST(List, InsertManyBackNoneInt) {
  s21::list<int> test{8, 7, 5, 9, 0, 1, 3, 2, 6, 4};
  std::list<int> example{8, 7, 5, 9, 0, 1, 3, 2, 6, 4};
  test.insert_many_back();
  auto it_test = test.begin();
  auto it_example = example.begin();
  EXPECT_EQ(example.size(), test.size());
  for (size_t i = 0; i < example.size(); i++) {
    EXPECT_EQ(*it_test, *it_example);
    ++it_test;
    ++it_example;
  }
}

TEST(List, InsertManyFrontInt) {
  s21::list<int> test{8, 7, 5, 9, 0, 1, 3, 2, 6, 4};
  std::list<int> example{8, 7, 5, 9, 0, 1, 3, 2, 6, 4};
  std::vector<int> to_insert{5, 9, 7, 7, 7, 6, 3};
  test.insert_many_front(5, 9, 7, 7, 7, 6, 3);
  for (auto val : to_insert) {
    example.push_front(val);
  }
  auto it_test = test.begin();
  auto it_example = example.begin();
  EXPECT_EQ(example.size(), test.size());
  for (size_t i = 0; i < example.size(); i++) {
    EXPECT_EQ(*it_test, *it_example);
    ++it_test;
    ++it_example;
  }
}

TEST(List, InsertManyFrontNoneInt) {
  s21::list<int> test{8, 7, 5, 9, 0, 1, 3, 2, 6, 4};
  std::list<int> example{8, 7, 5, 9, 0, 1, 3, 2, 6, 4};
  test.insert_many_front();
  auto it_test = test.begin();
  auto it_example = example.begin();
  EXPECT_EQ(example.size(), test.size());
  for (size_t i = 0; i < example.size(); i++) {
    EXPECT_EQ(*it_test, *it_example);
    ++it_test;
    ++it_example;
  }
}

TEST(List, InsertManyFrontSingleInt) {
  s21::list<int> test{8, 7, 5, 9, 0, 1, 3, 2, 6, 4};
  std::list<int> example{8, 7, 5, 9, 0, 1, 3, 2, 6, 4};
  test.insert_many_front(5);
  example.push_front(5);
  auto it_test = test.begin();
  auto it_example = example.begin();
  EXPECT_EQ(example.size(), test.size());
  for (size_t i = 0; i < example.size(); i++) {
    EXPECT_EQ(*it_test, *it_example);
    ++it_test;
    ++it_example;
  }
}
