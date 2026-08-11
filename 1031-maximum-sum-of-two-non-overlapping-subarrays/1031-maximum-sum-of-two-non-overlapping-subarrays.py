class Solution:
    def maxSumTwoNoOverlap(self, nums: List[int], firstLen: int, secondLen: int) -> int:
        n = len(nums)
        prefix = [0] * (n + 1)
        for i in range(n):
            prefix[i+1] = prefix[i] + nums[i]
            
        def get_max_split(L: int, R: int) -> int:
            left_max = [0] * n
            curr_max_L = 0
            for i in range(L - 1, n):
                curr_window = prefix[i + 1] - prefix[i + 1 - L]
                curr_max_L = max(curr_max_L, curr_window)
                left_max[i] = curr_max_L
            right_max = [0] * n
            curr_max_R = 0
            for i in range(n - R, -1, -1):
                curr_window = prefix[i + R] - prefix[i]
                curr_max_R = max(curr_max_R, curr_window)
                right_max[i] = curr_max_R
            max_combined = 0
            for i in range(L - 1, n - R):
                max_combined = max(max_combined, left_max[i] + right_max[i + 1])
                
            return max_combined
        return max(get_max_split(firstLen, secondLen), get_max_split(secondLen, firstLen))