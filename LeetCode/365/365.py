# 裴蜀定理
from math import gcd
class Solution:
    def canMeasureWater(self, x: int, y: int, z: int) -> bool:
        if x + y < z:
            return False
        if x == 0 or y == 0:
            return z == 0 or x + y == 0
        else:
            return z % gcd(x, y) == 0
if __name__ == "__main__":
    a = Solution()
    print(a.canMeasureWater(3, 5, 4))         
