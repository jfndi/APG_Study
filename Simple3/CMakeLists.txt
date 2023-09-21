cmake_minimum_required(VERSION 3.20)

project(Simple3 VERSION 1.0)

set(CMAKE_PREFIX_PATH /usr/local)
find_library(ACE_LIBRARY NAMES libACE.so.7.1.1
            HINTS "${CMAKE_PREFIX_PATH}/lib")

add_library(simple3_compiler_flags INTERFACE)
target_compile_features(simple3_compiler_flags INTERFACE cxx_std_14)

add_executable(simple3 simple3.cpp)

target_link_libraries(simple3 PUBLIC 
                     "${ACE_LIBRARY}"
                     simple3_compiler_flags)

target_include_directories(simple3
                           PUBLIC
                          "${CMAKE_PREFIX_PATH}/include")

target_include_directories(simple3 
                          PUBLIC
                          "${PROJECT_BINARY_DIR}")

target_include_directories(simple3 
                           PUBLIC
                          "${PROJECT_SOURCE_DIR}/../include")   