class Solution:
    def uniqueXorTriplets(self, nums: List[int]) -> int:
        n = len(nums)
        if n==1:
            return 1
        if n==2:
            return 2
        if n==3:
            return 4
        length = n.bit_length()
        return (1<<length)