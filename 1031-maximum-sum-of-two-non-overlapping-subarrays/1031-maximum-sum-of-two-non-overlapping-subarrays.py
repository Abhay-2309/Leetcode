class Solution:
    def maxSumTwoNoOverlap(self, nums: List[int], firstLen: int, secondLen: int) -> int:
        n = len(nums)
        
        def f(l:int,r:int)->int:
            if r-l+1 < secondLen:
                return 0
            
            L = l
            R = l
            curr_win_sum = 0 
            for _ in range(secondLen):
                curr_win_sum += nums[R]
                R += 1
            maxi = curr_win_sum
            while R <= r:
                curr_win_sum = curr_win_sum - nums[L] + nums[R]
                maxi = max(maxi, curr_win_sum)
                L += 1
                R += 1    
            return maxi

        left = 0
        right = 0
        currsum = 0
        for _ in range(firstLen):
            currsum += nums[right]
            right += 1
        res = currsum + max(f(0, left-1), f(right, n-1))
        
        while right < n:
            currsum = currsum - nums[left] + nums[right]
            left += 1
            right += 1
            tempsumsecond = max(f(0, left-1), f(right, n-1))
            res = max(res, currsum + tempsumsecond)
            
        return res