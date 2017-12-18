set(NAMESPACE taskThree)
set(COMPONENT fractal)
project(${NAMESPACE}-${COMPONENT}
    VERSION 0.0.0
    LANGUAGES CXX
)

add_executable(${PROJECT_NAME}
    src/main.cpp
)

target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_17)
set_target_properties(${PROJECT_NAME} PROPERTIES CXX_EXTENSIONS OFF)

find_package(taskThree-window 0.0.0 REQUIRED)
target_link_libraries(${PROJECT_NAME} taskThree-window)
