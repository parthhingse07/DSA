#include<iostream>
using namespace std;

struct Node {
    int value;
    Node* prev;
    Node* next;
};

class DoubleList {
    Node* start;

public:
    DoubleList() {
        start = NULL;
    }

    void addFront(int num) {
        Node* newNode = new Node();
        newNode->value = num;
        newNode->prev = NULL;
        newNode->next = start;

        if (start != NULL)
            start->prev = newNode;

        start = newNode;
    }

    void addRear(int num) {
        Node* newNode = new Node();
        newNode->value = num;
        newNode->next = NULL;

        if (start == NULL) {
            newNode->prev = NULL;
            start = newNode;
            return;
        }

        Node* move = start;
        while (move->next != NULL)
            move = move->next;

        move->next = newNode;
        newNode->prev = move;
    }

    void removeFront() {
        if (start == NULL) {
            cout << "List is empty\n";
            return;
        }

        Node* temp = start;
        start = start->next;

        if (start != NULL)
            start->prev = NULL;

        delete temp;
    }

    void removeRear() {
        if (start == NULL) {
            cout << "List is empty\n";
            return;
        }

        if (start->next == NULL) {
            delete start;
            start = NULL;
            return;
        }

        Node* move = start;
        while (move->next != NULL)
            move = move->next;

        move->prev->next = NULL;
        delete move;
    }

    void show() {
        Node* move = start;

        while (move != NULL) {
            cout << move->value << " <-> ";
            move = move->next;
        }

        cout << "NULL\n";
    }
};

int main() {
    DoubleList obj;

    obj.addFront(5);
    obj.addRear(15);
    obj.addRear(25);
    obj.show();

    obj.removeFront();
    obj.show();

    obj.removeRear();
    obj.show();

    return 0;
}
