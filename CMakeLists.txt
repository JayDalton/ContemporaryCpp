cmake_minimum_required(VERSION 3.24)

project(ContemporaryCpp VERSION 0.1) 

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(CMAKE_GENERATOR_PLATFORM "Win32")
set(CMAKE_TOOLCHAIN_FILE "C:/Packages/scripts/buildsystems/vcpkg.cmake")

set(SOURCE_FILES 
    common.h
    console.h
    main.cpp
)

# asio is a header-only, No need to use find_package()
set(PATH_ASIO "C:/Packages/installed/x86-windows/include")

add_executable(ContemporaryCpp ${SOURCE_FILES})

include_directories(${PATH_ASIO})
