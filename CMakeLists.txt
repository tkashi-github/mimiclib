cmake_minimum_required(VERSION 3.11)
project(mimiclib_unit_test)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -DWIN_TEST-I../cpputest/include -Wall -Wextra -Wno-long-long -pedantic -L../cpputest/lib -lCppUTest -lCppUTestExt")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -DWIN_TEST -I../cpputest/include -Wall -Wextra -Wno-long-long -pedantic -L../cpputest/lib -lCppUTest -lCppUTestExt")

add_executable(utest.exe
  ./source/utest.c
  ./source/mimiclib.c
)


