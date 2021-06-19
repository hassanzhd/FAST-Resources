#include <iostream>
#include <list>
#include <map>
using namespace std;

class A {
   public:
    string j;
    int a;
    A() {}
    A(string f, int x) : a(x), j(f) {}
    void dis() {
        cout << j << "\t" << a << endl;
    }
};

int main(int argc, char const *argv[]) {
    A q[5] = {{"casillas", 1}, {"ramos", 4}, {"ramos", 3}, {"ronaldo", 7}, {"kaka", 10}};

    multimap<string, int> map;

    for (int i = 0; i < 5; i++) {
        map.insert(pair<string, int>(q[i].j, q[i].a));
    }

    string nam;
    cout << "Enter name to search: ";
    cin >> nam;

    multimap<string, int>::iterator i;
    for (i = map.begin(); i != map.end(); i++) {
        if (nam == (i->first)) {
            cout << i->first << " " << i->second << endl;
        }
    }

    return 0;
}
