#include <conio.h>
#include <iostream>
#include "header.h"
using namespace std;

int main(int argc, char const *argv[]) {
    gradingSystem gradeBook;
    gradeBook.print();
    getch();
    return 0;
}