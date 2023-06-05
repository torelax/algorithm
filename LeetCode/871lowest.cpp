#include<iostream>
#include<vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=871 lang=cpp
 *
 * [871] 最低加油次数
 */

// @lc code=start
class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        int n = stations.size();
        vector<long> dp(n+1);
        // int m[n] = {};
        vector<int> m(n);
        dp[0] = startFuel;
        for(int i = 0; i < n; i++) {
            int index = 0;
            for(int j = 0; j < n; j++) {
                if(dp[i] >= stations[j][0] && !m[j]) {
                    // dp[i+1] = max(dp[i+1], dp[i]+stations[i][1]);
                    if (dp[i]+stations[j][1] > dp[i+1]) {
                        index = j;
                        dp[i+1] = dp[i]+stations[j][1];
                    }
                }
            }
            m[index] = 1;
        }
        for(int i = 0; i <= n; i++) {
            if(dp[i] >= target)    return i;
        }
        return -1;
    }
};
// @lc code=end

int main() {
    vector<vector<int>> stations = {{13,21},{26,115},{100,47},{225,99},{299,141},{444,198},{608,190},{636,157},{647,255},{841,123}};
    cout << Solution().minRefuelStops(1000, 299, stations);
}