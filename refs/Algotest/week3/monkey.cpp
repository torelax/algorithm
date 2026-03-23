#include <iostream>
using namespace std;
int monkey(int day);
int m, n, d;
int main() {
  cout << "Input m, n, d:" ;
  cin >> m >> n >> d;
  int num = monkey(n);
  cout  << num;
  return 0;
}
int monkey(int day) {
  if(day == 1)
   return d;
  else
    return 2 * (monkey(day-1) + m);
}