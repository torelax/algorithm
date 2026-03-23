#
# @lc app=leetcode.cn id=1170 lang=python3
#
# [1170] 比较字符串最小字母出现频次
#
from typing import List
# @lc code=start
class Solution:
    def numSmallerByFrequency(self, queries: List[str], words: List[str]) -> List[int]:
        answer = []

        def searchN(str):
            _c, num = str[0], 0
            for c in str:
                if c < _c:
                    num = 1
                    _c = c
                elif c == _c:
                    num += 1
            return num
        mem = [0] * 11
        for str in words:
            n = searchN(str)
            for i in range(n):
                mem[i] += 1
        for q in queries:
            c = searchN(q)
            answer.append(mem[c])
        return answer
# @lc code=end

