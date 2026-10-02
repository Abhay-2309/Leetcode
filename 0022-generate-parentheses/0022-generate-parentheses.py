class Solution:
    def f(self, s, o, c, ans, n)->None:
        if c==n:
            res=''.join(s)
            ans.append(res)
            return
        if o<n: 
            s.append('(')
            self.f(s, o+1, c, ans, n)
            s.pop()
        if c<o: 
            s.append(')')
            self.f(s, o, c+1, ans, n)
            s.pop()
    def generateParenthesis(self, n: int) -> list[str]:
        ans=[]
        s=[]
        self.f(s, 0, 0, ans, n)
        return ans