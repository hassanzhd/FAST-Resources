#include<iostream>
using namespace std;

class count {
    int x;
    public:
        count(int a=0):x(a) {}
        count operator +(int a) {
            count k;
            k.x=this->x+a;
            return (k);
        }
        void display() {
            cout << "Value of x= " << x << endl ;
        }
        friend bool operator ==(count &, count &);
};

class count1: public count {
    int b;
    public:
        count1(int a=0):b(a) {}
        void display() {
            cout << "Value of B= " << b << endl ;
        }
        friend bool operator ==(count &, count &);
};

bool operator ==(count &a, count &b) {
    if(a.x==b.x) {
        return (true);
    } else {
        return (false);
    }
}

int main(int argc, char const *argv[])
{
    count c1(10);
    count c2=c1+10;
    if(c1==c2) {
        cout << "Equal." << endl ;
    } else {
        cout << "Not equal. " << endl ; 
    }
    
    count1 cc(10);
    cc=count1(20);
    count1 cc1=move(cc);
    if(cc==cc1) {
        cout << "Equal." ;
    } else {
        cout << "Not equal. "; 
    }
    
    return 0;
}
 