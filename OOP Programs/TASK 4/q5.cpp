#include<iostream>
#include<cstring>
using namespace std; 

class detail{
    private:
    char name[20];
    char roll_no[10];
    int semester;
    char section;

    public:
    detail(const char *n, const char *roll, int sem, char sec)
    {
        strcpy(name,n);
        strcpy(roll_no,roll);
        semester=sem;
        section=sec;

    }
    
    void display()
    {
        cout << "Name: "<< name<< endl;
        cout << "Roll No: " << roll_no<< endl;
        cout << "Semester: " << semester<< endl;
        cout << "Section: " << section;
    }
};

int main()
{
    detail d1("Hassan Zahid","18K-0208",2018,'H');
    d1.display();


    return 0;
}