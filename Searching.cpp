#include<iostream>
using namespace std;

int main()
{
    int size, key;

    cout << "Enter size: ";
    cin >> size;

    int num[size];

    cout << "Enter elements: ";
    for(int i = 0; i < size; i++)
        cin >> num[i];

    cout << "Enter element to search: ";
    cin >> key;

    int pos = -1;

    for(int i = 0; i < size; i++)
    {
        if(num[i] == key)
        {
            pos = i;
            break;
        }
    }

    if(pos != -1)
        cout << "Element present in index: " << pos;
    else
        cout << "Element not present";

    return 0;
}
