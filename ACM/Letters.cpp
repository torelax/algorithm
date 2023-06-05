 #include <bits/stdc++.h> 
using namespace std; 
int n, m, T;
 
void out(char x, int cnt = 1, bool end = false) { 
	for (int i = 0; i < cnt; i += 1) 
		cout << x;
	if (end) cout << endl;
}
 
int main() { 
	cin >> T;
	while (T--) {
		cin >> n;
		for (int i = 0; i < n - 1; i += 1) {
			out('X');
			out('.', n - 1, true);
		}
		out('X', n, true); 
		cout << endl;
		for (int i = 0; i < n; i += 1) {
			if (i == 0 || i == n / 2 || i == n - 1) {
				out('X', n, true);
			} 
			else {
				out('X');
				out('.', n - 1, true);
			}
		}
		cout << endl;
		out('X', n, true);
		for (int i = 1; i < n; i += 1) {
			out('.', n / 2);
			out('X', 1);
			out('.', n / 2, true);
		} 
		cout << endl;
		out('X', n, true);
		for (int i = 1; i < n; i += 1) {
			out('.', n / 2); 
			out('X', 1);
			out('.', n / 2, true);
		}
		cout << endl;
	}
	return 0;
}
