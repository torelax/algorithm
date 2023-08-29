#
# @lc app=leetcode.cn id=264 lang=python3
#
# [264] 丑数 II
#

# @lc code=start
class Solution:
    def nthUglyNumber(self, n: int) -> int:
        # 1 2 3 4 5 6 8 9 10 12 15 16 18 20
        # 按顺序依次挑 乘2 3 5最大的
        # mem = [[0] * 3 for i in range(500)]
        mul = [2, 3, 5]
        a = [1, 2, 3]
        c = 3
        idx = 2
        res = [1, 2, 3]
        if n <= 3:
            return res[n-1]
        while c < n:
            # idx = min(a)
            tmp = [2000, 2000, 2000]
            slip = max(a)
            _min = min(a)
            for i, _ in enumerate(a):
                for m in mul:
                    if _ * m > slip:
                        tmp[i] = _ * m
                        break
            ss = min(tmp)
            for i in range(3):
                if a[i] == _min:
                    a[i] = ss
                    break
            c += 1
        return max(a)
# @lc code=end

