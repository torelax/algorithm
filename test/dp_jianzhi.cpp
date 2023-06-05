#include <iostream>
#include "hell.h"

int sum(int a, int b) {
    int sum = 0;
    sum = a+b;
    return sum;
}
int main(int argc, char const *argv[])
{
    // int a[1001][1001];
    ppp(1024);
    int a = 2, b = 3;
    int i = 0;
    std::cout << i;
    i = sum(a, b);
    std::cout << i;
    return 0;
}
