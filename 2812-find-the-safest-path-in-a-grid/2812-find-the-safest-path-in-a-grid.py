import heapq
from collections import deque
from typing import List

class Solution:
    def maximumSafenessFactor(self, grid: List[List[int]]) -> int:
        n = len(grid)
        m = len(grid[0])
        vis = [[float('inf')] * m for _ in range(n)]
        q = deque()
        directions = [(1, 0), (-1, 0), (0, 1), (0, -1)]
        
        for i in range(n):
            for j in range(m):
                if grid[i][j] == 1:
                    vis[i][j] = 0
                    q.append((0, i, j))
                    
        while q:
            efforts, r, c = q.popleft()
            for dr, dc in directions:
                nr, nc = r + dr, c + dc
                if 0 <= nr < n and 0 <= nc < m:
                    if vis[nr][nc] > 1 + vis[r][c]:
                        vis[nr][nc] = 1 + vis[r][c]
                        q.append((vis[nr][nc], nr, nc))
        pq = [(-vis[0][0], 0, 0)]
        seen = [[False] * m for _ in range(n)]
        seen[0][0] = True
        while pq:
            safe, r, c = heapq.heappop(pq)
            safe = -safe
            if r == n - 1 and c == m - 1:
                return safe
            for dr, dc in directions:
                nr, nc = r + dr, c + dc
                if 0 <= nr < n and 0 <= nc < m and not seen[nr][nc]:
                    seen[nr][nc] = True
                    new_safe = min(safe, vis[nr][nc])
                    heapq.heappush(pq, (-new_safe, nr, nc))
        return 0