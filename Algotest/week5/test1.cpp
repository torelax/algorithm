#include <iostream>
using namespace std;
int a[100];
int midpart(int low, int hight) {
  int index = a[low];
  int j = low;
  for (int i = low+1; i <= hight; i++) {
    if (a[i] < index) {
      j++;
      if (j != i) {
        int t = a[i];
        a[i] = a[j];
        a[j] = t;
      }
    }
  }
  a[low] = a[j];
  a[j] = index;
  return j;
}
void qsort(int low, int hight) {
  if (hight > low) {
    int pnext = midpart(low, hight);
    qsort(low, pnext-1);
    qsort(pnext+1, hight);
  }
}
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
  }
  qsort(0, n-1);
  int count = 0, max = 0;
  int index = 0;
  for (int i = 0; i < n-1; i++) {
    if(a[i+1] == a[i]) {
      count++;
      continue;
    }
    else {
      max = max>count? max : count;
      index = max>count?index : i;
      count = 0;
    }
  }
  cout << a[index];
  return 0;
}