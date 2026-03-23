#
# @lc app=leetcode.cn id=1262 lang=python3
#
# [1262] 可被三整除的最大和
#

# @lc code=start
class Solution:
    def maxSumDivThree(self, nums: List[int]) -> int:
        # dp[i][mod] nums[i:]
        # dp[0][0] = max(dp[1][0], nums[0] + dp[1][3-nums[0]%3]
        # 从左往右状态压缩
        n = len(nums)
        dp = [[0, -10000, -10000] for _ in range(n+1)]
        for i in range(1,n+1):
            dp[i][0] = max(dp[i-1][0], nums[i-1] + dp[i-1][(3 -(nums[i-1] % 3)) % 3])
            dp[i][1] = max(dp[i-1][1], nums[i-1] + dp[i-1][(4 -(nums[i-1] % 3)) % 3])
            dp[i][2] = max(dp[i-1][2], nums[i-1] + dp[i-1][(5 -(nums[i-1] % 3)) % 3])
        return dp[n][0]
# @lc code=end

