cmake_minimum_required(VERSION 3.16)

set(CMAKE_MAKE_PROGRAM "C:/msys64/mingw64/bin/mingw32-make.exe")
set(CMAKE_C_COMPILER "C:/msys64/ucrt64/bin/gcc.exe")
set(CMAKE_CXX_COMPILER "C:/msys64/ucrt64/bin/g++.exe")

project(MyProjects VERSION 0.1.0 LANGUAGES C CXX)

# Add the shared headers directory
include_directories(SharedHeaders)

# Add subdirectories for the common library and each project
add_subdirectory(common)
add_subdirectory(Binary_Tree_Operations)
add_subdirectory(Tower_Of_Hanoi)

set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 17)
