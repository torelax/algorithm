import math
class Solution:
	def gcdOfStrings(self, str1: str, str2: str) -> str:
		my = math.gcd(len(str1), len(str2))
		stm = str1[:my]
		if stm * (len(str1)//my) == str1 and stm * (len(str2)//my) == str2:
			return stm
		return ""
if __name__ == "__main__":
	a = Solution()
	print(a.gcdOfStrings("ABCABCABC","ABCABC"))