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

PYBIND11_MODULE(Card, m) {
    py::class_<Card> (m, "Card")
            .def(py::init<const std::string &>())
            .def("getName", &Card::getName)
            .def("setName", &Card::setName)
            .def("printFoo", &Card::printFoo);
}