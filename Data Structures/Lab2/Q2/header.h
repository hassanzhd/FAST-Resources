#ifndef HEADER_H
#define HEADER_H
#include<fstream>

class Student {
	int id,batch,graduatingYear;
	std::string discipline,*courses;
	std::ofstream myOutputFile;
	public:
		Student();
		void addInfo();
		void addCourses();
		~Student();
};

#endif
