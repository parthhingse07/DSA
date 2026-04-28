
#include<iostream>
using namespace std;

struct Node {
    int value;
    Node* left;
    Node* right;
};

Node* makeNode(int num) {
    Node* temp = new Node();
    temp->value = num;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

void preOrder(Node* root) {
    if (root == NULL)
        return;

    cout << root->value << " ";
    preOrder(root->left);
    preOrder(root->right);
}

void inOrder(Node* root) {
    if (root == NULL)
        return;

    inOrder(root->left);
    cout << root->value << " ";
    inOrder(root->right);
}

void postOrder(Node* root) {
    if (root == NULL)
        return;

    postOrder(root->left);
    postOrder(root->right);
    cout << root->value << " ";
}

int main() {

    Node* root = makeNode(1);
    root->left = makeNode(2);
    root->right = makeNode(3);
    root->left->left = makeNode(4);
    root->left->right = makeNode(5);

    cout << "Preorder: ";
    preOrder(root);

    cout << "\nInorder: ";
    inOrder(root);

    cout << "\nPostorder: ";
    postOrder(root);

    return 0;
}
