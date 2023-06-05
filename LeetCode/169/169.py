# from collections import Counter
# class Solution:
#     def majorityElement(self, nums: List[int]) -> int:
#         return Counter(nums).most_common(1)[0][0]

class Solution(object):
	def majorityElement(self, nums):
		"""
		:type nums: List[int]
		:rtype: int
		"""
		corr = None
		count = 0
		for num in nums:
			if count == 0:	corr = num
			count += (1 if num == corr else -1)
		# print(corr)
		return corr
if __name__ == "__main__":
	s = Solution()
	s.majorityElement([1, 2, 3, 3, 4, 3, 3])