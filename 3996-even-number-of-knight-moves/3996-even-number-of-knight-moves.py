class Solution:
    def canReach(self, start: list[int], end: list[int]) -> bool:
        block1 = start[0]*7 + start[1]
        block2 = end[0]*7 + end[1]
        return (block1%2) == (block2%2)