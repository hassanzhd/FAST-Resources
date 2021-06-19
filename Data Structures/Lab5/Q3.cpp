#include <iostream>
using namespace std;

struct student {
    int id;
    string name;
    float cgpa;

    student(int __id, string __name, float __cgpa) {
        id = __id;
        name = __name;
        cgpa = __cgpa;
    }

    void display() {
        cout << "ID: " << id << '\n';
        cout << "NAME: " << name << '\n';
        cout << "CGPA: " << cgpa << '\n';
    }
};

class node {
   public:
    node() : data(0, "XXXX", 0.0) {
        next = NULL;
    }

    node(int __id, string __name, float __cgpa, node* _temp = NULL) : data(__id, __name, __cgpa) {
        this->next = _temp;
    }

    student data;
    node* next;
};

class SinglyLinkedList {
    node *Head, *Tail;
    int count;

   public:
    SinglyLinkedList() {
        Head = Tail = NULL;
        count = 0;
    }

    void addToHead(int __id, string __name, float __cgpa) {
        if (Head == NULL) {
            Tail = Head = new node(__id, __name, __cgpa);
            count++;
        } else {
            Head = new node(__id, __name, __cgpa, Head);
            count++;
        }
    }

    void addToTail(int __id, string __name, float __cgpa) {
        if (Tail == NULL) {
            Head = Tail = new node(__id, __name, __cgpa);
            count++;
        } else {
            Tail->next = new node(__id, __name, __cgpa);
            Tail = Tail->next;
        }
    }

    void deleteFromHead() {
        if (Head == NULL) {
            return;
        } else {
            node* temp = Head;
            Head = Head->next;
            delete temp;
            count--;
        }
    }

    void deleteFromTail() {
        if (Tail == NULL) {
            return;
        } else {
            node* temp;
            for (temp = Head; temp->next != Tail; temp = temp->next)
                ;
            delete Tail;
            Tail = temp;
            Tail->next = NULL;
            count--;
        }
    }

    void addAtint(int __id, string __name, float __cgpa, int _position) {
        node* temp = Head;
        if (_position > count) {
            return;
        } else {
            if (_position == 0 || Head == NULL) {
                addToHead(__id, __name, __cgpa);
            } else if (_position == count) {
                addToTail(__id, __name, __cgpa);
            } else {
                for (int i = 1; i < _position; temp = temp->next, i++)
                    ;
                temp->next = new node(__id, __name, __cgpa, temp->next);
            }
        }
    }

    void deleteAt(int _position) {
        node* temp = Head;
        if (_position > count || Head == NULL) {
            return;
        } else {
            if (_position == 0) {
                deleteFromHead();
            } else if (_position == count) {
                deleteFromTail();
            } else {
                for (int i = 1; i < _position; temp = temp->next, i++)
                    ;
                node* p = temp->next;
                temp->next = temp->next->next;
                delete p;
            }
        }
    }

    void swap(int __firstNode, int __secondNode) {
        if (Head == NULL) {
            return;
        }

        if (__firstNode == __secondNode) {
            return;
        } else if (__firstNode > __secondNode) {
            int s = __firstNode;
            __firstNode = __secondNode;
            __secondNode = s;
        }

        if (__firstNode == 0 || __secondNode == 0) {
            if (__secondNode == __firstNode + 1) {
                node* swap1 = Head;
                node* swap2 = swap1->next;

                if (swap2 == NULL) {
                    return;
                }

                swap1->next = swap2->next;
                swap2->next = swap1;
                Head = swap2;
                return;
            }

            node* secondVal = Head;
            for (int i = 1; i < __secondNode && secondVal != NULL; secondVal = secondVal->next, i++)
                ;
            if (secondVal == NULL) {
                return;
            }

            node* swap2 = secondVal->next;

            if (swap2 == Tail) {
                node* ptr = swap2->next;
                swap2->next = Head->next;
                secondVal->next = Head;
                Head->next = ptr;
                Tail = Head;
                Head = swap2;
                return;
            }

            node* ptr = swap2->next;
            swap2->next = Head->next;
            secondVal->next = Head;
            Head->next = ptr;
            Head = swap2;
            return;

        } else {
            if ((__firstNode == __secondNode + 1) || (__secondNode == __firstNode + 1)) {
                node* firstVal = Head;
                for (int i = 1; i < __firstNode && firstVal != NULL; firstVal = firstVal->next, i++)
                    ;
                if (firstVal == NULL || firstVal == Tail) {
                    return;
                }

                node* swap1 = firstVal->next;
                node* swap2 = swap1->next;

                if (swap2 == Tail) {
                    swap1->next = swap2->next;
                    swap2->next = swap1;
                    firstVal->next = swap2;
                    Tail = swap1;
                    return;
                }

                swap1->next = swap2->next;
                swap2->next = swap1;
                firstVal->next = swap2;
                return;
            }

            node* firstVal = Head;
            node* secondVal = Head;
            for (int i = 1; i < __firstNode && firstVal != NULL; firstVal = firstVal->next, i++)
                ;
            for (int i = 1; i < __secondNode && secondVal != NULL; secondVal = secondVal->next, i++)
                ;

            if (firstVal == NULL || secondVal == NULL) {
                return;
            }

            node* swap1 = firstVal->next;
            node* swap2 = secondVal->next;
            node* ptr = swap2->next;

            if (swap2 == Tail) {
                swap2->next = swap1->next;
                secondVal->next = swap1;
                swap1->next = ptr;
                firstVal->next = swap2;
                Tail = swap1;
                return;
            }

            swap2->next = swap1->next;
            secondVal->next = swap1;
            swap1->next = ptr;
            firstVal->next = swap2;
            return;
        }
    }

    void sort() {
        node* temp = Head;
        for (int i = 0; temp != NULL; temp = temp->next, i++) {
            node* tmp = temp->next;
            for (int j = i; tmp != NULL; tmp = tmp->next, j++) {
                if (temp->data.id > tmp->data.id) {
                    swap(i, j + 1);
                    temp = tmp;
                }
            }
        }
    }

    void display() {
        node* temp;
        for (temp = Head; temp != NULL; temp = temp->next) {
            temp->data.display();
        }
        cout << '\n';
    }

    ~SinglyLinkedList() {
        node* temp;
        while (Head != NULL) {
            temp = Head->next;
            delete Head;
            Head = temp;
        }
    }
};

int main(int argc, char const* argv[]) {
    SinglyLinkedList l;
    l.addToTail(2, "HASSAN", 2.67);
    l.addToTail(3, "RAFAY", 3.1);
    l.addToTail(1, "SAJJAD", 3.4);
    l.display();
    l.sort();
    l.addToTail(4, "MAHAD", 3.8);
    l.display();
    return 0;
}