cmake_minimum_required(VERSION 3.8 FATAL_ERROR)

set(NAMESPACE taskThree)
set(COMPONENT window)
project(${NAMESPACE}-${COMPONENT}
    VERSION 0.0.0
    LANGUAGES CXX
)

add_library(${PROJECT_NAME}
    include/${NAMESPACE}/window.hpp
    src/window.cpp
)

target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_17)
set_target_properties(${PROJECT_NAME} PROPERTIES CXX_EXTENSIONS OFF)

target_include_directories(${PROJECT_NAME} PUBLIC "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>")
