class Solution:
    def compressString(self, S: str) -> str:
        if not S:   return ''
        cor = S[0]
        compression = ''
        count = 0
        lenold, lennew = 0, 0
        for s in S:
            if s == cor:    
                count += 1
                lenold += 1
            else:
                compression += cor
                compression += str(count)
                lennew += 2
                lenold += 1
                count = 1
                cor = s
        compression += (cor+str(count))
        print(compression)
        if lenold <= lennew:    return S
        return compression

if __name__ == "__main__":
    s = Solution()
    s.compressString('aabbcccaab')
