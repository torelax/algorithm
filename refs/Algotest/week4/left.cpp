#include <iostream>
using namespace std;
int main() {
  int n;
  cin >> n;
  int a[n], b[n];
  for (int i=0; i<n; i++) {
    cin >> a[i];
  }
  b[0] = 1;
  for (int i = 1; i < n; i++) {
    b[0] *= a[i-1];
    b[i] = b[0];
  }
  b[0] = 1;
  for (int i = n-2; i > 0 ; i--) {
    b[0] *=  a[i+1];
    b[i] *= b[0];
  }
  b[0] *= a[1];
  for (int i = 0; i < n; i++)
  {
    cout << b[i] << '\t';
  }
  
  return 0;
}