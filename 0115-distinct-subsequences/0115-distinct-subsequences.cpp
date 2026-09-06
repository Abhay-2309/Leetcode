class Solution {
public:
    int dp[1001][1001];
    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();
        memset(dp,-1,sizeof(dp));
        auto f = [&](auto&& self, int m,int n)->int{
            if(n==0) return 1;
            if(m==0) return 0;
            if(dp[m][n]!=-1) return dp[m][n];
            if(s[m-1]==t[n-1]) return dp[m][n] = self(self,m-1,n-1)+self(self,m-1,n);
            else return dp[m][n] = self(self,m-1,n);
            return -1;
        };
        return f(f,n,m);
    }
};