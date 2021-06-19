#include<iostream>
#include<cstdlib>
using namespace std ;

class Employee {
	private:
		string name;
		int number;
	protected:
		void set_value() {
			cout << "Enter employee name: " ;
			cin >> name ;
			cout << "Enter Identification number: " ;
			cin >> number ;
		}
		
		void display() {
			cout << "Employee Name: " << name << endl ;
			cout << "Identification number: " << number << endl ;
		}
};

class Manager: public Employee {
	private:
		string title;
		float club_dues;
	public:
		void set_value() {
			Employee::set_value();
			cout << "Enter title: " ;
			cin >> title;
			cout << "Enter golf-club dues: " ;
			cin >> club_dues ;
		}
		
		void display() {
			Employee::display();
			cout << "Title: " << title <<endl ;
			cout << "Golf-club dues: " << club_dues ;
		}
};

class Scientist: public Employee {
	private:
		string title;
		int publications;
	public:
		void set_value() {
			Employee::set_value();
			cout << "Enter title: " ;
			cin >> title;
			cout << "Enter number of publications: " ;
			cin >> publications;
		}
		
		void display() {
			Employee::display();
			cout << "Title: " << title << endl ;
			cout << "Publications: " << publications << endl ;
		}
};

class Labourer: public Employee {
	private:
		string title;
	public:
		void set_value() {
			Employee::set_value();
			cout << "Enter title: " ;
			cin >> title;
		}
		
		void display() {
			Employee::display();
			cout << "Title: " << title << endl;
		}
};


int main()
{
	Manager M1;
	Scientist S1;
	Labourer L1;
	M1.set_value();
	S1.set_value();
	L1.set_value();
	system("CLS");
	M1.display();
	S1.display();
	L1.display();
	
	return 0;
}

