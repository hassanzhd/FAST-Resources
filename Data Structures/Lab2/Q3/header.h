#ifndef HEADER_H
#define HEADER_H

class gradingSystem {
    int **details, sections;
    char id[5] = {'A', 'B', 'C', 'D', 'F'};

   public:
    gradingSystem();
    void setDetails();
    void print();
    ~gradingSystem();
};

#endif
