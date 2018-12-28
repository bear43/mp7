cmake_minimum_required(VERSION 3.9)
project(untitled1)

set(CMAKE_CXX_STANDARD 14)

add_executable(untitled1 main.cpp Interface/Function.h Implementation/Function/MyFunction.cpp Implementation/Function/MyFunction.h Interface/FunctionResearcher.h Implementation/CoordDown/CoordDownResearcher.cpp Implementation/CoordDown/CoordDownResearcher.h Implementation/Point.h)