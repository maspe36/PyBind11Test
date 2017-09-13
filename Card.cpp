//
// Created by Sam Privett on 9/11/2017.
//
#include <pybind11/pybind11.h>
#include <iostream>
#include "Card.h"

namespace py = pybind11;

Card::Card(std::string name) : name(name){
}

std::string Card::getName() {
    return this->name;
}

void Card::setName(std::string newName) {
    this->name = newName;
}

void Card::printFoo(Foo* foo) {
    foo->sayHi();
}

void Card::Effect() {
    std::cout << "C++ Effect!" << std::endl;
}

class PyCard : public Card {
public:
    /* Inherit the constructors */
    using Card::Card;

    /* Trampoline (need one for each virtual function) */
    void Effect() override {
        PYBIND11_OVERLOAD_PURE(
                void,        /* Return type */
                Card,        /* Parent class */
                Effect       /* Name of function in C++ (must match Python name) */
        );
    }
};

PYBIND11_MODULE(Card, m) {
    py::class_<Card, PyCard> (m, "Card")
            .def(py::init<const std::string &>())
            .def("getName", &Card::getName)
            .def("setName", &Card::setName)
            .def("printFoo", &Card::printFoo)
            .def("Effect", &Card::Effect);
}