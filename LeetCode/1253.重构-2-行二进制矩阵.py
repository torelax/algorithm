#
# @lc app=leetcode.cn id=1253 lang=python3
#
# [1253] 重构 2 行二进制矩阵
#
from typing import List
# @lc code=start
class Solution:
    def reconstructMatrix(self, upper: int, lower: int, colsum: List[int]) -> List[List[int]]:
        n = len(colsum)
        up, down = [0] * n, [0] * n
        cnt = 0
        cntu, cntd = upper, lower
        k = 0
        if upper + lower != sum(colsum):
            return []
        for i, c in enumerate(colsum):
            if c == 2:
                up[i] ,down[i] = 1, 1
                k += 1
                upper -= 1
                lower -= 1
            if c == 1:
                cnt += 1
        if upper + lower != cnt or cntu < k or cntd < k:
            return []
        for i in range(n):
            if colsum[i] == 1:
                if upper == 0 and lower > 0:
                    down[i] = 1
                    lower -= 1
                if upper > 0:
                    up[i] = 1
                    upper -= 1
        return [up, down]


# @lc code=end

