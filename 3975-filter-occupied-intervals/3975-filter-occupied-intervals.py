class Solution:
    def filterOccupiedIntervals(self, occupiedIntervals: List[List[int]], freeStart: int, freeEnd: int) -> List[List[int]]:
        occupiedIntervals.sort()
        temp = []
        for start,end in occupiedIntervals:
            if not temp:
                temp.append([start,end])
            else:
                lastend = temp[len(temp)-1][1]
                if lastend >= start-1:
                    temp[len(temp)-1][1] = max(lastend, end)
                else:
                    temp.append([start,end])
        ans = []
        for start,end in temp:
            if end < freeStart or start>freeEnd:
                ans.append([start, end])
            else:
                if start<freeStart:
                    ans.append([start,freeStart-1])
                if end >freeEnd:
                    ans.append([freeEnd+1,end])
        return ans