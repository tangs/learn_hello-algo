cmake_minimum_required(VERSION 3.10)
project(learn_hello-algo)

set(CMAKE_CXX_STANDARD 17)

include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

#add_executable(min_path_sum  chapter_dynamic_programming/dp_solution_pipeline/min_path_sum.cc)
#add_executable(knapsack_problem chapter_dynamic_programming/dp_solution_pipeline/knapsack_problem.cc)
enable_testing()

# test.
add_executable(
        knapsack_problem_test
        chapter_dynamic_programming/dp_solution_pipeline/knapsack_problem.cc
        chapter_dynamic_programming/dp_solution_pipeline/knapsack_problem_test.cc
)
target_link_libraries(knapsack_problem_test GTest::gtest_main)
add_test(
        NAME knapsack_problem_test
        COMMAND knapsack_problem_test
)

include(GoogleTest)
gtest_discover_tests(knapsack_problem_test)