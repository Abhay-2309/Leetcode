class Solution:
    def minMoves(self, nums: List[int]) -> int:
        maxi = max(nums)
        moves =0
        for ele in nums:
            moves += (maxi - ele)
        return moves