#
# @lc app=leetcode.cn id=1025 lang=python3
#
# [1025] 除数博弈
#

# @lc code=start
class Solution:
    def divisorGame(self, n: int) -> bool:
        # 如果是奇数 x必为奇数 n-x必为偶数 奇数开局 最后到3
        # 如果n是偶数开局 爱丽丝就选1 必变为奇数 再让对手选后变为偶数 最后一定可以到2然后爱丽丝选1
        if n % 2 == 0:
            return True
        else :
            return False
# @lc code=end

