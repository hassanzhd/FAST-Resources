#include<iostream>
using namespace std;

class RentCalculator{
	private:
		const string name;
		float rentPerDay;
		int numberOfDays;
		float customerRent;
	public:
		RentCalculator(string a,int b):name(a) {
			rentPerDay=1000.85;	
			numberOfDays=b;
			customerRent=0.00;
			if(numberOfDays>7) {
				RentwithBonus();
			}
			else {
				RentWithoutBonus();
			}
	}	
		void RentwithBonus() {

			customerRent=(numberOfDays*rentPerDay)-rentPerDay;
			DisplayRent();
			
		}
		
		void RentWithoutBonus() {
			customerRent=numberOfDays*rentPerDay;
			DisplayRent();
		}
		
		void DisplayRent()const {
			cout << "Customer Name: " << name << endl ;
			cout << "Days: " << numberOfDays << endl ;
			cout << "Rent: " << customerRent << endl ;
		}
		
};
int main() {
	RentCalculator cust1("Hassan",7),cust2("Farzan",8);
	return 0;

}
