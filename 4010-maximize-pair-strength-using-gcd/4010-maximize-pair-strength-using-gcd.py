from math import gcd

class Solution:
    def maxPairStrength(self, nums: list[int]) -> int:
        n = len(nums)
        maxi = 0
        for i in range(n):
            for j in range(i + 1, n):
                tar = (nums[i] * nums[j]) // (gcd(nums[i], nums[j]) ** 2)
                maxi = max(maxi, tar)
        return maxi