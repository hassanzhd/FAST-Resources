#include <iostream>
using namespace std;

class node {
   public:
    int data;
    node *next, *prev;
    node() {
        data = 0;
        next = NULL;
        prev = NULL;
    }

    node(int __data, node *__next = NULL, node *__prev = NULL) {
        data = __data;
        next = __next;
        prev = __prev;
    }
};

class doublyLinkedList {
    node *head, *tail;
    int count;

   public:
    doublyLinkedList() {
        head = tail = NULL;
        count = 0;
    }

    void addToHead(int __value) {
        if (head == NULL) {
            head = tail = new node(__value);
            count++;
        } else {
            head = new node(__value, head, NULL);
            head->next->prev = head;
            count++;
        }
    }

    void addToTail(int __value) {
        if (tail == NULL) {
            tail = head = new node(__value);
            count++;
        } else {
            tail->next = new node(__value, NULL, tail);
            tail = tail->next;
            tail->prev->next = tail;
            count++;
        }
    }

    void addTo(int __index, int __value) {
        if (__index > count) {
            return;
        } else {
            if (__index == 0 || head == NULL) {
                this->addToHead(__value);
            } else if (__index == count) {
                this->addToTail(__value);
            } else {
                node *temp = head;
                for (int i = 1; i < __index && temp != NULL; temp = temp->next, i++)
                    ;
                if (temp == NULL) {
                    return;
                } else {
                    temp->next = new node(__value, temp->next, temp);
                    temp->next->next->prev = temp->next;
                    count++;
                }
            }
        }
    }

    void deleteFromHead() {
        if (head == NULL) {
            return;
        } else {
            if (head == tail) {
                delete head;
                head = tail = NULL;
                count--;
                return;
            }
            head = head->next;
            delete head->prev;
            head->prev = NULL;
            count--;
        }
    }

    void deleteFromTail() {
        if (tail == NULL) {
            return;
        } else {
            if (tail == head) {
                delete tail;
                tail = head = NULL;
                count--;
                return;
            }
            tail = tail->prev;
            delete tail->next;
            tail->next = NULL;
            count--;
        }
    }

    void deleteFrom(int __index) {
        if (__index > count) {
            return;
        } else {
            if (__index == 0) {
                this->deleteFromHead();
            } else if (__index == count) {
                this->deleteFromTail();
            } else {
                node *temp = head;
                for (int i = 1; i < __index && temp != NULL; temp = temp->next, i++)
                    ;
                if (temp == NULL) {
                    return;
                } else {
                    temp->next = temp->next->next;
                    delete temp->next->prev;
                    temp->next->prev = temp;
                    count--;
                }
            }
        }
    }

    void display() {
        node *temp = head;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << '\n';
    }

    ~doublyLinkedList() {
        node *temp;
        while (head != NULL) {
            temp = head->next;
            delete head;
            head = temp;
        }
    }
};

class circularLinkedList {
    node *tail;
    int count;

   public:
    circularLinkedList() {
        tail = NULL;
        count = 0;
    }

    void addToTail(int __value) {
        if (tail == NULL) {
            tail = new node(__value);
            tail->next = tail;
            tail->prev = tail;
            count++;
        } else {
            node *ptr = new node(__value, tail->next, tail);
            tail->next->prev = ptr;
            tail->next = ptr;
            tail = ptr;
            count++;
        }
    }

    void deleteFromTail() {
        if (tail == NULL) {
            return;
        } else {
            if (tail->next == tail) {
                delete tail;
                tail = NULL;
                count--;
            } else {
                node *temp = tail->prev;
                tail->next->prev = temp;
                temp->next = tail->next;
                delete tail;
                tail = temp;
                count--;
            }
        }
    }

    void addTo(int __index, int __value) {
        if (__index > count) {
            return;
        } else {
            if (__index == count || tail == NULL) {
                this->addToTail(__value);
            } else if (__index == 0) {
                node *head = tail->next;
                node *temp = new node(__value, head, tail);
                head->prev = temp;
                tail->next = temp;
                count++;
            } else {
                node *temp = tail->next;
                int i = 0;
                do {
                    temp = temp->next;
                    i++;
                } while (i < __index && temp != tail->next);

                if (temp == tail->next) {
                    return;
                } else {
                    node *ptr = new node(__value, temp->next, temp);
                    temp->next = ptr;
                    ptr->next->prev = ptr;
                    count++;
                }
            }
        }
    }

    void display() {
        node *temp = tail->next;
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != tail->next);
    }

    ~circularLinkedList() {
        if (tail == NULL) {
            return;
        }
        node *head = tail->next;
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
    doublyLinkedList l;
    l.addToHead(1);
    l.addToTail(2);
    l.addToTail(3);
    l.addTo(3, 4);
    l.addTo(4, 5);
    l.display();
    l.deleteFrom(2);
    l.deleteFrom(4);
    l.deleteFrom(0);
    l.display();

    circularLinkedList cl;
    cl.addToTail(2);
    cl.addToTail(3);
    cl.addTo(0, 1);
    cl.display();

    return 0;
}