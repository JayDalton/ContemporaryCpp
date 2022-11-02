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
include_directories(${PATH_ASIO})

# Set SDL2Config.cmake Search Directory 
set(SDL2_DIR "C:/Packages/installed/x86-windows/share/sdl2")
# set(SDL2_DIR ${PATH_SDL2}) # ???

find_package(SDL2 CONFIG REQUIRED)

# Additional Include Directories
include_directories( ${SDL_INCLUDE_DIRS} )

# Additional Library Directories
link_directories( ${SDL_LIBRARIES} )

# Additional Dependencies
target_link_libraries(${PROJECT_NAME} 
   SDL2::SDL2 SDL2::SDL2main 
)

target_sources(${PROJECT_NAME} PRIVATE
  "common.h"
  "console.h"
  "main.cpp"
)
