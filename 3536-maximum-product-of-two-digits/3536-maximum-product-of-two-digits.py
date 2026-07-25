class Solution:
    def maxProduct(self, n: int) -> int:
        firstmaxi = 0
        secondmaxi = 0
        temp = abs(n)
        
        while temp:
            digit = temp % 10
            
            if digit > firstmaxi:
                secondmaxi = firstmaxi
                firstmaxi = digit
            elif digit > secondmaxi:
                secondmaxi = digit
                
            temp = temp // 10
            
        return firstmaxi * secondmaxi