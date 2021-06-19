#include "header.h"
#include <cstring>
#include <iostream>

car::car() {
    const char* _category = "NO NAME";
    this->category = new char[strlen(_category) + 1];
    strcpy(this->category, _category);
    this->tankSize = new int(0);
    this->registrationNo = new int(0);
}

car::car(const char* _category, int _tankSize, int _registrationNo) {
    this->category = new char[strlen(_category) + 1];
    strcpy(this->category, _category);
    this->tankSize = new int(_tankSize);
    this->registrationNo = new int(_registrationNo);
}

car::car(car& _copycar) {
    this->category = new char[strlen(_copycar.category) + 1];
    strcpy(this->category, _copycar.category);
    this->tankSize = new int(*(_copycar.tankSize));
    this->registrationNo = new int(*(_copycar.registrationNo));
}

car& car::operator=(const car& _copycar) {
    if ((this) != (&_copycar)) {
        if ((this->category) != 0) {
            delete[] this->category;
            this->category = new char[strlen(_copycar.category) + 1];
            strcpy(this->category, _copycar.category);
        } else {
            this->category = new char[strlen(_copycar.category)];
            strcpy(this->category, _copycar.category);
        }
        *(this->tankSize) = *(_copycar.tankSize);
    } else {
        return (*this);
    }
    return (*this);
}

void car::display() {
    std::cout << "Registration number: " << *(this->registrationNo) << std::endl;
    std::cout << "Category: " << this->category << std::endl;
    std::cout << "Tank size: " << *(this->tankSize) << std::endl;
    std::cout << std::endl;
}

car::~car() {
    delete[] category;
    delete tankSize;
    delete registrationNo;
}