class Solution:
    def countOfPairs(self, n: int, x: int, y: int) -> list[int]:
        if x > y:
            x, y = y, x
            
        diff = [0] * (n + 2)
        def add_range(start: int, end: int):
            if start <= end:
                diff[start] += 1
                diff[end + 1] -= 1
                
        for i in range(1, n):
            if abs(i - y) <= abs(i - x) + 1:
                add_range(1, n - i)
            else:
                S = (i + abs(i - x) + 1 + y) // 2
                add_range(1, S - i)
                add_range(abs(i - x) + 1, abs(i - x) + y - S)
                add_range(abs(i - x) + 2, abs(i - x) + 1 + n - y)
        res = [0] * n
        current_active = 0
        for k in range(1, n + 1):
            current_active += diff[k]
            res[k - 1] = current_active * 2
            
        return res