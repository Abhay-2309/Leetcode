class Solution:
    def removeDuplicateLetters(self, s: str) -> str:
        n = len(s)
        taken = [False] * 26
        lastoccurance = [-1] * 26
        for i in range(n):
            lastoccurance[ord(s[i]) - ord('a')] = i
        monotonicstack = []
        
        for index in range(n):
            char = s[index]
            char_idx = ord(char) - ord('a')
            if taken[char_idx]:
                continue
                
            if len(monotonicstack) == 0:
                monotonicstack.append(char)
                taken[char_idx] = True
            else:
                curr = char
                while monotonicstack and monotonicstack[-1] > curr:
                    prev = monotonicstack[-1]
                    nextoccur = lastoccurance[ord(prev) - ord('a')]
                    if nextoccur > index:
                        monotonicstack.pop()
                        taken[ord(prev) - ord('a')] = False
                    else:
                        break
                monotonicstack.append(char)
                taken[char_idx] = True
        return "".join(monotonicstack)