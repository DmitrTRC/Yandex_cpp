cmake_minimum_required(VERSION 3.17)

project(Yandex_cpp)

set(CMAKE_CXX_STANDARD 20)

add_executable(split_vector srs/vectors/split_vector.cpp)
add_executable(words_brackets srs/vectors/words_brackets.cpp)
add_executable(resizing srs/vectors/resizing.cpp)