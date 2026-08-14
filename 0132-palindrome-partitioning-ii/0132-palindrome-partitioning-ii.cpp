class Solution {
public:
    static const int MAX = 2005;
    inline static int powerofbase[MAX];
    inline static int inverseofbase[MAX];
    inline static bool is_precomputed = false;
    static const int base = 31;
    static const int MOD = 1e9 + 7;
    inline static int modadd(int a, int b) {return (a + b) % MOD;}
    inline static int modmul(int a, int b) {return (1LL * a * b) % MOD;}
    inline static int modsub(int a, int b) {return (a - b + MOD) % MOD;}
    static int modpow(int b, int exp) {
        int res = 1;
        b = b % MOD;
        while (exp > 0) {
            if (exp % 2 == 1) res = modmul(res, b);
            b = modmul(b, b);
            exp /= 2;
        }
        return res;
    }
    static void precompute() {
        if (is_precomputed) return;
        powerofbase[0] = 1;
        inverseofbase[0] = 1;
        int inv_base = modpow(base, MOD - 2);
        for (int i = 1; i < MAX; i++) {
            powerofbase[i] = modmul(powerofbase[i - 1], base);
            inverseofbase[i] = modmul(inverseofbase[i - 1], inv_base);
        }
        is_precomputed = true;
    }
    int minCut(string s) {
        precompute();
        int n = s.size();
        vector<int> prefix(n + 1, 0), suffix(n + 1, 0);
        for(int i = 0; i < n; i++){
            int char_val = s[i] - 'a' + 1;
            prefix[i + 1] = modadd(prefix[i], modmul(char_val, powerofbase[i]));
        }
        for(int i = 0; i < n; i++){
            int char_val = s[n - 1 - i] - 'a' + 1;
            suffix[i + 1] = modadd(suffix[i], modmul(char_val, powerofbase[i]));
        }
        auto check = [&](int L, int R) -> bool {
            int forward_hash = modsub(prefix[R + 1], prefix[L]);
            forward_hash = modmul(forward_hash, inverseofbase[L]);
            int rev_L = n - 1 - R;
            int rev_R = n - 1 - L;
            int backward_hash = modsub(suffix[rev_R + 1], suffix[rev_L]);
            backward_hash = modmul(backward_hash, inverseofbase[rev_L]);
            
            return forward_hash == backward_hash;
        };
        vector<int> dp(n, -1);

        auto f = [&](auto&& self, int ind) -> int {
            if(ind == n) return 0;
            if(dp[ind] != -1) return dp[ind];
            
            int mini = 1e9; 
            for(int j = ind; j < n; j++){
                if(check(ind, j)){
                    mini = min(mini, 1 + self(self, j + 1));
                }
            }
            return dp[ind] = mini;
        };
        return f(f, 0) - 1;
    }
};

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
