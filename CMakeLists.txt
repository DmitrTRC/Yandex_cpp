cmake_minimum_required(VERSION 3.17)
project(Yandex_cpp)

set(CMAKE_CXX_STANDARD 14)

add_executable(Yandex_cpp
        words_brackets.cpp split_vector.cpp)

add_executable(split_vector split_vector.cpp)