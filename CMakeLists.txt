cmake_minimum_required(VERSION 3.24)

project(ContemporaryCpp VERSION 0.1) 

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# set(CMAKE_GENERATOR_PLATFORM "Win32")
# set(CMAKE_TOOLCHAIN_FILE "C:/Packages/scripts/buildsystems/vcpkg.cmake")

add_executable(ContemporaryCpp ${SOURCE_FILES})
# add_executable(${PROJECT_NAME}) # WIN32

# asio is a header-only, No need to use find_package()
# set(PATH_ASIO "C:/Packages/installed/x86-windows/include")
include_directories(${PATH_INCLUDE})
include_directories(${PATH_LIBS})

message(STATUS ${PATH_INCLUDE})
message(STATUS ${PATH_LIBS})
message(STATUS ${PATH_FFMPEG_INC})
message(STATUS ${PATH_FFMPEG_LIB})

# find_path(AVCODEC_INCLUDE_DIR libavcodec/avcodec.h  PATHS ${PATH_INCLUDE})
# find_library(AVCODEC_LIBRARY avcodec PATHS ${PATH_FFMPEG_LIB})
# message(STATUS ${AVCODEC_INCLUDE_DIR})
# message(STATUS ${PATH_INCLUDE}/libavcodec)
# message(STATUS ${AVCODEC_LIBRARY})

# find_path(AVFORMAT_INCLUDE_DIR libavformat/avformat.h PATHS ${PATH_INCLUDE})
# find_library(AVFORMAT_LIBRARY avformat PATHS ${PATH_FFMPEG_LIB})
# message(STATUS ${AVFORMAT_INCLUDE_DIR})
# message(STATUS ${PATH_INCLUDE}/libavformat)
# message(STATUS ${AVFORMAT_LIBRARY})

# Set SDL2Config.cmake Search Directory 
set(SDL2_DIR "C:/Packages/installed/x86-windows/share/sdl2")
# set(SDL2_DIR ${PATH_SDL2}) # ???

find_package(SDL2 CONFIG REQUIRED)

# Additional Include Directories
message(STATUS ${SDL_INCLUDE_DIRS})
include_directories( 
  ${SDL_INCLUDE_DIRS} 
  # ${PATH_INCLUDE}/libavformat
  # ${PATH_INCLUDE}/libavcodec
  # ${AVCODEC_INCLUDE_DIR} 
  # ${AVFORMAT_INCLUDE_DIR} 
  # "C:/Packages/packages/ffmpeg_x86-windows/include/libavcodec"
  # "C:/Packages/packages/ffmpeg_x86-windows/include/libavformat"
  # C:\Packages\installed\x86-windows\include\libavcodec
)

# Additional Library Directories
message(STATUS ${SDL_LIBRARIES})
link_directories( 
  ${SDL_LIBRARIES} 
  "C:/Packages/installed/x86-windows/lib"
  "C:/Packages/packages/ffmpeg_x86-windows/lib"
)
# c:/Packages/packages/ffmpeg_x86-windows/include

# Additional Dependencies
target_link_libraries(${PROJECT_NAME} 
   SDL2::SDL2 SDL2::SDL2main 
  #  ${AVCODEC_LIBRARY} ${AVFORMAT_LIBRARY}
   "C:/Packages/installed/x86-windows/lib/avcodec.lib"
   "C:/Packages/installed/x86-windows/lib/avformat.lib"
)

target_sources(${PROJECT_NAME} PRIVATE
  "common.h"
  "console.h"
  "main.cpp"
)
