#include <iostream>
using namespace std;

class emp {
    int id;

   public:
    emp() {}
    emp(int i) : id(i) {}
    void display() {
        cout << "Value of id is: " << id << endl;
    }
};

template <class T>
class arr {
    int pos;
    T *list;

    int pos_return() {
        return (pos++);
    }

   public:
    arr() : list(NULL), pos(0) {}

    void push_back(T x) {
        int n = pos_return();
        if (n == 0) {
            list = new T[n + 1];
            list[0] = x;
        } else {
            T *temp = new T[n + 1];
            for (int i = 0; i < n; i++) {
                temp[i] = list[i];
            }
            temp[n] = x;
            delete[] list;
            list = temp;
        }
    }

    void display() {
        if (list == NULL) {
            cout << "EMPTY\n";
        } else {
            for (int i = 0; i < pos; i++) {
                cout << "Value is: " << list[i] << endl;
            }
        }
    }

    ~arr() {
        delete[] list;
        list = NULL;
    }
};

template <>
class arr<emp> {
    int pos;
    emp *list;

    int pos_return() {
        return (pos++);
    }

   public:
    arr() : list(NULL), pos(0) {}

    void push_back(emp x) {
        int n = pos_return();
        if (n == 0) {
            list = new emp[n + 1];
            list[0] = x;
        } else {
            emp *temp = new emp[n + 1];
            for (int i = 0; i < n; i++) {
                temp[i] = list[i];
            }
            temp[n] = x;
            delete[] list;
            list = temp;
        }
    }

    void display() {
        if (list == NULL) {
            cout << "EMPTY\n";
        } else {
            for (int i = 0; i < pos; i++) {
                list[i].display();
            }
        }
    }

    ~arr() {
        delete[] list;
        list = NULL;
    }
};

int main(int argc, char const *argv[]) {
    arr<string> a;
    a.push_back("abc");

    return 0;
}
