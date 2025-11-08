cmake_minimum_required(VERSION 3.15)
project(FlappyBird LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Sources
file(GLOB_RECURSE SOURCES "${CMAKE_SOURCE_DIR}/src/*.cpp")
add_executable(flappy ${SOURCES})

# Include directories so "#include \"header/Bird.h\"" resolves
target_include_directories(flappy PRIVATE
    ${CMAKE_SOURCE_DIR}
    ${CMAKE_SOURCE_DIR}/header
)

# Find SFML
set(SFML_MIN_VERSION "2.5")
find_package(SFML ${SFML_MIN_VERSION} COMPONENTS graphics window system REQUIRED)

# Link SFML
target_link_libraries(flappy PRIVATE sfml-graphics sfml-window sfml-system)

# Put binary in build/bin
set_target_properties(flappy PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Copy assets into the build output directory (post-build)
add_custom_command(
    TARGET flappy POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_SOURCE_DIR}/assets
        ${CMAKE_BINARY_DIR}/bin/assets
)
