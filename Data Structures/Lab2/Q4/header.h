#ifndef HEADER_H
#define HEADER_H
#include <iostream>
class car {
    char *category;
    int *tankSize, *registrationNo;

   public:
    car();
    car(const char *, int, int);
    car(car &);
    car &operator=(const car &);
    void display();
    ~car();
};

#endif