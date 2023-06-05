#include <iostream>
using namespace std;
int main() {
  int P, sum = 0; // 3<p<10000
  cin >> P;
  int a[P][P];
  int i, j;
  for (i = 0; i < P; i++) {
    for (j = 0; j < P; j++) {
      cin >> a[i][j];
    }
  }
  if (P%3 == 0 || P%3 == 2) {
    for (i = 1; i < P; i+=3) {
      for (j = 1; j < P; j+=3) {
        sum += a[i][j];
      }
    }
  }
  else if(P%3 == 1) {
    for (i = 0; i < P; i+=3) {
      for (j = 0; j < P; j+=3) {
        sum += a[i][j];
      }
    }
  }
  cout << "The Number of lei is: " << sum;
  return 0;
}