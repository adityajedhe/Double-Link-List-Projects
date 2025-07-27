cmake_minimum_required(VERSION 3.10)  # Specify the minimum CMake version

# Set the C and C++ compilers
set(CMAKE_C_COMPILER "C:/msys64/ucrt64/bin/gcc.exe")
set(CMAKE_CXX_COMPILER "C:/msys64/ucrt64/bin/g++.exe")

project(NodeLibrary)                     # Replace with your library name

# Set the C++ standard
set(CMAKE_CXX_STANDARD 11)            # You can change this to 14, 17, etc. as needed
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Specify the include directories
include_directories(${CMAKE_SOURCE_DIR}/../SharedHeaders)

# Add the source files
file(GLOB SOURCES "${CMAKE_SOURCE_DIR}/Sources/*.cpp")

# Create the library
add_library(NodeLibrary SHARED ${SOURCES})  # Replace NodeLibrary with your desired library name

# Optionally, you can specify the output directory for the library
#set_target_properties(NodeLibrary PROPERTIES
#    ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib
#    LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib
#    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
#)


## Set the minimum version of CMake required
#cmake_minimum_required(VERSION 3.10)
#
## Set the C and C++ compilers
#set(CMAKE_C_COMPILER "C:/msys64/ucrt64/bin/gcc.exe")
#set(CMAKE_CXX_COMPILER "C:/msys64/ucrt64/bin/g++.exe")
#
## Specify the C++ standard
#set(CMAKE_CXX_STANDARD 11)
#set(CMAKE_CXX_STANDARD_REQUIRED True)
#
## Set the project name
#project(NodeLibrary)
#
## Include the SharedHeaders directory for header files
#include_directories(${CMAKE_SOURCE_DIR}/../SharedHeaders)
#
## Add the source files from the Sources directory
#file(GLOB SOURCES "${CMAKE_SOURCE_DIR}/Sources/*.cpp")
#
## Create an executable or library (uncomment one of the following lines based on your needs)
## add_executable(MyExecutable ${SOURCES})
#add_library(NodeLibrary ${SOURCES})
#
## Optionally, you can specify the output directory for the executable or library
## set_target_properties(MyExecutable PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
## set_target_properties(NodeLibrary PROPERTIES ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
#