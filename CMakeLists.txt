cmake_minimum_required(VERSION 3.10)
project(flappy)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add include directory
include_directories(${CMAKE_SOURCE_DIR})

# Source files
set(SOURCES src/main.cpp src/Bird.cpp src/Game.cpp src/Pipe.cpp)

# Create the executable
add_executable(flappy ${SOURCES})

# Find SFML library
find_package(SFML 2.5 COMPONENTS graphics window system REQUIRED)
target_link_libraries(flappy PRIVATE sfml-graphics sfml-window sfml-system)

# Copy assets to build directory
if(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/assets")
    add_custom_target(copy_assets ALL
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        "${CMAKE_CURRENT_SOURCE_DIR}/assets"
        "${CMAKE_CURRENT_BINARY_DIR}/assets"
    )
    add_dependencies(flappy copy_assets)
endif()
