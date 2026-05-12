cmake_minimum_required(VERSION 3.20)
project(problem_solving)
set(CMAKE_CXX_STANDARD 17)

# Force executables into an ASCII output path so CLion / GDB on MinGW can
# load them even when the source file lives in a Korean-named folder.
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")

# Auto-discover every problem .cpp under programmers/<folder>/<file>.cpp.
# Target name is "p<folder>", so programmers/12978/12978.cpp -> target p12978.
# CONFIGURE_DEPENDS makes Ninja re-glob on build when files are added/removed.
file(GLOB_RECURSE PROBLEM_SOURCES CONFIGURE_DEPENDS
        "${CMAKE_SOURCE_DIR}/programmers/*.cpp")

foreach(src ${PROBLEM_SOURCES})
    get_filename_component(dir ${src} DIRECTORY)
    get_filename_component(folder ${dir} NAME)
    add_executable("p${folder}" ${src})
endforeach()
