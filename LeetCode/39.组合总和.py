#
# @lc app=leetcode.cn id=39 lang=python3
#
# [39] 组合总和
#
from typing import List
# @lc code=start
class Solution:
    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        candidates.sort()
        n = len(candidates)
        ans = []
        ops = []
        def backtrace(can, target):
            if target == 0 and ops != []:
                ans.append(ops.copy())
            elif can != [] and target > 0:
                ops.append(can[0])
                backtrace(can, target-can[0])
                ops.pop()
                backtrace(can[1:], target)

        backtrace(candidates, target)

        return ans
# @lc code=end

