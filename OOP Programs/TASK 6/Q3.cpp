#include<iostream>
using namespace std ;

class Product {
	private:
		int barcode;
		string pro_name;
	public:
		Product(string n="NO-NAME",int b=000000){
			barcode=b;
			pro_name=n;
		}
		
		void set_code() {
			cout << "Enter name: " ;
			cin >> pro_name ;
			cout << "Enter bar-code: " ;
			cin >> barcode ;
		}
		
		int get_code() {
			cout << "Name: " << pro_name << endl ;
			cout << "Bar-code: " << barcode << endl ;
		}
		
		void scanner() {
			cout << "Enter product name: " ;
			cin >> pro_name ;
			cout << "Enter bar-code: " ;
			cin >> barcode;
		}
				
		void printer() {
			cout << "Product name: " << pro_name << endl ;
			cout << "Bar-code: " << barcode << endl ;
		}
			
};

class prepackedFood : public Product {
	private:
		float unit_price;
	public:
		prepackedFood(string n="NO-NAME",int b=0,float up=0.0) : Product(n,b) {
			unit_price=up;
		}
		
		void set() {
			Product::set_code();
			cout << "Enter unit-price: " ;
			cin >> unit_price ;
			cout << endl ;
		}
		
		float get_unit() {
			Product::get_code();
			cout <<"Unit-price: " << unit_price << endl ;
			cout << endl ;
		}
		
		void scanner() {
			Product::scanner();
			cout << "Enter uni-price: " ;
			cin >> unit_price ;
			cout << endl ;
		}
				
		void printer() {
			Product::printer();
			cout << "Unit price: " << unit_price << endl ;
			cout << endl ;
		}
		
};

class freshFood : public Product {
	private:
		float weight;
		float price_per_kilo;
	public:
		freshFood(string n="NO-NAME",int b=0,float w=0.0,float ppk=0.0) : Product(n,b) {
			weight=w;
			price_per_kilo=ppk;	
		}
		
		void set() {
			Product::set_code();
			cout << "Enter weight: " ;
			cin >> weight ;
			cout << "Enter price per kilo: " ;
			cin >> price_per_kilo ;
			cout << endl ;
		}
		
		float get() {
			Product::get_code();
			cout << "Weight: " << weight << endl ;
			cout << "Price-per-kilo: " << price_per_kilo << endl ;	
			cout << endl ;						
		}
		
		void scanner() {
			Product::scanner();
			cout << "Enter weight: " ;
			cin >> weight ;
			cout << "Enter price-per-kilo: " ;
			cin >> price_per_kilo ;
			cout << endl ;
		}
				
		void printer() {
			Product::printer();
			cout << "Weight: " << weight << endl ;
			cout << "Price-per-kilo: " << price_per_kilo << endl ;
			cout << endl ;
		}
		
};


int main()
{
	Product P1("NO-NAME",000000),P2,P3;
	prepackedFood PP1("Pepsi",101010,30),PP2,PP3;
	freshFood f1("Meat",101011,1.0,250.5),f2,f3;
	P2.scanner();
	cout << endl ;
	P2.printer();
	cout << endl ;
	P3.set_code();
	cout << endl ;
	P3.get_code();
	cout << endl ;
	PP2.scanner();
	PP2.printer();
	PP3.set();
	PP3.get_unit();
	f2.scanner();
	f2.printer();
	f3.set();
	f3.get();
	
	
	
	
	return 0;
}

