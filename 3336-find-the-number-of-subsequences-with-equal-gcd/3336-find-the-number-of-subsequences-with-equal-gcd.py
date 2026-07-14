from math import gcd
from typing import List

class Solution:
    def subsequencePairCount(self, nums: List[int]) -> int:
        n = len(nums)
        MOD = 10**9 + 7
        max_val = max(nums) if nums else 0
        memo = [[[-1 for _ in range(max_val + 1)] 
                 for _ in range(max_val + 1)] 
                for _ in range(n + 1)]
        def f(index: int, first: int, second: int) -> int:
            if memo[index][first][second] != -1:
                return memo[index][first][second]
            if index == n:
                return 1 if (first == second and first != 0) else 0
            skip = f(index + 1, first, second)
            takeinfirst = f(index + 1, gcd(first, nums[index]), second)
            takeinsecond = f(index + 1, first, gcd(nums[index], second))
            ans = (skip + takeinfirst + takeinsecond) % MOD
            memo[index][first][second] = ans
            
            return ans
            
        return f(0, 0, 0)