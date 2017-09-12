//
// Created by Sam Privett on 9/11/2017.
//

#include <pybind11/pybind11.h>
#include <iostream>
#include "Foo.h"

namespace py = pybind11;

Foo::Foo() {
}

void Foo::sayHi() {
    std::cout << "Hi from C++!" << std::endl;
}

PYBIND11_MODULE(Foo, m) {
    py::class_<Foo> (m, "Foo")
        .def(py::init<>())
        .def("sayHi", &Foo::sayHi);
}