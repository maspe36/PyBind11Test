cmake_minimum_required(VERSION 3.8)
project(PyBind11Test)

set(CMAKE_CXX_STANDARD 17)

# Add pybind11
set(PYBIND11_CPP_STANDARD -std=c++1z)

add_subdirectory(pybind11)
pybind11_add_module(Card Card.cpp Foo.cpp)
pybind11_add_module(Foo Foo.cpp)

# Add the hypot flag
set(GCC_HYPOT_FLAGS "-D_hypot=hypot")
add_definitions( ${GCC_HYPOT_FLAGS} )

# Add the ms win flag
set(GCC_MS64_FLAGS "-D MS_WIN64")
add_definitions( ${GCC_HYPOT_FLAGS} )

set(SOURCE_FILES main.cpp Card.cpp Card.h Foo.cpp Foo.h)
add_executable(PyBind11Test ${SOURCE_FILES})
target_link_libraries(PyBind11Test PRIVATE pybind11::embed)