from collections import defaultdict
class Solution:
    def numberOfSubstrings(self, s: str) -> int:
        n = len(s)
        left = 0
        right = 0
        a =0
        b= 0
        c = 0
        cnt =0
        while right<n:
            if s[right]=='a':
                a+=1
            if s[right]=='b':
                b+=1
            if s[right]=='c':
                c+=1
            if a>0 and b>0 and c>0:
                cnt += (n - right)
                while left<right and a>0 and b>0 and c>0:
                    if s[left]=='a':
                        a-=1
                    if s[left]=='b':
                        b-=1
                    if s[left]=='c':
                        c-=1
                    if a>0 and b>0 and c>0:
                        cnt += (n - right)
                    left+=1
            right+=1
        if a>0 and b>0 and c>0:
            cnt += (n - right)
        return cnt