#include <cstring>
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

/* input format: -2X^6+3X^3+4X^0=0
                +5X^6+1X^2+1X^1-4X^0=0            */
/* output format (i): +3X^6+3X^3+1X^2+1X^1=0
                (ii): +18X^5+9X^2+2X^1+1X^0=0     */

class node {
   public:
    int coefficient;
    char base;
    int exponent;
    node *next;

    node() {
        coefficient = 0;
        base = 'X';
        exponent = 0;
        next = NULL;
    }

    node(int __coefficient, char __base, int __exponent, node *__next = NULL) {
        coefficient = __coefficient;
        base = __base;
        exponent = __exponent;
        next = __next;
    }

    ~node() {}
};

class list {
   private:
    node *head, *tail;

   public:
    list() {
        head = tail = NULL;
    }

    list(const list &__copy) {
        head = tail = NULL;
        node *temp = __copy.head;
        while (temp != NULL) {
            this->addToTail(temp->coefficient, temp->base, temp->exponent);
            temp = temp->next;
        }
    }

    void addToHead(int __coefficient, char __base, int __exponent) {
        if (head == NULL) {
            head = tail = new node(__coefficient, __base, __exponent);
        } else {
            head = new node(__coefficient, __base, __exponent, head);
        }
    }

    void addToTail(int __coefficient, char __base, int __exponent) {
        if (tail == NULL) {
            tail = head = new node(__coefficient, __base, __exponent);
        } else {
            tail->next = new node(__coefficient, __base, __exponent);
            tail = tail->next;
        }
    }

    void deleteFromHead() {
        if (head == NULL) {
            return;
        } else {
            node *temp = head->next;
            delete head;
            head = temp;
        }
    }

    void deleteFromTail() {
        if (tail == NULL) {
            return;
        } else {
            node *temp;
            for (temp = head; temp->next != NULL; temp = temp->next)
                ;
            delete tail;
            tail = temp;
            tail->next = NULL;
        }
    }

    void display() {
        node *temp = head;
        while (temp != NULL) {
            if (temp->coefficient == 0) {
                temp = temp->next;
                continue;
            } else if (temp->coefficient == 1) {
                cout << '+' << temp->coefficient << temp->base << "^" << temp->exponent;
            } else if (temp->coefficient > 1) {
                cout << '+' << temp->coefficient << temp->base << "^" << temp->exponent;
            } else {
                cout << temp->coefficient << temp->base << "^" << temp->exponent;
            }
            temp = temp->next;
        }
        cout << "=0\n";
    }

    ~list() {
        node *temp;
        while (head != NULL) {
            temp = head->next;
            delete head;
            head = temp;
        }
    }
    friend list operator+(list &, list &);
    friend void putToFile(list &, string);
    friend void derivativeCalculate();
};

void getFromFile(list &__list, string __path) {
    ifstream inputFile;
    inputFile.open(__path);

    while (1) {
        int coefficient;
        char base;
        int exponent;
        char sign;

        inputFile >> sign;

        if (sign == '=') {
            continue;
        } else if (sign == '0') {
            break;  // end of line
        } else if (sign == '-') {
            inputFile >> coefficient;
            coefficient = -(coefficient);
            inputFile >> base;
            inputFile >> sign;
            inputFile >> exponent;
            __list.addToTail(coefficient, base, exponent);  // input of single negative polynomial
        } else {
            inputFile >> coefficient;
            inputFile >> base;
            inputFile >> sign;
            inputFile >> exponent;
            __list.addToTail(coefficient, base, exponent);  // input of single positive polynomial
        }
    }
}  // function for input from file part(ii)

void getFromFile(list &__firstList, list &__secondList, string __path) {
    ifstream inputFile;
    inputFile.open(__path);

    while (1) {
        int coefficient;
        char base;
        int exponent;
        char sign;

        inputFile >> sign;

        if (sign == '=') {
            continue;
        } else if (sign == '0') {
            break;  // end of line
        } else if (sign == '-') {
            inputFile >> coefficient;
            coefficient = -(coefficient);
            inputFile >> base;
            inputFile >> sign;
            inputFile >> exponent;
            __firstList.addToTail(coefficient, base, exponent);  // input of single negative polynomial
        } else {
            inputFile >> coefficient;
            inputFile >> base;
            inputFile >> sign;
            inputFile >> exponent;
            __firstList.addToTail(coefficient, base, exponent);  // input of single positive polynomial
        }
    }

    while (1) {
        int coefficient;
        char base;
        int exponent;
        char sign;

        inputFile >> sign;

        if (sign == '=') {
            continue;
        } else if (sign == '0') {
            break;  // end of line
        } else if (sign == '-') {
            inputFile >> coefficient;
            coefficient = -(coefficient);
            inputFile >> base;
            inputFile >> sign;
            inputFile >> exponent;
            __secondList.addToTail(coefficient, base, exponent);  // input of single negative polynomial
        } else {
            inputFile >> coefficient;
            inputFile >> base;
            inputFile >> sign;
            inputFile >> exponent;
            __secondList.addToTail(coefficient, base, exponent);  // input of single positive polynomial
        }
    }
}  // function for input from file part(i)

void putToFile(list &__resultantList, string __path) {
    ofstream outputFile;
    outputFile.open(__path);
    node *temp = __resultantList.head;

    while (temp != NULL) {
        if (temp->coefficient == 0) {
            temp = temp->next;
            continue;
        } else if (temp->coefficient == 1) {
            outputFile << '+' << temp->coefficient << temp->base << "^" << temp->exponent;
        } else if (temp->coefficient > 1) {
            outputFile << '+' << temp->coefficient << temp->base << "^" << temp->exponent;
        } else {
            outputFile << temp->coefficient << temp->base << "^" << temp->exponent;
        }
        temp = temp->next;
    }
    outputFile << "=0\n";
    outputFile.close();
}  // function for output file

list operator+(list &__list1, list &__list2) {
    list resultantList;
    node *temp = __list1.head;
    node *temp2 = __list2.head;
    while (temp != NULL && temp2 != NULL) {
        if (temp->exponent == temp2->exponent) {
            int a = temp->coefficient + temp2->coefficient;
            resultantList.addToTail(a, temp->base, temp->exponent);
            temp = temp->next;
            temp2 = temp2->next;
        } else if (temp->exponent > temp2->exponent) {
            resultantList.addToTail(temp->coefficient, temp->base, temp->exponent);
            temp = temp->next;
        } else if (temp->exponent < temp2->exponent) {
            resultantList.addToTail(temp2->coefficient, temp2->base, temp2->exponent);
            temp2 = temp2->next;
        }
    }

    return resultantList;
}  // overloaded '+' operator to sum two linkedlists

void derivativeCalculate() {
    list derivativeList;
    getFromFile(derivativeList, "P1_output1.txt");  // input from output of part(i)

    node *temp = derivativeList.head;
    while (temp != NULL) {
        if (temp->coefficient == 0) {
            temp->coefficient = temp->coefficient * temp->exponent;
            temp->exponent = 0;
        } else {
            temp->coefficient = temp->coefficient * temp->exponent;
            temp->exponent = temp->exponent - 1;
        }
        temp = temp->next;
    }
    derivativeList.display();
    putToFile(derivativeList, "P1_output2.txt");  // output to file for derivativelist of part(ii)
}

int main(int argc, char const *argv[]) {
    list l1, l2;
    getFromFile(l1, l2, "P1_input.txt");  // input from file for addition of lists
    l1.display();
    l2.display();
    list l3 = l1 + l2;  // l1 and l2 added by overloaded operators
    l3.display();
    putToFile(l3, "P1_output1.txt");  // output to file for resultant linked list of part(i)
    derivativeCalculate();            // function for calculation of derivative part(ii)
    return 0;
}