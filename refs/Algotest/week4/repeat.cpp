#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;
int compare(int a[], int i) {
  for (int j=i; j>=0 ; j--) {
    if (a[j] == a[j-1]) 
      return j;
  }
  return 0;
}
int compare(int num) {
  int a[10], lenth = 0;
  while (num) {
    a[lenth] = num%10;
    num /= 10;
    lenth++;
  }
  for (int j=lenth; j>=0 ; j--) {
    if (a[j] == a[j-1] && a[j] == 9) 
      return -1;
    else if (a[j] == a[j-1])
      return j;
  }
  return 0;
}
int main() {
  int n, num;
  cin >> n;
  num = n;
  int a[10], lenth = 0;
  while (num) {
    a[lenth] = num%10;
    num /= 10;
    lenth++;
  }
  int flag = compare(a, lenth);
  int flag1 = compare(n);
  while (flag1 == -1) {
    n += pow(10, flag-1);
    flag1 = compare(n);
    num = n;
    lenth = 0;
    while (num) {
      a[lenth] = num%10;
      num /= 10;
      lenth++;
    }
    flag = compare(a, lenth);
  }
  if (flag > 0) {
    n += pow(10, flag-1);
    a[flag-1]++;
    for(int i = flag-2, k = 0; i>=0; i--) {
      a[i] = k;
      k = k^1;
    }
  }
  for (int k=lenth-1; k >=0 ; k--) {
    cout << a[k];
  }
  return 0;
}