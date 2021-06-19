#include <conio.h>
#include <iostream>
#include "header.h"
int main(int argc, char const *argv[]) {
    jaggedArray arr;
    int a[3] = {1, 2, 3};
    arr.insertion(a, sizeof(a) / sizeof(int));
    jaggedArray arr1;
    arr1 = arr;
    jaggedArray arr2 = arr1;
    arr2.insertion();
    arr.display();
    arr1.display();
    arr2.display();
    return 0;
}