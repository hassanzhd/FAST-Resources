#include<iostream>
using namespace std ;

class dis{
	private:
		float feet;
		float inches;
		float meter;
	
	public: 	
		distance()
		{
			feet=0;
			inches=0;
		}
		
		void set()
		{
			cout << "Enter distance in meters: " ;
			cin >> meter ;
			cal();
		}
		
		void cal()
		{
			feet=(float)meter*3.28;
			inches=(float)meter*39.37;  
			display();
		}
		
		void display()
		{
			cout << "Entered distance in meters: " << meter << " => Distance in feet:  " << feet << endl ;
			cout << "Entered distance in meters: " << meter << " => Distance in inches: " << inches << endl ;
		}
		
		~dis()
		{
			cout << "Object killed. " << endl ;
		}
		
};


int main()
{
	dis d1,d2;
	d1.display();
	d2.set();
	
	
	return 0;
}
