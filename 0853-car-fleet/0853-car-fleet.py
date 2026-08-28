class Solution:
    def carFleet(self, target: int, position: List[int], speed: List[int]) -> int:
        n = len(position) 
        if n == 0: return 0
        
        stack = []
        vec = []
        for i in range(n):
            vec.append([position[i],speed[i]])
        vec.sort(reverse = True)
        stack.append([vec[0][1],vec[0][0]])
        
        for i in range(1,n):
            currdist = vec[i][0]
            currspeed = vec[i][1]
            prevspeed = stack[-1][0]
            prevdist = stack[-1][1]
            if currspeed <= prevspeed:
                stack.append([currspeed,currdist])
            else:
                temp = stack.pop()
                prevdist = temp[1]
                prevspeed = temp[0]
                extradist = ((prevdist-currdist)*currspeed)/(currspeed-prevspeed)
                if currdist + extradist <= target:
                    stack.append([prevspeed,prevdist])
                else:
                    stack.append([prevspeed,prevdist])
                    stack.append([currspeed,currdist])
                    
        return len(stack)