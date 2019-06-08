cmake_minimum_required(VERSION 3.11)
project(mimiclib_unit_test)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)


set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -DWIN_TEST -I../source -I../cpputest/include -Wall -Wextra -Wno-long-long -pedantic -L../cpputest/lib")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -DWIN_TEST -I../source -I../cpputest/include -Wall -Wextra -Wno-long-long -pedantic -L../cpputest/lib")

add_executable(utest
  ./utest/utest.cpp
  ./source/mimiclib.c
)

target_link_libraries(utest libCppUTest.a libCppUTestExt.a)
