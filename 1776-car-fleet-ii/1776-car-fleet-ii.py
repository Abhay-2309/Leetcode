class Solution:
    def getCollisionTimes(self, cars: List[List[int]]) -> List[float]:
        n = len(cars)
        ans = [-1.0] * n
        stack = []
        for i in range(n - 1, -1, -1):
            currdist = cars[i][0]
            currspeed = cars[i][1]
            
            while stack:
                j = stack[-1] 
                prevdist = cars[j][0]
                prevspeed = cars[j][1]
                if currspeed <= prevspeed:
                    stack.pop()
                    continue
                col_time = (prevdist - currdist) / (currspeed - prevspeed)
                if ans[j] != -1.0 and col_time >= ans[j]:
                    stack.pop()
                    continue
                ans[i] = col_time
                break
            stack.append(i)
            
        return ans