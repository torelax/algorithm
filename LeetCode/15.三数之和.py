#
# @lc app=leetcode.cn id=15 lang=python3
#
# [15] 三数之和
#
from typing import List
# @lc code=start
class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        c = len(nums)
        res = [][3]
        for i in range(c):
            for j in range(c):
                if i != j:
# @lc code=end

