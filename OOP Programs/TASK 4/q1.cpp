#include<iostream>
#include<cstring>
using namespace std;

class item{
	private:
		string name;
		int code;
		int price;
		int quantity;
	public:
		item()
		{
			code=0;
			price=0;
			quantity=0;
		}
		
		void detail()
		{
			cout << "Enter name of product: " ;
			cin >> name ;
			cout << "Enter code: " ;
			cin >> code ;
			cout << "Enter price: " ;
			cin >> price ;
			cout << "Enter quantity: " ;
			cin >> quantity ;
			//display();
		}
	
		void display()
		{
			cout << "Name of product: " << name << endl;
			cout << "Code of product: " << code << endl ;
			cout << "Price of product: " << price << endl ;
			cout << "Quantity of product: " << quantity << endl ;
		}
		
		void orderdis(int a)
		{
			cout << "Object number: " << a << endl ;
			cout << "Name of product: " << name << endl ;
			cout << "Code of product: " << code << endl ;
		}
		
		void o()
		{
			int quan, total;
			cout << "Enter number of items required: " ;
			cin >> quan ;
			total=quan*price;
			cout << "Total: Rs. " << total << endl ;
		}
		
};

void adobj(item obj[],int no,int *ite)
{
	cout << "Object number: " << *ite << endl ;
	obj[*ite].detail();
	*ite=*ite+1;
}

void del(item obj[],int no, int *ite)
{
	int i,j,delobj;
	for(i=0;i<*ite;i++)
	{
		obj[i].orderdis(i);
	}
	
	cout << "Enter object number to delete: " ;
	cin >> delobj ;
	
	if(delobj<*ite)
	{
		*ite=*ite-1;
		for(j=delobj;j<*ite;j++)
		{
			obj[j]=obj[j+1];			
		}	
	}
	
}

void order(item obj[],int no,int flag)
{
	int i,selec;
	for(i=0;i<flag;i++)
	{
		obj[i].orderdis(i);
	}
	
	cout << "Enter object number: " ;
	cin >> selec ;
	obj[selec].o();
	
}

int main()
{
	int no=100,choice;
	item obj[no];
	int ite=0;
	do{
		cout << "1. ADD ITEM\n2. DELETE ITEM\n3.Order\n4. Exit\nEnter choice:" ;
		cin >> choice ;
		switch(choice)
		{
			case 1:
			adobj(obj,no,&ite);
			break;
			
			case 2: 
			del(obj,no,&ite);	
			break;
			
			case 3: 
			order(obj,no,ite);
			break;
			
			default:
			break;		
		}
		
		if(choice==4)
		{
			break;
		}
		
	}while(1);

	
	return 0;
}
