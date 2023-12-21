#include <vector>

int knapsackDFS(std::vector<int> &wgt, std::vector<int> &val, int i, int c) {
  if (i == 0) return c >= wgt[0] ? val[0] : 0;

  if (c < wgt[i]) return knapsackDFS(wgt, val, i - 1, c);

  auto no = knapsackDFS(wgt, val, i - 1, c);
  auto yes = knapsackDFS(wgt, val, i - 1, c - wgt[i]) + val[i];

  return std::max(no, yes);
}

int main() {
  std::vector<int> wgt = {10, 20, 30, 40, 50};
  std::vector<int> val = {50, 120, 150, 210, 240};

  auto ret0 = knapsackDFS(wgt, val, wgt.size() - 1, 50);
  return 0;
}
