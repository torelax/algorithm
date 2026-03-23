#include <iostream>
using namespace std;
int main() {
  int A[16] = {17,2,33,33,4,43,42,42,42,89,89,5,71,61,127,127};
  int back, j, old = 1;
  for (int i=0; i<15; i++) {
    if (A[i+1] == A[i]) {
      while (A[i+1] == A[i]) {
      i++;
      back++;
      }
      for (j = i+1; j<15; j++) {
        if (A[j+1] == A[j])
          break;
      }
      for (int k=i; k<j; k++) {
        A[k-back] = A[k];
      }
      i = j-1;
      }
  }
  for (int m = 0; m < 16-back; m++) {
    cout << A[m] << " ";
  }
  return 0;
}