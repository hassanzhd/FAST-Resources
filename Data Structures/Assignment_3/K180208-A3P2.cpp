#include <fstream>
#include <iostream>
#include <queue>
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

class BTree {
   private:
    node *root;
    int numOfNodes;
    int sum;

    void preOrder(node *__root) {
        if (__root != NULL) {
            cout << __root->data << ' ';
            preOrder(__root->left);
            preOrder(__root->right);
        }
    }

    void clear(node *__root) {
        if (__root != NULL) {
            clear(__root->left);
            clear(__root->right);
            delete __root;
            __root = NULL;
        }
    }

    void putToFile(node *__root, int __traversals, ofstream &__outputFile) {
        queue<node *> q;
        q.push(__root);

        while (__traversals > 0) {
            int count = q.size();

            while (count > 0) {
                node *temp = q.front();
                __outputFile << temp->data << '\n';
                q.pop();
                if (temp->left != NULL) {
                    q.push(temp->left);
                }
                if (temp->right != NULL) {
                    q.push(temp->right);
                }
                count--;
            }
            __traversals--;
        }
    }

    int sumOfTree(node *__root) {
        if (__root == NULL) {
            return 0;
        } else {
            return __root->data + sumOfTree(__root->left) + sumOfTree(__root->right);
        }
    }

    bool calcBST(node *__root, int __minimum, int __maximum) {
        if (__root == NULL) {
            return true;
        }
        if (__root->data > __minimum && __root->data < __maximum && calcBST(__root->left, __minimum, __root->data) && calcBST(__root->right, __root->data, __maximum)) {
            return true;
        } else {
            return false;
        }
    }

   public:
    BTree() {
        root = NULL;
    }

    void insert(int __data) {
        if (root == NULL) {
            root = new node(__data);
        } else {
            queue<node *> q;
            q.push(root);
            while (!q.empty()) {
                node *add = q.front();
                q.pop();

                if (add->left == NULL) {
                    add->left = new node(__data);
                    break;
                } else {
                    q.push(add->left);
                }

                if (add->right == NULL) {
                    add->right = new node(__data);
                    break;
                } else {
                    q.push(add->right);
                }
            }
        }
    }

    void preOrder() {
        this->preOrder(root);
    }

    void getFromFile() {
        ifstream inputFile;
        inputFile.open("P2_input.txt");
        int value;

        inputFile >> numOfNodes;
        inputFile >> sum;

        while (inputFile >> value) {
            this->insert(value);
        }
        inputFile.close();
        this->preOrder();
        ofstream o("P2_output.txt");
        this->putToFile(this->root, 3, o);
        o.close();
    }

    int sumOfTree() {
        return this->sumOfTree(root);
    }

    bool calcBST() {
        return calcBST(root, INT16_MIN, INT16_MAX);
    }

    void binarySubTree() {
        if (root == NULL) {
            return;
        }

        ofstream outputFile;
        outputFile.open("P2_output.txt");

        queue<node *> q;
        q.push(root);
        BTree temporary;
        temporary.insert(q.front()->data);
        int traversal = 1;

        while (!q.empty()) {
            node *temp = q.front();

            if (temp->left != NULL) {
                temporary.insert(temp->left->data);
            }

            if (temp->right != NULL) {
                temporary.insert(temp->right->data);
            }

            if (this->calcBST(temporary.root, INT16_MIN, INT16_MAX) == true) {
                if (this->sumOfTree(temporary.root) == this->sum) {
                    traversal++;
                    this->putToFile(temporary.root, traversal, outputFile);
                    outputFile.close();
                    return;
                } else {
                    q.pop();
                    if (temp->left != NULL) {
                        q.push(temp->left);
                    }
                    if (temp->right != NULL) {
                        q.push(temp->right);
                    }
                    traversal++;
                }
            } else {
                q.pop();
                if (temp->left != NULL) {
                    q.push(temp->left);
                }
                temporary.clear(temporary.root);
                temporary.root = NULL;
                temporary.insert(q.front()->data);
                traversal = 1;
            }
        }

        q.push(root->left);
        temporary.clear(temporary.root);
        temporary.root = NULL;
        temporary.insert(q.front()->data);
        traversal = 1;

        while (!q.empty()) {
            node *temp = q.front();

            if (temp->left != NULL) {
                temporary.insert(temp->left->data);
            }

            if (temp->right != NULL) {
                temporary.insert(temp->right->data);
            }

            if (this->calcBST(temporary.root, INT16_MIN, INT16_MAX) == true) {
                if (this->sumOfTree(temporary.root) == this->sum) {
                    traversal++;
                    this->putToFile(temporary.root, traversal, outputFile);
                    outputFile.close();
                    return;
                } else {
                    q.pop();
                    if (temp->left != NULL) {
                        q.push(temp->left);
                    }
                    if (temp->right != NULL) {
                        q.push(temp->right);
                    }
                    traversal++;
                }
            } else {
                q.pop();
                if (temp->left != NULL) {
                    q.push(temp->left);
                }
                temporary.clear(temporary.root);
                temporary.root = NULL;
                temporary.insert(q.front()->data);
                traversal = 1;
            }
        }

        q.push(root->right);
        temporary.clear(temporary.root);
        temporary.root = NULL;
        temporary.insert(q.front()->data);
        traversal = 1;

        while (!q.empty()) {
            node *temp = q.front();

            if (temp->left != NULL) {
                temporary.insert(temp->left->data);
            }

            if (temp->right != NULL) {
                temporary.insert(temp->right->data);
            }

            if (this->calcBST(temporary.root, INT16_MIN, INT16_MAX) == true) {
                if (this->sumOfTree(temporary.root) == this->sum) {
                    traversal++;
                    this->putToFile(temporary.root, traversal, outputFile);
                    outputFile.close();
                    return;
                } else {
                    q.pop();
                    if (temp->left != NULL) {
                        q.push(temp->left);
                    }
                    if (temp->right != NULL) {
                        q.push(temp->right);
                    }
                    traversal++;
                }
            } else {
                q.pop();
                if (temp->right != NULL) {
                    q.push(temp->right);
                }
                temporary.clear(temporary.root);
                temporary.root = NULL;
                temporary.insert(q.front()->data);
                traversal = 1;
            }
        }

        outputFile << "NO POSSIBLE COMBINATIONS.";
        outputFile.close();
    }

    ~BTree() {
        this->clear(root);
    }
};

int main(int argc, char const *argv[]) {
    BTree b;
    b.getFromFile();
    b.binarySubTree();
    return 0;
}