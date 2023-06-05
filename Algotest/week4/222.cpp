#include <iostream>
using namespace std;
int main() {
  int n, m; //n 为基数（2） m为项数
  cin >> n >> m;
  int sum, a=1;
  for (int i=m; i>=1; i--) {
    sum += a*i;
    a = a*10;
  }
  sum += sum;
  cout << sum;
  return 0;
}