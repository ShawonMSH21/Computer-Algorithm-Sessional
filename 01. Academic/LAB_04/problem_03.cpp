#include <iostream>
using namespace std;

int linear_search(int item, int arr[], int n) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == item) {
            cout << "Item found at index " << i << "\n";
            return i;
        }
    }
    cout << "Item not found\n";
    return -1;
}

int main() {
    int n;
    cin >> n;

    int A[n];
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    int item;
    cin >> item;

    linear_search(item, A, n);
    return 0;
}
