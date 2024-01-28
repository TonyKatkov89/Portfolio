#ifndef SRC_TESTS_TEST_H_
#define SRC_TESTS_TEST_H_

#include <array>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

#include "../s21_containers.h"
#include "../s21_containersplus.h"
#include "gtest/gtest.h"

struct TeslaTypeTest {
  int battery;
  double speed;
  double distance;
  std::string name;
  bool operator==(const TeslaTypeTest& other) const noexcept {
    auto res = true;
    if (battery != other.battery) {
      res = false;
    }
    if (speed != other.speed) {
      res = false;
    }
    if (distance != other.distance) {
      res = false;
    }
    if (name != other.name) {
      res = false;
    }
    return res;
  }
};

void CompareTesla(const s21::list<TeslaTypeTest>::iterator& it_test,
                  const std::list<TeslaTypeTest>::iterator& it_example);
s21::list<TeslaTypeTest> S21GenerateTesla();
std::list<TeslaTypeTest> StdGenerateTesla();

#endif  // SRC_TESTS_TEST_H_
