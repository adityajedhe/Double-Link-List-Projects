cmake_minimum_required(VERSION 3.16)

set(CMAKE_MAKE_PROGRAM "C:/msys64/mingw64/bin/mingw32-make.exe")
set(CMAKE_C_COMPILER "C:/msys64/ucrt64/bin/gcc.exe")
set(CMAKE_CXX_COMPILER "C:/msys64/ucrt64/bin/g++.exe")

project(BinaryTree VERSION 0.1.0 LANGUAGES C CXX)

# Specify the source files
file(GLOB_RECURSE SOURCES Sources/*.cpp)

# Include local headers
include_directories(LocalHeaders)

# Create an executable
add_executable(${PROJECT_NAME} ${SOURCES})

# Include other headers
target_include_directories(${PROJECT_NAME} INTERFACE ../SharedHeaders)

# Link any necessary libraries or dependencies here
target_link_libraries(${PROJECT_NAME} NodeLibrary)
