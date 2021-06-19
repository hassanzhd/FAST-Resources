#include<iostream>
using namespace std ;

class Sales{
	private:
		int saleID;
		string Itemname;
		int quantity;
	
	public: 
	Sales()
	{
		 	saleID=0;
		 	Itemname="ABC";
		 	quantity=0;
	}
	
	Sales(int a, string b, int c)
	{
		saleID=a;
		Itemname=b;
		quantity=c;
	}
	
	Sales(Sales &s)
	{
		saleID=s.saleID;
		Itemname=s.Itemname;
		quantity=s.quantity;	
	}
	
	void setdata()
	{
		cout << "Enter code: " ;
		cin >> saleID ;
		cout << "Enter itemname: " ;
		cin >> Itemname ;
		cout << "Enter quantity: " ;
		cin >> quantity ;
		cout << endl ;
	}
	
	void display()
	{
		cout << "Code no: " << saleID << endl ;
		cout << "Item name: " << Itemname << endl ;
		cout << "Quantity: " << quantity << endl << endl ;
	}
};

int main()
{
	Sales s1;
	s1.display();
	Sales s2(1000,"Pepsi",500);
	s2.display();
	Sales s3;
	s3.setdata();
	s3.display();
	Sales s4(s2);
	s4.display();
	
}
