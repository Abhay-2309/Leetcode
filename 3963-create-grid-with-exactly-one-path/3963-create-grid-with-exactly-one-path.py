class Solution:
    def createGrid(self, m: int, n: int) -> list[str]:
        ans = [["#" for _ in range(n)] for _ in range(m)]
        start = 0
        end = 0
        move = 0 
        
        if m==1:
            res = ""
            for i in range(n):
                res+="."
            return [res]
        if n==1:
            return ["."]*m
            
        while (start < m) and (end < n):
            ans[start][end] = "."
            if (move & 1) == 0:
                if end < n - 1:
                    end += 1
                else:
                    start += 1
            else:
                if start < m - 1:
                    start += 1
                else:
                    end += 1
                    
            move += 1
            
        ans[m-1][n-1] = "."
        
        res = []
        for i in range(m):
            s = ""
            for j in range(n):
                s+=ans[i][j]
            res.append(s)
            
        return res