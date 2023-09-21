cmake_minimum_required(VERSION 3.20)

project(Syslog VERSION 1.0)

set(CMAKE_PREFIX_PATH /usr/local)
find_library(ACE_LIBRARY NAMES libACE.so.7.1.1
            HINTS "${CMAKE_PREFIX_PATH}/lib")

add_library(syslog_compiler_flags INTERFACE)
target_compile_features(syslog_compiler_flags INTERFACE cxx_std_14)

add_executable(syslog syslog.cpp)

target_link_libraries(syslog PUBLIC 
                     "${ACE_LIBRARY}"
                     syslog_compiler_flags)

target_include_directories(syslog
                           PUBLIC
                          "${CMAKE_PREFIX_PATH}/include")

target_include_directories(syslog 
                          PUBLIC
                          "${PROJECT_BINARY_DIR}")

target_include_directories(syslog 
                           PUBLIC
                          "${PROJECT_SOURCE_DIR}/../include")   