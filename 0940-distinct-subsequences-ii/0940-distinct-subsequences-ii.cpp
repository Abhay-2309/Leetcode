class Solution {
public:
    static const int MOD = 1e9+7;
    static inline int modadd(int a,int b){
        return (a+b)%MOD;
    }
    int distinctSubseqII(string s) {
        int n = s.size();
        int dp[26] = {0};
        int ans = 0;
        
        for(int i = 0; i < n; i++) {
            int newtotal = (modadd(ans, ans) - dp[s[i]-'a'] + 1) % MOD;
            if (newtotal < 0) {
                newtotal += MOD;
            }
            dp[s[i]-'a'] = (ans + 1) % MOD;
            ans = newtotal;
        }
        return ans;
    }
};