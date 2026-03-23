#
# @lc app=leetcode.cn id=873 lang=python3
#
# [873] 最长的斐波那契子序列的长度
#
from typing import List

# 假设index顺序 k, j, i
# dp[i][j] = dp[j][k] + 1, 3

# @lc code=start
class Solution:
    def lenLongestFibSubseq(self, arr: List[int]) -> int:
        lenth = len(arr)
        maps = {x: i for i, x in enumerate(arr)}
        dp = [[0] * lenth for i in range(lenth)]
        res = 0
        for i, x in enumerate(arr):
            for j in range(lenth-1, -1, -1):
                if x - arr[j] >= arr[j]:
                    break
                else:
                    if x-arr[j] in maps:
                        k = maps[x-arr[j]]
                        dp[i][j] = max(dp[j][k]+1, 3)
                        res = max(res, dp[i][j])
        return res

# @lc code=end