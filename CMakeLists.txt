cmake_minimum_required(VERSION 3.24)

project(ContemporaryCpp LANGUAGES CXX VERSION 0.1) 

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(CMAKE_TOOLCHAIN_FILE "C:/Packages/scripts/buildsystems/vcpkg.cmake")

set(OpenCV_DIR "C:/Packages/installed/x64-windows/share/opencv4")
find_package(OpenCV REQUIRED)

include_directories( ${OpenCV_INCLUDE_DIRS} )

set(SOURCE_FILES 
    common.h
    console.h
    main.cpp
)

add_executable(ContemporaryCpp ${SOURCE_FILES})

target_link_libraries(ContemporaryCpp ${OpenCV_LIBS} )
