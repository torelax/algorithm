#include <iostream>
#include <stdlib.h>
using namespace std;
int min(int a, int b) {
  return a < b? a : b;
}
int main() {
  int n, num;
  cin >> n;
  int S[n];
  for (int i = 0; i < n; i++)
  {
    cin >> S[i];
  }
  cin >> num;
  int L[num+1];
  for (int i = 1; i <= num; i++)
  {
    L[i] = 100000;
  }
  L[0] = 0;
  for (int i = 0; i < n; i++)
  {
    for (int j = 1; j <= num; j++)
    {
      int integer = 1000000;
      if ((j - S[i]) >= 0 && L[j-S[i]] < integer)
      {
        integer = L[j-S[i]] + 1; 
      }
      L[j] = min(integer, L[j]);
    }
  }
  cout << L[num];
  return 0;
}