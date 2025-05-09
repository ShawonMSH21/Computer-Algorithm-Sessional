#include <iostream>
using namespace std;

int main() {
    int N;
    cout<<"Enter the size of the array: ";
    cin >> N;
    int A[N];
    cout<<"Enter the elements ::\n";
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    int sum = 0;
    for (int i = 0; i < N; i++) {
        sum += A[i];
    }
    cout <<"The sum of the elemets are: "<< sum << endl;
    return 0;
}
