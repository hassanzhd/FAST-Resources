#ifndef HEADER_HPP
#define HEADER_HPP
#include <iostream>
using namespace std;

template <typename T>
class node {
   public:
    T data;
    node* next;

    node() : data(), next(NULL) {}
    node(T& __value, node* __next = NULL) : data(__value), next(__next) {}
};

template <typename T>
class list {
   protected:
    node<T>*head, *tail;
    int count;

   public:
    list() {
        head = tail = NULL;
        count = 0;
    }

    ~list() {
        node<T>* temp;
        while (head != NULL) {
            temp = head->next;
            delete head;
            head = temp;
        }
    }
};

template <typename T>
class singlyLinkedList : public list<T> {
   public:
    class iterator {
       public:
        node<T>* value;

        iterator() {}

        iterator(node<T>* __value) {
            value = __value;
        }

        iterator(iterator& __copy) {
            value = __copy.value;
        }

        iterator(iterator&& __copy) {
            value = __copy.value;
        }

        void operator++(int) {
            if (value == NULL) {
                return;
            }
            value = value->next;
        }

        bool operator!=(iterator __value) {
            if (value != __value.value) {
                return true;
            } else {
                return false;
            }
        }

        T& operator*() {
            return value->data;
        }

        ~iterator() {}
    };

    singlyLinkedList() {}

    singlyLinkedList(int __noOfCopies, T& __copyObj) {
        for (int i = 0; i < __noOfCopies; i++) {
            this->addTotail(__copyObj);
        }
    }

    singlyLinkedList(singlyLinkedList<T>::iterator __first, singlyLinkedList<T>::iterator __last) {
        while (__first != __last) {
            this->addTotail(__first.value->data);
            __first++;
        }
    }

    void insert(singlyLinkedList<T>::iterator __i, int __n, T __copyObj) {
        if (__i.value == this->head) {
            for (int i = 0; i < __n; i++) {
                this->addTohead(__copyObj);
            }
        } else if (__i.value == NULL) {
            for (int i = 0; i < __n; i++) {
                this->addTotail(__copyObj);
            }
        } else if (__i.value == this->tail) {
            node<T>* temp = this->tail;
            for (int i = 0; i < __n; i++) {
                this->addTotail(__copyObj);
            }
            this->tail = temp;
        } else {
            node<T>* temp;
            for (int i = 0; i < __n; i++) {
                for (temp = this->head; temp->next != __i.value; temp = temp->next)
                    ;
                temp->next = new node<T>(__copyObj, temp->next);
            }
        }
    }

    iterator insert(singlyLinkedList<T>::iterator __i, T __copyObj) {
        if (__i.value == this->head) {
            this->addTohead(__copyObj);
            iterator i(this->head);
            return i;
        } else if (__i.value == NULL) {
            this->addTotail(__copyObj);
        } else if (__i.value == this->tail) {
            node<T>* temp = this->tail;
            this->addTotail(__copyObj);
            iterator i(this->tail);
            this->tail = temp;
            return i;
        } else {
            node<T>* temp;
            for (temp = this->head; temp->next != __i.value; temp = temp->next)
                ;
            temp->next = new node<T>(__copyObj, temp->next);
            iterator i(temp->next);
            return i;
        }
    }

    iterator erase(singlyLinkedList<T>::iterator __i) {
        if (__i.value == NULL) {
            iterator i(NULL);
            return i;
        } else {
            node<T>* temp;
            for (temp = this->next; temp->next != __i.value; temp = temp->next)
                ;
            node<T>* p = temp->next;
            temp->next = temp->next->next;
            iterator i(temp->next);
            delete p;
            return i;
        }
    }

    iterator erase(singlyLinkedList<T>::iterator __first, singlyLinkedList<T>::iterator __last) {
        if (__first.value == NULL) {
            iterator i(NULL);
            return i;
        } else {
            if (__first.value == this->head && this->tail->next == __last.value) {
                this->clear();
            } else if (__first.value == this->head) {
                node<T>* temp;
                for (temp = this->head; temp != __last.value; temp = temp->next) {
                    this->deleteFromhead();
                }
                if (__last.value == NULL) {
                    this->head = this->tail = NULL;
                } else {
                    this->head = __last.value;
                }
            } else {
                node<T>* temp;
                for (temp = this->head; temp->next != __first.value; temp = temp->next)
                    ;
                temp->next = __last.value;

                node<T>* tmp = __first.value;
                while (tmp != __last.value) {
                    node<T>* del = tmp->next;
                    delete tmp;
                    tmp = del;
                }
            }
        }
    }

    T& front() {
        if (this->head == NULL) {
            cout << "LIST IS EMPTY\n";
            exit(0);
        } else {
            return this->head->data;
        }
    }

    const T& front() const {
        if (this->head == NULL) {
            cout << "LIST IS EMPTY\n";
            exit(0);
        } else {
            return this->head->data;
        }
    }

    T& back() {
        if (this->tail == NULL) {
            cout << "LIST IS EMPTY\n";
            exit(0);
        } else {
            return this->tail->data;
        }
    }

    const T& back() const {
        if (this->tail == NULL) {
            cout << "LIST IS EMPTY\n";
            exit(0);
        } else {
            return this->tail->data;
        }
    }

    void clear() {
        node<T>* temp = this->head;
        while (this->head != NULL) {
            temp = this->head->next;
            delete this->head;
            this->head = temp;
        }
        this->tail = NULL;
    }

    bool empty() const {
        if (this->head == NULL) {
            return true;
        }
        return true;
    }

    iterator begin() {
        iterator i(this->head);
        return i;
    }

    iterator end() {
        if (this->tail == NULL) {
            iterator i(NULL);
            return i;
        } else {
            iterator i(this->tail->next);
            return i;
        }
    }

    void addTohead(T __value) {
        if (this->head == NULL) {
            this->tail = this->head = new node<T>(__value);
            this->count++;
        } else {
            this->head = new node<T>(__value, this->head);
            this->count++;
        }
    }

    void addTotail(T __value) {
        if (this->tail == NULL) {
            this->head = this->tail = new node<T>(__value);
            this->count++;
        } else {
            this->tail->next = new node<T>(__value);
            this->tail = this->tail->next;
        }
    }

    void deleteFromhead() {
        if (this->head == NULL) {
            return;
        } else {
            node<T>* temp = this->head;
            this->head = this->head->next;
            delete temp;
            this->count--;
        }
    }

    void deleteFromtail() {
        if (this->tail == NULL) {
            return;
        } else {
            node<T>* temp;
            for (temp = this->head; temp->next != this->tail; temp = temp->next)
                ;
            delete this->tail;
            this->tail = temp;
            this->tail->next = NULL;
            this->count--;
        }
    }

    void addAt(T _value, int _position) {
        node<T>* temp = this->head;
        if (_position > this->count) {
            return;
        } else {
            if (_position == 0) {
                addTohead(_value);
            } else if (_position == this->count) {
                addTotail(_value);
            } else {
                for (int i = 1; i < _position; temp = temp->next, i++)
                    ;
                temp->next = new node<T>(_value, temp->next);
            }
        }
    }

    void deleteAt(int _position) {
        node<T>* temp = this->head;
        if (_position > this->count) {
            return;
        } else {
            if (_position == 0) {
                deleteFromhead();
            } else if (_position == this->count) {
                deleteFromtail();
            } else {
                for (int i = 1; i < _position; temp = temp->next, i++)
                    ;
                node<T>* p = temp->next;
                temp->next = temp->next->next;
                delete p;
            }
        }
    }

    void display() {
        node<T>* temp = this->head;
        if (temp == NULL) {
            cout << "LIST IS EMPTY\n";
        }
        while (temp != NULL) {
            cout << temp->data << ' ';
            temp = temp->next;
        }

        cout << "\n";
    }

    ~singlyLinkedList() {}
};

#endif