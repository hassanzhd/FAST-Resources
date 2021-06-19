#ifndef ROOT_H
#define ROOT_H
#include<fstream>
class roots {
	int a,b,c,d;
	std::ifstream myInputFile;
	std::ofstream myOutputFile;
	public:
		roots();
		void realAndDiff();
		void compAndDiff();
		void realAndSame();
		void getRoots();
		void putRoots();
		~roots();
};
#endif
