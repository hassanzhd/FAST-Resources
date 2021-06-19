#ifndef HEADER_H
#define HEADER_H

class DSA {
   public:
    int *data;
    int size;

    DSA(int);
    DSA(const DSA &);
    int getSize();
    DSA &operator=(const DSA &);
    int operator[](unsigned int);

    virtual void insert();
    virtual void search();

    ~DSA();
};

class orderedDSA : public DSA {
   public:
    orderedDSA(int);
    void insert();
    void search();
};

class unorderedDSA : public DSA {
   public:
    unorderedDSA(int);
    void insert();
    void search();
};

#endif
