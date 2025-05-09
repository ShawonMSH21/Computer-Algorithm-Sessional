#include <iostream>
using namespace std;

int main() {
    int testCases;
    cout << "Enter number of test cases: ";
    cin >> testCases;

    while (testCases--) {
        int arraySize;
        cout << "\nEnter the size of the array: ";
        cin >> arraySize;

        int numbers[100];
        cout << "Enter the elements of the array: ";
        for (int i = 0; i < arraySize; i++) {
            cin >> numbers[i];
        }

        int minValue = numbers[0];
        for (int i = 1; i < arraySize; i++) {
            if (numbers[i] < minValue) {
                minValue = numbers[i];
            }
        }

        int operationsNeeded = 0;
        for (int i = 0; i < arraySize; i++) {
            if (numbers[i] > minValue) {
                operationsNeeded++;
            }
        }

        cout << "Minimum operations needed to make " << minValue << " the maximum: " << operationsNeeded << endl;
    }

    return 0;
}
