class Solution:
    def countRatioSubarrays(self, nums: list[int], a: int, b: int) -> int:
        val = a//b
        n = len(nums)
        cnt =0
        for i in range(n):
            odd =0
            even =0
            for j in range(i,n):
                if nums[j]&1:
                    odd+=1
                else:
                    even+=1
                if (even*b)<=(odd*a):
                    cnt+=1
        return cnt