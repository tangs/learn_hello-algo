#include <vector>

int minPathSumDFS(std::vector<std::vector<int>> &grid, int i, int j) {
  if (i < 0 || j < 0) return std::numeric_limits<int>::max();
  if (i == 0 && j == 0) return grid[i][j];

  int up = minPathSumDFS(grid, i - 1, j);
  int left = minPathSumDFS(grid, i, j - 1);

  int ret = std::min(up, left) + grid[i][j];

  return ret;
}

int main() {
  std::vector<std::vector<int>> grid0 = {
          {1, 3, 1, 5},
          {2, 2, 4, 2},
          {5, 3, 2, 1},
          {4, 3, 5, 2},
  };
  auto ret0 = minPathSumDFS(grid0, grid0.size() - 1, grid0[0].size() - 1);
  return 0;
}