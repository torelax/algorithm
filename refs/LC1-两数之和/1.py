from typing import List
class Solution:
    def twoSum(self, nums: List[int], target) -> List[int]:
        has = dict()
        # 以下思路在于 讲 num放入字典的同时就判断另一个数在不在字典
        # num完全添加进字典之前就可出结果
        for index, num in enumerate(nums):
            other = target - num
            if other in has:
                # print(type([has[other], index]))
                return [has[other], index]
            has[num] = index
        return None

# if __name__ == "__main__":
#     nums = [2, 7, 8, 11]
#     s = Solution()
#     print(s.twoSum(nums, 9))
        