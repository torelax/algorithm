#
# @lc app=leetcode.cn id=1503 lang=python3
#
# [1503] 所有蚂蚁掉下来前的最后一刻
#

# @lc code=start
class Solution:
    def getLastMoment(self, n: int, left: List[int], right: List[int]) -> int:
        if left == []:
            return n-min(right)
        elif right == []:
            return max(left)
        else:
            return max(max(left), n-min(right))
# @lc code=end

