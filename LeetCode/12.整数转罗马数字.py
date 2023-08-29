#
# @lc app=leetcode.cn id=12 lang=python3
#
# [12] 整数转罗马数字
#
from typing import List
# @lc code=start
class Solution:
    def intToRoman(self, num: int) -> str:
        dic = {1: 'I', 5: 'V', 10: 'X', 50: 'L', 100: 'C', 500: 'D', 1000: 'M'}
        res = []
        def dp(num):
            pass
        for k in dic:
            if num + k % 


        return res
# @lc code=end

