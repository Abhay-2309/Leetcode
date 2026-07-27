class Solution {
public:
    int countValidSequences(int n, int k) {
        long long MOD = 1e9 + 7;
        auto power = [&](long long base, long long exp) {
            long long res = 1;
            base %= MOD;
            while (exp > 0) {
                if (exp % 2 == 1) res = (res * base) % MOD;
                base = (base * base) % MOD;
                exp /= 2;
            }
            return res;
        };
        auto modInverse = [&](long long num) {
            return power(num, MOD - 2);
        };
        vector<long long> fact(n + 1, 1);
        vector<long long> invFact(n + 1, 1);
        
        for (int i = 2; i <= n; i++) {
            fact[i] = (fact[i - 1] * i) % MOD;
        }
        invFact[n] = modInverse(fact[n]);
        for (int i = n - 1; i >= 1; i--) {
            invFact[i] = (invFact[i + 1] * (i + 1)) % MOD;
        }
        auto nCr = [&](int N, int R) -> long long {
            if (R < 0 || R > N) return 0;
            if (R == 0 || R == N) return 1;
            long long res = fact[N];
            res = (res * invFact[R]) % MOD;
            res = (res * invFact[N - R]) % MOD;
            return res;
        };
        long long total_ways = nCr(n - 1, k - 1);
        long long odd_ways = 0;
        if ((n + k) % 2 == 0) {
            int m = (n + k) / 2;
            odd_ways = nCr(m - 1, k - 1);
        }
        long long ans = (total_ways - odd_ways + MOD) % MOD;
        return ans;
    }
};