#include <iostream>
#include <algorithm>
using namespace std;
void InsertSort(int a[], int l, int r) {
  for (int i = l+1; i <= r; i++)
  {
    if (a[i-1] > a[i]) {
      int t = a[i];
      int j = i;
      while (j > l && a[j-1] > t) {
        a[j] = a[j-1];
        j--;
      }
      a[j] = t;
    }
  }
}
void swap(int &a, int &b) {
  int t = a;
  a = b;
  b = t;
}
int FindMid(int a[], int l, int r) {
  if (l == r)
    return l;
  int index = 0;
  int i = 0;
  for (i = l; i <= r-4; i+=5)
  {
    InsertSort(a, i, i+4);
    index = i-l;
    swap(a[l+index/5], a[i+2]);
    //cout << a[l+index] << a[i+2] << endl;
  }
  if (r-i+1 > 0) {
    int m = r-i+1;
    index = i-l;
    InsertSort(a, i, r);
    swap(a[l+index/5], a[i+m/2]);
  }
  index /= 5;
  if (index == l)
    return l;
  else 
    return FindMid(a, l, l+index);
}
int Part(int a[], int l, int r, int mid) {
    swap(a[mid], a[l]);
    int i = l, j = r;
    int pivot = a[l];
    while(i < j)
    {
        while(a[j] >= pivot && i < j)
            j--;
        a[i] = a[j];
        while(a[i] <= pivot && i < j)
            i++;
        a[j] = a[i];
    }
    a[i] = pivot;
    return i;
}
int BFPRT(int a[], int l, int r, int mi) {
  int mid = FindMid(a, l, r);
  int pos = Part(a, l, r, mid);
  //cout << pos;
  if (mi == (pos-l+1)) 
    return a[pos];
  else if (mi > (pos-l+1)) 
    return BFPRT(a, pos+1, r, mi-(pos-l+1));
  else 
    return BFPRT(a, l, pos-1, mi);
}
int main() {
  int n;
  cin >> n;
  int a[n];
  int x[n];
  for (int i = 0; i < n; i++)
  {
    cin >> x[i] >> a[i];
  }
  int sum = 0;
  int y = BFPRT(a, 0, n-1, n/2+1);
  //cout << y;
  for (int i = 0; i < n; i++)
  {
    sum += abs(y-a[i]);
  }
  cout << sum;
  return 0;
}