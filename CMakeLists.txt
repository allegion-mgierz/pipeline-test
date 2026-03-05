cmake_minimum_required(VERSION 3.15)
project(calculator VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Library target (reusable logic)
add_library(calculator_lib STATIC
    src/calculator.cpp
)
target_include_directories(calculator_lib PUBLIC src)

# Executable target
add_executable(calculator
    src/main.cpp
)
target_link_libraries(calculator PRIVATE calculator_lib)

# Installation rules
install(TARGETS calculator DESTINATION bin)
