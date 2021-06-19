#include <conio.h>
#include <iostream>
#include "header.h"
using namespace std;

int main(int argc, char const *argv[]) {
    car c1("Coupe", 70, 1234);
    car c2("Family", 80, 5678);
    car c3 = c1;
    car c4("Sport", 30, 999);
    c4 = c2;
    c3.display();
    c4.display();
    getch();
    return 0;
}