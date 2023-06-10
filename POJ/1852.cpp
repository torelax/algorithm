#include <iostream>
using namespace std;

int min(int a, int b) {
    return a < b ? a : b;
}

int main(int argc, char const *argv[])
{
    int l = 0, c = 0;
    cin >> l;
    int minl[10000] = {0};
    int maxl[10000] = {0};
    int x[10000] = {0};
    int L = 0, n;
    while (c < l) {
        cin >> L >> n ;
        // int x[n] = {0};
        // maxl[c] = L;
        for (int i = 0; i < n; i++) {
            cin >> x[i];
            minl[c] = max(min(L - x[i], x[i]), minl[c]);
            maxl[c] = max(max(L - x[i], x[i]), maxl[c]);
        }
        c++;
    }
    for (int i = 0; i < l; i++) {
        cout << minl[i] << " " << maxl[i] << '\n';
    }
    return 0;
}
