#
# @lc app=leetcode.cn id=1648 lang=python3
#
# [1648] 销售价值减少的颜色球
#
from typing import List
# @lc code=start
class Solution:
    def maxProfit(self, inventory: List[int], orders: int) -> int:
        # solution 1
        # 排序 再 减
        dic = {}
        tmp = []
        for i in inventory:
            if i in dic:
                dic[i] += 1
            else:
                dic[i] = 1
        sorted(dic.items())
        for (i, k) in dic.items():
            tmp.append([i, k])
        res = 0
        tmp.reverse()
        print(tmp)
        for i in range(len(tmp)-1):
            while tmp[i][0] > tmp[i+1][0]:
                if tmp[i][1] < orders:
                    res += (tmp[i][0] * tmp[i][1]) % (10**9+7)
                    tmp[i][0] -= 1
                    orders -= tmp[i][1]
                else:
                    res += (tmp[i][0] * orders) % (10**9+7)
                    orders = 0
                # tmp[]
            tmp[i+1][1] += tmp[i][1]
            if orders == 0:
                break
        res += (tmp[-1][0] * orders) % (10**9+7)
        return res
        # solution 2
        # 二分 T


# @lc code=end

