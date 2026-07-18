class Solution:
    def maxConsistentColumns(self, grid: list[list[int]], limit: int) -> int:
        m = len(grid)
        n = len(grid[0])
        dp = [1] * n
        def is_compatible(col_a, col_b):
            for row in range(m):
                if abs(grid[row][col_b] - grid[row][col_a]) > limit:
                    return False
            return True
        for current_col in range(n):
            for previous_col in range(current_col):
                if is_compatible(previous_col, current_col):
                    dp[current_col] = max(dp[current_col], dp[previous_col] + 1)
        return max(dp)