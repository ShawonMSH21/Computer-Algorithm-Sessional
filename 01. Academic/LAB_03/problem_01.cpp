#include <iostream>
using namespace std;

void arrayLeader(int arr[], int Size) {
    int leaders[Size];
    int l_count = 0;
    int maxRight = arr[Size - 1];
    leaders[l_count++] = maxRight;

    for (int i = Size - 2; i >= 0; i--) {
        if (arr[i] > maxRight) {
            maxRight = arr[i];
            leaders[l_count++] = maxRight;
        }
    }

    for (int i = l_count - 1; i >= 0; i--) {
        cout << leaders[i] << " ";
    }
}

int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;
    int a[n];
    cout << "Enter array elements: ";
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    cout << "Leader of an Array: ";
    arrayLeader(a, n);
    cout << "\n";
    return 0;
}
