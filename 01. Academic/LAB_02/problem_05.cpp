#include <iostream>
#include <cstring>
#include <ctime>
using namespace std;

#define MAX 500  // Maximum digits to handle large numbers

class BigIntMultiplication {
private:
    int result[MAX * 2]; // To store intermediate and final result

public:
    // Constructor to initialize result array
    BigIntMultiplication() {
        memset(result, 0, sizeof(result));
    }

    // Function to multiply two large integers represented as strings
    void multiply(const string &numA, const string &numB) {
        int lenA = numA.size();
        int lenB = numB.size();

        if (lenA == 0 || lenB == 0 || numA == "0" || numB == "0") {
            cout << "0\n"; // If either number is 0, the product is 0
            return;
        }

        // Perform grade-school multiplication
        for (int i = lenA - 1; i >= 0; --i) {
            for (int j = lenB - 1; j >= 0; --j) {
                int mul = (numA[i] - '0') * (numB[j] - '0');
                int sum = mul + result[i + j + 1];

                result[i + j + 1] = sum % 10;
                result[i + j] += sum / 10;
            }
        }

        printResult(lenA + lenB);
    }

    // Function to print the final result
    void printResult(int lenResult) {
        int i = 0;
        while (i < lenResult && result[i] == 0) i++;  // Skip leading zeros

        if (i == lenResult) {
            cout << "0";
        } else {
            for (; i < lenResult; ++i)
                cout << result[i];
        }
        cout << "\n";
    }
};

// ----------- Driver Code -----------
int main() {
    string X, Y;
    cout << "Enter number X: ";
    cin >> X;
    cout << "Enter number Y: ";
    cin >> Y;

    BigIntMultiplication multiplier;

    clock_t startT = clock();
    cout << "\nProduct: ";
    multiplier.multiply(X, Y);
    clock_t endT = clock();

    double duration = static_cast<double>(endT - startT) / CLOCKS_PER_SEC;
    cout << "\nDuration: " << duration << " seconds\n";

    return 0;
}
