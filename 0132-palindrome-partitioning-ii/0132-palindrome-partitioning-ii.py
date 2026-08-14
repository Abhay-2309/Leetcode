import sys

sys.setrecursionlimit(3000)

class Solution:
    MAX = 2005
    base = 31
    MOD = 10**9 + 7
    
    is_precomputed = False
    powerofbase = [0] * MAX
    inverseofbase = [0] * MAX

    @classmethod
    def precompute(cls):
        if cls.is_precomputed:
            return
            
        cls.powerofbase[0] = 1
        cls.inverseofbase[0] = 1
        
        inv_base = pow(cls.base, cls.MOD - 2, cls.MOD)
        
        for i in range(1, cls.MAX):
            cls.powerofbase[i] = (cls.powerofbase[i - 1] * cls.base) % cls.MOD
            cls.inverseofbase[i] = (cls.inverseofbase[i - 1] * inv_base) % cls.MOD
            
        cls.is_precomputed = True

    def minCut(self, s: str) -> int:
        self.precompute() 
        
        n = len(s)
        prefix = [0] * (n + 1)
        suffix = [0] * (n + 1)
        
        for i in range(n):
            char_val = ord(s[i]) - ord('a') + 1
            prefix[i + 1] = (prefix[i] + char_val * self.powerofbase[i]) % self.MOD
            
        for i in range(n):
            char_val = ord(s[n - 1 - i]) - ord('a') + 1
            suffix[i + 1] = (suffix[i] + char_val * self.powerofbase[i]) % self.MOD

        def check(L: int, R: int) -> bool:
            forward_hash = (prefix[R + 1] - prefix[L]) % self.MOD
            forward_hash = (forward_hash * self.inverseofbase[L]) % self.MOD
            
            rev_L = n - 1 - R
            rev_R = n - 1 - L
            
            backward_hash = (suffix[rev_R + 1] - suffix[rev_L]) % self.MOD
            backward_hash = (backward_hash * self.inverseofbase[rev_L]) % self.MOD
            
            return forward_hash == backward_hash

        dp = [-1] * n

        def f(ind: int) -> int:
            if ind == n:
                return 0
                
            if dp[ind] != -1:
                return dp[ind]
                
            mini = 10**9
            for j in range(ind, n):
                if check(ind, j):
                    mini = min(mini, 1 + f(j + 1))
                    
            dp[ind] = mini
            return mini

        return f(0) - 1