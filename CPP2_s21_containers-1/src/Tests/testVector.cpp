#include "test.h"

template <typename T>
bool vector_comparision(const s21::vector<T> &v1, const std::vector<T> &v2) {
  if (v1.size() != v2.size()) {
    return false;
  }
  for (std::size_t i = 0; i < v1.size(); ++i) {
    if (v1[i] != v2[i]) {
      return false;
    }
  }
  return true;
}

TEST(S21VectorTest, Constructor) {
  s21::vector<int> v1;
  std::vector<int> v2;
  EXPECT_TRUE(vector_comparision(v1, v2));
}

TEST(S21VectorTest, Constructor_Correct) {
  s21::vector<int> v1;
  std::vector<int> v2;
  EXPECT_EQ(v1.size(), v2.size());
}

TEST(S21VectorTest, Constructor_Incorrect) {
  s21::vector<int> v1;
  std::vector<int> v2;
  v2.push_back(1);
  EXPECT_NE(v1.size(), v2.size());
}

TEST(S21VectorTest, SizeConstructor) {
  s21::vector<int> v1(5);
  std::vector<int> v2(5);
  EXPECT_TRUE(vector_comparision(v1, v2));
}

TEST(S21VectorTest, SizeConstructor_Correct) {
  s21::vector<int> v1(5);
  std::vector<int> v2(5);
  EXPECT_EQ(v1.size(), v2.size());
}

TEST(S21VectorTest, SizeConstructor_Incorrect) {
  s21::vector<int> v1(5);
  std::vector<int> v2(6);
  EXPECT_NE(v1.size(), v2.size());
}

TEST(S21VectorTest, InitializerConstructor) {
  s21::vector<int> v1{1, 2, 3};
  std::vector<int> v2{1, 2, 3};
  EXPECT_TRUE(vector_comparision(v1, v2));
}

TEST(S21VectorTest, InitializerConstructor_Correct) {
  s21::vector<int> v1{1, 2, 3};
  std::vector<int> v2{1, 2, 3};
  EXPECT_EQ(v1.size(), v2.size());
}

TEST(S21VectorTest, InitializerConstructor_Incorrect) {
  s21::vector<int> v1{1, 2, 3};
  std::vector<int> v2{1, 2, 3, 4};
  EXPECT_NE(v1.size(), v2.size());
}

TEST(S21VectorTest, CopyConstructor) {
  s21::vector<int> v1{1, 2, 3};
  s21::vector<int> v1_copy(v1);
  std::vector<int> v2{1, 2, 3};
  std::vector<int> v2_copy(v2);
  EXPECT_TRUE(vector_comparision(v1_copy, v2_copy));
}

TEST(S21VectorTest, CopyConstructor_Correct) {
  s21::vector<int> v1{1, 2, 3};
  s21::vector<int> v1_copy(v1);
  EXPECT_EQ(v1.size(), v1_copy.size());
}

TEST(S21VectorTest, CopyConstructor_Incorrect) {
  s21::vector<int> v1{1, 2, 3};
  s21::vector<int> v1_copy(v1);
  s21::vector<int> v1_wrong{1, 2, 3, 4};
  EXPECT_NE(v1_copy.size(), v1_wrong.size());
}

TEST(S21VectorTest, MoveConstructor) {
  s21::vector<int> v1{1, 2, 3};
  s21::vector<int> v1_moved(std::move(v1));
  std::vector<int> v2{1, 2, 3};
  std::vector<int> v2_moved(std::move(v2));
  EXPECT_TRUE(vector_comparision(v1_moved, v2_moved));
}

TEST(S21VectorTest, MoveConstructor_Correct) {
  s21::vector<int> v1{1, 2, 3};
  s21::vector<int> v1_moved(std::move(v1));
  EXPECT_EQ(v1_moved[0], 1);
  EXPECT_EQ(v1_moved[1], 2);
  EXPECT_EQ(v1_moved[2], 3);
}

TEST(S21VectorTest, MoveConstructor_Incorrect) {
  s21::vector<int> v1{1, 2, 3};
  s21::vector<int> v1_moved(std::move(v1));
  EXPECT_NE(v1_moved.size(), v1.size());
}

TEST(S21VectorTest, MoveAssignment) {
  s21::vector<int> v1{1, 2, 3};
  s21::vector<int> v1_moved;
  v1_moved = std::move(v1);
  std::vector<int> v2{1, 2, 3};
  std::vector<int> v2_moved;
  v2_moved = std::move(v2);
  EXPECT_TRUE(vector_comparision(v1_moved, v2_moved));
}

TEST(S21VectorTest, MoveAssignment_Correct) {
  s21::vector<int> v1{1, 2, 3};
  s21::vector<int> v1_moved;
  v1_moved = std::move(v1);
  EXPECT_EQ(v1_moved[0], 1);
  EXPECT_EQ(v1_moved[1], 2);
  EXPECT_EQ(v1_moved[2], 3);
}

TEST(S21VectorTest, MoveAssignment_Incorrect) {
  s21::vector<int> v1{1, 2, 3};
  s21::vector<int> v1_moved;
  v1_moved = std::move(v1);
  EXPECT_NE(v1_moved.size(), v1.size());
}

TEST(S21VectorTest, At) {
  s21::vector<int> v1{1, 2, 3};
  std::vector<int> v2{1, 2, 3};
  for (std::size_t i = 0; i < v1.size(); ++i) {
    EXPECT_EQ(v1.at(i), v2.at(i));
  }
}

TEST(S21VectorTest, At_Correct) {
  s21::vector<int> v1{1, 2, 3};
  EXPECT_EQ(v1.at(0), 1);
  EXPECT_EQ(v1.at(1), 2);
  EXPECT_EQ(v1.at(2), 3);
}

TEST(S21VectorTest, At_Incorrect) {
  s21::vector<int> v1{1, 2, 3};
  EXPECT_THROW(v1.at(3), std::out_of_range);
}

TEST(S21VectorTest, FrontAndBack) {
  s21::vector<int> v1{1, 2, 3};
  std::vector<int> v2{1, 2, 3};
  EXPECT_EQ(v1.front(), v2.front());
}

TEST(S21VectorTest, FrontAndBack_Correct) {
  s21::vector<int> v1{1, 2, 3};
  EXPECT_EQ(v1.front(), 1);
  EXPECT_EQ(v1.back(), 3);
}

TEST(S21VectorTest, FrontAndBack_Incorrect) {
  s21::vector<int> v1{1, 2, 3};
  EXPECT_NE(v1.front(), 3);
  EXPECT_NE(v1.back(), 1);
}

TEST(S21VectorTest, Data) {
  s21::vector<int> v1{1, 2, 3};
  std::vector<int> v2{1, 2, 3};
  EXPECT_EQ(*v1.data(), *v2.data());
}

TEST(S21VectorTest, Data_Correct) {
  s21::vector<int> v1{1, 2, 3};
  std::vector<int> v2{1, 2, 3};
  int *ar1 = v1.data();
  int *ar2 = v2.data();
  EXPECT_EQ(ar1[1], ar2[1]);
}

TEST(S21VectorTest, Empty) {
  s21::vector<int> v1;
  std::vector<int> v2;
  EXPECT_EQ(v1.empty(), v2.empty());
}

TEST(S21VectorTest, Empty_Correct) {
  s21::vector<int> v1;
  EXPECT_TRUE(v1.empty());
}

TEST(S21VectorTest, Empty_Incorrect) {
  s21::vector<int> v1{1, 2, 3};
  EXPECT_FALSE(v1.empty());
}

TEST(S21VectorTest, Size) {
  s21::vector<int> v1{1, 2, 3};
  std::vector<int> v2{1, 2, 3};
  EXPECT_EQ(v1.size(), v2.size());
}

TEST(S21VectorTest, Size_Correct) {
  s21::vector<int> v1{1, 2, 3};
  EXPECT_EQ(v1.size(), 3);
}

TEST(S21VectorTest, Size_Incorrect) {
  s21::vector<int> v1{1, 2, 3};
  EXPECT_NE(v1.size(), 4);
}

TEST(S21VectorTest, MaxSize) {
  s21::vector<int> v1;
  std::vector<int> v2;
  double ratio = static_cast<double>(v1.max_size()) / v2.max_size();
  EXPECT_NEAR(ratio, 2.0, 0.1);
}

TEST(S21VectorTest, MaxSize_Correct) {
  s21::vector<int> v1;
  EXPECT_GT(v1.max_size(), 0);
}

TEST(S21VectorTest, MaxSize_Incorrect) {
  s21::vector<int> v1;
  EXPECT_NE(v1.max_size(), -1);
}

TEST(S21VectorTest, ReserveAndCapacity) {
  s21::vector<int> v1{1, 2, 3};
  std::vector<int> v2{1, 2, 3};
  v1.reserve(100);
  v2.reserve(100);
  EXPECT_EQ(v1.capacity(), v2.capacity());
}

TEST(S21VectorTest, ReserveAndCapacity_Correct) {
  s21::vector<int> v1{1, 2, 3};
  v1.reserve(100);
  EXPECT_GE(v1.capacity(), 100);
}

TEST(S21VectorTest, ReserveAndCapacity_Incorrect) {
  s21::vector<int> v1{1, 2, 3};
  v1.reserve(100);
  EXPECT_NE(v1.capacity(), 50);
}

TEST(S21VectorTest, ShrinkToFit) {
  s21::vector<int> v1{1, 2, 3};
  std::vector<int> v2{1, 2, 3};
  v1.shrink_to_fit();
  v2.shrink_to_fit();
  EXPECT_EQ(v1.capacity(), v2.capacity());
}

TEST(S21VectorTest, ShrinkToFit_Correct) {
  s21::vector<int> v1{1, 2, 3};
  v1.shrink_to_fit();
  EXPECT_EQ(v1.capacity(), v1.size());
}

TEST(S21VectorTest, ShrinkToFit_Incorrect) {
  s21::vector<int> v1{1, 2, 3};
  v1.reserve(100);
  v1.shrink_to_fit();
  EXPECT_NE(v1.capacity(), 100);
}

TEST(S21VectorTest, Clear) {
  s21::vector<int> v1{1, 2, 3};
  std::vector<int> v2{1, 2, 3};
  v1.clear();
  v2.clear();
  EXPECT_TRUE(vector_comparision(v1, v2));
}

TEST(S21VectorTest, Clear_Correct) {
  s21::vector<int> v1{1, 2, 3};
  v1.clear();
  EXPECT_TRUE(v1.empty());
}

TEST(S21VectorTest, Clear_Incorrect) {
  s21::vector<int> v1{1, 2, 3};
  v1.clear();
  EXPECT_FALSE(v1.size() == 3);
}

TEST(S21VectorTest, PushBack) {
  s21::vector<int> v1{1, 2, 3};
  std::vector<int> v2{1, 2, 3};
  v1.push_back(4);
  v2.push_back(4);
  EXPECT_TRUE(vector_comparision(v1, v2));
}

TEST(S21VectorTest, PushBack_Correct) {
  s21::vector<int> v1{1, 2, 3};
  v1.push_back(4);
  EXPECT_EQ(v1.size(), 4);
  EXPECT_EQ(v1.back(), 4);
}

TEST(S21VectorTest, PushBack_Incorrect) {
  s21::vector<int> v1{1, 2, 3};
  v1.push_back(4);
  EXPECT_NE(v1.size(), 3);
  EXPECT_NE(v1.back(), 3);
}

TEST(S21VectorTest, PopBack) {
  s21::vector<int> v1{1, 2, 3};
  std::vector<int> v2{1, 2, 3};
  v1.pop_back();
  v2.pop_back();
  EXPECT_TRUE(vector_comparision(v1, v2));
}

TEST(S21VectorTest, PopBack_Correct) {
  s21::vector<int> v1{1, 2, 3};
  v1.pop_back();
  EXPECT_EQ(v1.size(), 2);
  EXPECT_EQ(v1.back(), 2);
}

TEST(S21VectorTest, PopBack_Incorrect) {
  s21::vector<int> v1{1, 2, 3};
  v1.pop_back();
  EXPECT_NE(v1.size(), 3);
  EXPECT_NE(v1.back(), 3);
}

TEST(S21VectorTest, Swap) {
  s21::vector<int> v1{1, 2, 3};
  s21::vector<int> v1_swap{4, 5, 6};
  std::vector<int> v2{1, 2, 3};
  std::vector<int> v2_swap{4, 5, 6};
  v1.swap(v1_swap);
  v2.swap(v2_swap);

  EXPECT_TRUE(vector_comparision(v1, v2));
  EXPECT_TRUE(vector_comparision(v1_swap, v2_swap));
}

TEST(S21VectorTest, Swap_Correct) {
  s21::vector<int> v1{1, 2, 3};
  s21::vector<int> v1_swap{4, 5, 6};
  v1.swap(v1_swap);
  EXPECT_EQ(v1.size(), 3);
  EXPECT_EQ(v1.front(), 4);
  EXPECT_EQ(v1.back(), 6);
  EXPECT_EQ(v1_swap.size(), 3);
  EXPECT_EQ(v1_swap.front(), 1);
  EXPECT_EQ(v1_swap.back(), 3);
}

TEST(VectorIteratorTest, Increment_Correct) {
  s21::vector<int> v{1, 2, 3};
  s21::vector<int>::iterator it = v.begin();
  ++it;
  EXPECT_EQ(*it, 2);
  ++it;
  EXPECT_EQ(*it, 3);
}

TEST(VectorIteratorTest, Increment_Incorrect) {
  s21::vector<int> v{1, 2, 3};
  s21::vector<int>::iterator it = v.begin();
  ++it;
  EXPECT_NE(*it, 1);
  ++it;
  EXPECT_NE(*it, 2);
}

TEST(VectorIteratorTest, Decrement_Correct) {
  s21::vector<int> v{1, 2, 3};
  s21::vector<int>::iterator it = v.end();
  --it;
  EXPECT_EQ(*it, 3);
  --it;
  EXPECT_EQ(*it, 2);
}

TEST(VectorIteratorTest, Decrement_Incorrect) {
  s21::vector<int> v{1, 2, 3};
  s21::vector<int>::iterator it = v.end();
  --it;
  EXPECT_NE(*it, 2);
  --it;
  EXPECT_NE(*it, 1);
}

TEST(VectorIteratorTest, Dereference_Correct) {
  s21::vector<int> v{1, 2, 3};
  s21::vector<int>::iterator it = v.begin();
  EXPECT_EQ(*it, 1);
  ++it;
  EXPECT_EQ(*it, 2);
}

TEST(VectorIteratorTest, Dereference_Incorrect) {
  s21::vector<int> v{1, 2, 3};
  s21::vector<int>::iterator it = v.begin();
  EXPECT_NE(*it, 2);
  ++it;
  EXPECT_NE(*it, 1);
}

TEST(VectorIteratorTest, Equality_Correct) {
  s21::vector<int> v{1, 2, 3};
  s21::vector<int>::iterator it1 = v.begin();
  s21::vector<int>::iterator it2 = v.begin();
  EXPECT_TRUE(it1 == it2);
  ++it1;
  EXPECT_FALSE(it1 == it2);
}

TEST(VectorIteratorTest, Equality_Incorrect) {
  s21::vector<int> v{1, 2, 3};
  s21::vector<int>::iterator it1 = v.begin();
  s21::vector<int>::iterator it2 = v.begin();
  EXPECT_FALSE(it1 != it2);
  ++it1;
  EXPECT_TRUE(it1 != it2);
}

TEST(VectorConstIteratorTest, Increment_Correct) {
  const s21::vector<int> v{1, 2, 3};
  s21::vector<int>::const_iterator it = v.cbegin();
  ++it;
  EXPECT_EQ(*it, 2);
  ++it;
  EXPECT_EQ(*it, 3);
}

TEST(VectorConstIteratorTest, Increment_Incorrect) {
  const s21::vector<int> v{1, 2, 3};
  s21::vector<int>::const_iterator it = v.cbegin();
  ++it;
  EXPECT_NE(*it, 1);
  ++it;
  EXPECT_NE(*it, 2);
}

TEST(VectorConstIteratorTest, Decrement_Correct) {
  const s21::vector<int> v{1, 2, 3};
  s21::vector<int>::const_iterator it = v.cend();
  --it;
  EXPECT_EQ(*it, 3);
  --it;
  EXPECT_EQ(*it, 2);
}

TEST(VectorConstIteratorTest, Decrement_Incorrect) {
  const s21::vector<int> v{1, 2, 3};
  s21::vector<int>::const_iterator it = v.cend();
  --it;
  EXPECT_NE(*it, 2);
  --it;
  EXPECT_NE(*it, 1);
}

TEST(VectorConstIteratorTest, Dereference_Correct) {
  const s21::vector<int> v{1, 2, 3};
  s21::vector<int>::const_iterator it = v.cbegin();
  EXPECT_EQ(*it, 1);
  ++it;
  EXPECT_EQ(*it, 2);
}

TEST(VectorConstIteratorTest, Dereference_Incorrect) {
  const s21::vector<int> v{1, 2, 3};
  s21::vector<int>::const_iterator it = v.cbegin();
  EXPECT_NE(*it, 2);
  ++it;
  EXPECT_NE(*it, 1);
}

TEST(VectorConstIteratorTest, Equality_Correct) {
  const s21::vector<int> v{1, 2, 3};
  s21::vector<int>::const_iterator it1 = v.cbegin();
  s21::vector<int>::const_iterator it2 = v.cbegin();
  EXPECT_TRUE(it1 == it2);
  ++it1;
  EXPECT_FALSE(it1 == it2);
}

TEST(VectorConstIteratorTest, Equality_Incorrect) {
  const s21::vector<int> v{1, 2, 3};
  s21::vector<int>::const_iterator it1 = v.cbegin();
  s21::vector<int>::const_iterator it2 = v.cbegin();
  EXPECT_FALSE(it1 != it2);
  ++it1;
  EXPECT_TRUE(it1 != it2);
}

TEST(VectorConstIteratorTest2, ConstIteratorOperatorPlus) {
  const s21::vector<int> v{1, 2, 3};

  s21::vector<int>::const_iterator it = v.cbegin();
  s21::vector<int>::const_iterator result = it + 2;

  EXPECT_EQ(*result, 3);
}

TEST(VectorConstIteratorTest2, ConstIteratorOperatorMinus) {
  const s21::vector<int> v{1, 2, 3};
  s21::vector<int>::const_iterator it = v.cend();
  s21::vector<int>::const_iterator result = it - 2;

  EXPECT_EQ(*result, 2);
}

TEST(VectorConstIteratorTest2, ConstIteratorOperatorPlusPlus) {
  const s21::vector<int> v{1, 2, 3};
  s21::vector<int>::const_iterator it = v.cbegin();
  it++;

  EXPECT_EQ(*it, 2);
}

TEST(VectorConstIteratorTest2, ConstIteratorOperatorMinusMinus) {
  const s21::vector<int> v{1, 2, 3};
  s21::vector<int>::const_iterator it = v.cend();
  it--;

  EXPECT_EQ(*it, 3);
}

TEST(VectorConstIteratorTest2, ConstIteratorOperatorMinus2) {
  const s21::vector<int> v{1, 2, 3};

  s21::vector<int>::const_iterator it1 = v.cbegin();
  s21::vector<int>::const_iterator it2 = v.cend();

  ptrdiff_t result = it2 - it1;

  EXPECT_EQ(result, 3);
}

TEST(S21VectorTest, OperatorBracketThrowTest) {
  s21::vector<int> v;
  EXPECT_THROW(v[0], std::out_of_range);
  EXPECT_THROW(v[5], std::out_of_range);

  v.push_back(42);
  EXPECT_NO_THROW(v[0]);
  EXPECT_THROW(v[1], std::out_of_range);
}

TEST(S21VectorTest, FrontThrowTest) {
  s21::vector<int> v;
  EXPECT_THROW(v.front(), std::out_of_range);

  v.push_back(42);
  EXPECT_NO_THROW(v.front());

  v.clear();
  EXPECT_THROW(v.front(), std::out_of_range);
}

TEST(S21VectorTest, BackThrowTest) {
  s21::vector<int> v;
  EXPECT_THROW(v.back(), std::out_of_range);

  v.push_back(42);
  EXPECT_NO_THROW(v.back());

  v.clear();
  EXPECT_THROW(v.back(), std::out_of_range);
}

TEST(S21VectorTest, InsertThrowTest) {
  s21::vector<int> v;
  v.push_back(1);
  v.push_back(2);
  v.push_back(3);

  EXPECT_NO_THROW(v.insert(v.begin() + 1, 42));

  EXPECT_THROW(v.insert(v.begin() + 5, 42), std::out_of_range);
}

TEST(S21VectorTest, EraseThrowTest) {
  s21::vector<int> v;
  v.push_back(1);
  v.push_back(2);
  v.push_back(3);

  EXPECT_NO_THROW(v.erase(v.begin() + 1));

  EXPECT_THROW(v.erase(v.begin() + 5), std::out_of_range);
}

TEST(S21VectorTest, OperatorIndexOutOfRangeTest) {
  const s21::vector<int> v{1, 2, 3};

  EXPECT_THROW({ v[3]; }, std::out_of_range);
  EXPECT_THROW({ v[4]; }, std::out_of_range);
  EXPECT_THROW({ v[-1]; }, std::out_of_range);
}

TEST(S21VectorTest, ReserveExceedsMaxSizeTest) {
  s21::vector<int> v;

  EXPECT_THROW({ v.reserve(v.max_size() + 1); }, std::length_error);
}

TEST(VectorBonusTest, INSERTMANYTest0) {
  s21::vector<int> v1;
  std::vector<int> v2;

  v1.insert_many(v1.begin(), 21);
  v2.emplace(v2.begin(), 21);

  EXPECT_TRUE(vector_comparision(v1, v2));
}

TEST(VectorBonusTest, INSERTMANYTest1) {
  s21::vector<int> v1{1, 2, 3};
  std::vector<int> v2{1, 2, 3};

  v1.insert_many(v1.begin() + 1, 21);
  v2.emplace(v2.begin() + 1, 21);

  EXPECT_TRUE(vector_comparision(v1, v2));
}

TEST(VectorBonusTest, INSERTMANYTest12) {
  s21::vector<int> v1{1, 2, 3};
  std::vector<int> v2{1, 2, 3};

  v1.insert_many(v1.begin() + 1, 4);
  v2.emplace(v2.begin() + 1, 4);
  v1.insert_many(v1.begin() + 1, 5);
  v2.emplace(v2.begin() + 1, 5);

  EXPECT_TRUE(vector_comparision(v1, v2));
}

TEST(VectorBonusTest, INSERTMANYTest2) {
  s21::vector<int> v1{1, 2, 3};
  std::vector<int> v2{1, 2, 3};

  v1.insert_many(v1.begin(), 21);
  v2.emplace(v2.begin(), 21);

  EXPECT_TRUE(vector_comparision(v1, v2));
}

TEST(VectorBonusTest, INSERTMANYTest3) {
  s21::vector<int> v1{1, 2, 3};
  std::vector<int> v2{1, 2, 3};

  v1.insert_many(v1.end(), 21);
  v2.emplace(v2.end(), 21);

  EXPECT_TRUE(vector_comparision(v1, v2));
}

TEST(VectorBonusTest, INSERTMANYTest4) {
  s21::vector<std::string> v1{"aboba", "abiba", "abuba"};
  std::vector<std::string> v2{"aboba", "abiba", "abuba"};

  v1.insert_many(v1.begin() + 1, "abeba");
  v2.emplace(v2.begin() + 1, "abeba");

  EXPECT_TRUE(vector_comparision(v1, v2));
}

TEST(VectorBonusTest, INSERTMANYBackTest1) {
  s21::vector<int> v1{1, 2, 3};
  std::vector<int> v2{1, 2, 3};

  v1.insert_many_back(21);
  v2.emplace_back(21);

  EXPECT_TRUE(vector_comparision(v1, v2));
}

TEST(VectorBonusTest, INSERTMANYBackTest2) {
  s21::vector<int> v1;
  std::vector<int> v2;

  v1.insert_many_back(21);
  v2.emplace_back(21);

  EXPECT_TRUE(vector_comparision(v1, v2));
}

TEST(VectorBonusTest, INSERTMANYBackTest3) {
  s21::vector<std::string> v1{"aboba", "abiba", "abuba"};
  std::vector<std::string> v2{"aboba", "abiba", "abuba"};

  v1.insert_many_back("abeba");
  v2.emplace_back("abeba");

  EXPECT_TRUE(vector_comparision(v1, v2));
}

TEST(VectorBonusTest, INSERTMANYBackTest5) {
  s21::vector<int> v1;
  std::vector<int> v2;

  for (int i = 0; i < 10; ++i) {
    v1.insert_many_back(i);
    v2.emplace_back(i);
  }

  EXPECT_TRUE(vector_comparision(v1, v2));
}

TEST(VectorBonusTest, INSERTMANYBackTest6) {
  s21::vector<double> v1{1.12, 2.23, 3.34};
  std::vector<double> v2{1.12, 2.23, 3.34};

  v1.insert_many_back(4.45);
  v2.emplace_back(4.45);

  EXPECT_TRUE(vector_comparision(v1, v2));
}

TEST(VectorBonusTest, INSERTMANYBackTest7) {
  s21::vector<std::string> v1;
  std::vector<std::string> v2;

  v1.insert_many_back("aboooooba");
  v2.emplace_back("aboooooba");

  EXPECT_TRUE(vector_comparision(v1, v2));
}

TEST(VectorBonusTest, INSERTMANYBackTest9) {
  s21::vector<int> v1;
  std::vector<int> v2;

  for (int i = 0; i < 999; ++i) {
    v1.insert_many_back(i);
    v2.emplace_back(i);
  }

  EXPECT_TRUE(vector_comparision(v1, v2));
}

TEST(VectorBonusTest, INSERTMANYBackTest10) {
  s21::vector<int> v1;
  std::vector<int> v2;

  v1.reserve(99);
  v2.reserve(99);

  for (int i = 0; i < 99; ++i) {
    v1.insert_many_back(i);
    v2.emplace_back(i);
  }

  EXPECT_TRUE(vector_comparision(v1, v2));
}
