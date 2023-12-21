cmake_minimum_required(VERSION 3.10)
project(learn_hello-algo)

set(CMAKE_CXX_STANDARD 17)

add_executable(min_path_sum chapter_dynamic_programming/dp_solution_pipeline/min_path_sum.cc)
add_executable(knapsack_problem chapter_dynamic_programming/dp_solution_pipeline/knapsack_problem.cc)
