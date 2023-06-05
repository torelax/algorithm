/* 约瑟夫环
 * 递归求解
 * 
 */
 #include <iostream>
 using namespace std;

int ysfh(int n, int m, int k) {
  return k == 1? (m-1)%n : (ysfh(n-1, m, k-1)+m) % n; 
}

int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; i++)
  {
    cout << ysfh(n, m, i+1);
  }
  return 0;
}