class Solution:
    def maxActiveSectionsAfterTrade(self, s: str) -> int:
        n = len(s)
        one = s.count("1")
        s = "1" + s + "1"
        newlength = n + 2
        leftmefirstone = [0] * newlength
        rightmefirstone = [0] * newlength
        last_one = -1
        for i, char in enumerate(s):
            if char == "1":
                last_one = i
            leftmefirstone[i] = last_one
                
        last_one = newlength
        for i in range(newlength - 1, -1, -1):
            if s[i] == "1":
                last_one = i
            rightmefirstone[i] = last_one
                
        maxi = one
        ptr = 1
        limit = newlength - 1
        
        while ptr < limit:
            if s[ptr] == "1":
                left = ptr
                right = ptr
                
                while right + 1 < newlength and s[right + 1] == "1":
                    right += 1
                
                if s[left - 1] == "0" and right + 1 < newlength and s[right + 1] == "0":
                    nextfirstone = rightmefirstone[right + 2]
                    prevfirstone = leftmefirstone[left - 1]
                    current_val = one + nextfirstone - prevfirstone - right + left - 2
                    
                    if current_val > n:
                        current_val = n
                    if current_val > maxi:
                        maxi = current_val
                
                ptr = right + 1
            else:
                ptr += 1
                
        return maxi