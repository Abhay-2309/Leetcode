import heapq
from typing import List

class Solution:
    def minimumEffortPath(self, heights: List[List[int]]) -> int:
        n = len(heights)
        m = len(heights[0])
        vis = [[float('inf')] * m for _ in range(n)]
        pq = []
        heapq.heappush(pq, (0, 0, 0))
        vis[0][0] = 0
        
        directions = [(0, 1), (1, 0), (0, -1), (-1, 0)]
        
        while pq:
            effort, r, c = heapq.heappop(pq)
            if r == n - 1 and c == m - 1:
                return effort
            if effort > vis[r][c]:
                continue
            for dr, dc in directions:
                nr, nc = r + dr, c + dc
                if 0 <= nr < n and 0 <= nc < m:
                    new_effort = max(effort, abs(heights[r][c] - heights[nr][nc]))
                    if new_effort < vis[nr][nc]:
                        vis[nr][nc] = new_effort
                        heapq.heappush(pq, (new_effort, nr, nc))        
        return 0