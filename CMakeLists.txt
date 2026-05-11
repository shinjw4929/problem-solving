cmake_minimum_required(VERSION 3.20)
project(problem_solving)
set(CMAKE_CXX_STANDARD 17)

# Force executables into an ASCII output path so CLion / GDB on MinGW can
# load them even when the source file lives in a Korean-named folder.
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")

# One add_executable per problem. Target name must be ASCII.
add_executable(baedal "programmers/12978/12978.cpp")
