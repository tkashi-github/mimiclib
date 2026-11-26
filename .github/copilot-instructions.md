# Project instructions

## Project and code

- `source/mimiclib.c` and `source/mimiclib.h` implement a small-footprint C11 library for embedded/RTOS use. Aim for MISRA-C compliance where practical.
- Keep production code independent of `<stdio.h>`, `<stdlib.h>`, and `<string.h>`; their existing uses under `UNIT_TEST` are test-only.
- Preserve the `MIMICLIB_*` porting hooks and C/C++ compatibility of the public header. See `README.md` for the required hooks and project goals.
- Use UTF-8 and tabs for indentation (one tab is four spaces), as specified in `README.md`. Follow the surrounding code's naming and formatting.
- Update public declarations and their Doxygen comments when changing the API. Add or update CppUTest cases in `utest/utest.cpp` for behavior changes, including relevant boundary cases.

## Build and verification

- `CMakeLists.txt` builds the `utest` executable from the library and CppUTest tests with `UNIT_TEST` defined. Run the resulting executable to execute the tests; CTest tests are not registered.
- The CMake configuration uses relative paths to `source` and `cpputest` and expects a build directory directly under the repository root. The bundled CppUTest archives must be compatible with the selected compiler and platform.
- For MISRA static analysis, see `MISRA-C_Check/README.md`. Avoid modifying bundled CppUTest or generated build and Doxygen output unless the task specifically requires it.
