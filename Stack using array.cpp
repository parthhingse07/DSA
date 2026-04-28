
#include<iostream>
using namespace std;

int sizeLimit;
int *arr;
int topPos = -1;

bool fullCheck()
{
    return topPos == sizeLimit - 1;
}

bool emptyCheck()
{
    return topPos == -1;
}

void insertItem(int num)
{
    if(fullCheck())
    {
        cout << "\n[!] Stack Overflow! Cannot add " << num << endl;
    }
    else
    {
        arr[++topPos] = num;
        cout << "\n[+] " << num << " pushed to stack.\n";
    }
}

int deleteItem()
{
    if(emptyCheck())
    {
        cout << "\n[!] Stack Underflow! No elements to remove.\n";
        return -1;
    }
    else
    {
        return arr[topPos--];
    }
}

void topItem()
{
    if(emptyCheck())
    {
        cout << "\nStack is empty.\n";
    }
    else
    {
        cout << "\nTop element is: " << arr[topPos] << endl;
    }
}

int main()
{
    int ch, value;

    cout << "Enter maximum size of the stack: ";
    cin >> sizeLimit;

    if(sizeLimit <= 0)
    {
        cout << "Invalid size. Exiting...\n";
        return 1;
    }

    arr = new int[sizeLimit];

    while(true)
    {
        cout << "\n1. Push\n2. Pop\n3. Peek\n4. Check Empty/Full\n5. Exit\n";
        cout << "Enter your choice: ";
        cin >> ch;

        switch(ch)
        {
            case 1:
                cout << "Enter value to push: ";
                cin >> value;
                insertItem(value);
                break;

            case 2:
                value = deleteItem();
                if(value != -1)
                    cout << "Popped: " << value << endl;
                break;

            case 3:
                topItem();
                break;

            case 4:
                if(fullCheck())
                    cout << "Stack is Full.\n";
                else if(emptyCheck())
                    cout << "Stack is Empty.\n";
                else
                    cout << "Stack has space available ("
                         << topPos + 1 << "/" << sizeLimit << " used).\n";
                break;

            case 5:
                delete[] arr;
                cout << "Exiting...\n";
                return 0;

            default:
                cout << "Invalid choice! Try again.\n";
        }
    }

    return 0;
}

            
