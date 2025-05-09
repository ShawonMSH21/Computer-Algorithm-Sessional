#include <iostream>
using namespace std;

int main() {
    int testCases;
    cout << "Enter number of test cases: ";
    cin >> testCases;

    while (testCases--) {
        int numberOfMountains;
        cout << "Enter number of mountains: ";
        cin >> numberOfMountains;

        int height, tallestMountain = 0;
        cout << "Enter the heights of the mountains: ";
        for (int i = 0; i < numberOfMountains; i++) {
            cin >> height;
            if (height > tallestMountain) {
                tallestMountain = height;
            }
        }

        cout << "Tallest mountain height: " << tallestMountain << endl;
    }

    return 0;
}
