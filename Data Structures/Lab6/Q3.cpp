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

    void sortedInsert(int __value) {
        if (head == NULL) {
            this->addToHead(__value);
        } else if (head->next == head) {
            if (head->data == __value) {
                this->addToHead(__value);
            } else if (head->data > __value) {
                this->addToHead(__value);
            } else {
                this->addToTail(__value);
            }
            return;
        } else {
            if (__value > tail->data) {
                this->addToTail(__value);
                return;
            } else if (__value < head->data) {
                this->addToHead(__value);
            } else {
                node *temp = head;
                int i = 1;
                do {
                    if (__value > temp->data && __value < temp->next->data) {
                        this->addTo(__value, i);
                        return;
                    } else {
                        temp = temp->next;
                        i++;
                    }
                } while (temp != head);
            }
        }
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
    cl.sortedInsert(1);
    cl.sortedInsert(4);
    cl.sortedInsert(3);
    cl.sortedInsert(2);
    cl.sortedInsert(0);

    cl.display();
    return 0;
}