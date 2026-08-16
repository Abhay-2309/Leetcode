class Solution:
    def stoneGameIX(self, stones: List[int]) -> bool:
        zero = 0
        one = 0
        second = 0
        for num in stones:
            if num % 3 == 0:
                zero += 1
            elif num % 3 == 1:
                one += 1
            else:
                second += 1
        if zero % 2 == 0:
            if one != 0 and second != 0:
                return True
            else:
                return False
        else:
            if one > second + 2:
                return True
            elif second > one + 2:
                return True
            else:
                return False