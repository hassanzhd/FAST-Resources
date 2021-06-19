#include <fstream>
#include <iostream>
using namespace std;

class node {
   public:
    int data;
    node *left, *right;

    node() {
        data = 0;
        left = right = NULL;
    }

    node(int __data, node *__left = NULL, node *__right = NULL) {
        data = __data;
        left = __left;
        right = __right;
    }
};

class BST {
   private:
    node *root;

    node *insert(int __data, node *__root) {
        if (__root == NULL) {
            __root = new node(__data);
        } else if (__data < __root->data) {
            __root->left = insert(__data, __root->left);
        } else {
            __root->right = insert(__data, __root->right);
        }
        return (__root);
    }

    void preOrder(node *__root) {
        if (__root != NULL) {
            cout << __root->data << ' ';
            preOrder(__root->left);
            preOrder(__root->right);
        }
    }

    int height(node *__root) {
        if (__root == NULL) {
            return 0;
        } else {
            int left = height(__root->left);
            int right = height(__root->right);
            return 1 + max(left, right);
        }
    }

    int heightLeft(node *__root) {
        if (__root == NULL) return 0;
        return 1 + heightLeft(__root->left);
    }

    int heightRight(node *__root) {
        if (__root == NULL) return 0;
        return 1 + heightRight(__root->right);
    }

    void clear(node *__root) {
        if (__root != NULL) {
            clear(__root->left);
            clear(__root->right);
            delete __root;
            __root = NULL;
        }
    }

   public:
    BST() {
        root = NULL;
    }

    void insert(int __data) {
        this->root = this->insert(__data, this->root);
    }

    void preOrder() {
        cout << "PRE-ORDER TRAVERSAL: ";
        this->preOrder(this->root);
        cout << '\n';
    }

    void longestOrderSubsequence() {
        if (root == NULL) {
            return;
        }

        node *longestRoot = NULL;
        node *temp = this->root;
        string identifier = "";
        int length;

        while (temp != NULL) {
            int check = this->height(temp);
            int left = this->heightLeft(temp);
            int right = this->heightRight(temp);

            if (left == check) {
                longestRoot = temp;
                identifier = "left";
                break;
            } else if (right == check) {
                longestRoot = temp;
                identifier = "right";
                break;
            }

            if (this->height(temp->left) >= this->height(temp->right)) {
                temp = temp->left;
            } else {
                temp = temp->right;
            }
        }

        length = this->height(longestRoot);
        ofstream outputFile;
        outputFile.open("P1_output.txt");
        cout << "LENGTH OF LONGEST POSSIBLE SUB-SEQUENCE:" << ' ' << length << '\n';
        outputFile << length << '\n';
        cout << "LONGEST SUB-SEQUENCE: ";
        while (longestRoot != NULL) {
            cout << longestRoot->data << ' ';
            outputFile << longestRoot->data << '\n';
            if (identifier.compare("left") == 0) {
                longestRoot = longestRoot->left;
            } else {
                longestRoot = longestRoot->right;
            }
        }
        outputFile.close();
    }

    void getFromFile() {
        ifstream inputFile;
        inputFile.open("P1_input.txt");
        int value;
        while (inputFile >> value) {
            this->insert(value);
        }
        this->preOrder();
        inputFile.close();
    }

    ~BST() {
        this->clear(this->root);
    }
};

int main(int argc, char const *argv[]) {
    BST b;
    b.getFromFile();
    b.longestOrderSubsequence();
    return 0;
}
