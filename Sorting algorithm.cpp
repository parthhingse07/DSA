#include<iostream>
using namespace std;

void display(int *x, int size)
{
    for(int i = 0; i < size; i++)
        cout << x[i] << " ";

    cout << endl;
}

void bubbleSort(int *x, int size)
{
    for(int i = 0; i < size - 1; i++)
        for(int j = 0; j < size - i - 1; j++)
            if(x[j] > x[j + 1])
                swap(x[j], x[j + 1]);
}

void selectSort(int *x, int size)
{
    for(int i = 0; i < size - 1; i++)
    {
        int small = i;

        for(int j = i + 1; j < size; j++)
            if(x[j] < x[small])
                small = j;

        swap(x[i], x[small]);
    }
}

void insertSort(int *x, int size)
{
    for(int i = 1; i < size; i++)
    {
        int item = x[i];
        int j = i - 1;

        while(j >= 0 && x[j] > item)
        {
            x[j + 1] = x[j];
            j--;
        }

        x[j + 1] = item;
    }
}

int divide(int *x, int low, int high)
{
    int pivot = x[low];
    int i = low + 1;
    int j = high;

    while(i <= j)
    {
        while(i <= high && x[i] <= pivot)
            i++;

        while(x[j] > pivot)
            j--;

        if(i < j)
            swap(x[i], x[j]);
    }

    swap(x[low], x[j]);
    return j;
}

void quick(int *x, int low, int high)
{
    if(low < high)
    {
        int pos = divide(x, low, high);

        quick(x, low, pos - 1);
        quick(x, pos + 1, high);
    }
}

int main()
{
    int n, ch;

    cout << "Enter number of elements: ";
    cin >> n;

    int *arr = new int[n];

    cout << "Enter elements:\n";
    for(int i = 0; i < n; i++)
        cin >> arr[i];

    cout << "\n--- Sorting Menu ---\n";
    cout << "1. Bubble Sort\n";
    cout << "2. Selection Sort\n";
    cout << "3. Insertion Sort\n";
    cout << "4. Quick Sort\n";
    cout << "Enter choice: ";
    cin >> ch;

    switch(ch)
    {
        case 1:
            bubbleSort(arr, n);
            break;

        case 2:
            selectSort(arr, n);
            break;

        case 3:
            insertSort(arr, n);
            break;

        case 4:
            quick(arr, 0, n - 1);
            break;

        default:
            cout << "Invalid choice";
            delete[] arr;
            return 0;
    }

    cout << "Sorted array:\n";
    display(arr, n);

    delete[] arr;
    return 0;
}
