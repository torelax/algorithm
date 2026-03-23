#
# @lc app=leetcode.cn id=3 lang=python3
#
# [3] 无重复字符的最长子串
#

# @lc code=start
class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        # 滑动窗口
        window = {}
        mlen = l = r = 0
        while r < len(s):
            if s[r] not in window:
                window[s[r]] = 1
                r += 1
            # elif s[l] != s[r]:
            #     window.pop(s[l])
            #     l += 1
            else:
                while s[l] != s[r]:
                    window.pop(s[l])
                    l += 1
                window.pop(s[l])
                l += 1
            mlen = max(mlen, r-l)
        return mlen
            
# @lc code=end

if __name__ == '__main__':
    print(Solution().lengthOfLongestSubstring('asdgasgdsa'))