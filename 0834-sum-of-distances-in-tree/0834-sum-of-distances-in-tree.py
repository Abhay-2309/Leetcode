from collections import defaultdict
from typing import List

class Solution:
    def sumOfDistancesInTree(self, n: int, edges: List[List[int]]) -> List[int]:
        graph = defaultdict(list)
        for u, v in edges:
            graph[u].append(v)
            graph[v].append(u)
        count = [1] * n
        ans = [0] * n 
        def dfs_bottom_up(curr_node: int, parent_node: int) -> None:
            for child in graph[curr_node]:
                if child == parent_node:
                    continue
                dfs_bottom_up(child, curr_node)
                count[curr_node] += count[child]
                ans[curr_node] += ans[child] + count[child]
        def dfs_top_down(curr_node: int, parent_node: int) -> None:
            for child in graph[curr_node]:
                if child == parent_node:
                    continue
                ans[child] = ans[curr_node] - count[child] + (n - count[child])
                dfs_top_down(child, curr_node)
        dfs_bottom_up(0, -1)
        dfs_top_down(0, -1)
        
        return ans