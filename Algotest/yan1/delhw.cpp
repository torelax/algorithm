#include<iostream>
#include<vector>
#include<math.h>
using namespace std;
int main(int argc, char const *argv[])
{
    string s;
    while (std::cin >> s)  
    {
        int lenth = s.size();
        vector<vector<int>> dp(lenth, vector<int>(lenth, 0));
        // 第一层循环代表枚举字串的长度
        // 第二层循环枚举起始位置
        // 第一轮 dp[0][1] dp[1][2] dp[2][3]
        // 第二轮 dp[0][2] dp[1][3] dp[2][4]
        for(int d = 2; d <= lenth; d++) {
            for(int i = 0; i <= lenth-d; i++) {
                int j = i + d - 1;
                if(s[i] == s[j]) {
                    dp[i][j] = dp[i+1][j-1];
                }
                else
                    dp[i][j] = min(dp[i][j-1], dp[i+1][j]) + 1;
            }
        }
        std::cout << dp[0][lenth-1] << endl;
    }
    return 0;
}
