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

    void doublySwap(int __firstIndex, int __secondIndex) {
        if (head == NULL || __firstIndex == __secondIndex) {
            return;
        } else {
            if (__firstIndex > __secondIndex) {
                int s = __firstIndex;
                __secondIndex = __firstIndex;
                __secondIndex = s;
            }

            if (__firstIndex == 0) {
                if (__secondIndex == __firstIndex + 1) {
                    if (head->next == NULL) {
                        return;
                    } else {
                        head = head->next;
                        head->prev->next = head->next;
                        head->prev->prev = head;
                        head->next = head->prev;
                        head->prev = NULL;
                        return;
                    }
                } else {
                    node *swap2 = head;
                    for (int i = 1; i <= __secondIndex && swap2 != NULL; swap2 = swap2->next, i++)
                        ;

                    if (swap2 == NULL) {
                        return;
                    }

                    if (swap2 == tail) {
                        swap2->next = head->next;
                        swap2->next->prev = swap2;
                        head->prev = swap2->prev;
                        head->prev->next = head;
                        head->next = NULL;
                        swap2->prev = NULL;
                        tail = head;
                        head = swap2;
                        return;
                    }

                    node *temp = swap2->next;
                    swap2->next = head->next;
                    swap2->next->prev = swap2;
                    head->prev = swap2->prev;
                    head->prev->next = head;
                    head->next = temp;
                    head->next->prev = head;
                    swap2->prev = NULL;
                    head = swap2;
                    return;
                }
            } else if (__secondIndex == __firstIndex + 1) {
                node *swap1 = head;
                node *swap2 = head;
                for (int i = 1; i <= __firstIndex && swap1 != NULL; swap1 = swap1->next, i++)
                    ;
                for (int i = 1; i <= __secondIndex && swap2 != NULL; swap2 = swap2->next, i++)
                    ;
                if (swap1 == NULL || swap2 == NULL) {
                    return;
                }

                if (swap2 == tail) {
                    swap1->next = swap2->next;
                    swap2->next = swap1;
                    swap2->prev = swap1->prev;
                    swap2->prev->next = swap2;
                    swap2->next->prev = swap2;
                    tail = swap1;
                    return;
                }

                swap1->next = swap2->next;
                swap1->next->prev = swap1;
                swap2->next = swap1;
                swap2->prev = swap1->prev;
                swap2->prev->next = swap2;
                swap2->next->prev = swap2;
                return;
            } else {
                node *swap1 = head;
                node *swap2 = head;

                for (int i = 1; i <= __firstIndex && swap1 != NULL; swap1 = swap1->next, i++)
                    ;
                for (int i = 1; i <= __secondIndex && swap2 != NULL; swap2 = swap2->next, i++)
                    ;

                if (swap1 == NULL || swap2 == NULL) {
                    return;
                }

                if (swap2 == tail) {
                    node *prev = swap2->prev;
                    node *next = swap2->next;
                    swap2->next = swap1->next;
                    swap2->next->prev = swap2;
                    swap2->prev = swap1->prev;
                    swap2->prev->next = swap2;
                    swap1->next = next;
                    swap1->prev = prev;
                    swap1->prev->next = swap1;
                    tail = swap1;
                    return;
                }

                node *prev = swap2->prev;
                node *next = swap2->next;
                swap2->next = swap1->next;
                swap2->next->prev = swap2;
                swap2->prev = swap1->prev;
                swap2->prev->next = swap2;
                swap1->next = next;
                swap1->next->prev = swap1;
                swap1->prev = prev;
                swap1->prev->next = swap1;
                return;
            }
        }
    }

    void bubbleSort() {
        node *temp = head;
        for (int i = 0; temp != NULL; temp = temp->next, i++) {
            node *tmp = temp->next;
            for (int j = i; tmp != NULL; tmp = tmp->next, j++) {
                if (temp->data > tmp->data) {
                    doublySwap(i, j + 1);
                    temp = tmp;
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

int main(int argc, char const *argv[]) {
    doublyLinkedList dl;
    dl.addToTail(2);
    dl.addToTail(5);
    dl.addToTail(1);
    dl.addToTail(3);
    dl.addToTail(4);
    dl.bubbleSort();
    dl.addToTail(6);
    dl.display();

    return 0;
}