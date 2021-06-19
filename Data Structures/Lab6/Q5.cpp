#include <stdio.h>
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

    void pairCheck(int __value) {
        cout << "x = " << __value << '\n';
        node *temp;
        for (temp = head; temp != NULL; temp = temp->next) {
            for (node *tmp = temp; tmp != NULL; tmp = tmp->next) {
                if (temp->data + tmp->data == __value) {
                    printf("(%d, %d)\n", temp->data, tmp->data);
                }
            }
        }
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

int main(int argc, char const *argv[]) {
    doublyLinkedList dl;
    dl.addToTail(1);
    dl.addToTail(2);
    dl.addToTail(4);
    dl.addToTail(5);
    dl.addToTail(6);
    dl.addToTail(8);
    dl.addToTail(9);
    dl.pairCheck(10);
    return 0;
}