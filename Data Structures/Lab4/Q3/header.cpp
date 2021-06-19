#include "header.h"
#include <iostream>

node::node() {
    this->data = 0;
    this->next = NULL;
}

node::node(int __value, node *__next = NULL) {
    this->data = __value;
    this->next = __next;
}

linkedList::linkedList() {
    head = tail = NULL;
}

void linkedList::addToHead(int __value) {
    if (head == NULL) {
        head = tail = new node(__value);
        count++;
    } else {
        head = new node(__value, head);
        count++;
    }
}

void linkedList::addToTail(int __value) {
    if (tail == NULL) {
        head = tail = new node(__value);
        count++;
    } else {
        tail->next = new node(__value);
        tail = tail->next;
        count++;
    }
}

void linkedList::addTo(int __value, int __position) {
    if (__position > count) {
        return;
    } else {
        if (__position == 0) {
            addToHead(__value);
            count++;
        } else if (__position == count) {
            addToTail(__value);
            count++;
        } else {
            node *temp = head;
            for (int i = 1; i < __position; temp = temp->next, i++)
                ;
            temp->next = new node(__value, temp->next);
        }
    }
}

void linkedList::deleteFromHead() {
    if (head == NULL) {
        return;
    } else {
        node *temp = head;
        head = head->next;
        delete temp;
        count--;
    }
}

void linkedList::deleteFromTail() {
    if (tail == NULL) {
        return;
    } else {
        node *temp;
        for (temp = head; temp->next != tail; temp = temp->next)
            ;
        delete tail;
        tail = temp;
        tail->next = NULL;
        count--;
    }
}

void linkedList::deleteFrom(int __position) {
    if (__position > count) {
        return;
    } else {
        if (__position == 0) {
            deleteFromHead();
        } else if (__position == count) {
            deleteFromTail();
        } else {
            node *temp = head;
            for (int i = 0; i < __position; temp = temp->next, i++)
                ;
            node *del = temp->next;
            temp->next = temp->next->next;
            delete del;
        }
    }
}

int linkedList::countElement(int __value) {
    int no = 0;
    node *temp = head;
    while (temp != NULL) {
        if (temp->data == __value) {
            no++;
        }
        temp = temp->next;
    }
    return no;
}

void linkedList::display() {
    node *temp = head;
    std::cout << "Linked List: ";
    while (temp != NULL) {
        std::cout << temp->data << " ";
        temp = temp->next;
    }
    std::cout << '\n';
}

linkedList::~linkedList() {
    node *temp;
    while (head != NULL) {
        temp = head->next;
        delete head;
        head = temp;
    }
}
