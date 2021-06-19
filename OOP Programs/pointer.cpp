#include <iostream>
using namespace std;

class test {
   public:
    int a;
    void print() {
        cout << a << endl;
    }
};

int addition(int _a, int _b) {
    return _a + _b;
}

int main(int argc, char const *argv[]) {
    test t;
    int (*poi)(int, int) = addition;
    int test::*ptr = &test::a;
    t.*ptr = 10;
    t.print();
    void (test::*fp)() = &test::print;
    (t.*fp)();
    cout << poi(1, 2) << endl;
    return 0;
}

// const int *ptr - non constant pointer to constant integer
// int const *ptr - constant pointer to non constant integer
// const int const *ptr - constant pointer to constant integer
