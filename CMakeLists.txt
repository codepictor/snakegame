cmake_minimum_required(VERSION 3.2)

project(snakegame VERSION 0.1 DESCRIPTION "a simple snake game")

# Use C++11 standard for compiling
set(CMAKE_CXX_STANDARD 11)

# Find SFML library
find_package(SFML 2.5 COMPONENTS graphics window system REQUIRED)

# Bring all files with extension .cpp in src/ into the project
file(GLOB SOURCES "src/*.cpp")

# Add all sources to target
add_executable(snakegame ${SOURCES})

# Add paths to includes
target_include_directories(snakegame PUBLIC include)

# Linking
target_link_libraries(snakegame sfml-graphics sfml-window sfml-system)

