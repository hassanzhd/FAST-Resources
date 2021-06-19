#include <cstring>
#include <fstream>
#include <iostream>
using namespace std;

int main(int argc, char const *argv[]) {
    string comp;
    string str1 = "#include<iostream>\nusing namespace std;\n";
    string str2 = "void add(int x, int y) {int c;c=x+y;cout<<\"Sum of \"<< x << \" and \" << y << \" equals \" << c << endl;\n}";
    string str3 = "void product(int x, int y) {int c;c=x*y;cout<<\"Product of \"<< x << \" and \" << y << \" equals \" << c << endl;\n}";
    string str4 = "int main(){int a,b; cout << \"Enter element no1: \";cin >>a;cout << \"Enter element no2: \" ; cin >> b ;";
    string str5 = "add(a,b);";
    string str6 = "product(a,b);";
    string str7 = "return 0;}";

    int choice;
    cout << "Choose your functions: \n1. Add\n2. Product\n3. Both: ";
    cin >> choice;
    switch (choice) {
        case 1:
            comp = str1 + str2 + str4 + str5 + str7;
            break;

        case 2:
            comp = str1 + str3 + str4 + str6 + str7;
            break;

        case 3:
            comp = str1 + str2 + str3 + str4 + str5 + str6 + str7;
            break;

        default:
            comp = str1 + str2 + str3 + str4 + str5 + str6 + str7;
            break;
    }

    string name;
    cout << "Enter program name: ";
    cin >> name;
    ofstream fo;
    fo.open(name + ".cpp");
    fo << comp;
    fo.close();

    string com = "g++ ";
    string run1 = com + name + ".cpp" + " -o " + name;
    const char *run = run1.c_str();
    system(run);
    string run2 = "code " + name + ".cpp";
    const char *run_r = run2.c_str();
    system(run_r);

    return 0;
}
