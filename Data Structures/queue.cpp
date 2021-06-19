#include <iostream>
using namespace std;

class node {
   public:
    int data;
    node *next;

    node(int __data, node *__next = NULL) {
        data = __data;
        next = __next;
    }
};

class Stack {
   private:
    node *head;

   public:
    Stack() {
        head = NULL;
    }

    bool isEmpty() {
        if (head == NULL) {
            return true;
        }
        return false;
    }

    int pop() {
        if (isEmpty()) {
            return -1;
        } else {
            int data = head->data;
            node *temp = head->next;
            delete head;
            head = temp;
            return data;
        }
    }

    void push(int __value) {
        if (isEmpty()) {
            head = new node(__value);
        } else {
            head = new node(__value, head);
        }
    }

    int peek() {
        if (isEmpty()) {
            return -1;
        }
        return head->data;
    }

    void display() {
        cout << "Stack: ";
        if (isEmpty()) {
            cout << "Empty";
        } else {
            node *temp = head;
            while (temp != NULL) {
                cout << temp->data << ' ';
                temp = temp->next;
            }
            cout << '\n';
        }
    }

    ~Stack() {
        node *temp;
        while (head != NULL) {
            temp = head->next;
            delete head;
            head = temp;
        }
    }
};

class Queue {
   private:
    node *head, *tail;
    int rear, size;

   public:
    Queue(int __size) {
        head = tail = NULL;
        rear = -1;
        size = __size;
    }

    bool isEmpty() {
        if (tail == NULL || rear == -1) {
            return true;
        }
        return false;
    }

    bool isFull() {
        if (rear + 1 == size) {
            return true;
        }
        return false;
    }

    void enqueue(int __value) {
        if (this->isEmpty()) {
            tail = head = new node(__value);
            rear++;
        } else if (this->isFull()) {
            cout << "QUEUE IS FULL\n";
            return;
        } else {
            tail->next = new node(__value);
            tail = tail->next;
            rear++;
        }
    }

    int dequeue() {
        if (this->isEmpty()) {
            return -1;
        } else {
            int value = head->data;
            node *temp = head;
            head = head->next;
            delete temp;
            rear--;
            return value;
        }
    }

    void deleteAt(node *__toDelete) {
        if (__toDelete == head) {
            node *temp = head;
            head = head->next;
            rear--;
            delete temp;
            return;
        } else if (__toDelete == tail) {
            node *temp;
            for (temp = head; temp->next != tail; temp = temp->next)
                ;
            delete tail;
            rear--;
            tail = temp;
            tail->next = NULL;
            return;
        }
        node *temp;
        for (temp = head; temp->next != __toDelete; temp = temp->next)
            ;
        node *ptr = temp->next;
        temp->next = temp->next->next;
        rear--;
        delete ptr;
    }

    void display() {
        node *temp = head;
        while (temp != NULL) {
            cout << temp->data << ' ';
            temp = temp->next;
        }
        cout << '\n';
    }

    ~Queue() {
        node *temp;
        while (head != NULL) {
            temp = head->next;
            delete head;
            head = temp;
        }
    }
    friend void deleteNegativeNumber(Queue &);
    friend void reverseQueue(Queue &);
};

void deleteNegativeNumber(Queue &__queue) {
    if (__queue.isEmpty()) {
        return;
    }

    node *temp = __queue.head;
    node *ptr = NULL;

    while (temp != NULL) {
        if (temp->data < 0) {
            ptr = temp->next;
            __queue.deleteAt(temp);
            temp = ptr;
        } else {
            temp = temp->next;
        }
    }
}

void reverseQueue(Queue &__queue) {
    node *p = __queue.head, *q = NULL, *r = NULL;
    while (p != NULL) {
        r = q;
        q = p;
        p = p->next;
        q->next = r;
    }
    node *ptr = __queue.head;
    __queue.head = q;
    __queue.tail = ptr;
}

void enQueue(Stack &__stack, int __x) {
    Stack temp;
    while (!__stack.isEmpty()) {
        temp.push(__stack.pop());
    }

    __stack.push(__x);
    while (!temp.isEmpty()) {
        __stack.push(temp.pop());
    }
    cout << "VALUE PUSHED: " << __x << '\n';
    __stack.display();
}

int deQueue(Stack &__stack) {
    if (__stack.isEmpty()) {
        return -1;
    } else {
        int data = __stack.pop();
        return data;
    }
}

int main(int argc, char const *argv[]) {
    //QUESTION # 1-3
    Queue q(6);
    q.enqueue(-1);
    q.enqueue(2);
    q.enqueue(1);
    q.enqueue(3);
    q.enqueue(3);
    q.enqueue(-3);
    deleteNegativeNumber(q);
    cout << "Negative removed queue: ";
    q.display();
    cout << "Reversed queue: ";
    reverseQueue(q);
    q.display();

    // QUESTION # 4
    Stack s;
    enQueue(s, 1);
    enQueue(s, 2);
    enQueue(s, 3);
    cout << "Dequeued value: " << deQueue(s) << '\n';
    s.display();
    return 0;
}