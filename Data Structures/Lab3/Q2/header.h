#ifndef HEADER_H
#define HEADER_H

class jaggedArray {
    int *jArray[9];
    int sizeArray[9];
    int check;

   public:
    jaggedArray();
    jaggedArray(const jaggedArray &);
    jaggedArray &operator=(const jaggedArray &);
    void insertion();
    void insertion(int *, unsigned int);
    void display();
    ~jaggedArray();
};

#endif