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

    int pop() {
        if (isEmpty()) {
            return -1;
        } else {
            int data = stack[top];
            top = top - 1;
            return data;
        }
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

    int peek() {
        if (isEmpty()) {
            return -1;
        }
        return stack[top];
    }

    void display() {
        cout << "Stack: ";
        if (isEmpty()) {
            cout << "Empty";
        } else {
            for (int i = 0; i <= top; i++) {
                cout << stack[i] << " ";
            }
            cout << '\n';
        }
    }

    void reverseStack(Stack &__stack) {
        while (!__stack.isEmpty()) {
            __stack.pop();
        }

        int recover = this->top;
        while (!this->isEmpty()) {
            int temp = this->pop();
            __stack.push(temp);
        }
        this->top = recover;
    }

    ~Stack() {
        delete[] stack;
    }
};

int main(int argc, char const *argv[]) {
    Stack stack1(5), stack2(5);
    stack1.push(1);
    stack1.push(2);
    stack1.push(3);
    stack1.push(4);
    stack1.push(5);
    stack1.reverseStack(stack2);
    stack1.display();
    stack2.display();
    return 0;
}