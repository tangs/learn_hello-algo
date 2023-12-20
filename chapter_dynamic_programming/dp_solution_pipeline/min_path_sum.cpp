#include <vector>
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

int main() {
//  std::vector<std::vector<int>> grid0 = {
//          {1, 3, 1, 5},
//          {2, 2, 4, 2},
//          {5, 3, 2, 1},
//          {4, 3, 5, 2},
//  };
  constexpr auto ROW = 14;
  constexpr auto COL = 18;
  std::vector<std::vector<int>> grid0;
  for (int i = 0; i < ROW; ++i) {
    grid0.emplace_back();
    for (int j = 0; j < COL; ++j) {
      grid0[i].push_back(j);
    }
  }
  std::vector<std::vector<int>> men(grid0.size(), std::vector<int>(grid0[0].size(), -1));

  const auto time0{std::chrono::steady_clock::now()};
  auto ret0 = minPathSumDFS(grid0, (int)grid0.size() - 1, (int)grid0[0].size() - 1);
  const auto time1{std::chrono::steady_clock::now()};
  auto ret1 = minPathSumDFSMen(grid0, men, (int)grid0.size() - 1, (int)grid0[0].size() - 1);
  const auto time2{std::chrono::steady_clock::now()};

  const std::chrono::duration<double> time_seconds0{time1 - time0};
  const std::chrono::duration<double> time_seconds1{time2 - time1};

  std::cout << ret0 << ", " << time_seconds0.count() << std::endl;
  std::cout << ret1 << ", " << time_seconds1.count() << std::endl;

  return 0;
}