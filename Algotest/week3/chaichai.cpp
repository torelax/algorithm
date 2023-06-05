#include <iostream>
using namespace std;
int main() {
  int n, i = 0, j;
  cin >> n;
  int A[n];
  for (int k=0; k<n; k++) {
    cin >> A[k];
  }
  j = n-1;
  while (i < j) {
    while (A[i] >= 0 && i < n) {
      i++;
    }
    while (A[j] < 0 && j > 0) {
      j--;
    }
    if (i < j) {
      int t = A[i];
      A[i] = A[j];
      A[j] = t;
      i++;  j--;
    }
  }
  cout << "B: ";
  for (int k = 0; k<i; k++) {
    cout << A[k] << " ";
  }
  cout << '\n' << "C: ";
  for (int k = i; k<n; k++) {
    cout << A[k] << " ";
  }
  return 0;
}