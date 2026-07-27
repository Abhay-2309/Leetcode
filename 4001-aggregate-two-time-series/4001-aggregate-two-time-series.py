class Solution:
    def aggregateTimeSeries(self, series1: list[list[int]], series2: list[list[int]]) -> list[list[int]]:
        p1 = len(series1) - 1
        p2 = len(series2) - 1
        next_v1 = 0
        next_v2 = 0
        
        res = []
        while p1 >= 0 or p2 >= 0:
            t1 = series1[p1][0] if p1 >= 0 else -1
            t2 = series2[p2][0] if p2 >= 0 else -1
            
            if t1 > t2:
                next_v1 = series1[p1][1]
                res.append([t1, next_v1 + next_v2])
                p1 -= 1
                
            elif t2 > t1:
                next_v2 = series2[p2][1]
                res.append([t2, next_v1 + next_v2])
                p2 -= 1
                
            else:
                next_v1 = series1[p1][1]
                next_v2 = series2[p2][1]
                res.append([t1, next_v1 + next_v2])
                p1 -= 1
                p2 -= 1
        res.reverse()
        return res