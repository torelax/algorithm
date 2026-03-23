from typing import List
class Solution:
    def countCharacters(self, words: List[str], chars: str) ->int:
        dict = {}
        for char in chars:
            if char in dict:    dict[char] += 1
            else:   dict[char] = 1
        count = 0
        print(dict)
        for word in words:
            dw = {}
            flag = True
            for w in word:
                if w not in dict:
                    flag = False
                    break
                if w in dw and dw[w] == dict[w]:
                    flag = False
                    break
                elif w in dw:   
                    dw[w] += 1
                else:
                    dw[w] = 1
            if flag:
                # print(dw)
                count += len(word)
        print(count)
        return count

if __name__ == "__main__":
    s = Solution()
    s.countCharacters(["hello","world","leetcode"], 'welldonehoneyr')