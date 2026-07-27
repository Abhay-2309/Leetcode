class Solution:
    def aggregateTimeSeries(self, series1: list[list[int]], series2: list[list[int]]) -> list[list[int]]:
        n = len(series1)
        m = len(series2)
        
        first_val = defaultdict(int)
        second_val = defaultdict(int)
        totalid = set()
        
        for i in range(n):
            first_val[series1[i][0]] = series1[i][1]
            totalid.add(series1[i][0])
            
        for i in range(m):
            second_val[series2[i][0]] = series2[i][1]
            totalid.add(series2[i][0])
            
        t1 = [x[0] for x in series1]
        t2 = [x[0] for x in series2]
        
        for ids in totalid:
            if ids in first_val and ids in second_val:
                continue
            if ids in first_val and ids not in second_val:
                index = bisect_left(t2, ids)
                if index != m:
                    second_val[ids] = series2[index][1]
                else:
                    second_val[ids] = 0
                continue
            if ids in second_val and ids not in first_val:
                index = bisect_left(t1, ids)
                if index != n:
                    first_val[ids] = series1[index][1]
                else:
                    first_val[ids] = 0
                    
        result = []
        for ids in sorted(totalid):
            result.append([ids, first_val[ids] + second_val[ids]])
            
        return result