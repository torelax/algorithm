from typing import List
class Solution:
    def lengthOfLIS(self, nums: List[int]) -> int:
        if not nums:
            return 0
        dp = []
        for i in range(len(nums)):
            dp.append(1)
            for j in range(i):
                # print(i)
                if nums[j] < nums[i]:
                    dp[i] = max(dp[i], dp[j]+1)
        print(max(dp))
        return max(dp)
if __name__ == "__main__":
    S = Solution()
    S.lengthOfLIS([10, 9, 2, 5, 3, 7, 101, 18])
    S.lengthOfLIS([10, 9, 2, 5, 3, 4])     
    S.lengthOfLIS([])