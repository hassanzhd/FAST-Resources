#include<iostream>
using namespace std ;

class Person {
	private:
		int age;
	protected:
		string name;
	public:
		Person(int a, string b) {
			age=a;
			name=b;
		}
		
		void display() {
			cout << "Age: " << age << endl ;	
		}
};

class Employee {
	private:
		int empID;
	protected:
		float salary;
	public:
		Employee(int c, float d) {
			empID=c;
			salary=d;
		}
		
		void display() {
			cout << "Employee ID: " << empID << endl ;
		}
};

class Manager: public Person, public Employee {
	private:
		string type;
	public:
		Manager(int a, string b, int c, float d, string e): Person(a,b),Employee(c,d) {
			type=e;
		}
		
		void display() {
			cout << "Name: " << name << endl ;
			Person::display();
			Employee::display();
			cout << "Salary: " << salary << endl ; 
			cout << "Type: " << type << endl ;
		}
};

class ITManager: public Manager {
	private:
		int noOfPersons;
	public:
		ITManager(int a, string b, int c, float d, string e, int f): Manager(a,b,c,d,e){
			noOfPersons=f;
		}
		void display() {
			Manager::display();	
			cout << "No of persons: " << noOfPersons << endl ;
		}
};
 

int main() {
	ITManager obj(25,"Hassan",1010,15000,"Manager",15);
	obj.display();
	return 0;
} 
