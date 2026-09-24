class Solution:
    def smallestIndex(self, nums: List[int]) -> int:
        n = len(nums)
        def f(num: int)->int:
            s = 0
            while num:
                s += (num%10)
                num//=10
            return s
        for i in range(n):
            if f(nums[i])==i:
                return i
        return -1