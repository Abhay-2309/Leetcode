class Solution:
    def finishTime(self, n: int, edges: List[List[int]], baseTime: List[int]) -> int:
        graph = [[] for _ in range(n)]
        for u,v in edges:
            graph[v].append(u)
            graph[u].append(v)
        ans = 0
        def f(curr_node:int,parent_node:int)->int:
            finishTimes = []
            if not graph[curr_node]:
                return baseTime[curr_node]
            for child in graph[curr_node]:
                if child==parent_node:
                    continue
                finishTimes.append(f(child,curr_node))
            if not finishTimes:                
                return baseTime[curr_node]
            earliest = min(finishTimes)
            latest = max(finishTimes)
            ownDuration = (latest - earliest) + baseTime[curr_node]
            return latest + ownDuration
        return f(0,-1)