#include <iostream>
using namespace std;

class SinglyNode {
   public:
    SinglyNode() {
        data = 0;
        next = NULL;
    }

    SinglyNode(int _value, SinglyNode* _temp = NULL) {
        this->data = _value;
        this->next = _temp;
    }

    int data;
    SinglyNode* next;
};

class SinglyLinkedList {
    SinglyNode *Head, *Tail;
    int count;

   public:
    SinglyLinkedList() {
        Head = Tail = NULL;
        count = 0;
    }

    SinglyLinkedList(const SinglyLinkedList& __copylist) {
        SinglyNode* temp = __copylist.Head;
        while (temp != NULL) {
            this->addToTail(temp->data);
            temp = temp->next;
        }
    }

    void addToHead(int _value) {
        if (Head == NULL) {
            Tail = Head = new SinglyNode(_value);
            count++;
        } else {
            Head = new SinglyNode(_value, Head);
            count++;
        }
    }

    void addToTail(int _value) {
        if (Tail == NULL) {
            Head = Tail = new SinglyNode(_value);
            count++;
        } else {
            Tail->next = new SinglyNode(_value);
            Tail = Tail->next;
        }
    }

    void deleteFromHead() {
        if (Head == NULL) {
            return;
        } else {
            SinglyNode* temp = Head;
            Head = Head->next;
            delete temp;
            count--;
        }
    }

    void deleteFromTail() {
        if (Tail == NULL) {
            return;
        } else {
            SinglyNode* temp;
            for (temp = Head; temp->next != Tail; temp = temp->next)
                ;
            delete Tail;
            Tail = temp;
            Tail->next = NULL;
            count--;
        }
    }

    void addAt(int _value, int _position) {
        SinglyNode* temp = Head;
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
                temp->next = new SinglyNode(_value, temp->next);
            }
        }
    }

    void deleteAt(int _position) {
        SinglyNode* temp = Head;
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
                SinglyNode* p = temp->next;
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
                SinglyNode* swap1 = Head;
                SinglyNode* swap2 = swap1->next;

                if (swap2 == NULL) {
                    return;
                }

                swap1->next = swap2->next;
                swap2->next = swap1;
                Head = swap2;
                return;
            }

            SinglyNode* secondVal = Head;
            for (int i = 1; i < __secondNode && secondVal != NULL; secondVal = secondVal->next, i++)
                ;
            if (secondVal == NULL) {
                return;
            }

            SinglyNode* swap2 = secondVal->next;

            if (swap2 == Tail) {
                SinglyNode* ptr = swap2->next;
                swap2->next = Head->next;
                secondVal->next = Head;
                Head->next = ptr;
                Tail = Head;
                Head = swap2;
                return;
            }

            SinglyNode* ptr = swap2->next;
            swap2->next = Head->next;
            secondVal->next = Head;
            Head->next = ptr;
            Head = swap2;
            return;

        } else {
            if ((__firstNode == __secondNode + 1) || (__secondNode == __firstNode + 1)) {
                SinglyNode* firstVal = Head;
                for (int i = 1; i < __firstNode && firstVal != NULL; firstVal = firstVal->next, i++)
                    ;
                if (firstVal == NULL || firstVal == Tail) {
                    return;
                }

                SinglyNode* swap1 = firstVal->next;
                SinglyNode* swap2 = swap1->next;

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

            SinglyNode* firstVal = Head;
            SinglyNode* secondVal = Head;
            for (int i = 1; i < __firstNode && firstVal != NULL; firstVal = firstVal->next, i++)
                ;
            for (int i = 1; i < __secondNode && secondVal != NULL; secondVal = secondVal->next, i++)
                ;

            if (firstVal == NULL || secondVal == NULL) {
                return;
            }

            SinglyNode* swap1 = firstVal->next;
            SinglyNode* swap2 = secondVal->next;
            SinglyNode* ptr = swap2->next;

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
        SinglyNode* temp = Head;
        for (int i = 0; temp != NULL; temp = temp->next, i++) {
            SinglyNode* tmp = temp->next;
            for (int j = i; tmp != NULL; tmp = tmp->next, j++) {
                if (temp->data > tmp->data) {
                    swap(i, j + 1);
                    temp = tmp;
                }
            }
        }
    }

    void display() {
        SinglyNode* temp;
        for (temp = Head; temp != NULL; temp = temp->next) {
            cout << temp->data << " ";
        }
        cout << '\n';
    }

    ~SinglyLinkedList() {
        SinglyNode* temp;
        while (Head != NULL) {
            temp = Head->next;
            delete Head;
            Head = temp;
        }
    }
    friend SinglyLinkedList merge(const SinglyLinkedList&, const SinglyLinkedList&);
};

SinglyLinkedList merge(const SinglyLinkedList& __list1, const SinglyLinkedList& __list2) {
    SinglyLinkedList l3;
    SinglyNode* head = __list1.Head;
    while (head != NULL) {
        l3.addToTail(head->data);
        head = head->next;
    }
    head = __list2.Head;
    while (head != NULL) {
        l3.addToTail(head->data);
        head = head->next;
    }
    return l3;
}

int main(int argc, char const* argv[]) {
    SinglyLinkedList l1, l2;
    l1.addToTail(1);
    l1.addToTail(2);
    l1.addToTail(3);
    l1.display();
    l2.addToTail(4);
    l2.addToTail(5);
    l2.addToTail(6);
    l2.display();
    SinglyLinkedList l3 = merge(l1, l2);
    l3.display();
    getchar();
    return 0;
}