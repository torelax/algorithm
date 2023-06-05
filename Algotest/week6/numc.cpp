#include <iostream>
#include <cmath>
using namespace std;
char a[500];
int mama[501][21] = {0};
int maxn = 99999999;
int num(int left, int right) {
  int sum = 0;
  for (int i = left; i < right; i++) {
    sum = sum * 10 + int(a[i]-'0');
  }
  return sum;
}
int Min(int n, int x) {
  mama[n][x] = maxn;
  if (x == 0) {
    return num(0, n);
  }
  else {
    for (int k = n-1; k >= x; k--) {
      mama[n][x] = min(Min(k, x-1)+num(k, n), mama[n][x]);
      //cout << mama[n][x];
    }
  }
  return mama[n][x];
}
int main() {
  int n, m;
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
  }
  cin >> m;
  cout << Min(n, m);
  return 0;
}