#include "test.h"

TEST(Stack, ConstructorSimpleCustom) {
  s21::stack<TeslaTypeTest> test;
  std::stack<TeslaTypeTest> example;
  EXPECT_EQ(test.size(), example.size());
  EXPECT_EQ(test.empty(), example.empty());
}

TEST(Stack, ConstructorSimpleInt) {
  s21::stack<int> test;
  std::stack<int> example;
  EXPECT_EQ(example.size(), test.size());
}

TEST(Stack, ConstructorSimpleString) {
  s21::stack<std::string> test;
  std::stack<std::string> example;
  EXPECT_EQ(example.size(), test.size());
}
TEST(Stack, ConstructorInitializerInt) {
  s21::stack<int> test{12, 23, 45, 56, 67, 45, 13, 2, 4, 5};
  std::vector<int> to_push{12, 23, 45, 56, 67, 45, 13, 2, 4, 5};
  std::stack<int> example;
  for (auto val : to_push) {
    example.push(val);
  }
  EXPECT_EQ(example.size(), test.size());
  while (!example.empty()) {
    auto test_val = test.top();
    auto example_val = example.top();
    EXPECT_EQ(test_val, example_val);
    example.pop();
    test.pop();
  }
}

TEST(Stack, ConstructorInitializerString) {
  s21::stack<std::string> test{"lol", "kek", "cheburek"};
  std::vector<std::string> to_push{"lol", "kek", "cheburek"};
  std::stack<std::string> example;
  for (auto val : to_push) {
    example.push(val);
  }
  EXPECT_EQ(example.size(), test.size());
  while (!example.empty()) {
    auto test_val = test.top();
    auto example_val = example.top();
    EXPECT_EQ(test_val, example_val);
    example.pop();
    test.pop();
  }
}

TEST(Stack, ConstructorCopyInt) {
  s21::stack<int> copy_from_t{12, 23, 45, 56, 67, 45, 13, 2, 4, 5};
  std::stack<int> copy_from_e;
  std::vector<int> to_push{12, 23, 45, 56, 67, 45, 13, 2, 4, 5};
  for (auto val : to_push) {
    copy_from_e.push(val);
  }
  s21::stack<int> test(copy_from_t);
  std::stack<int> example(copy_from_e);
  EXPECT_EQ(example.size(), test.size());
  EXPECT_EQ(copy_from_t.size(), copy_from_e.size());
  while (!example.empty()) {
    auto test_val = test.top();
    auto example_val = example.top();
    auto test_val_copy = copy_from_t.top();
    auto example_val_copy = copy_from_e.top();
    EXPECT_EQ(test_val, example_val);
    EXPECT_EQ(test_val_copy, example_val_copy);
    example.pop();
    test.pop();
    copy_from_e.pop();
    copy_from_t.pop();
  }
}

TEST(Stack, ConstructorCopyString) {
  s21::stack<std::string> copy_from_t{"lol", "kek", "cheburek"};
  std::stack<std::string> copy_from_e;
  std::vector<std::string> to_push{"lol", "kek", "cheburek"};
  for (auto val : to_push) {
    copy_from_e.push(val);
  }
  s21::stack<std::string> test(copy_from_t);
  std::stack<std::string> example(copy_from_e);
  EXPECT_EQ(example.size(), test.size());
  EXPECT_EQ(copy_from_t.size(), copy_from_e.size());
  while (!example.empty()) {
    auto test_val = test.top();
    auto example_val = example.top();
    auto test_val_copy = copy_from_t.top();
    auto example_val_copy = copy_from_e.top();
    EXPECT_EQ(test_val, example_val);
    EXPECT_EQ(test_val_copy, example_val_copy);
    example.pop();
    test.pop();
    copy_from_e.pop();
    copy_from_t.pop();
  }
}

TEST(Stack, ConstructorMoveInt) {
  s21::stack<int> move_from_t{12, 23, 45, 56, 67, 45, 13, 2, 4, 5};
  std::stack<int> move_from_e;
  std::vector<int> to_push{12, 23, 45, 56, 67, 45, 13, 2, 4, 5};
  for (auto val : to_push) {
    move_from_e.push(val);
  }
  s21::stack<int> test(std::move(move_from_t));
  std::stack<int> example(std::move(move_from_e));
  EXPECT_EQ(example.size(), test.size());
  EXPECT_EQ(move_from_t.size(), move_from_e.size());
  EXPECT_EQ(move_from_t.empty(), move_from_e.empty());
  while (!example.empty()) {
    auto test_val = test.top();
    auto example_val = example.top();
    EXPECT_EQ(test_val, example_val);
    example.pop();
    test.pop();
  }
}

TEST(Stack, ConstructorMoveString) {
  s21::stack<std::string> move_from_t{"lol", "kek", "cheburek"};
  std::stack<std::string> move_from_e;
  std::vector<std::string> to_push{"lol", "kek", "cheburek"};
  for (auto val : to_push) {
    move_from_e.push(val);
  }
  s21::stack<std::string> test(std::move(move_from_t));
  std::stack<std::string> example(std::move(move_from_e));
  EXPECT_EQ(example.size(), test.size());
  EXPECT_EQ(move_from_t.size(), move_from_e.size());
  EXPECT_EQ(move_from_t.empty(), move_from_e.empty());
  while (!example.empty()) {
    auto test_val = test.top();
    auto example_val = example.top();
    EXPECT_EQ(test_val, example_val);
    example.pop();
    test.pop();
  }
}

TEST(Stack, AssignMoveInt) {
  s21::stack<int> move_from_t{12, 23, 45, 56, 67, 45, 13, 2, 4, 5};
  std::stack<int> move_from_e;
  std::vector<int> to_push{12, 23, 45, 56, 67, 45, 13, 2, 4, 5};
  std::vector<int> to_push2{13, 2, 4, 5};
  for (auto val : to_push) {
    move_from_e.push(val);
  }
  s21::stack<int> test{13, 2, 4, 5};
  std::stack<int> example;
  for (auto val : to_push2) {
    example.push(val);
  }
  test = std::move(move_from_t);
  example = std::move(move_from_e);
  EXPECT_EQ(example.size(), test.size());
  EXPECT_EQ(move_from_t.size(), move_from_e.size());
  EXPECT_EQ(move_from_t.empty(), move_from_e.empty());
  while (!example.empty()) {
    auto test_val = test.top();
    auto example_val = example.top();
    EXPECT_EQ(test_val, example_val);
    example.pop();
    test.pop();
  }
}

TEST(Stack, AssignMoveString) {
  s21::stack<std::string> move_from_t{"lol", "kek", "cheburek"};
  std::stack<std::string> move_from_e;
  std::vector<std::string> to_push{"lol", "kek", "cheburek"};
  std::vector<std::string> to_push2{"peepee poopoo"};
  for (auto val : to_push) {
    move_from_e.push(val);
  }
  s21::stack<std::string> test{"peepee poopoo"};
  std::stack<std::string> example;
  for (auto val : to_push2) {
    example.push(val);
  }
  test = std::move(move_from_t);
  example = std::move(move_from_e);
  EXPECT_EQ(example.size(), test.size());
  EXPECT_EQ(move_from_t.size(), move_from_e.size());
  EXPECT_EQ(move_from_t.empty(), move_from_e.empty());
  while (!example.empty()) {
    auto test_val = test.top();
    auto example_val = example.top();
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

TEST(Stack, TopValidInt) {
  s21::stack<int> test{12, 23, 45, 56, 67, 45, 13, 2, 4, 5};
  std::stack<int> example;
  std::vector<int> to_push{12, 23, 45, 56, 67, 45, 13, 2, 4, 5};
  for (auto val : to_push) {
    example.push(val);
  }
  while (!example.empty()) {
    auto test_val = test.top();
    auto example_val = example.top();
    EXPECT_EQ(example.size(), test.size());
    EXPECT_EQ(test_val, example_val);
    example.pop();
    test.pop();
  }
}

TEST(Stack, TopValidString) {
  s21::stack<std::string> test{"lol", "kek", "cheburek"};
  std::stack<std::string> example;
  std::vector<std::string> to_push{"lol", "kek", "cheburek"};
  for (auto val : to_push) {
    example.push(val);
  }
  while (!example.empty()) {
    auto test_val = test.top();
    auto example_val = example.top();
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

TEST(Stack, PushTest) {
  s21::stack<int> test;
  std::stack<int> example;
  std::vector<int> to_push{12, 23, 45, 56, 67, 45, 13, 2, 4, 5};
  for (auto val : to_push) {
    example.push(val);
    test.push(val);
    auto test_val_f = test.top();
    auto example_val_f = example.top();
    EXPECT_EQ(example.size(), test.size());
    EXPECT_EQ(test_val_f, example_val_f);
  }
}

TEST(Stack, PushTestString) {
  s21::stack<std::string> test;
  std::stack<std::string> example;
  std::vector<std::string> to_push{"poo", "pee", "peepoo", "1", "323"};
  for (auto val : to_push) {
    example.push(val);
    test.push(val);
    auto test_val_f = test.top();
    auto example_val_f = example.top();
    EXPECT_EQ(example.size(), test.size());
    EXPECT_EQ(test_val_f, example_val_f);
  }
}

TEST(Stack, PopTest) {
  s21::stack<int> test;
  std::stack<int> example;
  std::vector<int> to_push{12, 23, 45, 56, 67, 45, 13, 2, 4, 5};
  for (auto val : to_push) {
    example.push(val);
    test.push(val);
  }
  while (!example.empty()) {
    auto test_val_f = test.top();
    auto example_val_f = example.top();
    EXPECT_EQ(example.size(), test.size());
    EXPECT_EQ(test_val_f, example_val_f);
    example.pop();
    test.pop();
  }
}

TEST(Stack, PopTestString) {
  s21::stack<std::string> test;
  std::stack<std::string> example;
  std::vector<std::string> to_push{"poo", "pee", "peepoo", "1", "323"};
  for (auto val : to_push) {
    example.push(val);
    test.push(val);
  }
  while (!example.empty()) {
    auto test_val_f = test.top();
    auto example_val_f = example.top();
    EXPECT_EQ(example.size(), test.size());
    EXPECT_EQ(test_val_f, example_val_f);
    example.pop();
    test.pop();
  }
}

TEST(Stack, SwapInt) {
  s21::stack<int> test{8, 7, 5, 9, 0, 1, 3, 2, 6, 4};
  s21::stack<int> test2{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
  std::stack<int> example;
  std::stack<int> example2;
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
    auto test_val_f = test.top();
    auto example_val_f = example.top();
    EXPECT_EQ(example.size(), test.size());
    EXPECT_EQ(test_val_f, example_val_f);
    example.pop();
    test.pop();
  }
  while (!example2.empty()) {
    auto test_val_f = test2.top();
    auto example_val_f = example2.top();
    EXPECT_EQ(example2.size(), test2.size());
    EXPECT_EQ(test_val_f, example_val_f);
    example2.pop();
    test2.pop();
  }
}

TEST(Stack, InsertManyFrontInt) {
  s21::stack<int> test{8, 7, 5, 9, 0, 1, 3, 2, 6, 4};
  std::stack<int> example;
  std::vector<int> to_push{8, 7, 5, 9, 0, 1, 3, 2, 6, 4};
  for (auto val : to_push) {
    example.push(val);
  }
  std::vector<int> to_insert{5, 9, 7, 7, 7, 6, 3};
  test.insert_many_front(5, 9, 7, 7, 7, 6, 3);
  for (auto val : to_insert) {
    example.push(val);
  }
  while (!test.empty()) {
    auto test_val_f = test.top();
    auto example_val_f = example.top();
    EXPECT_EQ(example.size(), test.size());

    EXPECT_EQ(test_val_f, example_val_f);
    example.pop();
    test.pop();
  }
}
TEST(Stack, InsertManyFrontNoneInt) {
  s21::stack<int> test{8, 7, 5, 9, 0, 1, 3, 2, 6, 4};
  std::stack<int> example;
  std::vector<int> to_push{8, 7, 5, 9, 0, 1, 3, 2, 6, 4};
  for (auto val : to_push) {
    example.push(val);
  }
  test.insert_many_front();
  while (!test.empty()) {
    auto test_val_f = test.top();
    auto example_val_f = example.top();
    EXPECT_EQ(example.size(), test.size());
    EXPECT_EQ(test_val_f, example_val_f);
    example.pop();
    test.pop();
  }
}

TEST(Stack, InsertManyFrontSingleInt) {
  s21::stack<int> test{8, 7, 5, 9, 0, 1, 3, 2, 6, 4};
  std::stack<int> example;
  std::vector<int> to_push{8, 7, 5, 9, 0, 1, 3, 2, 6, 4};
  for (auto val : to_push) {
    example.push(val);
  }
  test.insert_many_front(5);
  example.push(5);

  while (!test.empty()) {
    auto test_val_f = test.top();
    auto example_val_f = example.top();
    EXPECT_EQ(example.size(), test.size());

    EXPECT_EQ(test_val_f, example_val_f);
    example.pop();
    test.pop();
  }
}