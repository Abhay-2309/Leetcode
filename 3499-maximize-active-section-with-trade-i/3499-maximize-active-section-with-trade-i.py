class Solution:
    def maxActiveSectionsAfterTrade(self, s: str) -> int:
        n = len(s)
        one = s.count("1")
        s = "1" + s + "1"
        newlength = len(s)
        leftmefirstone = [-1] * (newlength + 1)
        rightmefirstone = [newlength] * (newlength + 1)
        for i in range(0, newlength):
            if s[i] == "1":
                leftmefirstone[i] = i
            else:
                leftmefirstone[i] = leftmefirstone[i-1]
        for i in range(newlength-1, -1, -1):
            if s[i] == "1":
                rightmefirstone[i] = i
            else:
                rightmefirstone[i] = rightmefirstone[i+1]
                
        maxi = one
        ptr = 1
        while ptr < newlength - 1:
            if s[ptr] == "1":
                left = ptr
                right = ptr
                while right + 1 < newlength and s[right + 1] == "1":
                    right += 1
                if s[left - 1] == "0" and right + 1 < newlength and s[right + 1] == "0":
                    nextfirstone = rightmefirstone[right + 2]
                    prevfirstone = leftmefirstone[left - 1]
                    maxi = max(maxi, min(n, one + nextfirstone - prevfirstone - 1 - (right-left+1)))
                ptr = right + 1
            else:
                ptr += 1
                
        return maxi