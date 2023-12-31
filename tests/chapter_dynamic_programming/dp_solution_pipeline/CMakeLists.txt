cmake_minimum_required(VERSION 3.10)
project(dp_solution_pipeline)

set(CMAKE_CXX_STANDARD 17)

include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

set(SRC_PATH ${ROOT_PATH}/src/chapter_dynamic_programming/dp_solution_pipeline)
set(TESTS_PATH ${ROOT_PATH}/tests/chapter_dynamic_programming/dp_solution_pipeline)

include_directories(
        ${SRC_PATH}
        ${TESTS_PATH}
)

# test.
enable_testing()

add_executable(
        min_path_sum_test
        ${SRC_PATH}/min_path_sum.cc
        ${TESTS_PATH}/min_path_sum_test.cc
)
target_link_libraries(min_path_sum_test GTest::gtest_main)

add_executable(
        knapsack_problem_test
        ${SRC_PATH}/knapsack_problem.cc
        ${TESTS_PATH}/knapsack_problem_test.cc
)
target_link_libraries(knapsack_problem_test GTest::gtest_main)

include(GoogleTest)
gtest_discover_tests(min_path_sum_test)
gtest_discover_tests(knapsack_problem_test)
