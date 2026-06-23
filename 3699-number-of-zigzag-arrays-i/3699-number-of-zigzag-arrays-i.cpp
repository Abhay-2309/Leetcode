class Solution {
public:
    const static int MOD = 1e9+7;
    
    inline static int modadd(int a, int b) {
        return (a + b) % MOD;
    }
    int dp[2003][2003][2];
    int zigZagArrays(int n, int l, int r) {
        int k = r - l + 1;
        memset(dp,sizeof(dp),0);
        for (int prev = 1; prev <= k; prev++) {
            dp[n + 1][prev][0] = 1;
            dp[n + 1][prev][1] = 1;
        }
        for (int curr = n; curr >= 2; curr--) {
            int running_sum_down = 0;
            for (int prev = 1; prev <= k; prev++) {
                dp[curr][prev][0] = running_sum_down;
                running_sum_down = modadd(running_sum_down, dp[curr + 1][prev][1]);
            }
            int running_sum_up = 0;
            for (int prev = k; prev >= 1; prev--) {
                dp[curr][prev][1] = running_sum_up;
                running_sum_up = modadd(running_sum_up, dp[curr + 1][prev][0]);
            }
        }
        int total_valid_arrays = 0;
        for (int x = 1; x <= k; x++) {
            total_valid_arrays = modadd(total_valid_arrays, dp[2][x][0]);
            total_valid_arrays = modadd(total_valid_arrays, dp[2][x][1]);
        }

        return total_valid_arrays;
    }
};