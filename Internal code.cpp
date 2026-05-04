#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* next;
};

// Create circular linked list
Node* createList(int n) {
    Node *head = NULL, *temp = NULL, *newNode;

    for (int i = 0; i < n; i++) {
        newNode = new Node;
        cout << "Enter data: ";
        cin >> newNode->data;

        if (head == NULL) {
            head = newNode;
            newNode->next = head; // first node points to itself
            temp = head;
        } else {
            temp->next = newNode;
            newNode->next = head; // last node points to head
            temp = newNode;
        }
    }
    return head;
}

// Display circular linked list
void display(Node* head) {
    if (head == NULL) {
        cout << "List is empty";
        return;
    }

    Node* temp = head;

    cout << "Circular Linked List: ";

    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp
