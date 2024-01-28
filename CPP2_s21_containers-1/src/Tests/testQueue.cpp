#include "test.h"

TEST(Queue, ConstructorSimpleCustom) {
  s21::queue<TeslaTypeTest> test;
  std::queue<TeslaTypeTest> example;
  EXPECT_EQ(test.size(), example.size());
  EXPECT_EQ(test.empty(), example.empty());
}

TEST(Queue, ConstructorSimpleInt) {
  s21::queue<int> test;
  std::queue<int> example;
  EXPECT_EQ(example.size(), test.size());
}

TEST(Queue, ConstructorSimpleString) {
  s21::queue<std::string> test;
  std::queue<std::string> example;
  EXPECT_EQ(example.size(), test.size());
}
TEST(Queue, ConstructorInitializerInt) {
  s21::queue<int> test{12, 23, 45, 56, 67, 45, 13, 2, 4, 5};
  std::vector<int> to_push{12, 23, 45, 56, 67, 45, 13, 2, 4, 5};
  std::queue<int> example;
  for (auto val : to_push) {
    example.push(val);
  }
  EXPECT_EQ(example.size(), test.size());
  while (!example.empty()) {
    auto test_val = test.front();
    auto example_val = example.front();
    EXPECT_EQ(test_val, example_val);
    example.pop();
    test.pop();
  }
}

TEST(Queue, ConstructorInitializerString) {
  s21::queue<std::string> test{"lol", "kek", "cheburek"};
  std::vector<std::string> to_push{"lol", "kek", "cheburek"};
  std::queue<std::string> example;
  for (auto val : to_push) {
    example.push(val);
  }
  EXPECT_EQ(example.size(), test.size());
  while (!example.empty()) {
    auto test_val = test.front();
    auto example_val = example.front();
    EXPECT_EQ(test_val, example_val);
    example.pop();
    test.pop();
  }
}

TEST(Queue, ConstructorCopyInt) {
  s21::queue<int> copy_from_t{12, 23, 45, 56, 67, 45, 13, 2, 4, 5};
  std::queue<int> copy_from_e;
  std::vector<int> to_push{12, 23, 45, 56, 67, 45, 13, 2, 4, 5};
  for (auto val : to_push) {
    copy_from_e.push(val);
  }
  s21::queue<int> test(copy_from_t);
  std::queue<int> example(copy_from_e);
  EXPECT_EQ(example.size(), test.size());
  EXPECT_EQ(copy_from_t.size(), copy_from_e.size());
  while (!example.empty()) {
    auto test_val = test.front();
    auto example_val = example.front();
    auto test_val_copy = copy_from_t.front();
    auto example_val_copy = copy_from_e.front();
    EXPECT_EQ(test_val, example_val);
    EXPECT_EQ(test_val_copy, example_val_copy);
    example.pop();
    test.pop();
    copy_from_e.pop();
    copy_from_t.pop();
  }
}

TEST(Queue, ConstructorCopyString) {
  s21::queue<std::string> copy_from_t{"lol", "kek", "cheburek"};
  std::queue<std::string> copy_from_e;
  std::vector<std::string> to_push{"lol", "kek", "cheburek"};
  for (auto val : to_push) {
    copy_from_e.push(val);
  }
  s21::queue<std::string> test(copy_from_t);
  std::queue<std::string> example(copy_from_e);
  EXPECT_EQ(example.size(), test.size());
  EXPECT_EQ(copy_from_t.size(), copy_from_e.size());
  while (!example.empty()) {
    auto test_val = test.front();
    auto example_val = example.front();
    auto test_val_copy = copy_from_t.front();
    auto example_val_copy = copy_from_e.front();
    EXPECT_EQ(test_val, example_val);
    EXPECT_EQ(test_val_copy, example_val_copy);
    example.pop();
    test.pop();
    copy_from_e.pop();
    copy_from_t.pop();
  }
}

TEST(Queue, ConstructorMoveInt) {
  s21::queue<int> move_from_t{12, 23, 45, 56, 67, 45, 13, 2, 4, 5};
  std::queue<int> move_from_e;
  std::vector<int> to_push{12, 23, 45, 56, 67, 45, 13, 2, 4, 5};
  for (auto val : to_push) {
    move_from_e.push(val);
  }
  s21::queue<int> test(std::move(move_from_t));
  std::queue<int> example(std::move(move_from_e));
  EXPECT_EQ(example.size(), test.size());
  EXPECT_EQ(move_from_t.size(), move_from_e.size());
  EXPECT_EQ(move_from_t.empty(), move_from_e.empty());
  while (!example.empty()) {
    auto test_val = test.front();
    auto example_val = example.front();
    EXPECT_EQ(test_val, example_val);
    example.pop();
    test.pop();
  }
}

TEST(Queue, ConstructorMoveString) {
  s21::queue<std::string> move_from_t{"lol", "kek", "cheburek"};
  std::queue<std::string> move_from_e;
  std::vector<std::string> to_push{"lol", "kek", "cheburek"};
  for (auto val : to_push) {
    move_from_e.push(val);
  }
  s21::queue<std::string> test(std::move(move_from_t));
  std::queue<std::string> example(std::move(move_from_e));
  EXPECT_EQ(example.size(), test.size());
  EXPECT_EQ(move_from_t.size(), move_from_e.size());
  EXPECT_EQ(move_from_t.empty(), move_from_e.empty());
  while (!example.empty()) {
    auto test_val = test.front();
    auto example_val = example.front();
    EXPECT_EQ(test_val, example_val);
    example.pop();
    test.pop();
  }
}

TEST(Queue, AssignMoveInt) {
  s21::queue<int> move_from_t{12, 23, 45, 56, 67, 45, 13, 2, 4, 5};
  std::queue<int> move_from_e;
  std::vector<int> to_push{12, 23, 45, 56, 67, 45, 13, 2, 4, 5};
  std::vector<int> to_push2{13, 2, 4, 5};
  for (auto val : to_push) {
    move_from_e.push(val);
  }
  s21::queue<int> test{13, 2, 4, 5};
  std::queue<int> example;
  for (auto val : to_push2) {
    example.push(val);
  }
  test = std::move(move_from_t);
  example = std::move(move_from_e);
  EXPECT_EQ(example.size(), test.size());
  EXPECT_EQ(move_from_t.size(), move_from_e.size());
  EXPECT_EQ(move_from_t.empty(), move_from_e.empty());
  while (!example.empty()) {
    auto test_val = test.front();
    auto example_val = example.front();
    EXPECT_EQ(test_val, example_val);
    example.pop();
    test.pop();
  }
}

TEST(Queue, AssignMoveString) {
  s21::queue<std::string> move_from_t{"lol", "kek", "cheburek"};
  std::queue<std::string> move_from_e;
  std::vector<std::string> to_push{"lol", "kek", "cheburek"};
  std::vector<std::string> to_push2{"peepee poopoo"};
  for (auto val : to_push) {
    move_from_e.push(val);
  }
  s21::queue<std::string> test{"peepee poopoo"};
  std::queue<std::string> example;
  for (auto val : to_push2) {
    example.push(val);
  }
  test = std::move(move_from_t);
  example = std::move(move_from_e);
  EXPECT_EQ(example.size(), test.size());
  EXPECT_EQ(move_from_t.size(), move_from_e.size());
  EXPECT_EQ(move_from_t.empty(), move_from_e.empty());
  while (!example.empty()) {
    auto test_val = test.front();
    auto example_val = example.front();
    EXPECT_EQ(test_val, example_val);
    example.pop();
    test.pop();
  }
}

/*
 ---------------------------------------
|                                       |
|           Front/Back Access           |
|                                       |
 ---------------------------------------
*/

TEST(Queue, FrontValidInt) {
  s21::queue<int> test{12, 23, 45, 56, 67, 45, 13, 2, 4, 5};
  std::queue<int> example;
  std::vector<int> to_push{12, 23, 45, 56, 67, 45, 13, 2, 4, 5};
  for (auto val : to_push) {
    example.push(val);
  }
  while (!example.empty()) {
    auto test_val = test.front();
    auto example_val = example.front();
    EXPECT_EQ(example.size(), test.size());
    EXPECT_EQ(test_val, example_val);
    example.pop();
    test.pop();
  }
}

TEST(Queue, FrontValidString) {
  s21::queue<std::string> test{"lol", "kek", "cheburek"};
  std::queue<std::string> example;
  std::vector<std::string> to_push{"lol", "kek", "cheburek"};
  for (auto val : to_push) {
    example.push(val);
  }
  while (!example.empty()) {
    auto test_val = test.front();
    auto example_val = example.front();
    EXPECT_EQ(example.size(), test.size());
    EXPECT_EQ(test_val, example_val);
    example.pop();
    test.pop();
  }
}

TEST(Queue, BackValidInt) {
  s21::queue<int> test{12, 23, 45, 56, 67, 45, 13, 2, 4, 5};
  std::queue<int> example;
  std::vector<int> to_push{12, 23, 45, 56, 67, 45, 13, 2, 4, 5};
  for (auto val : to_push) {
    example.push(val);
  }
  while (!example.empty()) {
    auto test_val = test.back();
    auto example_val = example.back();
    EXPECT_EQ(example.size(), test.size());
    EXPECT_EQ(test_val, example_val);
    example.pop();
    test.pop();
  }
}

/*
 ---------------------------------------
|                                       |
|           Queue Modifiers             |
|                                       |
 ---------------------------------------
*/

TEST(Queue, PushTest) {
  s21::queue<int> test;
  std::queue<int> example;
  std::vector<int> to_push{12, 23, 45, 56, 67, 45, 13, 2, 4, 5};
  for (auto val : to_push) {
    example.push(val);
    test.push(val);
    auto test_val_b = test.back();
    auto example_val_b = example.back();
    auto test_val_f = test.front();
    auto example_val_f = example.front();
    EXPECT_EQ(example.size(), test.size());
    EXPECT_EQ(test_val_b, example_val_b);
    EXPECT_EQ(test_val_f, example_val_f);
  }
}

TEST(Queue, PushTestString) {
  s21::queue<std::string> test;
  std::queue<std::string> example;
  std::vector<std::string> to_push{"poo", "pee", "peepoo", "1", "323"};
  for (auto val : to_push) {
    example.push(val);
    test.push(val);
    auto test_val_b = test.back();
    auto example_val_b = example.back();
    auto test_val_f = test.front();
    auto example_val_f = example.front();
    EXPECT_EQ(example.size(), test.size());
    EXPECT_EQ(test_val_b, example_val_b);
    EXPECT_EQ(test_val_f, example_val_f);
  }
}

TEST(Queue, PopTest) {
  s21::queue<int> test;
  std::queue<int> example;
  std::vector<int> to_push{12, 23, 45, 56, 67, 45, 13, 2, 4, 5};
  for (auto val : to_push) {
    example.push(val);
    test.push(val);
  }
  while (!example.empty()) {
    auto test_val_b = test.back();
    auto example_val_b = example.back();
    auto test_val_f = test.front();
    auto example_val_f = example.front();
    EXPECT_EQ(example.size(), test.size());
    EXPECT_EQ(test_val_b, example_val_b);
    EXPECT_EQ(test_val_f, example_val_f);
    example.pop();
    test.pop();
  }
}

TEST(Queue, PopTestString) {
  s21::queue<std::string> test;
  std::queue<std::string> example;
  std::vector<std::string> to_push{"poo", "pee", "peepoo", "1", "323"};
  for (auto val : to_push) {
    example.push(val);
    test.push(val);
  }
  while (!example.empty()) {
    auto test_val_b = test.back();
    auto example_val_b = example.back();
    auto test_val_f = test.front();
    auto example_val_f = example.front();
    EXPECT_EQ(example.size(), test.size());
    EXPECT_EQ(test_val_b, example_val_b);
    EXPECT_EQ(test_val_f, example_val_f);
    example.pop();
    test.pop();
  }
}

TEST(Queue, SwapInt) {
  s21::queue<int> test{8, 7, 5, 9, 0, 1, 3, 2, 6, 4};
  s21::queue<int> test2{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
  std::queue<int> example;
  std::queue<int> example2;
  std::vector<int> to_push1{8, 7, 5, 9, 0, 1, 3, 2, 6, 4};
  std::vector<int> to_push2{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
  for (auto val : to_push1) {
    example.push(val);
  }
  for (auto val : to_push2) {
    example2.push(val);
  }
  test.swap(test2);
  example.swap(example2);
  EXPECT_EQ(example.size(), test.size());
  EXPECT_EQ(example2.size(), test2.size());
  while (!example.empty()) {
    auto test_val_b = test.back();
    auto example_val_b = example.back();
    auto test_val_f = test.front();
    auto example_val_f = example.front();
    EXPECT_EQ(example.size(), test.size());
    EXPECT_EQ(test_val_b, example_val_b);
    EXPECT_EQ(test_val_f, example_val_f);
    example.pop();
    test.pop();
  }
  while (!example2.empty()) {
    auto test_val_b = test2.back();
    auto example_val_b = example2.back();
    auto test_val_f = test2.front();
    auto example_val_f = example2.front();
    EXPECT_EQ(example2.size(), test2.size());
    EXPECT_EQ(test_val_b, example_val_b);
    EXPECT_EQ(test_val_f, example_val_f);
    example2.pop();
    test2.pop();
  }
}

TEST(Queue, InsertManyBackInt) {
  s21::queue<int> test{8, 7, 5, 9, 0, 1, 3, 2, 6, 4};
  std::queue<int> example;
  std::vector<int> to_push{8, 7, 5, 9, 0, 1, 3, 2, 6, 4};
  for (auto val : to_push) {
    example.push(val);
  }
  std::vector<int> to_insert{5, 9, 7, 7, 7, 6, 3};
  test.insert_many_back(5, 9, 7, 7, 7, 6, 3);
  for (auto val : to_insert) {
    example.push(val);
  }
  while (!test.empty()) {
    auto test_val_b = test.back();
    auto example_val_b = example.back();
    auto test_val_f = test.front();
    auto example_val_f = example.front();
    EXPECT_EQ(example.size(), test.size());
    EXPECT_EQ(test_val_b, example_val_b);
    EXPECT_EQ(test_val_f, example_val_f);
    example.pop();
    test.pop();
  }
}
TEST(Queue, InsertManyBackNoneInt) {
  s21::queue<int> test{8, 7, 5, 9, 0, 1, 3, 2, 6, 4};
  std::queue<int> example;
  std::vector<int> to_push{8, 7, 5, 9, 0, 1, 3, 2, 6, 4};
  for (auto val : to_push) {
    example.push(val);
  }
  test.insert_many_back();
  while (!test.empty()) {
    auto test_val_b = test.back();
    auto example_val_b = example.back();
    auto test_val_f = test.front();
    auto example_val_f = example.front();
    EXPECT_EQ(example.size(), test.size());
    EXPECT_EQ(test_val_b, example_val_b);
    EXPECT_EQ(test_val_f, example_val_f);
    example.pop();
    test.pop();
  }
}
