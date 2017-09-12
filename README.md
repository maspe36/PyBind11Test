# PyBind11Test
Test the bindings between C++ and Python using PyBind11. Wrap multiple C++ classes, create python classes from inherited wrapped C++ classes, overload virtual methods of C++ classes from Python, convert the Python instance back to the base C++ instance, call the method overloaded from Python in C++.

## Toolchain
- GNU 7.1.0
- Cmake 3.9.2
- Python 3.6.2
- C++ 17
- PyBind11 2.2.0

## Building
#### Building with CMake
- Open a command prompt and cd to this projects root directory
- mkdir build
- cd build
- cmake .. -G"MinGW Makefiles"
- cmake --build .
## Authors
- [Maspe36](https://github.com/maspe36)