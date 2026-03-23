#
# @lc app=leetcode.cn id=1483 lang=python3
#
# [1483] 树节点的第 K 个祖先
#
from typing import List
import math
# @lc code=start
class TreeAncestor:
    # 树上倍增
    def __init__(self, n: int, parent: List[int]):
        self.n = n
        self.log = int(math.log(n, 2) // 1) + 1
        self.parent = parent
        self.res = [[-1] * self.log for _ in range(n)]
        for i, p in enumerate(parent):
            self.res[i][0] = parent[i]
        for i in range(1, self.log):
            for j in range(n):
                if self.res[j][i-1] != -1:
                    self.res[j][i] = self.res[self.res[j][i-1]][i-1]


    def getKthAncestor(self, node: int, k: int) -> int:
        for i in range(self.log):
            if (k >> i) & 1:
                node = self.res[node][i]
                if node == -1:
                    return -1
        return node


# Your TreeAncestor object will be instantiated and called as such:
# obj = TreeAncestor(n, parent)
# param_1 = obj.getKthAncestor(node,k)
# @lc code=end

