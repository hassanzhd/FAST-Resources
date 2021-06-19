#include <iostream>
using namespace std;

class node {
   public:
    int data;
    node *next;
    node() {
        data = 0;
        next = NULL;
    }
    node(int __value, node *__next = NULL) {
        data = __value;
        next = __next;
    }
    ~node() {}
};

class circularLinkedList {
   private:
    node *head;
    node *tail;
    int count;

   public:
    circularLinkedList() {
        head = tail = NULL;
    }

    void addToHead(int __value) {
        if (head == NULL) {
            head = tail = new node(__value);
            head->next = tail->next = head;
            count++;
        } else {
            node *temp = new node(__value, head);
            tail->next = temp;
            head = temp;
            count++;
        }
    }

    void deleteFromHead() {
        if (head == NULL) {
            return;
        } else {
            if (head->next == head) {
                delete head;
                count--;
                head = tail = NULL;
            } else {
                node *temp = head->next;
                tail->next = temp;
                delete head;
                head = temp;
                count--;
            }
        }
    }

    void addToTail(int __value) {
        if (tail == NULL) {
            head = tail = new node(__value);
            head->next = tail->next = tail;
            count++;
        } else {
            node *temp = new node(__value, tail->next);
            tail->next = temp;
            tail = temp;
            count++;
        }
    }

    void deleteFromTail() {
        if (tail == NULL) {
            return;
        } else {
            if (tail->next == tail) {
                delete tail;
                head = tail = NULL;
                count--;
            } else {
                node *temp;
                for (temp = head; temp->next != tail; temp = temp->next)
                    ;
                delete tail;
                temp->next = head;
                tail = temp;
                count--;
            }
        }
    }

    void addTo(int __value, int __index) {
        if (__index == 0 || head == NULL) {
            this->addToHead(__value);
        } else if (__index == count) {
            this->addToTail(__value);
        } else {
            node *temp = head;
            if (__index == 1) {
                node *newNode = new node(__value, temp->next);
                temp->next = newNode;
                return;
            }

            int i = 1;
            do {
                temp = temp->next;
                i++;
            } while (i < __index && temp != head);

            if (temp == head) {
                return;
            } else {
                node *newNode = new node(__value, temp->next);
                temp->next = newNode;
                count++;
            }
        }
    }

    void createLL(int *__ptr, int __index) {
        for (int i = 0; i < __index; i++) {
            this->addToTail(__ptr[i]);
        }
    }

    void modifyEvenOdd() {
        if (head == NULL) {
            return;
        }
        node *eStart = NULL, *eEnd = NULL;
        node *oStart = NULL, *oEnd = NULL;

        node *temp = head;
        do {
            if (temp->data % 2 == 0) {
                if (eStart == NULL) {
                    eStart = temp;
                    eEnd = eStart;
                } else {
                    eEnd->next = temp;
                    eEnd = eEnd->next;
                }
            } else {
                if (oStart == NULL) {
                    oStart = temp;
                    oEnd = oStart;
                } else {
                    oEnd->next = temp;
                    oEnd = oEnd->next;
                }
            }
            temp = temp->next;
        } while (temp != head);

        if (eStart == NULL || oStart == NULL) {
            return;
        }

        eEnd->next = oStart;
        oEnd->next = eStart;
        head = eStart;
        tail = oEnd;
    }

    void display() {
        node *temp = head;
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);
        cout << '\n';
    }

    ~circularLinkedList() {
        if (head == NULL || tail == NULL) {
            return;
        }
        tail->next = NULL;
        node *temp;
        while (head != NULL) {
            temp = head->next;
            delete head;
            head = temp;
        }
    }
};

int main(int argc, char const *argv[]) {
    circularLinkedList cl;
    int arr[] = {17, 15, 8, 12, 10, 5, 4, 1, 7, 6};
    cl.createLL(arr, 10);
    cl.display();
    cl.modifyEvenOdd();
    cl.display();
    return 0;
}