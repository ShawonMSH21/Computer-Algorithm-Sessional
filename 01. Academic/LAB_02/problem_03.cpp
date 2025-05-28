#include<iostream> 
using namespace std; 
int main() 
{ 
int n; 
cout << "Enter the size of the numbers: "; 
cin >> n; 
int A[n]; 
cout << "Numbers: "; 
for(int i = 0 ; i < n ; i++) 
{ 
cin >> A[i]; 
} 
for(int i = 1 ; i < n ; i++) 
{ 
int key; 
key = A[i]; 
int j; 
j = i - 1; 
while(j >= 0 && key < A[j]) 
{ 
A[j + 1] = A[j]; 
j = j - 1; 
} 
A[j + 1] = key; 
} 
cout << "Sorted: "; 
for(int i = 0 ; i < n ; i++) 
{ 
cout << A[i] << " "; 
} 
return 0; 
}