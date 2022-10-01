cmake_minimum_required(VERSION 3.24)

project(ContemporaryCpp LANGUAGES CXX VERSION 0.1) 

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(SOURCE_FILES 
    common.h
    console.h
    main.cpp
)

add_executable(ContemporaryCpp ${SOURCE_FILES})

