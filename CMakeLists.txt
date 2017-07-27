cmake_minimum_required(VERSION 3.8)

set(CMAKE_C_STANDARD 99)

set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -Wall")
set(CMAKE_C_FLAGS_RELEASE "${CMAKE_C_FLAGS_RELEASE} -s")

add_executable(print_anagram print_anagram.c)
add_executable(print_difftble print_difftble.c)
add_executable(print_euler print_euler.c)
add_executable(print_fib print_fib.c)
add_executable(print_linterpol print_linterpol.c)
add_executable(print_ninterpol print_ninterpol.c)
add_executable(print_root_bisection print_root_bisection.c)
add_executable(print_root_nr print_root_nr.c)
add_executable(print_simpson print_simpson.c)
add_executable(print_trapezoidal print_trapezoidal.c)