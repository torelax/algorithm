#include <iostream>
using namespace std;
int main() {
  int n; //除数
  cout << "Input Divisor:";
  cin >> n;
  int div = n % 10;
  while (div != 1 && div != 3 && div != 7 && div != 9)
  {
    cout << "Can't, Input again!";
    cin >> n;
  }
  int num = 1;
  int length = 1;
  while (num % n) {
    length ++;
    num = (num % n) * 10 + 1;
  }
  cout << length;
  return 0;
}