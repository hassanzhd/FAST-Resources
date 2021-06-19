#include <iostream>
#include "header.h"
using namespace std;

int main(int argc, char const *argv[]) {
    linkedList numberList, averageList;

    for (int i = 0, value = 0; i < 12; i++) {
        cout << "Enter value# " << i + 1 << ": ";
        cin >> value;
        numberList.addToTail(value);
    }

    calculateAverage(numberList, averageList);
    numberList.display();
    averageList.display();
    return 0;
}
