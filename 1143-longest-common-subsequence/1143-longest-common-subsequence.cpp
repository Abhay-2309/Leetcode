class Solution {
public:
    int f(int i,int j, string& s1, string& s2, vector<vector<int>>&dp){
        int n = s1.size();
        int m = s2.size();
        if(i<0||j<0) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        if(s1[i]==s2[j]) return dp[i][j] = 1 + f(i-1,j-1,s1,s2,dp);
        else return dp[i][j] = max(f(i-1,j,s1,s2,dp),f(i,j-1,s1,s2,dp));
    }
    int longestCommonSubsequence(string s1, string s2) {
        vector<vector<int>> dp(s1.size(),vector<int>(s2.size(),-1));
        return f(s1.size()-1,s2.size()-1,s1,s2,dp);
    }
};