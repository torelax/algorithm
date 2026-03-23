#
# @lc app=leetcode.cn id=4 lang=python3
#
# [4] 寻找两个正序数组的中位数
#
from typing import List
# @lc code=start
class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        # solution 1 依次添加 复杂度o(m+n)
        # ...
        # solution 2 复杂度o(log(m+n))
        # 分别2分 搜到的值紧邻 且下标左+左=右+右
        m, n = len(nums1), len(nums2)
        nleft = nright = 0

        if nums1[-1] < nums2[0]:
            return nums1[(n + m) // 2] if m > n else nums2[(n+m)//2 - m]
        elif nums1[0] > nums2[-1]:
            return (n+m) if m < n else nums2[n]
        def binarysearch(arr, key):

            return index, value

        binaryserach(nums1)

# @lc code=end

