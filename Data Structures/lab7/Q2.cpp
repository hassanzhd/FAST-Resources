#include <iostream>
using namespace std;

class Stack {
   private:
    char *stack;
    int top;
    int size;

   public:
    Stack(int __size) {
        size = __size;
        stack = new char[size]{'\0'};
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

    char peek() {
        if (isEmpty()) {
            return '\0';
        }
        return stack[top];
    }

    bool push(char __value) {
        if (isFull()) {
            return false;
        } else {
            top = top + 1;
            stack[top] = __value;
        }
        return true;
    }

    char pop() {
        if (isEmpty()) {
            return '\0';
        } else {
            char data = stack[top];
            top = top - 1;
            return data;
        }
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

    ~Stack() {
        delete[] stack;
    }
    friend void matchCheck(string);
};

void matchCheck(string __expression) {
    Stack stack(10);
    cout << "Expression: " << __expression << " "
         << "is: ";
    for (int i = 0; __expression[i] != '\0'; i++) {
        if (__expression[i] == '(' || __expression[i] == '{' || __expression[i] == '[') {
            stack.push(__expression[i]);
        }

        switch (__expression[i]) {
            case ')': {
                if (stack.isEmpty() || stack.peek() != '(') {
                    cout << "UNBALANCED";
                    return;
                }
                stack.pop();
                break;
            }

            case '}': {
                if (stack.isEmpty() || stack.peek() != '{') {
                    cout << "UNBALANCED";
                    return;
                }
                stack.pop();
                break;
            }

            case ']': {
                if (stack.isEmpty() || stack.peek() != '[') {
                    cout << "UNBALANCED";
                    return;
                }
                stack.pop();
                break;
            }

            default:
                break;
        }
    }

    if (stack.top == -1) {
        cout << "BALANCED\n";
    } else {
        cout << "UNBALANCED\n";
    }
}

int main(int argc, char const *argv[]) {
    matchCheck("(1 * 2) + [4 + 5]");
    matchCheck("5 + {(13 + 7) / 8 - 2 * 9");
    return 0;
}