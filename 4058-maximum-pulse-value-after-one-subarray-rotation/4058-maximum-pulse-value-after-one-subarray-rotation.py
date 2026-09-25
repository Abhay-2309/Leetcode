class Solution:
    def maxValue(self, nums: List[int]) -> int:
        n = len(nums)
        P = 0
        b = [0] * n
        
        for i in range(n):
            if i % 2 == 0:
                P += nums[i]
                b[i] = -2 * nums[i]
            else:
                P -= nums[i]
                b[i] = 2 * nums[i]
                
        if n == 1:
            return P
            
        p = [0] * n
        p[0] = 0
        p[1] = max(0, b[1] + b[0])
        
        for i in range(2, n):
            p[i] = max(0, b[i] + b[i-1], b[i] + b[i-1] + p[i-2])
            
        return P + max(p)