#
# @lc app=leetcode.cn id=2475 lang=python3
#
# [2475] 数组中不等三元组的数目
#
from typing import List
# @lc code=start
class Solution:
    def unequalTriplets(self, nums: List[int]) -> int:
        # solution 1
        """ n = len(nums)
        res = 0
        for i in range(n):
            for j in range(i+1, n):
                for k in range(j+1, n):
                    if nums[i] != nums[j] and nums[j] != nums[k] and nums[i] != nums[k]:
                        res += 1
        return res """
        # solution 2
        nums.sort()
        n = len(nums)
        c = i = j = 0
        while i < n:
            while j < n and nums[i] == nums[j]:
                j += 1
            c += i * (j-i) * (n-j)
            i = j
        return c
        # solution 3
        dic = Counter(nums)
        c = res = 0
        n = len(nums)
        for _, v in dic.items():
            res += c * v * (n - c - v)
            c += v
# @lc code=end

