class Solution:
    def countMajoritySubarrays(self, nums: List[int], target: int) -> int:
        n = len(nums)
        cnt = 0
        for left in range(n):
            freq = 0
            for right in range(left,n):
                if target == nums[right]:
                    freq+=1
                length = right - left + 1
                if (freq<<1)>length:
                    cnt+=1
        return cnt
                