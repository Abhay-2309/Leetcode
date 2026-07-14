from functools import cache
from math import gcd
from typing import List

class Solution:
    def subsequencePairCount(self, nums: List[int]) -> int:
        n = len(nums)
        MOD = 10**9 + 7
        @cache
        def f(index: int, first: int, second: int) -> int:
            if index == n:
                return 1 if (first == second and first != 0) else 0
                
            skip = f(index + 1, first, second)
            takeinfirst = f(index + 1, gcd(first, nums[index]), second)
            takeinsecond = f(index + 1, first, gcd(nums[index], second))
            
            return (skip + takeinfirst + takeinsecond) % MOD
            
        ans = f(0, 0, 0)
        f.cache_clear() 
        
        return ans