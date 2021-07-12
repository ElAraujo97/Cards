cmake_minimum_required(VERSION 3.17)
project(cards)

set(CMAKE_CXX_STANDARD 11)

add_executable(cards main.cpp
        dealer.cpp
        dealer.h
        )