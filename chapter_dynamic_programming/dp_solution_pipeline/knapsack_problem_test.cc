#include <gtest/gtest.h>
#include <cstdlib>
#include <ctime>

#include "knapsack_problem.h"

TEST(exp_test, BasicAssertions) {
  std::vector<int> wgt = {10, 20, 30, 40, 50};
  std::vector<int> val = {50, 120, 150, 210, 240};
  const auto knapsackCapacity = 50;

  std::vector<std::vector<int>> men(wgt.size(), std::vector<int>(knapsackCapacity + 1, -1));

  auto ret0 = knapsackDFS(wgt, val, wgt.size() - 1, knapsackCapacity);
  auto ret1 = knapsackDFSMen(wgt, val, men, wgt.size() - 1, knapsackCapacity);
  auto ret2 = knapsackDP(wgt, val, knapsackCapacity);
  auto ret3 = knapsackDPComp(wgt, val, knapsackCapacity);

  EXPECT_EQ(ret0, 270);
  EXPECT_EQ(ret1, 270);
  EXPECT_EQ(ret2, 270);
  EXPECT_EQ(ret3, 270);
}

TEST(test1, BasicAssertions) {
  std::srand(std::time(nullptr));
  for (int i = 0; i < 100; ++i) {
    std::vector<int> wgt;
    std::vector<int> val;

    int wgtCnt = std::rand() % 50 + 5;
    int valCnt = std::rand() % 10000 + 1;

    for (int j = 0; j < wgtCnt; ++j) wgt.push_back(std::rand() % 10000 + 1);
    for (int j = 0; j < valCnt; ++j) val.push_back(std::rand() % 10000 + 1);

    int knapsackCapacity = std::rand() % 1000 + 5;
    std::vector<std::vector<int>> men(wgt.size(), std::vector<int>(knapsackCapacity + 1, -1));

    auto ret0 = knapsackDFS(wgt, val, wgt.size() - 1, knapsackCapacity);
    auto ret1 = knapsackDFSMen(wgt, val, men, wgt.size() - 1, knapsackCapacity);
    auto ret2 = knapsackDP(wgt, val, knapsackCapacity);
    auto ret3 = knapsackDPComp(wgt, val, knapsackCapacity);

    EXPECT_EQ(ret0, ret1);
    EXPECT_EQ(ret0, ret2);
    EXPECT_EQ(ret0, ret3);
  }
}