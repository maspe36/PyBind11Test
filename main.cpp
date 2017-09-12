#include <pybind11/embed.h>
#include <iostream>
#include "Card.h"

namespace py = pybind11;

int main() {
    // start the interpreter and keep it alive
    py::scoped_interpreter guard{};

    Foo* foo = new Foo();

    // use the Python API
    py::module fam = py::module::import("Foo");
    py::module example = py::module::import("Card");
    py::object obj = example.attr("Card")("Python");
    obj.attr("printFoo")(foo);

    std::cout << "Got object from python" << std::endl;

    auto *cls = obj.cast<Card *>();
    cls->printFoo(foo);
    std::cout << "Converted from python!!!!! " << cls->getName() << std::endl;
}
