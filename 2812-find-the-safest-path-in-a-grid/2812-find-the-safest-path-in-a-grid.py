from collections import deque
from typing import List

class Solution:
    def __init__(self):
        self.directions = [(1, 0), (-1, 0), (0, -1), (0, 1)]

    def check(self, distNearestThief: List[List[int]], sf: int, n: int) -> bool:
        que = deque()
        visited = [[False] * n for _ in range(n)]
        que.append((0, 0))
        visited[0][0] = True

        if distNearestThief[0][0] < sf:
            return False

        while que:
            curr_i, curr_j = que.popleft()

            if curr_i == n - 1 and curr_j == n - 1:
                return True

            for dr, dc in self.directions:
                new_i = curr_i + dr
                new_j = curr_j + dc

                if 0 <= new_i < n and 0 <= new_j < n and not visited[new_i][new_j]:
                    if distNearestThief[new_i][new_j] < sf:
                        continue
                    
                    que.append((new_i, new_j))
                    visited[new_i][new_j] = True

        return False

    def maximumSafenessFactor(self, grid: List[List[int]]) -> int:
        n = len(grid)
        distNearestThief = [[-1] * n for _ in range(n)]
        que = deque()
        visited = [[False] * n for _ in range(n)]
        for i in range(n):
            for j in range(n):
                if grid[i][j] == 1:
                    que.append((i, j))
                    visited[i][j] = True

        level = 0
        while que:
            size = len(que)
            for _ in range(size):
                curr_i, curr_j = que.popleft()
                distNearestThief[curr_i][curr_j] = level
                for dr, dc in self.directions:
                    new_i = curr_i + dr
                    new_j = curr_j + dc
                    if new_i < 0 or new_i >= n or new_j < 0 or new_j >= n or visited[new_i][new_j]:
                        continue
                    que.append((new_i, new_j))
                    visited[new_i][new_j] = True

            level += 1
        l = 0
        r = 400
        result = 0
        while l <= r:
            mid_sf = l + (r - l) // 2
            if self.check(distNearestThief, mid_sf, n):
                result = mid_sf
                l = mid_sf + 1
            else:
                r = mid_sf - 1
        return result