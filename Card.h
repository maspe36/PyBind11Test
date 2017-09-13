//
// Created by Sam Privett on 9/11/2017.
//

#ifndef PYBIND11TEST_CARD_H
#define PYBIND11TEST_CARD_H

#include <string>
#include "Foo.h"

class Card {
public:
    Card(std::string name);
    std::string getName();
    void setName(std::string newName);
    void printFoo(Foo* foo);

    virtual void Effect();
private:
    std::string name;
};


#endif //PYBIND11TEST_CARD_H
