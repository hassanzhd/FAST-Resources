#include"header.h"
#include<iostream>
#include<fstream>
Student::Student() {
	myOutputFile.open("file.txt",std::ios::app);
}

void Student::addInfo() {
	std::cout << "Enter ID: " ;
	std::cin >> id ;
	
	std::cout << "Enter Batch: " ;
	std::cin >> batch ;
	
	std::cout << "Enter Graduating Year: " ;
	std::cin >> graduatingYear ;
	
	std::cout << "Enter Discipline: " ;
	std::cin >>  discipline; 
	
	myOutputFile << id << " " << batch << " " << graduatingYear << " " << discipline << " " ;
	
}

void Student::addCourses() {
	int noOfCourses;
	std::cout << "Enter no of courses: " ;
	std::cin >>  noOfCourses;
	
	courses= new std::string[noOfCourses];
	
	for(int i=0;i<noOfCourses;i++) {
		std::cout << "Enter course # " << i+1 << ": ";
		std::cin >>  courses[i];
		myOutputFile << courses[i] << " " ;	
	}
	myOutputFile << std::endl ;
}

Student::~Student() {
	delete[] courses ;
	myOutputFile.close();

}

