#include <iostream>
using namespace std;
int main() {
  int n, x;
  cin >> n >> x;
  int M[n][n];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> M[i][j];
    }
  }
  int row = n-1, col = 0;
  while (row >= 0 && col <= n-1) {
    if (M[row][col] == x) {
      cout << "row:" << row << "col:" << col;
      break;
    }
    else if (M[row][col] > x) row--;
    else col++;
  }
  if (row < 0 || col > n-1)
  cout << "No!";
  return 0;
}