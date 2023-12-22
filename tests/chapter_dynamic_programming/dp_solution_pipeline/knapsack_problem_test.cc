#include <gtest/gtest.h>
#include <random>

#include "knapsack_problem.h"

TEST(knapsack_problem_exp_testing, BasicAssertions) {
  std::vector<int> wgt = {10, 20, 30, 40, 50};
  std::vector<int> val = {50, 120, 150, 210, 240};
  const auto knapsackCapacity = 50;
  const auto wgtSize = static_cast<int>(wgt.size());

  std::vector<std::vector<int>> men(wgt.size(), std::vector<int>(knapsackCapacity + 1, -1));

  auto ret0 = knapsackDFS(wgt, val, wgtSize - 1, knapsackCapacity);
  auto ret1 = knapsackDFSMen(wgt, val, men, wgtSize - 1, knapsackCapacity);
  auto ret2 = knapsackDP(wgt, val, knapsackCapacity);
  auto ret3 = knapsackDPComp(wgt, val, knapsackCapacity);

  EXPECT_EQ(ret0, 270);
  EXPECT_EQ(ret1, 270);
  EXPECT_EQ(ret2, 270);
  EXPECT_EQ(ret3, 270);
}

TEST(knapsack_problem_rand_testing, BasicAssertions) {
  std::random_device rd;
  std::mt19937 mt(rd());
  for (int i = 0; i < 1000; ++i) {
    std::vector<int> wgt;
    std::vector<int> val;

    int wgtCnt = std::uniform_int_distribution<int>(5, 100)(mt);
    int valCnt = std::uniform_int_distribution<int>(1, 10000)(mt);
    int knapsackCapacity = std::uniform_int_distribution<int>(5, 1000)(mt);

    std::uniform_int_distribution<int> dist(1, 10000);

    wgt.reserve(wgtCnt);
    for (int j = 0; j < wgtCnt; ++j) wgt.push_back(dist(mt));

    val.reserve(valCnt);
    for (int j = 0; j < valCnt; ++j) val.push_back(dist(mt));

    std::vector<std::vector<int>> men(wgt.size(), std::vector<int>(knapsackCapacity + 1, -1));

    auto ret0 = knapsackDFS(wgt, val, static_cast<int>(wgt.size() - 1), knapsackCapacity);
    auto ret1 = knapsackDFSMen(wgt, val, men,  static_cast<int>(wgt.size() - 1), knapsackCapacity);
    auto ret2 = knapsackDP(wgt, val, knapsackCapacity);
    auto ret3 = knapsackDPComp(wgt, val, knapsackCapacity);

    EXPECT_EQ(ret0, ret1);
    EXPECT_EQ(ret0, ret2);
    EXPECT_EQ(ret0, ret3);
  }
}