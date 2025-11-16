cmake_minimum_required(VERSION 4.0)
project(MyProject)
set(CMAKE_CXX_STANDARD 17)

# Collect all .cpp files in the project directory
file(GLOB SOURCES "*.cpp")

# Create an executable for each .cpp file
foreach(source ${SOURCES})
    get_filename_component(target ${source} NAME_WE)
    add_executable(${target} ${source})
endforeach()