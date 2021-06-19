#include<iostream>
using namespace std ;

class vehicle {
	private:
		string type_of_car;
		string make;
		string model;
		string color;
		int year;
		float miles_driven;
	public:
		vehicle() {}
		vehicle(string a, string b, string c, string d, int e, float f) {
			type_of_car=a;
			make=b;
			model=c;
			color=d;
			year=e;
			miles_driven=f;
		}		
		
		void dis() {
			cout << "Type of car: " << type_of_car << endl ;
			cout << "Make: " << make << endl ;
			cout << "Model: " << model << endl ;
			cout << "Color: " << color << endl ;
			cout << "Year: " << year << endl ;
			cout << "Miles driven: " << miles_driven << endl ;
		}
};

class gasvehicle: virtual public vehicle {
	private:
		int tanksize;
	public:
		gasvehicle(int g){
			tanksize=g;
		}		
		
		void display() {
			cout << "Tank size: " << tanksize << endl ;
		}
};

class electricvehicle: virtual public vehicle {
	private:
		int energystorage;
	public:
		electricvehicle(string a, string b, string c, string d, int e, float f, int g):
		vehicle(a,b,c,d,e,f) {
			energystorage=g;
		}
		
		void display() {
			cout << "Energy storage: " << energystorage << endl ;
		}
};

class highperformance: public gasvehicle {
	private:
		float horsepower;
};

class heavyvehicle: public gasvehicle, public electricvehicle {
	private:
		float maximum_weight;
		int number_of_wheels;
		int length;
	public:
		heavyvehicle(string a, string b, string c, string d, int e, float f, int g, int h,float i,int j,int k):
		gasvehicle(g),
		electricvehicle(a,b,c,d,e,f,h) {
			maximum_weight=i;
			number_of_wheels=j;
			length=k;	
		}
		
		void display() {
			cout << "Maximum weight: " << maximum_weight << endl ;
			cout << "Number of wheels: " << number_of_wheels << endl ;
			cout << "Length: " << length << endl ;
		}
};

class sportscar: public highperformance {
	private:
		string gearbox;
		string drive_system;
};

class constructiontruck: public heavyvehicle {
	private:
		string cargo;
};

class bus: public heavyvehicle {
	private:
		int number_of_seats;
	public:
		bus(string a, string b, string c, string d, int e, float f, int g, int h, float i, int j, int k, int l):
		heavyvehicle(a,b,c,d,e,f,g,h,i,j,k),
		vehicle(a,b,c,d,e,f) {
			 number_of_seats=l;
		}
		
		void display() {
			vehicle::dis();
			gasvehicle::display();
			electricvehicle::display();
			heavyvehicle::display();
			cout << "Number of seats: " << number_of_seats << endl ;
		}
};

int main() {
	bus b("Bus","BMW","AKJ-1234","Black",2018,12.68,400,5500,1000,8,10,100);
	b.display();
	
	return 0;
}

