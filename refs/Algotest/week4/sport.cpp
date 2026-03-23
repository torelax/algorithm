#include <iostream>
using namespace std;
int main() {
  int a, b, c;
  for (a=1; a<=3; a++) {
    for (b=1; b<=3; b++) {
      if (a != b ) {
        for (c=1; c<=3; c++) {
          if (c!=a && c!=b && a!=1 && c!=1 && c!=3) {
            cout << "a:" << char('w' + a) << '\t'
                 << "b:" << char('w' + b) << '\t'
                 << "c:" << char('w' + c) << '\t';
          } 
        }
      }
    }
  }
  return 0;
}