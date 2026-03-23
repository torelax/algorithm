#
# @lc app=leetcode.cn id=63 lang=python3
#
# [63] 不同路径 II
#

# @lc code=start
from typing import List
class Solution:
    def uniquePathsWithObstacles(self, obstacleGrid: List[List[int]]) -> int:
        # dp[i][j] = dp[i-1][j] + dp[i][j-1], if [i,j] != 1
        # dp[i][j] = 0,                       if [i,j] == 1
        m = len(obstacleGrid)
        n = len(obstacleGrid[0])
        dp = [[0] *n for _ in range(m)]
        dp[0][0] = 1 if obstacleGrid[0][0] == 0 else 0
        # for i in range(1, m):
        #     if obstacleGrid[i][0] == 0:
        #         dp[i][0] = 1
        # for i in range(1, n):
        #     if obstacleGrid[0][i] == 0:
        #         dp[0][i] = 1
        for i in range(0, m):
            for j in range(0, n):
                if obstacleGrid[i][j] == 0:
                    if i - 1 >= 0:
                        dp[i][j] += dp[i-1][j]
                    if j - 1 >= 0:
                        dp[i][j] += dp[i][j-1]
                else:
                    dp[i][j] = 0
        # print(dp)
        return dp[m-1][n-1]
    # 优化
    # dp 压缩到一维
# @lc code=end

