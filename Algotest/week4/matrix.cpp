#include <iostream>
using namespace std;
int main() {
  int m, n;
  cin >> m >> n;
  int a[m][n];
  int sum = 1, k = 0;
  while (sum <= m*n) {
    int i = k, j = k++;
    if (i > m/2)
      break;
    for (i; i < m-k; i++) {
      a[i][j] = sum++;
    }
    for (j; j < n-k; j++) {
      a[i][j] = sum++;
    }
    for (i; i >= k; i--) {
      a[i][j] = sum++;
    }
    for (j; j >= k; j--) {
      a[i][j] = sum++;
    }
  }
  if ((m*n)%2 == 1) {
    a[m/2][n/2] = m*n;
  }
  for(int k = 0; k < m ; k++) {
    for (int j = 0; j < n ; j++) {
      cout << a[k][j] << '\t';
    }
    cout << endl;
  }
  return 0;
}