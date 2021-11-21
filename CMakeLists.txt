cmake_minimum_required(VERSION 3.0)

set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wextra -Wall -std=c++17")

project(imx)

add_executable(
  imx
  src/main.cpp
  src/ArgsParser.cpp
  src/Base36.cpp
  src/Imx.cpp
  src/Downloader.cpp
)

target_link_libraries(imx curl)
set(EXECUTABLE_OUTPUT_PATH "bin")