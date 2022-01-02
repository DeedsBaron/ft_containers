cmake_minimum_required(VERSION 3.20)
project(containers)

set(CMAKE_CXX_STANDARD 98)

add_executable(containers main.cpp srcs/utils/BidirectionalIter.hpp srcs/utils/RBTree.hpp)
