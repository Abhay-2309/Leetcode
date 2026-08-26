class Solution:
    def shortestBeautifulSubstring(self, s: str, k: int) -> str:
        n =len(s)
        left =0
        right =0
        end = -1
        minilen = float('inf')
        cntone =0
        while right<n:
            if s[right]=='1':
                cntone+=1
            if cntone<k:
                right+=1
            else:
                while left<=right and cntone>=k:
                    lenght = right - left+1
                    if minilen > lenght:
                        minilen = lenght
                        end = right
                    elif minilen == lenght:
                        if s[left:right+1] < s[end-minilen+1:end+1]:
                            end = right
                    if s[left]=='1':
                        cntone-=1
                    left+=1
                right+=1
                
        if minilen==float('inf'):
            return ""
        return s[end-minilen+1:end+1]