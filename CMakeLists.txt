cmake_minimum_required(VERSION 3.20)
project(containers)

set(CMAKE_CXX_STANDARD 98)

add_executable(containers main.cpp srcs/utils/RBTree.hpp srcs/utils/TreeIter.hpp srcs/utils/Node.hpp srcs/utils/ReverseIterator.hpp srcs/containers/Set.hpp srcs/utils/RBTree4set.hpp)
