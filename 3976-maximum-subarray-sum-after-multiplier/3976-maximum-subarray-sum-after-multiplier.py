class Solution:
    INF = float('-inf')
    def maxSubarraySum(self, nums: List[int], k: int) -> int:
        n = len(nums)
        def f1()->int:
            a = float('-inf')
            b = float('-inf')
            c = float('-inf')
            maxi = float('-inf')
            for i,val in enumerate(nums):
                temp = val*k
                nexta = max(val,a+val)
                nextb = max([temp,a+temp,b+temp])
                nextc = max(b+val,c+val)
                a = nexta
                b = nextb
                c = nextc
                maxi = max([maxi,b,c]);
            return maxi
        def f2()->int:
            a = float('-inf')
            b = float('-inf')
            c = float('-inf')
            maxi = float('-inf')
            for i,val in enumerate(nums):
                temp = int(val/k)
                nexta = max(val,a+val)
                nextb = max([temp,a+temp,b+temp])
                nextc = max(b+val,c+val)
                a = nexta
                b = nextb
                c = nextc
                maxi = max([maxi,b,c]);
            return maxi
        ans1 = f1()
        ans2 = f2()
        res = float('-inf')
        curr = 0
        index =0
        while index<len(nums):
            curr = max(nums[index],curr+nums[index])
            res = max(res,curr)
            index+=1
        return max([res,ans1,ans2])