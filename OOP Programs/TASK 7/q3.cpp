#include<iostream>
using namespace std ;

class account {
	protected:
		double balance;
	public:
		account(float bal=0) {
			balance=bal;
		}
		
		void deposit(double p=0) {
			balance=balance+p;
		}
		
		void withdraw(double w=0) {
			balance=balance-w;
		}
		
		void checkbalance() {
			cout << "Available Balance: " << balance << endl ;
		}
};

class interestAccount: virtual public account {
	protected:
		double interest;
	public:
		interestAccount():interest(0.3),account() {}
		
		void deposit() {
			double dep;
			cout << "Enter amount to deposit: " ;
			cin >> dep;
			dep=dep+(dep*interest);
			account::deposit(dep);
			cout << "New amount: " << balance << endl ;
		}
};

class chargingAccount: virtual public account {
	protected:
		double fee;
	public:
		chargingAccount(): fee(3) {}
		
		void widthdraw() {
			double with;
			cout << "Enter amount to widthdraw: " ;
			cin >> with ;
			with=with+fee;
			account::withdraw(with);
			cout << "New amount: " << balance << endl ;
		}
};

class aci: public interestAccount, public chargingAccount {
		public:
		aci(double b=0):account(b) {}
		
		void transfer(double b, aci &obj) {
			obj.account::deposit(b);
			this->account::withdraw(b);
		}
};

int main() {
	aci o(2000);
	cout << "\t\t\t\t\tData of person#1" << endl ;
	o.checkbalance();
	o.deposit();
	o.checkbalance();
	o.widthdraw();
	o.checkbalance();
	
	cout << endl ;
	cout << "\t\t\t\t\tData of person#2" << endl ;
	aci o1(2000);
	double trans;
	o1.checkbalance();
	cout << "Enter amount to transfer from person#2 to person#1: " ;
	cin >> trans ;
	o1.transfer(trans,o);
	cout << "Amount of person#2: " ;
	o1.checkbalance();
	cout << "Amount of person#1: " ;
	o.checkbalance();
	
	
	return 0;
}
