#include "knapsack_problem.h"

int knapsackDFS(std::vector<int> &wgt, std::vector<int> &val, int i, int c) {
  if (i == 0) return c >= wgt[0] ? val[0] : 0;

  if (c < wgt[i]) return knapsackDFS(wgt, val, i - 1, c);

  auto no = knapsackDFS(wgt, val, i - 1, c);
  auto yes = knapsackDFS(wgt, val, i - 1, c - wgt[i]) + val[i];

  return std::max(no, yes);
}

int knapsackDFSMen(std::vector<int> &wgt, std::vector<int> &val, std::vector<std::vector<int>> &men, int i, int c) {
  if (auto ret = men[i][c]; ret != -1) return ret;
  if (i == 0) return c >= wgt[0] ? val[0] : 0;
  if (c < wgt[i]) return knapsackDFSMen(wgt, val, men, i - 1, c);

  auto no = knapsackDFSMen(wgt, val, men, i - 1, c);
  auto yes = knapsackDFSMen(wgt, val, men, i - 1, c - wgt[i]) + val[i];

  auto ret = std::max(no, yes);
  men[i][c] = ret;
  return ret;
}

int knapsackDP(std::vector<int> &wgt, std::vector<int> &val, int cap) {
  const auto size = wgt.size();
  std::vector<std::vector<int>> dp(size + 1, std::vector<int>(cap + 1, 0));

  for (int i = 1; i <= size; ++i) {
    auto w = wgt[i - 1];
    auto v = val[i - 1];

    for (int j = 1; j <= cap; ++j) {
      auto no = dp[i][j] = dp[i - 1][j];
      if (j < w) {
        dp[i][j] = no;
        continue;
      }

      auto yes = dp[i - 1][j - w] + v;
      dp[i][j] = std::max(no, yes);
    }
  }

  return dp[size][cap];
}

int knapsackDPComp(std::vector<int> &wgt, std::vector<int> &val, int cap) {
  const auto size = wgt.size();
  std::vector<int> dp(cap + 1, 0);

  for (int i = 1; i <= size; ++i) {
    auto w = wgt[i - 1];
    auto v = val[i - 1];

    for (int j = cap; j >= 1; --j) {
      if (j < w) {
        continue;
      }

      auto yes = dp[j - w] + v;
      dp[j] = std::max(dp[j], yes);
    }
  }

  return dp[cap];
}
