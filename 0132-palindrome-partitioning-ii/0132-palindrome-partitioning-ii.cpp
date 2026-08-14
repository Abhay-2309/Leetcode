class Solution {
public:
    int minCut(string s) {
        int n = s.size();
        if (n <= 1) return 0;
        string t = "#";
        for (char c : s) {
            t += c;
            t += "#";
        }
        
        int m = t.size();
        vector<int> P(m, 0);
        int C = 0, R = 0;
        
        for (int i = 0; i < m; i++) {
            int i_mirror = 2 * C - i;
            
            if (R > i) {
                P[i] = min(R - i, P[i_mirror]);
            }
            while (i - 1 - P[i] >= 0 && i + 1 + P[i] < m && t[i - 1 - P[i]] == t[i + 1 + P[i]]) {
                P[i]++;
            }
            if (i + P[i] > R) {
                C = i;
                R = i + P[i];
            }
        }
        vector<int> dp(n);
        
        for (int i = 0; i < n; i++) {
            dp[i] = i; 
            
            for (int j = 0; j <= i; j++) {
                if (P[j + i + 1] >= i - j + 1) {
                    
                    if (j == 0) {
                        dp[i] = 0;
                    } else {
                        dp[i] = min(dp[i], dp[j - 1] + 1);
                    }
                }
            }
        }
        return dp[n - 1];
    }
};