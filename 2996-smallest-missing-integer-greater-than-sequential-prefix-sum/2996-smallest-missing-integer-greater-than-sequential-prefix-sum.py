class Solution:
    def missingInteger(self, nums: List[int]) -> int:
        n = len(nums)
        if n == 1:
            return nums[0] + 1
            
        currsum = 0
        ptr = 0
        indexmapped = [-1] * 5000 
        for i in range(n):
            indexmapped[nums[i]] = i
            
        while ptr < n:
            if ptr > 0 and nums[ptr] != nums[ptr-1] + 1:
                break
                
            currsum += nums[ptr]
            ptr += 1
        res = currsum
        while indexmapped[res] != -1:
            res += 1
            
        return res