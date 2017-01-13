cmake_minimum_required(VERSION 3.5)

project(CPP_BENCHMARKS)

set(BUILD_ITER1 "compiler le test iter1" ON)

if(BUILD_ITER1)
    add_subdirectory(iter1)
endif()
