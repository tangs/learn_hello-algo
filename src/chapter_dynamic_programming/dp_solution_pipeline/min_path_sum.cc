#include <chrono>
#include <iostream>

int minPathSumDFS(std::vector<std::vector<int>> &grid, int i, int j) {
  if (i == 0 && j == 0) return grid[i][j];
  if (i < 0 || j < 0) return std::numeric_limits<int>::max();

  int up = minPathSumDFS(grid, i - 1, j);
  int left = minPathSumDFS(grid, i, j - 1);

  int ret = std::min(up, left) + grid[i][j];

  return ret;
}

int minPathSumDFSMen(std::vector<std::vector<int>> &grid, std::vector<std::vector<int>> &men, int i, int j) {
  if (i == 0 && j == 0) return grid[i][j];
  if (i < 0 || j < 0) return std::numeric_limits<int>::max();
  if (men[i][j] != -1) return men[i][j];

  int up = minPathSumDFSMen(grid, men, i - 1, j);
  int left = minPathSumDFSMen(grid, men, i, j - 1);

  int ret = std::min(up, left) + grid[i][j];
  men[i][j] = ret;

  return ret;
}

int minPathSumDP(std::vector<std::vector<int>> grid) {
  auto row = grid.size();
  auto col = grid[0].size();

  std::vector<std::vector<int>> dp(row + 1, std::vector<int>(col + 1, 0));
  for (int i = 2; i <= row; ++i) dp[i][0] = std::numeric_limits<int>::max();
  for (int i = 2; i <= col; ++i) dp[0][i] = std::numeric_limits<int>::max();

  for (int i = 1; i <= row; ++i) {
    for (int j = 1; j <= col; ++j) {
      dp[i][j] = std::min(dp[i - 1][j], dp[i][j - 1]) + grid[i - 1][j - 1];
    }
  }

  return dp[row][col];
}

int minPathSumDP1(std::vector<std::vector<int>> grid) {
  auto row = grid.size();
  auto col = grid[0].size();

  std::vector<int> dp(col + 1, 0);
  for (int j = 1; j <= col; ++j) {
    dp[j] = dp[j - 1] + grid[0][j - 1];
  }
  dp[0] = std::numeric_limits<int>::max();

  for (int i = 2; i <= row; ++i) {
    for (int j = 1; j <= col; ++j) {
      dp[j] = std::min(dp[j], dp[j - 1]) + grid[i - 1][j - 1];
    }
  }

  return dp[col];
}
