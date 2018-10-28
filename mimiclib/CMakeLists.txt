cmake_minimum_required(VERSION 3.11)
project(mimiclib_unit_test C)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -I./include -Wall -std=c11 -DWIN_TEST")
add_executable(mimic_test.exe
  ./source/main.c
  ./source/mimiclib.c
)