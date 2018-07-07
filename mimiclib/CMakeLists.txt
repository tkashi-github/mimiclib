cmake_minimum_required(VERSION 2.8)
project(mimiclib_unit_test C)
include_directories(./include)
add_definitions("-Wall -std=c++11 -DWIN_TEST") # <= new
add_executable(mimic_test.exe
  ./source/main.c
  ./source/mimicstring.c
  ./source/mimicio.c
)