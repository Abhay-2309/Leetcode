class Solution {
public:
    const int MOD = 1e9+7;
    int numberOfUniqueGoodSubsequences(string binary) {
        int n = binary.size();
        long long dp[2] = {0, 0};
        long long total = 0;
        bool hasZero = false;
        for (int i = n - 1; i >= 0; i--) {
            int idx = binary[i] - '0';
            if (binary[i] == '0') hasZero = true;
            long long val = (1 + total) % MOD;
            total = (total + val - dp[idx] + MOD) % MOD;
            dp[idx] = val;
        }
        long long ans = dp[1];
        if (hasZero) ans = (ans + 1) % MOD;
        return (int) ans;
    }
};