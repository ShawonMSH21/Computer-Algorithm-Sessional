#include <iostream>
using namespace std;

int subArray(int arr[], int Size) {
    int max_global = arr[0];
    int max_current = arr[0];

    for (int i = 1; i < Size; i++) {
        max_current = max(arr[i], max_current + arr[i]);
        if (max_current > max_global) {
            max_global = max_current;
        }
    }

    return max_global;
}

int main() {
    int t;
    cout << "Enter test cases: ";
    cin >> t;

    while (t--) {
        int n;
        cout << "Enter the size of the array: ";
        cin >> n;
        int a[n];
        cout << "Enter array elements: ";
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        int max_sum = subArray(a, n);
        cout << max_sum << "\n";
    }

    return 0;
}
