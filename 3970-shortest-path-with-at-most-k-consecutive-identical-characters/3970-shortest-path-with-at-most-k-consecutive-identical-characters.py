import heapq
from typing import List

class Solution:
    def shortestPath(self, n: int, edges: List[List[int]], labels: str, k: int) -> int:
        adj = [[] for _ in range(n)]
        for u, v, w in edges:
            adj[u].append((v, w))
            
        dist = [[float('inf')] * (k + 1) for _ in range(n)]
        pq = []
        
        dist[0][1] = 0
        heapq.heappush(pq, (0, 0, 1))
        
        while pq:
            curr_dist, u, curr_consec = heapq.heappop(pq)
            
            if curr_dist > dist[u][curr_consec]:
                continue
                
            if u == n - 1:
                return curr_dist
                
            for v, weight in adj[u]:
                if labels[u] == labels[v]:
                    next_consec = curr_consec + 1
                else:
                    next_consec = 1
                
                if next_consec > k:
                    continue
                    
                if curr_dist + weight < dist[v][next_consec]:
                    dist[v][next_consec] = curr_dist + weight
                    heapq.heappush(pq, (dist[v][next_consec], v, next_consec))
                    
        return -1