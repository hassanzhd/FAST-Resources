#include<iostream>
#include<fstream>

using namespace std ;

int main(int argc, char const *argv[])
{
    string a; int b;
    ifstream i;
    ofstream o;
    i.open("write.txt");
    o.open("temp.txt");
    while (!i.eof()){
        i >> b >> a ;
        o << b << " " << a << endl;
    }
    o.close();
    i.close();
    return 0;
}
