#include <iostream>
using namespace std;
int main(){
  int n, i = 0;
  cin >> n;
  while (n) {
    i += n/5;
    n = n/5;
  }
  cout << i;
  return 0;
}