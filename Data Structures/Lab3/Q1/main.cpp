#include <iostream>
#include "header.h"
int main(int argc, char **argv) {
    DSA *ptr = new orderedDSA(5);
    DSA *ptr1 = ptr;
    ptr->insert();
    ptr->search();
    ptr1->search();

    return 0;
}
