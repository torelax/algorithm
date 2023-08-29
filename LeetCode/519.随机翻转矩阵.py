#
# @lc app=leetcode.cn id=519 lang=python3
#
# [519] 随机翻转矩阵
#
from typing import List
# @lc code=start
class Solution:

    def __init__(self, m: int, n: int):
        self.matrix = [[0] * n for _ in range(m)]

    def flip(self) -> List[int]:
        pass

    def reset(self) -> None:
        self.matrix = [[0] * len(self.matrix[0]) for _ in range(len(self.matrix))]


# Your Solution object will be instantiated and called as such:
# obj = Solution(m, n)
# param_1 = obj.flip()
# obj.reset()
# @lc code=end

