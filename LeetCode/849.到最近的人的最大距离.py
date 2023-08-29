#
# @lc app=leetcode.cn id=849 lang=python3
#
# [849] 到最近的人的最大距离
#
from typing import List
# @lc code=start
class Solution:
    def maxDistToClosest(self, seats: List[int]) -> int:
        n = len(seats)
        dis = [0] * n
        _max = 0
        for i in range(1, n):
            if seats[i] == 0:
                dis[i] = dis[i-1] + 1
            else:
                dis[i] = 0
        _max = dis[n-1]
        for j in range(n-2, -1, -1):
            if seats[j] == 0:
                dis[j] = min(dis[j], dis[j+1] + 1)
                _max = max(_max, dis[j])
        return _max
        # solution 2
        # 快慢指针
        n = len(seats)
        i, j = 0, 1
        ans = 0
        while j < n:
            while j < n and seats[j] != 1:
                j += 1
            if j >= n:
                break
            if i == 0 and seats[i] == 0:
                ans = j
            ans = max(ans, (j-i) // 2)
            i = j
            j = i+1
        if seats[-1] == 0:
            ans = max(ans, n-i-1)
        return ans
# @lc code=end

