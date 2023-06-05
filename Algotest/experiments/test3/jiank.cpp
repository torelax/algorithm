#include <iostream>
#include <algorithm>
using namespace std;
int getmaxindex(int a[], int n) {
  int index = 1;
  for (int i = 2; i <= n; i++)
  {
    index = a[index] > a[i] ? index : i;
  }
  return index;
}
int main() {
  int n;
  cin >> n;
  int a[n+1][n+1] = {0};
  int num[n+1] = {0};
  int x, y;
  for (int i = 1; i <= n; i++) {
    cin >> x >> y;
    a[x][y] = 1;
    a[y][x] = 1;
    num[x]++; num[y]++;
  }
  int sum = 0, count = 0;
  for (int i = 1; i <= n; i++) {
    // for (int j = 0; j < n; j++)
    // {
    //   cout << "num[" << j+1 << "]=" << num[j+1] << " ";
    // }
    int ind = getmaxindex(num, n);
    // cout << " ind->" << ind << endl;;
    sum += num[ind];
    num[ind] = 0;
    count++;
    int flag = 0;
    for (int j = 1; j <= n; j++) {
      if (a[ind][j] == 1 && j != ind) {
        num[j]--;
        flag = 1;
        a[ind][j] = 0;  a[j][ind] = 0;
      }
    }
    if (sum >= n) {
      break;
    }
  }
  cout << count;
  return 0;
}