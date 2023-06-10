#
# @lc app=leetcode.cn id=2611 lang=python3
#
# [2611] 老鼠和奶酪
#

# @lc code=start
class Solution(object):
    def miceAndCheese(self, reward1: List[int], reward2: List[int], k: int) -> int:
        s1, s2 = sum(reward1), sum(reward2)
        ind = []
        for i in range(len(reward1)):
            ind.append(reward2[i] - reward1[i])
        ind.sort()
        return s2 - sum(ind[:k])
# @lc code=end

# 优化
# ind改为优先队列 heapq heappush() heappop()