#
# @lc app=leetcode.cn id=1171 lang=python3
#
# [1171] 从链表中删去总和值为零的连续节点
#

# @lc code=start
from typing import Optional
# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def removeZeroSumSublists(self, head: Optional[ListNode]) -> Optional[ListNode]:
        count = 0
        h = head
        lis = [h]
        while h := h.next:
            lis.append(h)
        lenth = len(lis)
        dp = [[0] * lenth for _ in range(lenth)]
        h = head
        dp[0][0] = h.val
        if head.val == 0:
            lis[0] = head.next
        while h := h.next:
            count += 1
            for i in range(count+1):
                dp[i][count] = dp[i][count-1] + h.val
                if dp[i][count] == 0:
                    # print(i, count)
                    if i == 0 and count == lenth - 1:
                        return None
                    elif i == 0:
                        lis[0] = lis[count+1]
                        # print(i, count+1)
                        # print(lis[0].val, lis[0].next.val)
                    elif count == lenth - 1:
                        lis[i-1].next = None
                    else:
                        lis[i-1].next = lis[count+1]
        return lis[0]
        # solution 2 哈希表 相同前缀和说明两个节点间的和为0 可以覆盖掉
        # 相比上面dp 需要哈希表大小为 数的大小 而dp需要的是链表长度的平方
        prefix = 0
        seen = {}
        seen[0] = dummy = ListNode(0)
        dummy.next = head
        while head:
            prefix += head.val
            seen[prefix] = head
            head = head.next
        head = dummy
        prefix = 0
        while head:
            prefix += head.val
            head.next = seen[prefix].next
            head = head.next
        return dummy.next

# @lc code=end

