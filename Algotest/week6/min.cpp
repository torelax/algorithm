#include <iostream>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
using namespace std;
int a[10][10];
int mina = 0;
int minhe(int a, int b, int c) {
  a = a < b ? a : b;
  c = a < c ? a : c;
  return c;
}
int mindyn(int a[10][10], int row, int col) {
  if (row == 9 && col < 9)
  {
    return a[row][col] + mindyn(a, row, col+1);
  }
  else if (col == 9 && row < 9) {
    return a[row][col] + mindyn(a, row+1, col);
  }
  else if (col == 9 && row == 9) {
    return a[row][col];
  }
  else {
    return a[row][col] + minhe(mindyn(a, row+1, col+1), mindyn(a, row, col+1), mindyn(a, row+1, col));
  }
}
int main() {
  srand(time(0));
  for (int i = 0; i < 10; i++)
  {
    for (int j = 0; j < 10; j++)
    {
      
      a[i][j] = rand()%20+1;
    }
  }
  for (int i = 0; i < 10; i++)
  {
    for (int j = 0; j < 10; j++)
    {
      cout << a[i][i] << '\t';
    }
    cout << endl;
  }
  mina = mindyn(a, 0, 0);
  cout << mina;
  return 0;
}