#include "root.h"
#include<fstream>
#include<math.h>
#include<iostream>

roots::roots(){
	myInputFile.open("file.txt");
	myInputFile >> a >> b >> c ;
}

void roots::realAndDiff() {
	float x1 = (-b + sqrt(d)) / (2*a);
    float x2 = (-b - sqrt(d)) / (2*a);
    std::cout << "Roots are real and different." << std::endl;
    std::cout << "x1 = " << x1 << std::endl;
    std::cout << "x2 = " << x2 << std::endl;
}

void roots::compAndDiff() {
	float realPart = -b/(2*a);
    float imaginaryPart =sqrt(-d)/(2*a);
    std::cout << "Roots are complex and different."  << std::endl;
    std::cout << "x1 = " << realPart << "+" << imaginaryPart << "i" << std::endl;
    std::cout << "x2 = " << realPart << "-" << imaginaryPart << "i" << std::endl;	
}

void roots::realAndSame() {
	std::cout << "Roots are real and same." << std::endl;
    float x1 = (-b + sqrt(d)) / (2*a);
    std::cout << "x1 = x2 =" << x1 << std::endl;
}

void roots::getRoots() {
	d=b*b-4*a*c;
	if(d>0) {
		realAndDiff();
	} else if(d==0) {
		realAndSame();
	} else {
		compAndDiff();
	}
}				

void roots::putRoots() {
	myOutputFile.open("file.txt");
	std::cout << "Enter coefficient A: " ;
	std::cin >> a;
	std::cout << "Enter coefficient B: " ;
	std::cin >> b;
	std::cout << "Enter coefficient C: " ;
	std::cin >> c;
	myOutputFile << a << " " << b << " " << c ;
}	

roots::~roots(){
	myInputFile.close();
	myOutputFile.close();	
}

