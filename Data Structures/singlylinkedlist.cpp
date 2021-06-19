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
            if (_position == 0) {
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
        if (_position > count) {
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

    void display() {
        SinglyNode* temp;
        for (temp = Head; temp != NULL; temp = temp->next) {
            cout << temp->data << " ";
        }
        cout << "\n";
    }

    ~SinglyLinkedList() {
        SinglyNode* temp;
        while (Head != NULL) {
            temp = Head->next;
            delete Head;
            Head = temp;
        }
    }
};

int main(int argc, char const* argv[]) {
    SinglyLinkedList l;
    l.addToHead(1);
    l.addToTail(2);
    l.addToHead(3);
    l.addAt(4, 0);
    l.display();
    l.deleteFromHead();
    l.deleteFromTail();
    l.deleteAt(1);
    l.display();
    return 0;
}
