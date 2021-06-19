#ifndef HEADER_H
#define HEADER_H

class node {
   public:
    int data;
    node *next;
    node();
    node(int, node *);
};

class linkedList {
    node *head, *tail;
    int count;

   public:
    linkedList();
    void addToHead(int);
    void addToTail(int);
    void addTo(int, int);
    void deleteFromHead();
    void deleteFromTail();
    void deleteFrom(int);
    void display();
    friend void calculateAverage(linkedList &, linkedList &);

    ~linkedList();
};

void calculateAverage(linkedList &, linkedList &);

#endif