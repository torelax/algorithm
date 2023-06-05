#include <iostream>
using namespace std;
int res(int n) {
  if (n == 1)
    return 1;
  else
    return (n&1) == 0? res(n/2)+1 : res(n/2)+res(n/2+1);
}
int main() {
  int n, sum = 0;
  cin >> n; 
  cout << res(n);
  for (int i=0; i<n; i++) {
    sum += res(n);
  }
  return 0;
}