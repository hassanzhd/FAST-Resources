#include <iostream>
using namespace std;

class A {
    int x;

   public:
    A(int j = 0) {
        x = j;
    }

    void display() {
        cout << x << endl;
    }
    friend void operator+(int, A &);
};

void operator+(int h, A &o) {
    o.x = h + o.x;
}

int main(int argc, char const *argv[]) {
    A a(20);
    10 + a;
    a.display();

    return 0;
}
