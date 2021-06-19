#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iostream>
using namespace std;

int main(int argc, char const *argv[]) {
    string name;
    string st;
    int dir;
    cout << "Enter string to search: ";
    getline(cin, name);
    cout << "1. E:\n2. F:\nChoose directory:";
    cin >> dir;
    ofstream f;
    f.open("function.ps1");
    switch (dir) {
        case 1:
            st = "Get-ChildItem -Recurse 'E:\\*.cpp' | Select-String \"" + name + "\" | Select-Object -Unique Path\nls -r 'E:\\*.cpp' | sls \"" + name + "\" | select -u Path";
            f << st;
            break;

        case 2:
            st = "Get-ChildItem -Recurse 'F:\\*.cpp' | Select-String \"" + name + "\" | Select-Object -Unique Path\nls -r 'F:\\*.cpp' | sls \"" + name + "\" | select -u Path";
            f << st;
            break;
    }

    f.close();

    system("powershell.exe .\\function.ps1");
    remove("function.ps1");

    return 0;
}
