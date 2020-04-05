cmake_minimum_required(VERSION 3.10)

# set the project name
project(awesome-cipher)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)


# add source to build
add_subdirectory(src)

