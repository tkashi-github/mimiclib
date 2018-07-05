cmake_minimum_required(VERSION 2.8)
add_definitions("-Wall -std=c++11") # <= new
add_executable(Main
  ../source/main.c
  ../source/mimicstring.c
  ../source/mimicio.c
)