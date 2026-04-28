#include <iostream>
using namespace std;
int main() 
{
int n, m;
cout << "Enter size: ";
cin >> n;
int arr[n];
cout << "Enter elements: ";
for(int i = 0; i < n; i++) 
cin >> arr[i];
cout << "Enter element to search: ";
cin >> m;
int found = -1;
for(int i = 0; i < n; i++) 
{
if(arr[i] == m) 
{
found = i;
break;
}
}
if(found != -1)
cout << "Element present in index: " << found;
else
cout << "Element not present";
return 0;
}

