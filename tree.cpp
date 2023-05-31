#include <iostream>
using namespace std;
#include<conio.h>

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* createNode(int value) {
    Node* n = new Node;
    n->data = value;
    n->left = nullptr;
    n->right = nullptr;
    return n;
}

void insert(Node *&root, int value) {
    if (root == nullptr) {
        root = createNode(value);
        return;
    }
    if (value < root->data) {
        insert(root->left, value);
    }
    else {
        insert(root->right, value);
    }
}

void traversePreorder(Node* root) {
    if (root != nullptr) {
        cout << root->data << " ";
        traversePreorder(root->left);
        traversePreorder(root->right);
    }
}

void traverseInorder(Node* root) {
    if (root != nullptr) {
        traverseInorder(root->left);
        cout << root->data << " ";
        traverseInorder(root->right);
    }
}

void traversePostorder(Node* root) {
    if (root != nullptr) {
        traversePostorder(root->left);
        traversePostorder(root->right);
        cout << root->data << " ";
    }
}

Node* findMin(Node* root) {
    while (root->left != nullptr) {
        root = root->left;
    }
    return root;
}

Node* deleteNode(Node*& root, int value) {
    if (root == nullptr) {
        return root;
    }
    if (value < root->data) {
        root->left = deleteNode(root->left, value);
    }
    else if (value > root->data) {
        root->right = deleteNode(root->right, value);
    }
    else {
        if (root->left == nullptr) {
            Node* temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == nullptr) {
            Node* temp = root->left;
            delete root;
            return temp;
        }
        Node* temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

int main() {
    Node* root = nullptr;
    char choice;
    int value;
    do {
        cout << "'c': Create Binary Tree" << endl;
        cout << "'p': Traverse in Preorder" << endl;
        cout << "'i': Traverse in Inorder" << endl;
        cout << "'o': Traverse in Postorder" << endl;
        cout << "'d': Delete a Node in Binary Tree" << endl;
        cout << "'e': Exit" << endl;
        cout << "Enter Choice: ";
        cin >> choice;
        switch (choice) {
            case 'c': {
                cout << "Enter Node Value: ";
                cin >> value;
                insert(root, value);
                break;
            }
            case 'p': {
                traversePreorder(root);
                cout << endl;
                break;
            }
            case 'i': {
                traverseInorder(root);
                cout << endl;
                break;
            }
            case 'o': {
                traversePostorder(root);
                cout << endl;
                break;
            }
            case 'd': {
                cout << "Enter Value to Delete: ";
                cin >> value;
                root = deleteNode(root, value);
                break;
            }
        }
    } while (choice != 'e');
    return 0;
}