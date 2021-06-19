#include<iostream>
#include<fstream>
#include<cstring>
using namespace std ;

int main(int argc, char const *argv[])
{
    char arr[50],inp[50];
    cout << "Enter string to put: " ;
    gets(arr);
    int a=strlen(arr);
    cout << "Length of string is: " << a << endl ;

    ofstream o;
    o.open("write.txt");
    o << arr ;
    o.close();

    ifstream i;
    i.open("write.txt");
    i.getline(inp,50); 
    i.close();

    cout << "String from file: " << inp << endl ;

    return 0;
}
