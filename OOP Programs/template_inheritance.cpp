#include<iostream>
using namespace std ;

class var {
    protected:
    int f;
    public:
        var(int p):f(p){}
        virtual void pop()=0;
};

template<class T>
class car: public var {
    T l;
    public:
        car(T ll, int p):var(p),l(ll){}
        void pop(){}
        void displ() {
            cout << l << endl ;
            cout << f << endl ;
        }
};

int main(int argc, char const *argv[])
{
    car<int> p(1,1);
    p.displ();
    return 0;
}
