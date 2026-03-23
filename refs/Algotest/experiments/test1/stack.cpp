#include <iostream>
using namespace std;
void func(int &a, int &b) {
  int t = a;
  a = b;
  b = t;
}
int main() {
  int a = 0, b = 3;
  func(a, b);
  cout << "a: " << a
       << "b: " << b;
       return 0;
}