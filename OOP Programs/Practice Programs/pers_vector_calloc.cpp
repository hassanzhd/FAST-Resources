#include <time.h>
#include <cstdlib>
#include <iostream>

using namespace std;

template <class T>
class arr {
    int pos;
    T *list;

   public:
    arr() : list(NULL), pos(0) {}
    int pos_return() {
        return (pos++);
    }
    void push_back(T x) {
        int n = pos_return();
        if (n == 0) {
            list = (T *)calloc(n + 1, sizeof(T));
            list[0] = x;
        } else {
            list = (T *)realloc(list, n + 1);
            list[n] = x;
        }
    }
    void display() {
        for (int i = 0; i < pos; i++) {
            cout << "Value is: " << list[i] << endl;
        }
    }

    ~arr() {
        free(list);
        list = NULL;
    }
};

int main(int argc, char const *argv[]) {
    arr<int> a;
    a.push_back(1);

    return 0;
}
