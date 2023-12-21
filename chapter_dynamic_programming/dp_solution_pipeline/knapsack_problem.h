#pragma once

#include <vector>

int knapsackDFS(std::vector<int> &wgt, std::vector<int> &val, int i, int c);
int knapsackDFSMen(std::vector<int> &wgt, std::vector<int> &val, std::vector<std::vector<int>> &men, int i, int c);
int knapsackDP(std::vector<int> &wgt, std::vector<int> &val, int cap);
int knapsackDPComp(std::vector<int> &wgt, std::vector<int> &val, int cap);