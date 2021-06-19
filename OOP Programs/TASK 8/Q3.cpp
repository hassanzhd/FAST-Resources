#include<iostream>
#include<fstream>
#include<cstring>

using namespace std ;

class person{
    string name;
    int age;
    public:
        person(){}
        person(string a, int b):name(a),age(b){}
        void display() {
            cout << "Name: " << name << endl ;
            cout << "Age: " << age << endl ;
        }
};

int main(int argc, char const *argv[])
{
    person person1("Hassan",18),p2;
    ofstream o;
    o.open("person.bin");
    o.write((char *)&person1,sizeof(person1));
    o.close();

    ifstream i;
    i.open("person.bin");
    i.read((char*)&p2,sizeof(p2));
    i.close();

    p2.display();
    return 0;
}
