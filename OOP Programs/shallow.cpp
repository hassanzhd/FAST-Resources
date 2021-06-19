#include<iostream>
using namespace std ;
class car {

    private:
    int *model;
    int *regno;
    public:
    car(int m, int r)
    {
        model = new int;
        regno = new int;
        *model=m;
        *regno=r;
    }

    void display()
    {
        cout << "Memory location of object: " << this << endl ;
        cout << "Model memory stored: " << model << " Value stored: " << *model << " Location: " << &model << endl ;
        cout << "Regno memory stored: " << regno << " Value stored: " << *regno << " Location: " << &regno << endl ;
        
    }

    void set()
    {
        cout << "Enter model: " ;
        cin >> *model ;
        cout << "Enter regno: " ;
        cin >> *regno ;
    }
    
};

int main()
{
    car c1(10,10);
    car c2=c1;
    c1.display();
    c2.display();
    c1.set();
    c1.display();
    c2.display();

    return 0;
}
