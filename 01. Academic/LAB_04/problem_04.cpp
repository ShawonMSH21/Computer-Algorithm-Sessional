#include<iostream>
#include<cmath>
using namespace std;

void Merge(int arr[], int p, int q, int r) {
    int n1 = q - p + 1;
    int n2 = r - q;
    int L[n1], R[n2];

    for(int i = 0; i < n1; i++) {
        L[i] = arr[p + i];
    }
    for(int j = 0; j < n2; j++) {
        R[j] = arr[q + 1 + j];
    }

    int i = 0, j = 0, k = p;
    while(i < n1 && j < n2) {
        if(L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while(i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while(j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void Merge_sort(int a[], int p, int r) {
    if(p < r) {
        int q = floor((p + r) / 2);
        Merge_sort(a, p, q);
        Merge_sort(a, q + 1, r);
        Merge(a, p, q, r);
    }
}

int main() {
    int test;
    cin >> test;

    while(test--) {
        int n, sam_h;
        cin >> n >> sam_h;

        int heights[n];
        for(int j = 0; j < n; j++) {
            cin >> heights[j];
        }

        Merge_sort(heights, 0, n - 1);

        int L = 0;
        for(int k = 0; k < n; k++) {
            if(heights[k] < sam_h) {
                L++;
            }
        }

        int R = n - L;
        int cost = abs(L - R);
        cout << "Cost: " << cost << "\n\n";
    }

    return 0;
}
