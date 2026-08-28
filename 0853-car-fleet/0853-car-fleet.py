class Solution:
    def carFleet(self, target: int, position: List[int], speed: List[int]) -> int:
        n = len(position) 
        if n == 0: return 0
        speed_at_pos = [0] * (target + 1)
        for i in range(n):
            speed_at_pos[position[i]] = speed[i]
        stack = []
        for currdist in range(target, -1, -1):
            if speed_at_pos[currdist] > 0:
                currspeed = speed_at_pos[currdist]
                if not stack:
                    stack.append([currspeed, currdist])
                    continue
                prevspeed = stack[-1][0]
                prevdist = stack[-1][1]
                if currspeed <= prevspeed:
                    stack.append([currspeed, currdist])
                else:
                    temp = stack.pop()
                    prevdist = temp[1]
                    prevspeed = temp[0]
                    extradist = ((prevdist - currdist) * currspeed) / (currspeed - prevspeed)
                    if currdist + extradist <= target:
                        stack.append([prevspeed, prevdist])
                    else:
                        stack.append([prevspeed, prevdist])
                        stack.append([currspeed, currdist])
        return len(stack)