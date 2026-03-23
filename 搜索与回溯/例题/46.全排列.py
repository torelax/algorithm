#
# @lc app=leetcode.cn id=46 lang=python3
#
# [46] 全排列
#
from typing import List
# @lc code=start
class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
        n = len(nums)
        mem = [0] * len(nums)
        res = []
        def backtrace(nums, mem, ans):
            if len(ans) == n:
                t = ans.copy() #??????????????
                # backtrace传递的是一个ans，递归结束ans归[]
                res.append(t)
                return
            for i in range(n):
                if not mem[i]:
                    mem[i] = 1
                    ans.append(nums[i])
                    backtrace(nums, mem, ans)
                    ans.pop()
                    mem[i] = 0
        backtrace(nums, mem, [])

        return res

# @lc code=end

