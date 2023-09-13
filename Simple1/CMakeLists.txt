cmake_minimum_required(VERSION 3.20)

project(Simple1 VERSION 1.0)

set(CMAKE_PREFIX_PATH /usr/local)
find_library(ACE_LIBRARY NAMES libACE.so.7.1.1
            HINTS "${CMAKE_PREFIX_PATH}/lib")

add_library(simple1_compiler_flags INTERFACE)
target_compile_features(simple1_compiler_flags INTERFACE cxx_std_11)

add_executable(simple1 simple1.cpp)

target_link_libraries(simple1 PUBLIC 
                     "${ACE_LIBRARY}"
                     simple1_compiler_flags)

target_include_directories(simple1
                           PUBLIC
                          "${CMAKE_PREFIX_PATH}/include/ace")

target_include_directories(simple1 PUBLIC
                          "${PROJECT_BINARY_DIR}")