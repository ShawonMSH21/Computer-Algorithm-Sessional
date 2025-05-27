#include <iostream>
#include <cstring>
#include <ctime>
using namespace std;

#define MAX 200

class BigIntMultiplication {
private:
    int numA[MAX], numB[MAX], result[MAX];
    int lenA, lenB;

    void storeNumber(int num, int arr[], int &length) {
        while (num > 0) {
            arr[length++] = num % 10;
            num /= 10;
        }
    }

    void printResult() {
        int lenResult = lenA + lenB;
        while (lenResult > 1 && result[lenResult - 1] == 0) lenResult--;
        for (int i = lenResult - 1; i >= 0; i--) cout << result[i];
        cout << endl;
    }

public:
    BigIntMultiplication() {
        memset(numA, 0, sizeof(numA));
        memset(numB, 0, sizeof(numB));
        memset(result, 0, sizeof(result));
        lenA = lenB = 0;
    }

    void multiply(int A, int B) {
        if (A == 0 || B == 0) {
            cout << "0" << endl;
            return;
        }
        storeNumber(A, numA, lenA);
        storeNumber(B, numB, lenB);
        for (int i = 0; i < lenB; i++) {
            for (int j = 0; j < lenA; j++) {
                result[i + j] += numB[i] * numA[j];
                result[i + j + 1] += result[i + j] / 10;
                result[i + j] %= 10;
            }
        }
        printResult();
    }
};

int main() {
    int A, B;
    cout << "Enter two integers: ";
    cin >> A >> B;

    BigIntMultiplication multiplier;
    clock_t startT = clock();
    cout << "Product: ";
    multiplier.multiply(A, B);
    clock_t endT = clock();

    double duration = double(endT - startT) / CLOCKS_PER_SEC;
    cout << "Duration: " << duration << " seconds" << endl;
    return 0;
}
