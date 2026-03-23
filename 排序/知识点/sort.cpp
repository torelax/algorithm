#include <iostream>
using namespace std;
int test2(int b[], int length);
int main() {
  int A[]={-3, -2, -1, 2, 4, 5, 6, 9, 11};
  int length = sizeof(A)/sizeof(int);
  int flag;
  flag = test2(A, length);
  if (flag != -1) {
    while (A[flag] == flag) {
      printf("%d\t", flag);
      flag++;
    }  
  }
  else {
    printf("no!");
  }
  return 0;
}
int test2(int b[], int length) {
  int l = 0, r = length-1, mid;
  while (l <= r) {
    mid = l + r>>1;
    if (mid == 0 && b[mid] == mid) {
      return 0;
    }
    if (b[mid]-mid < 0 && b[mid+1] - mid == 1) {
      return mid+1;
    }
    if (b[mid]-mid >= 0) {
      r = mid-1;
    } 
    else {
      l = mid+1;
    }
  }
  return -1; 
}
