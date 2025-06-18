#include <iostream>
#include <conio.h>
#include <stdlib.h>

using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;
};

void insert(Node **root, int newData){
    if (*root == nullptr){
        Node *newNode = new Node;
        newNode->data = newData;
        newNode->left = nullptr;
        newNode->right = nullptr;
        *root = newNode;

        cout << "Data has been added\n";
    }
    else if (newData < (*root)->data){
        insert(&((*root)->left), newData);
    }
    else if (newData > (*root)->data){
        insert(&((*root)->right), newData);
    }
    else {
        cout << "Data already exists\n";
    }
}

void preOrder(Node *root){
    if (root != nullptr){
        cout << root->data << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
}

void inOrder(Node *root){
    if (root != nullptr){
        inOrder(root->left);
        cout << root->data << " ";
        inOrder(root->right);
    }
}

void postOrder(Node *root){
    if (root != nullptr){
        postOrder(root->left);
        postOrder(root->right);
        cout << root->data << " ";
    }
}

void clearTree(Node *root){
    if (root != nullptr){
        clearTree(root->left);
        clearTree(root->right);
        delete root;
    }
}

int main(){
    int opt, val;
    Node *tree = nullptr;

    do {
        system("cls");

        cout << "1. Insert\n";
        cout << "2. PreOrder\n";
        cout << "3. InOrder\n";
        cout << "4. PostOrder\n";
        cout << "5. Clear Tree\n";
        cout << "6. Exit\n";

        cout << "\nOption: ";
        cin >> opt;

        switch (opt) {
            case 1:
                cout << "\nInput:\n------\nNew data: ";
                cin >> val;
                insert(&tree, val);
                break;

            case 2:
                cout << "PreOrder Traversal\n==========================\n";
                if (tree == nullptr) {
                    cout << "Tree is empty!\n";
                } else {
                    preOrder(tree);
                    cout << endl;
                }
                break;

            case 3:
                cout << "InOrder Traversal\n==========================\n";
                if (tree == nullptr) {
                    cout << "Tree is empty!\n";
                } else {
                    inOrder(tree);
                    cout << endl;
                }
                break;

            case 4:
                cout << "PostOrder Traversal\n==========================\n";
                if (tree == nullptr) {
                    cout << "Tree is empty!\n";
                } else {
                    postOrder(tree);
                    cout << endl;
                }
                break;

            case 5:
                clearTree(tree);
                tree = nullptr;
                cout << "Tree has been cleared.\n";
                break;    

            case 6:
                return 0;

            default:
                cout << "Option is not valid! Please re-enter your option\n";
                break;
        }

        getch();
    } while(opt != 6);

    return 0;
}