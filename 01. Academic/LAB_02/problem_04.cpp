#include <iostream>
#include <cstring>
#include <ctime>
#include <cmath>
using namespace std;

#define MAX 200 // Maximum digits for big integers

// --------- Grade School Multiplication Class ---------
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
        for (int i = lenResult - 1; i >= 0; i--)
            cout << result[i];
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

// --------- Karatsuba Multiplication ---------
int karatsuba(int x, int y) {
    if (x < 10 || y < 10)
        return x * y;

    int n = max((int)log10(x) + 1, (int)log10(y) + 1);
    int m = n / 2;

    int a = x / pow(10, m);
    int b = x % (int)pow(10, m);
    int c = y / pow(10, m);
    int d = y % (int)pow(10, m);

    int z0 = karatsuba(b, d);
    int z1 = karatsuba(a + b, c + d);
    int z2 = karatsuba(a, c);

    return z2 * pow(10, 2 * m) + (z1 - z2 - z0) * pow(10, m) + z0;
}

// --------- Main Driver Function ---------
int main() {
    int A, B;
    cout << "Enter two integers: ";
    cin >> A >> B;

    // Grade School Multiplication
    BigIntMultiplication multiplier;
    clock_t startT = clock();
    cout << "\nProduct Using Grade School Multiplication: ";
    multiplier.multiply(A, B);
    clock_t endT = clock();
    double duration_grade_school = (double)(endT - startT) / CLOCKS_PER_SEC;
    cout << "Run Time For Grade School Multiplication: " << duration_grade_school << " seconds\n";

    // Karatsuba Multiplication
    clock_t startK = clock();
    int result = karatsuba(A, B);
    clock_t endK = clock();
    cout << "\nProduct Using Karatsuba Multiplication: " << result << endl;
    double duration_karatsuba = (double)(endK - startK) / CLOCKS_PER_SEC;
    cout << "Run Time For Karatsuba Multiplication: " << duration_karatsuba << " seconds\n";

    // Time Comparison
    double time_diff = abs(duration_grade_school - duration_karatsuba);
    cout << "\nTime Difference: " << time_diff << " seconds\n";

    return 0;
}
