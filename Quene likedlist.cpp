
#include<iostream>
using namespace std;

struct Node {
    int value;
    Node* next;
};

class LineQueue {
    Node *first, *last;

public:
    LineQueue() {
        first = last = NULL;
    }

    void insert(int num) {
        Node* newNode = new Node();
        newNode->value = num;
        newNode->next = NULL;

        if (last == NULL) {
            first = last = newNode;
        } else {
            last->next = newNode;
            last = newNode;
        }

        cout << num << " inserted\n";
    }

    void remove() {
        if (first == NULL) {
            cout << "Queue Underflow\n";
            return;
        }

        Node* temp = first;
        cout << temp->value << " deleted\n";
        first = first->next;

        if (first == NULL)
            last = NULL;

        delete temp;
    }

    void show() {
        if (first == NULL) {
            cout << "Queue is empty\n";
            return;
        }

        Node* temp = first;
        cout << "Queue elements: ";

        while (temp != NULL) {
            cout << temp->value << " ";
            temp = temp->next;
        }

        cout << endl;
    }
};

int main() {
    LineQueue q;

    q.insert(5);
    q.insert(15);
    q.insert(25);
    q.show();

    q.remove();
    q.show();

    return 0;
}
```
