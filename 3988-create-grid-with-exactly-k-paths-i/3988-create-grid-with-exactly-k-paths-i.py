class Solution:
    def createGrid(self, m: int, n: int, k: int) -> list[str]:
        if n == 1 or m == 1:
            if k != 1:
                return []
            if m == 1:
                return ['.' * n]
            if n == 1:
                return ['.']*m
        if k == 1:
            ans = ['.' * n]
            for _ in range(m - 1):
                ans.append('#' * (n - 1) + '.')
            return ans
        elif k == 2:
            if n >= 2 and m >= 2:
                ans = ['.' * n]
                ans.append('#' * (n - 2) + '..')
                for _ in range(m - 2):
                    ans.append('#' * (n - 1) + '.')
                return ans
            return []
        elif k == 3:
            if n >= 3 and m >= 2:
                ans = ['.' * n]
                ans.append('#' * (n - 3) + '...')
                for _ in range(m - 2):
                    ans.append('#' * (n - 1) + '.')
                return ans
            elif m >= 3 and n >= 2:
                ans = ['.' * n]
                ans.append('#' * (n - 2) + '..')
                ans.append('#' * (n - 2) + '..')
                for _ in range(m - 3):
                    ans.append('#' * (n - 1) + '.')
                return ans
            return []
        elif k == 4:
            if n >= 3 and m >= 3:
                ans = ['.' * (n - 1) + '#']
                ans.append('#' * (n - 3) + '...')
                ans.append('#' * (n - 3) + '#..')
                for _ in range(m - 3):
                    ans.append('#' * (n - 1) + '.')
                return ans
            elif m == 2 and n >= 4:
                return [
                    '.' * 4 + '#' * (n - 4),
                    '.' * n                  
                ]
            elif n == 2 and m >= 4:
                ans = []
                for i in range(m):
                    if i < 4:
                        ans.append('..')    
                    else:
                        ans.append('#.')     
                return ans
                
            return []
        return []