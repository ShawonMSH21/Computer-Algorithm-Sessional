#include <iostream>
using namespace std;

int main() {
    int size1, size2;
    cout << "Enter size of first array: ";
    cin >> size1;
    int arr1[size1];
    cout << "Enter elements of first array:\n";
    for (int i = 0; i < size1; i++) {
        cin >> arr1[i];
    }

    cout << "Enter size of second array: ";
    cin >> size2;
    int arr2[size2];
    cout << "Enter elements of second array:\n";
    for (int i = 0; i < size2; i++) {
        cin >> arr2[i];
    }

    int merged[size1 + size2];
    for (int i = 0; i < size1; i++) {
        merged[i] = arr1[i];
    }
    for (int i = 0; i < size2; i++) {
        merged[size1 + i] = arr2[i];
    }

    cout << "Merged Array: ";
    for (int i = 0; i < size1 + size2; i++) {
        cout << merged[i] << " ";
    }
    cout << endl;

    return 0;
}
