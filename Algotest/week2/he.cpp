#include <cmath>
#include <iostream>
using namespace std;

//求解数字的位数
int numLength(int N) {
    int len = 0;
    while (N > 0) {
        N = N / 10;
        len++;
    }
    return len;
}
//求解最小不重复数
int minNoneDNum(int N) {
    bool isDNum = false;  // 是重复数的标志
    N++;                  // 自增1，确保比原来的数大
    do {
        isDNum = false;
        int len = numLength(N);  // 从最高位向右遍历，检索是否有重复的两位
        int a, b;                // 最高位和次高位
        for (int i = len - 1; i >= 1; i--) {
            int d = pow(10, i);
            a = N / d % 10;
            b = N / (d / 10) % 10;
            if (a == b) {  // 发现重复的两位,在次高位+随后在后面补01
                isDNum = true;
                N = N / (d / 10) + 1;
                int temp = 0, k = i-1;
                while (k > 0) {  // 低位置为0和1
                    N = N * 10 + temp;
                    temp = 1 - temp;
                    k--;
                }
                cout <<"->"<< N << endl;
            }
        }
    } while (isDNum);
    return N;
}
int main() {
    int N;
    cin>>N;
    int ans = minNoneDNum(N);
    cout<<"Answer:"<<ans<<endl;
    return 0;
}