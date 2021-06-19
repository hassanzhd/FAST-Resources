#include <iostream>
using namespace std;

class node {
   public:
    int data;
    node *right, *left;

   public:
    node() {
        data = 0;
        right = NULL;
        left = NULL;
    }

    node(int __data, node *__left = NULL, node *__right = NULL) {
        data = __data;
        left = __left;
        right = __left;
    }

    ~node() {}
};

class BST {
   public:
    node *root;

    node *insert(int __data, node *__root) {
        if (__root == NULL) {
            __root = new node(__data);
        } else if (__data < __root->data) {
            __root->left = insert(__data, __root->left);
        } else if (__data > __root->data) {
            __root->right = insert(__data, __root->right);
        }
        return __root;
    }

    node *maxElement(node *__root) {
        if (__root->right == NULL) {
            return __root;
        } else {
            return this->maxElement(__root->right);
        }
    }

    node *mergeDelete(int __data, node *__root) {
        if (__root == NULL) {
            return NULL;
        }
        if (__data < __root->data) {
            __root->left = this->mergeDelete(__data, __root->left);
        } else if (__data > __root->data) {
            __root->right = this->mergeDelete(__data, __root->right);
        }

        if (__root->data == __data) {
            if (__root->left == NULL && __root->right == NULL) {
                delete __root;
                __root = NULL;
            } else if (__root->left != NULL && __root->right != NULL) {
                node *temp = __root;
                __root = this->maxElement(__root->left);
                delete temp;
                temp = NULL;
                this->mergeDelete(__root->data, __root->left);
            } else {
                node *old = __root;
                if (old->left != NULL) {
                    __root = old->left;
                } else if (old->right != NULL) {
                    __root = old->right;
                }
                delete old;
                old = NULL;
            }
        }
        return __root;
    }

   public:
    BST() {
        root = NULL;
    }

    // void insert(int __x) {
    //     if (root == NULL) {
    //         root = new node(__x);
    //     } else if (__x < root->data) {
    //         node *temp = root->left;
    //         node *pre = root;
    //         while (temp != NULL) {
    //             if (__x < temp->data) {
    //                 pre = temp;
    //                 temp = temp->left;
    //                 continue;
    //             } else {
    //                 pre = temp;
    //                 temp = temp->right;
    //                 continue;
    //             }
    //         }

    //         if (__x < pre->data) {
    //             pre->left = new node(__x);
    //         } else {
    //             pre->right = new node(__x);
    //         }

    //     } else if (__x > root->data) {
    //         node *temp = root->right;
    //         node *pre = root;
    //         while (temp != NULL) {
    //             if (__x > temp->data) {
    //                 pre = temp;
    //                 temp = temp->right;
    //                 continue;
    //             } else {
    //                 pre = temp;
    //                 temp = temp->left;
    //                 continue;
    //             }
    //         }

    //         if (__x < pre->data) {
    //             pre->left = new node(__x);
    //         } else {
    //             pre->right = new node(__x);
    //         }
    //     }
    // }

    void insert(int __data) {
        this->root = this->insert(__data, this->root);
    }

    void mergeDelete(int __x) {
        this->root = this->mergeDelete(__x, this->root);
    }

    void clear(node *__root = NULL) {
        if (__root != NULL) {
            clear(__root->left);
            clear(__root->right);
            delete __root;
            __root = NULL;
        }
    }

    void inorder(node *temp) {
        if (temp != NULL) {
            cout << temp->data << '\n';
            inorder(temp->left);
            inorder(temp->right);
        }
    }

    ~BST() {
        clear(root);
        root = NULL;
    }
};

int main(int argc, char const *argv[]) {
    BST tree;
    tree.insert(5);
    tree.insert(2);
    tree.insert(7);
    tree.insert(10);
    tree.insert(15);
    tree.insert(1);
    tree.insert(3);
    tree.mergeDelete(10);
    tree.inorder(tree.root);
    return 0;
}