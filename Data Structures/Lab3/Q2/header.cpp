#include "header.h"
#include <stdio.h>
#include <string.h>
#include <cstdlib>
#include <iostream>

jaggedArray::jaggedArray() {
    check = 0;
    for (int i = 0; i < 9; i++) {
        jArray[i] = NULL;
    }
}

jaggedArray::jaggedArray(const jaggedArray &_copy) {
    for (int i = 0; i < 9; i++) {
        jArray[i] = NULL;
    }

    this->check = _copy.check;

    for (int i = 0; i < _copy.check; i++) {
        this->jArray[i] = new int[_copy.sizeArray[i]];
        this->sizeArray[i] = _copy.sizeArray[i];
        for (int j = 0; j < _copy.sizeArray[i]; j++) {
            this->jArray[i][j] = _copy.jArray[i][j];
        }
    }
}

jaggedArray &jaggedArray::operator=(const jaggedArray &_copy) {
    if (this != &_copy) {
        for (int i = 0; i < this->check; i++) {
            delete[] this->jArray[i];
        }

        this->check = _copy.check;

        for (int i = 0; i < _copy.check; i++) {
            this->jArray[i] = new int[_copy.sizeArray[i]];
            this->sizeArray[i] = _copy.sizeArray[i];
            for (int j = 0; j < _copy.sizeArray[i]; j++) {
                this->jArray[i][j] = _copy.jArray[i][j];
            }
        }
    } else {
        return *(this);
    }

    return *(this);
}

void jaggedArray::insertion() {
    unsigned int size;

    if (check < 9) {
        std::cout << "Enter size of array: ";
        std::cin >> size;
        if (size == 0 || size < 0) {
            std::cout << "ERROR ALLOCATING." << std::endl;
            return;
        } else {
            jArray[check] = new int[size];
            sizeArray[check] = size;
        }
    } else {
        std::cout << "Array is full." << std::endl;
        return;
    }

    for (int i = 0; i < size; i++) {
        std::cout << "Enter Element#" << i + 1 << ": ";
        std::cin >> jArray[check][i];
    }
    (check++);
}

void jaggedArray::insertion(int *_ptrarr, unsigned int size) {
    if (check < 9) {
        jArray[check] = new int[size];
        sizeArray[check] = size;

    } else {
        std::cout << "Array is full." << std::endl;
        return;
    }

    for (int i = 0; i < size; i++) {
        jArray[check][i] = _ptrarr[i];
    }
    (check++);
}

void jaggedArray::display() {
    for (int i = 0; i < 9; i++) {
        if (jArray[i] != NULL) {
            std::cout << "ROW#" << i + 1 << std::endl;
            std::cout << "Elements ";
            for (int j = 0; j < sizeArray[i]; j++) {
                std::cout << jArray[i][j] << " ";
            }
            std::cout << std::endl;
        } else {
            break;
        }
    }
}

jaggedArray::~jaggedArray() {
    for (int i = 0; i < 9; i++) {
        if (jArray[i] != NULL) {
            delete[] jArray[i];
        } else {
            break;
        }
    }
}
