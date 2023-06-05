import collections as co
class Solution:
    def longestPalindrome(self, s: str) -> int:
        count = co.Counter(s)
        ans = 0
        for c in count.values():
            ans += c // 2 * 2
            if ans % 2 == 0 and c % 2 == 1:    ans += 1
        print(ans)
        return ans
s = Solution()
s.longestPalindrome('abccccdd')