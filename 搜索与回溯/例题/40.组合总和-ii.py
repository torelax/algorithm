#
# @lc app=leetcode.cn id=40 lang=python3
#
# [40] 组合总和 II
#
from typing import List
# @lc code=start
class Solution:
    def combinationSum2(self, candidates: List[int], target: int) -> List[List[int]]:
        candidates.sort()
        n = len(candidates)
        ans = []
        ops = []
        def backtrace(can, target):
            if target == 0 and ops != []:
                ans.append(ops.copy())
            elif can != [] and target > 0:
                # ops.append(can[0])
                i = 0
                while i < len(can) and can[i] == can[0]:
                    i += 1
                for j in range(i):
                    ops.append(can[0])
                    backtrace(can[i:], target-can[0] * (j+1))
                for k in range(i):
                    ops.pop()
                # ops.pop()
                backtrace(can[i:], target)

        backtrace(candidates, target)

        return ans
# @lc code=end

