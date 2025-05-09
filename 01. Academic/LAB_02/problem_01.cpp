#include <iostream>
#include <cmath>
using namespace std;

int get_digit_count(long number) {
    int digit_count = 0;
    while (number > 0) {
        digit_count++;
        number /= 10;
    }
    return digit_count;
}

long karatsuba_multiply(long num1, long num2) {
    if (num1 < 10 && num2 < 10) {
        return num1 * num2;
    }
    int num_size = fmax(get_digit_count(num1), get_digit_count(num2));
    if (num_size < 10) {
        return num1 * num2;
    }
    num_size = (num_size / 2) + (num_size % 2);
    long base = pow(10, num_size);
    long high1 = num1 / base;
    long low1 = num1 - (high1 * base);
    long high2 = num2 / base;
    long low2 = num2 - (high2 * base);

    long part1 = karatsuba_multiply(low1, low2);
    long part2 = karatsuba_multiply(high1, high2);
    long part3 = karatsuba_multiply(low1 + high1, low2 + high2);

    return part1 + ((part3 - part1 - part2) * base) + (part2 * pow(10, 2 * num_size));
}

int main() {
    long firstNumber, secondNumber;
    cout << "Enter the first number: ";
    cin >> firstNumber;
    cout << "Enter the second number: ";
    cin >> secondNumber;
    cout << "The final product is: " << karatsuba_multiply(firstNumber, secondNumber) << endl;
    return 0;
}
