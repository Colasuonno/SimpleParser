cmake_minimum_required(VERSION 3.17)
project(parse)

set(CMAKE_CXX_STANDARD 14)

add_executable(parse main.cpp parser/parser.cpp parser/parser.h parser/node.cpp parser/node.h parser/FinalNode.cpp parser/FinalNode.h)