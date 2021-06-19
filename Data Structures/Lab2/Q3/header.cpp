#include "header.h"
#include <iostream>

gradingSystem::gradingSystem() {
    setDetails();
}

void gradingSystem::setDetails() {
    std::cout << "Enter number of sections you teach: ";
    std::cin >> sections;

    details = new int*[sections];

    for (int i = 0; i < sections; i++) {
        details[i] = new int[5];
    }

    for (int i = 0; i < sections; i++) {
        for (int j = 0; j < 5; j++) {
            std::cout << "Enter no of " << id[j] << " grades of section " << char(65 + i) << ": ";
            std::cin >> details[i][j];
        }
        std::cout << std::endl;
    }
}

void gradingSystem::print() {
    int choice;

    do {
        std::cout << "Enter valid section id to view grades: ";
        std::cin >> choice;
    } while (choice < 0 || choice >= sections);

    std::cout << std::endl;
    std::cout << "Section " << id[choice] << std::endl;

    for (int i = 0; i < 5; i++) {
        std::cout << "Number of " << id[i] << " grades: " << details[choice][i] << std::endl;
    }
}

gradingSystem::~gradingSystem() {
    for (int i = 0; i < sections; i++) {
        delete[] details[i];
    }
    delete[] details;
}
