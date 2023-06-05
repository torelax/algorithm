#include <iostream>
#include <stdio.h>
using namespace std;
int main(int argc, char const *argv[])
{
/*     int i = 0;
    int b = 2;
    int *p = &b;
    int *s = nullptr;
    int *m;
    // m = ;
    cout << *m;
    // printf("%p\n", &i);
    cout << s << '\t' << &s << endl;
    // cout << sizeof(&b) << endl;
    cout << *p << '\t' << &(*p) << endl;
    cout << &i << '\t' << &b << '\t' << &p << '\t' << p << endl; */
    int a[] = {1, 2, 3, 4};
    int *p = a;                 // 64位中 指针实际上是 8字节的int大小  
    int i = 0;
    cout << a[++i];
    cout << *p++;
    cout << sizeof(p) << '\t' << p << '\n';
    cout << sizeof(p+1) << '\t' << p+1;
    return 0;
}
