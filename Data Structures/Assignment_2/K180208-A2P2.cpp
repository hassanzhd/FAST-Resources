#include <algorithm>
#include <fstream>
#include <iostream>
using namespace std;

class node {
   public:
    long long int data;
    node *next;

   public:
    node(long long int __data, node *__next = NULL) {
        data = __data;
        next = __next;
    }

    ~node() {}
};

class linkedList {
   private:
    node *head, *tail;

   public:
    linkedList() {
        head = tail = NULL;
    }

    void addToTail(long long int __value) {
        if (tail == NULL) {
            tail = head = new node(__value);
        } else {
            tail->next = new node(__value);
            tail = tail->next;
        }
    }

    void addToHead(long long int __value) {
        if (head == NULL) {
            head = tail = new node(__value);
        } else {
            head = new node(__value, head);
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
            for (temp = head; temp->next != tail; tail = tail->next)
                ;
            delete tail;
            tail = temp;
        }
    }

    void display() {
        cout << "Linked List: ";
        node *temp = head;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }

        cout << '\n';
    }

    void getFromFile() {
        ifstream inputFile;
        int numberOfElements;
        long long int number;

        inputFile.open("P2_input.txt");
        inputFile >> numberOfElements;
        for (int i = 0; i < numberOfElements; i++) {
            inputFile >> number;
            this->addToTail(number);
        }

        inputFile.close();
    }

    void longestPalindrome() {
        node *temp = head;
        string fullList = "";
        ofstream outputFile;
        long long int palindrome = 0;

        while (temp != NULL) {
            fullList += to_string(temp->data);  // long long int is converted into string using to_string()
            temp = temp->next;
        }

        for (int i = 0, j = 0; fullList[i] != '\0'; i++) {
            for (int j = 0; fullList[j] != '\0'; j++) {
                string temp = fullList.substr(i, j + 1);  // substr(i,n) gives a substring from ith position with length n
                reverse(temp.begin(), temp.end());        // reverse is a function that reverses string

                if (fullList.substr(i, j + 1).compare(temp) == 0 && stoll(fullList.substr(i, j + 1)) > palindrome) {
                    palindrome = stoll(fullList.substr(i, j + 1));  // stoll() converts string to long long int
                    continue;
                } else {
                    continue;
                }
            }
        }
        if (palindrome == 0) {
            cout << "NO PALINDROME FOUND.\n";
        } else {
            cout << "LONGEST POSSIBLE PALINDROME: " << palindrome << '\n';
        }

        outputFile.open("P2_output.txt");
        outputFile << palindrome;
        outputFile.close();
    }

    ~linkedList() {
        node *temp;
        while (head != NULL) {
            temp = head->next;
            delete head;
            head = temp;
        }
    }
};

int main(int argc, char const *argv[]) {
    linkedList l;
    l.getFromFile();        // input from file
    l.longestPalindrome();  // palindrome calculated
    return 0;
}