#include<iostream>
using namespace std ;

class employee{
	protected:
		string name ;
		string code;	
};

class consultant: virtual public employee {
	protected: 
		int yearsofexperience;
	public:
		consultant(string a, string b,int c){
			name=a;
			code=b;
			yearsofexperience=c;
		}
};

class manager: virtual public employee {
	protected:
		int noofteams;
	public:
		manager(string a,string b,int c){
			name=a;
			code=b;
			noofteams=c;
		}
};

class consultantManager: public consultant, public manager {
	public:
		consultantManager(string a, string b, int c,int d):consultant(a,b,c),manager(a,b,d){
		yearsofexperience=c;
		noofteams=d;
	}
		void display();
};

void consultantManager::display() {
		cout << "Name: " << name << endl ;
		cout << "Code: " << code << endl ;
		cout << "Years of experience: " << code << endl ;
		cout << "No of teams: " << noofteams << endl ;
}

int main() {
	
	consultantManager obj("Ali","S-128",17,5);
	obj.display();
	
	return 0;
}
