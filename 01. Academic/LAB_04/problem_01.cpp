#include <iostream>
#include <cmath>
using namespace std;

void Merge(int arr[], int p, int q, int r) {
    int n1 = q - p + 1;
    int n2 = r - q;
    int L[n1], R[n2];

    for (int i = 0; i < n1; i++) {
        L[i] = arr[p + i];
    }
    for (int j = 0; j < n2; j++) {
        R[j] = arr[q + 1 + j];
    }

    int i = 0, j = 0, k = p;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k++] = L[i++];
        } else {
            arr[k++] = R[j++];
        }
    }

    while (i < n1) {
        arr[k++] = L[i++];
    }

    while (j < n2) {
        arr[k++] = R[j++];
    }
}

void Merge_sort(int a[], int p, int r) {
    if (p < r) {
        int q = floor((p + r) / 2);
        Merge_sort(a, p, q);
        Merge_sort(a, q + 1, r);
        Merge(a, p, q, r);
    }
}

int main() {
    int n;
    cout << "Enter the number of elements of the array: ";
    cin >> n;

    int A[n];
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    Merge_sort(A, 0, n - 1);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << A[i] << " ";
    }
    cout << "\n";

    return 0;
}
