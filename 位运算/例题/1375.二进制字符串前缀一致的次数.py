#
# @lc app=leetcode.cn id=1375 lang=python3
#
# [1375] 二进制字符串前缀一致的次数
#

# @lc code=start
class Solution:
    def numTimesAllBlue(self, flips: List[int]) -> int:
        n = len(flips)
        # 最差n^2
        # solution 1
        # 模拟[1-n] 每次分别判断是否是前缀一致
        # f = [0 for _ in range(n)]
        # for i in range(n):
        #   f[flips[i]-1] ^= 1
        #   res += isFlip(f, i)
        # solution 2
        # 遍历过程中记录i左侧1的个数 同时记录i哟右侧0的个数？ （flips是否重复）
        dp = [0 for _ in range(n+1)]
        res = 0
        ans = 0
        for i in range(1,n+1):
            dp[flips[i-1]] = 1
            if flips[i-1] < i:
                res += 1
            res += dp[i]
            if res == i:
                ans += 1

        return ans
        # solution 3
        # 前i次翻转 下标的最大值等于i
        for i in range(n):
            res = max(res, flips[i]-1)
            if res == i:
                ans += 1
        return ans
# @lc code=end

