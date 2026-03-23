from typing import List
class Solution:
    def canThreePartsEqualSum(self, A: List[int]) -> bool:
        s = sum(A)
        l = 0;  r = 0
        print(s)
        ind1 = 0;   ind2 = 0
        for ind1 in range(len(A)):
            l += A[ind1]
            if l == s/3: 
                # print(l, ind1)
                break
        for ind2 in range(len(A)):
            r += A[-ind2-1]
            if r == s/3: 
                # print(r, ind2)
                break
        if ind1 < len(A)-ind2-1:   return True
        return False
# if __name__ == "__main__":
#     list = [0,2,1,-6,6,-7,9,1,2,0,1]
#     s = Solution()
#     print(s.canThreePartsEqualSum(list))