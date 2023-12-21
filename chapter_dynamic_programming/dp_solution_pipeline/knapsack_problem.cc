#include <vector>

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

int main() {
  std::vector<int> wgt = {10, 20, 30, 40, 50};
  std::vector<int> val = {50, 120, 150, 210, 240};
  const auto knapsackCapacity = 50;

  std::vector<std::vector<int>> men(wgt.size(), std::vector<int>(knapsackCapacity + 1, -1));

  auto ret0 = knapsackDFS(wgt, val, wgt.size() - 1, knapsackCapacity);
  auto ret1 = knapsackDFSMen(wgt, val, men, wgt.size() - 1, knapsackCapacity);

  return 0;
}
