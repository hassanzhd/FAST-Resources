#include<iostream>
#include<cstring>
using namespace std ;

class Employee {
    private:
        const int employID;
        char employname[20];
    public:
        Employee(const int id, const char *name):employID(id){
            strcpy(employname,name);
        }

        void access()
        {
            cout << "ID: " << employID << endl ;
            cout << "Name: " << employname << endl << endl ;
        }

        void mutator()
        {
            cout << "Enter Name: " ;
            cin >> employname ;
            access();
        }
        
};

int main()
{
    int eID=1000;
    Employee Employee1(eID," "),Employee2(++eID," "),Employee3(++eID," ");
    Employee1.mutator();
    Employee2.mutator();
    Employee3.mutator();
    return 0;
}
