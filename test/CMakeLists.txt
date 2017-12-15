cmake_minimum_required(VERSION 3.6 FATAL_ERROR)

set(NAMESPACE taskThree)
set(COMPONENT test)
project(${NAMESPACE}-${COMPONENT})

add_executable(${PROJECT_NAME} test.cpp)
add_executable(${NAMESPACE}::${COMPONENT} ALIAS ${PROJECT_NAME})

find_package(taskThree-window)
target_link_libraries(${PROJECT_NAME} PRIVATE taskThree::window)
