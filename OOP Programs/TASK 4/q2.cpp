#include<iostream>
using namespace std;

class numb{
	private:
		int area_code;
		int exc_code;
		int consu_code;
		int arr[11];
		long long bre;
			
	public:
		numb(int no)
		{
			consu_code=no%10000;
			no=no/10000;
			exc_code=no%10000;
			no=no/10000;
			area_code=no;
			display();
								
		}
		
		void display()
		{
			if(area_code/100>0)
			{
				cout << "Area code: " << area_code << endl ;
			}
			
			else
			{
				cout << "Area code: 0" << area_code << endl ;
		
			}
			
			if(exc_code/1000>0)
			{
				cout << "Exchange code: " << exc_code << endl ;		
			}
			
			else
			{
				cout << "Exchange code: 0" << exc_code << endl ;
			}
		
			if(consu_code/1000>0)
			{
				cout << "Consumer number: " << consu_code << endl ;		
			}
			
			else
			{
				cout << "Consumer number: 0" << consu_code << endl ;
			}		
		}			
};

main()
{
	long long num;
	cout << "Enter number: " ;
	cin >> num ;
	numb n(num);
		
}
