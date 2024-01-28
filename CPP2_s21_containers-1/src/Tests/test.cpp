#include "test.h"

s21::list<TeslaTypeTest> S21GenerateTesla() {
  TeslaTypeTest tesla{100, 40.5, 0, "Model X"};
  s21::list<TeslaTypeTest> tesla_list{tesla};
  for (int i = 0; i < 4; i++) {
    tesla_list.push_back(tesla);
  }
  for (int i = 0; i < 1000; i++) {
    tesla.distance += tesla.speed;
    tesla.battery -= 1;
    tesla_list.push_back(tesla);
  }
  for (int i = 0; i < 6; i++) {
    tesla_list.push_back(tesla);
  }
  tesla.battery = 100;
  tesla.speed = 90.12;
  tesla.distance = 0;
  tesla.name = "Roadster";
  for (int i = 0; i < 4; i++) {
    tesla_list.push_back(tesla);
  }
  for (int i = 0; i < 100; i++) {
    tesla.distance += tesla.speed;
    tesla.battery -= 2;
    tesla_list.push_back(tesla);
  }
  for (int i = 0; i < 8; i++) {
    tesla_list.push_back(tesla);
  }
  return tesla_list;
}

std::list<TeslaTypeTest> StdGenerateTesla() {
  TeslaTypeTest tesla{100, 40.5, 0, "Model X"};
  std::list<TeslaTypeTest> tesla_list{tesla};
  for (int i = 0; i < 4; i++) {
    tesla_list.push_back(tesla);
  }
  for (int i = 0; i < 1000; i++) {
    tesla.distance += tesla.speed;
    tesla.battery -= 1;
    tesla_list.push_back(tesla);
  }
  for (int i = 0; i < 6; i++) {
    tesla_list.push_back(tesla);
  }
  tesla.battery = 100;
  tesla.speed = 90.12;
  tesla.distance = 0;
  tesla.name = "Roadster";
  for (int i = 0; i < 4; i++) {
    tesla_list.push_back(tesla);
  }
  for (int i = 0; i < 100; i++) {
    tesla.distance += tesla.speed;
    tesla.battery -= 2;
    tesla_list.push_back(tesla);
  }
  for (int i = 0; i < 8; i++) {
    tesla_list.push_back(tesla);
  }
  return tesla_list;
}

void CompareTesla(const s21::list<TeslaTypeTest>::iterator& it_test,
                  const std::list<TeslaTypeTest>::iterator& it_example) {
  EXPECT_EQ((*it_example).battery, (*it_test).battery);
  EXPECT_EQ((*it_example).speed, (*it_test).speed);
  EXPECT_EQ((*it_example).distance, (*it_test).distance);
  EXPECT_EQ((*it_example).name, (*it_test).name);
}

int main() {
  ::testing::InitGoogleTest();
  return RUN_ALL_TESTS();
}
