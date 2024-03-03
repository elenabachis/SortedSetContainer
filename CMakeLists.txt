cmake_minimum_required(VERSION 3.24)
project(Lab2dsa)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Lab2dsa
        App.cpp
        ExtendedTest.cpp
        ExtendedTest.h
        ShortTest.cpp
        ShortTest.h
        SortedSet.cpp
        SortedSet.h
        SortedSetIterator.cpp
        SortedSetIterator.h)
