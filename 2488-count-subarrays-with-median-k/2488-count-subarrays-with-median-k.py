from typing import List
from collections import defaultdict

class Solution:
    def countSubarrays(self, nums: List[int], k: int) -> int:
        k_index = nums.index(k)
        left_counts = defaultdict(int)
        left_counts[0] = 1 
        balance = 0
        for i in range(k_index - 1, -1, -1):
            if nums[i] > k:
                balance += 1
            else:
                balance -= 1
                
            left_counts[balance] += 1
            
        ans = 0
        balance = 0
        for i in range(k_index, len(nums)):
            if nums[i] > k:
                balance += 1
            elif nums[i] < k:
                balance -= 1
            ans += left_counts[-balance]      
            ans += left_counts[1 - balance]   
            
        return ans