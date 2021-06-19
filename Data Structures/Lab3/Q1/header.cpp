#include "header.h"
#include <stdio.h>
#include <string.h>
#include <cstdlib>
#include <fstream>
#include <iostream>

DSA::DSA(int _size) {
    this->size = _size;
    data = new int[_size];
    memset(this->data, 0, sizeof(int) * size);
}

DSA::DSA(const DSA &_copy) {
    this->size = _copy.size;
    data = new int[this->size];

    for (int i = 0; i < _copy.size; i++) {
        this->data[i] = _copy.data[i];
    }
}

int DSA::getSize() {
    return this->size;
}

DSA &DSA::operator=(const DSA &_copy) {
    if (this != &_copy) {
        delete[] data;
        this->size = _copy.size;
        data = new int[this->size];

        for (int i = 0; i < _copy.size; i++) {
            this->data[i] = _copy.data[i];
        }

    } else {
        return (*this);
    }
    return *(this);
}

int DSA::operator[](unsigned int _val) {
    if (_val >= size) {
        std::cout << "Element not present" << std::endl;
        exit(0);
    } else {
        return *(data + _val);
    }
}

void DSA::insert() {}
void DSA::search() {}

DSA::~DSA() {
    delete[] data;
    data = NULL;
}

orderedDSA::orderedDSA(int _a) : DSA(_a) {}
unorderedDSA::unorderedDSA(int _a) : DSA(_a) {}

void orderedDSA::insert() {
    int index, value;
    std::cout << "Enter index to insert: ";
    std::cin >> index;
    std::cout << "Enter value to insert: ";
    std::cin >> value;

    if (index >= size || index < 0) {
        std::cout << "Element not present" << std::endl;
        exit(0);
    } else {
        data[index] = value;
    }
}

void unorderedDSA::insert() {
    int index, value;
    std::cout << "Enter index to insert: ";
    std::cin >> index;
    std::cout << "Enter value to insert: ";
    std::cin >> value;

    if (index >= size || index < 0) {
        std::cout << "Element not present" << std::endl;
        exit(0);
    } else {
        data[index] = value;
    }
}

void orderedDSA::search() {
    int index, value;
    std::cout << "Enter index to seach: ";
    std::cin >> index;

    if (index >= size || index < 0) {
        std::cout << "Element not present" << std::endl;
        exit(0);
    } else {
        std::cout << "Element#" << index << " Value: " << data[index] << std::endl;
    }
}

void unorderedDSA::search() {
    int index, value;
    std::cout << "Enter index to seach: ";
    std::cin >> index;

    if (index >= size || index < 0) {
        std::cout << "Element not present" << std::endl;
        exit(0);
    } else {
        std::cout << "Element#" << index << " Value: " << data[index] << std::endl;
    }
}
