#include <iostream>
#include "header.h"
using namespace std;

int main(int argc, char const *argv[]) {
    linkedList l;
    l.addToHead(1);
    l.addToTail(2);
    l.addTo(3, 1);
    l.addToTail(3);
    l.addToTail(3);
    l.addToTail(3);
    cout << "Count of 3: " << l.countElement(3) << '\n';
    l.display();
    return 0;
}
