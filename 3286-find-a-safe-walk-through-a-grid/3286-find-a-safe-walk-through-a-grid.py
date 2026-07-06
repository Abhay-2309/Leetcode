from collections import deque
from typing import List

class Solution:
    def findSafeWalk(self, grid: List[List[int]], health: int) -> bool:
        n = len(grid)
        m = len(grid[0])
        
        pq = deque([(0, 0)])
        mincost = [[float('inf')] * m for _ in range(n)]
        mincost[0][0] = grid[0][0]
        
        directions = [[-1, 0], [0, 1], [0, -1], [1, 0]]
        
        while pq:
            r, c = pq.popleft()
            
            for dx, dy in directions:
                newr, newc = r + dx, c + dy
                
                if 0 <= newr < n and 0 <= newc < m:
                    cost = grid[newr][newc]
                    
                    if mincost[newr][newc] > mincost[r][c] + cost:
                        mincost[newr][newc] = mincost[r][c] + cost
                        
                        if cost == 0:
                            pq.appendleft((newr, newc))
                        else:
                            pq.append((newr, newc))
                            
        total_damage = mincost[n-1][m-1]
        return (health - total_damage) >= 1