#include<iostream>
#include<vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=2028 lang=cpp
 *
 * [2028] 找出缺失的观测数据
 */

// @lc code=start
class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int sum = 0, r = 0;
        int m = rolls.size();
        vector<int> res(n, 0);
        for(auto &p:rolls) {
            sum += p;
        }
        r = mean * (n+m) - sum;
        if(r > 6*n || r < n)    return {};
        res = vector<int>(n, r/n);
        for(int i = 0; i < r%n; i++) {
            res[i] += 1;
        }
        return res;
    }
};
// @lc code=end

