#include <iostream>
using namespace std;
int num = 0;
void merge(int a[], int low, int high) {
  int i = low, mid = (low+high)/2, j = mid+1;
  int newmar[high-low+1];
  int ne = 0;
  while (i <= mid && j <= high) {
    if (a[i] < a[j]) {
      newmar[ne++] = a[i++];
    }
    else {
      newmar[ne++] = a[j++];
      num += (mid-i+1);
    }
  }
  while (i <= mid)  newmar[ne++] = a[i++];
  while (j <= high) newmar[ne++] = a[j++];
  for (int i = low; i <= high; i++) {
    a[i] = newmar[i-low];
  }
}
void merge_sort(int a[], int low, int high) {
  if (low < high) {
    merge_sort(a, low, (low+high)/2);
    merge_sort(a, (low+high)/2+1, high);
    merge(a, low, high);
  }
}
int main() {
  int n;
  cin >> n;
  int a[2*n];
  for (int i = 0; i < 2*n-1; i++)
  {
    cin >> a[i];
  }
  merge_sort(a, 0, 2*n-1);
  cout << num;
  return 0;
}