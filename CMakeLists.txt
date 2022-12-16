cmake_minimum_required(VERSION 3.24)

project(ContemporaryCpp VERSION 0.1) 

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED True)

find_package(asio CONFIG REQUIRED)
find_package(SDL2 CONFIG REQUIRED)

find_package(PkgConfig REQUIRED)
pkg_check_modules(LIBAV REQUIRED IMPORTED_TARGET
    # libavdevice
    # libavfilter
    libavformat
    libavcodec
    # libswresample
    # libswscale
    # libavutil
)

add_executable(${PROJECT_NAME} ${SOURCE_FILES})
target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_23)

target_link_libraries(${PROJECT_NAME}
  PRIVATE
    asio::asio
    PkgConfig::LIBAV
    SDL2::SDL2 SDL2::SDL2main 
)

target_sources(${PROJECT_NAME} PRIVATE
  "c_ressource.h"
  "common.h"
  "console.h"
  "gui.h"
  "main.cpp"
  "video.h"
  "videodecoder.h"
  "videoframe.h"
)
