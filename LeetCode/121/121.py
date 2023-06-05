from typing import List
class Solution:
    def maxProfit(self, prices: List[int]) ->int :
        _max = 0
        min_his = float('INF')
        for price in prices:
            min_his = min(min_his, price)
            _max = max(_max, price-min_his)
        print(_max)
# if __name__ == "__main__":
#     s = Solution()
#     s.maxProfit([7,1,5,3,6,4])