#include<iostream>
#include<cstring>
using namespace std;

class BankAccount {
	private:
		string depositor;
		int accountnumber;
		string type;
		float amount;
		static float rate;
	public:
		BankAccount() {
			depositor=" ";
			accountnumber=0;
			type="none";
			amount=0.0;	
		}
		
		BankAccount(string name,int accno,string typ,float amm) {
			depositor=name;
			accountnumber=accno;
			type=typ;
			amount=amm;
		}
		
		void deposit() {
			float deposit;
			cout << "Enter amount to deposit: " ;
			cin >> deposit ;
			amount=amount+deposit;
		}
		
		void withdraw() {
			float withdraw;
			cout << "Enter amount to withdraw: " ;
			cin >> withdraw ;
			if(withdraw<=amount) {
				amount=amount-withdraw;
			} 
			
			else {
				cout << "ERROR! Transaction not possible. " ;
			}
			
		}
		
		void display() {
			cout << "Name: " << depositor << endl ;
			cout << "Account No: " << accountnumber << endl ;
			cout << "Type: " << type << endl ;
			cout << "Amount: " << amount << endl;
			cout << "Rate of interest: " << BankAccount::ratedetail() << endl << endl ;
		}
		
		float static ratedetail();
		
		~BankAccount() {
			delete this;
		}
		
};

float BankAccount::rate=0.15;
float BankAccount::ratedetail() {
	return rate;
}

int main()
{
	BankAccount *A[10];
	int choice;
	static int i=0;
	
	do {
		cout << "1.ADD\n2.Deposit\n3.Withdraw\n4.Display Details\n5.Exit" << endl ;
		cout << "Enter choice: " ;
		cin >> choice ;
		
		switch(choice) {
			case 1:	{
			string n,t; int acc; float am;
			cout << "Enter name: " ;
			cin >> n;
			cout << "Account number: " ;
			cin >> acc;
			cout << "Enter type of account: " ;
			cin >> t ;
			cout << "Enter amount to deposit: " ;
			cin >> am ;
			
			A[i]= new BankAccount(n,acc,t,am);
			i++;
		}
			break;
			
			case 2: {
			int number;
			cout << "Enter account number to deposit: " ;
			cin >> number ;
			A[number]->deposit();
				
		}
			 break;
			 
			 
			case 3: {
			int number;
			cout << "Enter account number to withdraw: " ;
			cin >> number ;
			A[number]->withdraw();
				
		}
			 break;	
			 
			 
			case 4: {
			int number;
			cout << "Enter account number to display: " ;
			cin >> number ;
			A[number]->display();
				
		}
			 break;
			
		}
		
		if(choice==5) {
			break;
		}
	}while(1);
	
	delete []A;
	
	return 0;
}
