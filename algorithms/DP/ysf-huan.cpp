#include <iostream>

int ysf(int n, int m, int k) {
    return k == 1? (m-1) %n : (ysf(n-1, m, k-1) + m) % n;
}

int main(int argc, char const *argv[])
{
    int n, m;
    std::cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        std::cout << ysf(n, m, i+1);
    }
    return 0;
}
