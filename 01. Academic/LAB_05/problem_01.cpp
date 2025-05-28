#include<iostream>
using namespace std;
int main()
{
    int n;
    cout << "Enter the number of the elements: ";
    cin >> n;
    int a[n];
    cout << "Enter the elements: ";
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int item;
    cout << "Enter the Item: ";
    cin >> item;
    int b = 0;
    int e = n - 1;
    int mid = (b + e) / 2;
    int loc;
    while(b <= e && a[mid] != item)
    {
        if(item < a[mid])
        {
            e = mid - 1;
        }
        else
        {
            b = mid + 1;
        }
        mid = (b + e) / 2;
    }
    if(a[mid] == item)
    {
        loc = mid;
        cout << "Item found in location " << loc;
    }
    else
    {
        loc = NULL;
        cout << "Item not found in any location.";
    }
    return 0;
}
