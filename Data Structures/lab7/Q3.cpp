#include <iostream>
using namespace std;

class Stack {
   private:
    int *stack;
    int top;
    int size;

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
            return true;
        }
    }

    int pop() {
        if (isEmpty()) {
            return -1;
        } else {
            int x = stack[top];
            top = top - 1;
            return x;
        }
    }

    int peek() {
        if (isEmpty()) {
            return -1;
        } else {
            return stack[top];
        }
    }

    void display() {
        cout << "Stack: ";
        if (isEmpty()) {
            cout << "Empty";
            return;
        } else {
            for (int i = 0; i <= top; i++) {
                cout << stack[i] << " ";
            }
            cout << '\n';
        }
    }

    bool operator==(Stack &__stack) {
        if (this->top != __stack.top) {
            return false;
        } else {
            int top1 = this->top;
            int top2 = __stack.top;
            while (!isEmpty()) {
                if (this->pop() == __stack.pop()) {
                    continue;
                } else {
                    this->top = top1;
                    __stack.top = top2;
                    return false;
                }
            }
            this->top = top1;
            __stack.top = top2;
            return true;
        }
    }

    ~Stack() {
        delete[] stack;
    }
};

int main(int argc, char const *argv[]) {
    Stack stack1(3), stack2(3);
    stack1.push(1);
    stack1.push(2);
    stack1.push(3);
    stack2.push(1);
    stack2.push(2);
    stack2.push(3);
    if (stack1 == stack2) {
        cout << "STACKS ARE EQUAL\n";
    } else {
        cout << "STACKS ARE NOT EQUAL\n";
    }
    return 0;
}