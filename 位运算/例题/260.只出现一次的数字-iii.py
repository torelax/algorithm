#
# @lc app=leetcode.cn id=260 lang=python3
#
# [260] 只出现一次的数字 III
#

# @lc code=start
class Solution:
    def singleNumber(self, nums: List[int]) -> List[int]:
        t = 0
        for n in nums:
            t ^= n
        index = 0
        for i in range(32):
            if (t >> i) & 1:
                index = i
                break
        n1 = n2 = 0
        for n in nums:
            if (n >> i) & 1:
                n1 ^= n
            else:
                n2 ^= n
        return [n1, n2]

# @lc code=end

