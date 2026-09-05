class Solution:
    def firstStableIndex(self, nums: list[int], k: int) -> int:
        n = len(nums)
        prefixmax = [float('-inf')]*(n+1)
        suffixmini = [float('inf')]*(n+1)
        for i in range(0,n):
            prefixmax[i+1] = max(prefixmax[i],nums[i])
        for i in range(n-1,-1,-1):
            suffixmini[i] = min(suffixmini[i+1],nums[i])
        for i in range(n):
            maxi = prefixmax[i+1]
            mini = suffixmini[i]
            if maxi-mini <=k:
                return i
        return -1