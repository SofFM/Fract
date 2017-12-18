cmake_minimum_required(VERSION 3.8 FATAL_ERROR)

project(taskThree
    VERSION 0.0.0
    LANGUAGES CXX
)

set(SUBPROJECTS
    taskThree-window
    taskThree-test
    taskThree-fractal
)

macro(find_package)
    if(NOT "${ARGV0}" IN_LIST SUBPROJECTS)
        _find_package(${ARGV})
    endif()
endmacro()

foreach(subdir IN LISTS SUBPROJECTS)
    add_subdirectory(${subdir})
endforeach()
