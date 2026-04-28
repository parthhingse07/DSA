#include<iostream>
using namespace std;

#define LIMIT 5

class LineQueue
{
private:
    int num[LIMIT];
    int first, last;

public:
    LineQueue()
    {
        first = -1;
        last = -1;
    }

    void insert(int value)
    {
        if(last == LIMIT - 1)
        {
            cout << "Queue Overflow\n";
            return;
        }

        if(first == -1)
            first = 0;

        num[++last] = value;
        cout << value << " inserted into queue\n";
    }

    void remove()
    {
        if(first == -1 || first > last)
        {
            cout << "Queue Underflow\n";
            return;
        }

        cout << num[first++] << " deleted from queue\n";
    }

    void show()
    {
        if(first == -1 || first > last)
        {
            cout << "Queue is Empty\n";
            return;
        }

        cout << "Queue elements: ";

        for(int i = first; i <= last; i++)
            cout << num[i] << " ";

        cout << endl;
    }
};

int main()
{
    LineQueue q;

    q.insert(10);
    q.insert(20);
    q.insert(30);
    q.show();

    q.remove();
    q.show();

    return 0;
}
