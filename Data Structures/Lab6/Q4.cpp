#include <iostream>
using namespace std;

class node {
   public:
    node() {
        data = 0;
        next = NULL;
    }

    node(int _value, node* _temp = NULL) {
        this->data = _value;
        this->next = _temp;
    }

    int data;
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

    void addToHead(int _value) {
        if (Head == NULL) {
            Tail = Head = new node(_value);
            count++;
        } else {
            Head = new node(_value, Head);
            count++;
        }
    }

    void addToTail(int _value) {
        if (Tail == NULL) {
            Head = Tail = new node(_value);
            count++;
        } else {
            Tail->next = new node(_value);
            Tail = Tail->next;
            count++;
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

    void addAt(int _value, int _position) {
        node* temp = Head;
        if (_position > count) {
            return;
        } else {
            if (_position == 0 || Head == NULL) {
                addToHead(_value);
            } else if (_position == count) {
                addToTail(_value);
            } else {
                for (int i = 1; i < _position; temp = temp->next, i++)
                    ;
                temp->next = new node(_value, temp->next);
                count++;
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
                count--;
            }
        }
    }

    void swap(int __firstNode, int __secondNode) {
        if (Head == NULL || __firstNode == __secondNode || __firstNode < 0 || __secondNode < 0) {
            return;
        }

        if (__firstNode > __secondNode) {
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

    void positionSort(int __k) {
        swap(__k, (count - __k) - 1);
    }

    void display() {
        node* temp;
        for (temp = Head; temp != NULL; temp = temp->next) {
            cout << temp->data << " ";
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
    SinglyLinkedList l1;
    l1.addToTail(1);
    l1.addToTail(2);
    l1.addToTail(3);
    l1.addToTail(4);
    l1.addToTail(5);
    l1.positionSort(1);
    l1.display();
    return 0;
}