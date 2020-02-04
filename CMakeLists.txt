cmake_minimum_required(VERSION 3.10)
project(PA00)

set(CMAKE_CXX_STANDARD 14)
set (input01 "data01.txt")
set (input02 "output00.txt")

#
##########################################

# Copy data files to build dir

add_executable(PA00 main.cpp)