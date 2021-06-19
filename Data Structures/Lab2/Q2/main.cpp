#include"header.h"
#include<conio.h>
#include<iostream>

int main() {
	int noOfStudents;
	std::cout << "Enter no of Students: " ;
	std::cin >>  noOfStudents;
	Student *student=new Student[noOfStudents];
	
	for(int i=0;i<noOfStudents;i++) {
		std::cout << "Enter info of Student # " << i+1 << ": " << std::endl ;
		student[i].addInfo();
		fflush(stdin);
		student[i].addCourses();
		fflush(stdin);
	}
	delete[] student;
	getch();
	return 0;
}
