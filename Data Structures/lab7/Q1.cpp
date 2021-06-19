#include <math.h>
#include <iostream>
using namespace std;

class Stack {
   private:
    int *stack;
    int size;
    int top;

   public:
    Stack(int __size) {
        size = __size;
        stack = new int[size];
        top = -1;
    }

    bool isEmpty() {
        if (top == -1) {
            return true;
        }
        return false;
    }

    bool isFull() {
        if (top + 1 == size) {
            return true;
        }
        return false;
    }

    bool push(int __value) {
        if (isFull()) {
            return false;
        } else {
            top = top + 1;
            stack[top] = __value;
        }
        return true;
    }

    int pop() {
        if (isEmpty() == true) {
            return -1;
        } else {
            int data = stack[top];
            top = top - 1;
            return data;
        }
    }

    int peek() {
        if (isEmpty()) {
            return -1;
        } else {
            int data = stack[top];
            return data;
        }
    }

    void display() {
        cout << "STACK: ";
        if (isEmpty() == true) {
            cout << "EMPTY";
        } else {
            for (int i = 0; i <= top; i++) {
                cout << stack[i] << " ";
            }
            cout << '\n';
        }
    }

    ~Stack() {
        delete[] stack;
    }

    friend void primeFactor(int __number);
};

bool isPrime(int __number) {
    for (int i = 2; i <= sqrt(__number); i++) {
        if (__number % i == 0) {
            return false;
        }
    }
    return true;
}

void primeFactor(int __number) {
    Stack s(__number);
    int limit = sqrt(__number);

    for (int i = 2; i <= limit; i++) {
        if (__number % i == 0 && isPrime(i)) {
            s.push(i);
        } else {
            continue;
        }
    }
    s.display();
}

int main(int argc, char const *argv[]) {
    primeFactor(420);

    return 0;
}
