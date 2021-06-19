#ifndef ARRAY_HPP
#define ARRAY_HPP
#include <stdio.h>
#include <string.h>
#include <cstdlib>
#include <fstream>
#include <iostream>

template <typename T>
class DSA {
   public:
    T *data;
    int size;

    DSA(int __size) {
        this->size = __size;
        data = new T[__size];
    }

    DSA(const DSA<T> &__copy) {
        this->size = __copy.size;
        data = new T[this->size];

        for (int i = 0; i < __copy.size; i++) {
            this->data[i] = __copy.data[i];
        }
    }

    int getSize() {
        return this->size;
    }

    void ReSize(int __newSize) {
        if (size != __newSize) {
            T *temp = new T[size];

            for (int i = 0; i < size; i++) {
                temp[i] = *(data + i);
            }

            delete[] data;
            data = 0;

            data = new T[__newSize];
            for (int i = 0; i < size; i++) {
                *(data + i) = temp[i];
            }

            size = __newSize;
            delete[] temp;
            temp = 0;
        }
    }

    DSA<T> &operator=(const DSA<T> &_copy) {
        if (this != &_copy) {
            delete[] data;
            this->size = _copy.size;
            data = new T[this->size];

            for (int i = 0; i < _copy.size; i++) {
                this->data[i] = _copy.data[i];
            }

        } else {
            return (*this);
        }
        return *(this);
    }

    T operator[](unsigned int _val) {
        if (_val >= size) {
            std::cout << "Element not present" << std::endl;
            exit(0);
        } else {
            return *(data + _val);
        }
    }

    ~DSA() {
        delete[] data;
        data = NULL;
    }
};

#endif