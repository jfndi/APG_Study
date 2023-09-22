cmake_minimum_required(VERSION 3.20)

project(LogCallback VERSION 1.0)

set(CMAKE_PREFIX_PATH /usr/local)
find_library(ACE_LIBRARY NAMES libACE.so.7.1.1
            HINTS "${CMAKE_PREFIX_PATH}/lib")

add_library(logcallback_compiler_flags INTERFACE)
target_compile_features(logcallback_compiler_flags INTERFACE cxx_std_14)

add_executable(logcallback logcallback.cpp)

target_link_libraries(logcallback PUBLIC 
                     "${ACE_LIBRARY}"
                     logcallback_compiler_flags)

target_include_directories(logcallback
                           PUBLIC
                          "${CMAKE_PREFIX_PATH}/include")

target_include_directories(logcallback 
                          PUBLIC
                          "${PROJECT_BINARY_DIR}")

target_include_directories(logcallback 
                           PUBLIC
                          "${PROJECT_SOURCE_DIR}/../include")   