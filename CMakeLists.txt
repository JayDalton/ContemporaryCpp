cmake_minimum_required(VERSION 3.24)

project(ContemporaryCpp VERSION 0.1) 

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

find_package(asio CONFIG REQUIRED)
# find_package(FFMPEG CONFIG REQUIRED)
find_package(SDL2 CONFIG REQUIRED)

add_executable(${PROJECT_NAME} ${SOURCE_FILES})
target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_17)

target_link_libraries(${PROJECT_NAME}
  PRIVATE
    asio::asio
    # FFMPEG::avcodec
    # FFMPEG::avformat
    SDL2::SDL2 SDL2::SDL2main 
)

target_sources(${PROJECT_NAME} PRIVATE
  "common.h"
  "console.h"
  "main.cpp"
)
