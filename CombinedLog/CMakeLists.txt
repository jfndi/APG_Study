cmake_minimum_required(VERSION 3.20)

project(CombinedLog VERSION 1.0)

set(CMAKE_PREFIX_PATH /usr/local)
find_library(ACE_LIBRARY NAMES libACE.so.7.1.1
            HINTS "${CMAKE_PREFIX_PATH}/lib")

add_library(combinedlog_compiler_flags INTERFACE)
target_compile_features(combinedlog_compiler_flags INTERFACE cxx_std_14)

add_executable(combinedlog combinedlog.cpp)

target_link_libraries(combinedlog PUBLIC 
                     "${ACE_LIBRARY}"
                     combinedlog_compiler_flags)

target_include_directories(combinedlog
                           PUBLIC
                          "${CMAKE_PREFIX_PATH}/include")

target_include_directories(combinedlog 
                          PUBLIC
                          "${PROJECT_BINARY_DIR}")

target_include_directories(combinedlog 
                           PUBLIC
                          "${PROJECT_SOURCE_DIR}/../include")   