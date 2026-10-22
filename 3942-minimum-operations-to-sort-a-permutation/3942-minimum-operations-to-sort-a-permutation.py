class Solution:
    def minOperations(self, nums: List[int]) -> int:
        n = len(nums)
        if n==1:
            return 0
        idx =-1
        def f()->int:
            nonlocal idx
            if n<=1:return True
            isIncreasing = True
            isDecreasing = True
            for i in range(n):
                rawdiff = nums[(i+1)%n] - nums[i]
                moddifference = ((rawdiff%n)+n)%n
                if nums[i]==0:
                    idx=i
                if moddifference!=1:
                    isIncreasing = False
                if moddifference!=(n-1):
                    isDecreasing = False
            if isIncreasing :
                return 1
            if isDecreasing:
                return 2
            return 3
        check = f()
        if check==3:
            return -1
        if check ==1:
            return min(idx,2+(n-idx))
        return min(idx+1,n-1-idx)+1