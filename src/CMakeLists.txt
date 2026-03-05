add_library(calculator calculator.cpp)
target_include_directories(calculator PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

add_executable(calculator_app main.cpp)
target_link_libraries(calculator_app PRIVATE calculator)
