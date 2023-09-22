cmake_minimum_required(VERSION 3.20)

project(APG-Study VERSION 1.0)

set(DIRLIST ./Simple1;./Simple2;./Simple3;./Simple4;./Syslog;./CombinedLog;./LogCallback)

foreach(Dir ${DIRLIST})
    message("Entering ${Dir}")
    add_subdirectory(${Dir})
    message("Leaving ${Dir}")
endforeach()