cmake_minimum_required(VERSION 3.20)

project(Simple2 VERSION 1.0)

set(CMAKE_PREFIX_PATH /usr/local)
find_library(ACE_LIBRARY NAMES libACE.so.7.1.1
            HINTS "${CMAKE_PREFIX_PATH}/lib")

add_library(simple2_compiler_flags INTERFACE)
target_compile_features(simple2_compiler_flags INTERFACE cxx_std_14)

add_executable(simple2 simple2.cpp)

target_link_libraries(simple2 PUBLIC 
                     "${ACE_LIBRARY}"
                     simple2_compiler_flags)

target_include_directories(simple2
                           PUBLIC
                          "${CMAKE_PREFIX_PATH}/include/ace")

target_include_directories(simple2 PUBLIC
                          "${PROJECT_BINARY_DIR}")