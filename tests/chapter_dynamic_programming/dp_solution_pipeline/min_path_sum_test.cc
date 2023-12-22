#include <gtest/gtest.h>
#include <random>

#include "min_path_sum.h"

TEST(min_path_sum_exp_testing, BasicAssertions) {
    std::vector<std::vector<int>> grid0 = {
          {1, 3, 1, 5},
          {2, 2, 4, 2},
          {5, 3, 2, 1},
          {4, 3, 5, 2},
  };

  std::vector<std::vector<int>> men(grid0.size(), std::vector<int>(grid0[0].size(), -1));
  auto ret0 = minPathSumDFS(grid0, (int)grid0.size() - 1, (int)grid0[0].size() - 1);
  auto ret1 = minPathSumDFSMen(grid0, men, (int)grid0.size() - 1, (int)grid0[0].size() - 1);
  auto ret2 = minPathSumDP(grid0);
  auto ret3 = minPathSumDP1(grid0);

  EXPECT_EQ(ret0, ret1);
  EXPECT_EQ(ret0, ret2);
  EXPECT_EQ(ret0, ret3);
}

TEST(min_path_sum_rand_testing, BasicAssertions) {
  constexpr auto times = 1000;

  std::random_device rd;
  std::mt19937 mt(rd());
  std::uniform_int_distribution<int> dist1(5, 10);
  std::uniform_int_distribution<int> dist2(1, 10000);

  for (int time = 0; time < times; ++time) {
    auto ROW = dist1(mt);
    auto COL = dist1(mt);

    std::vector<std::vector<int>> grid0;
    for (int i = 0; i < ROW; ++i) {
      grid0.emplace_back();
      for (int j = 0; j < COL; ++j) {
        grid0[i].push_back(dist2(mt));
      }
    }
    std::vector<std::vector<int>> men(grid0.size(), std::vector<int>(grid0[0].size(), -1));

    auto ret0 = minPathSumDFS(grid0, (int)grid0.size() - 1, (int)grid0[0].size() - 1);
    auto ret1 = minPathSumDFSMen(grid0, men, (int)grid0.size() - 1, (int)grid0[0].size() - 1);
    auto ret2 = minPathSumDP(grid0);
    auto ret3 = minPathSumDP1(grid0);

    EXPECT_EQ(ret0, ret1);
    EXPECT_EQ(ret0, ret2);
    EXPECT_EQ(ret0, ret3);
  }
}