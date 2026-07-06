class Solution:
    def removeCoveredIntervals(self, intervals: List[List[int]]) -> int:
        n = len(intervals)
        intervals.sort()
        prevstart = intervals[0][0]
        preend = intervals[0][1]
        remove_cnt = 0
        for index in range(1, n):
            curr_start = intervals[index][0]
            curr_end = intervals[index][1]
            if curr_start == prevstart:
                preend = curr_end
                remove_cnt += 1
            else:
                if preend >= curr_end:
                    remove_cnt += 1
                else:
                    prevstart, preend = curr_start, curr_end 
        return n - remove_cnt