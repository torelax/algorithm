/*
 * @lc app=leetcode.cn id=62 lang=cpp
 *
 * [62] 不同路径
 */

// @lc code=start
class Solution {
public:
    int uniquePaths(int m, int n) {
        // Cm_n
        // m!
        int _m = m > n ? m : n;
        int _n = m > n ? n : m;
        long long j = 1, res = 1;
        for (int i = _m; i <= _m + _n - 2 ; i++)
        {
            res *= i;
            if (res % j == 0) {
                res /= j;
                j++;
            }
        }
        while (j <= _n-1) {
            res /= j;
            j++;
        }
        return res;
    }
};
// @lc code=end

