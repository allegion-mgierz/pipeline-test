add_executable(test_calculator test_calculator.cpp)
target_link_libraries(test_calculator PRIVATE calculator)

add_test(NAME CalculatorTests COMMAND test_calculator)
