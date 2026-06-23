class Solution {
public:
    const static int MOD = 1e9+7;
    
    inline static int modadd(int a, int b) {
        return (a + b) % MOD;
    }
    
    int zigZagArrays(int n, int l, int r) {
        int k = r - l + 1;
        int next_dp[2005][2];
        int curr_dp[2005][2];
        for (int prev = 1; prev <= k; prev++) {
            next_dp[prev][0] = 1;
            next_dp[prev][1] = 1;
        }
        
        for (int curr = n; curr >= 2; curr--) {
            int running_sum_down = 0;
            for (int prev = 1; prev <= k; prev++) {
                curr_dp[prev][0] = running_sum_down;
                running_sum_down = modadd(running_sum_down, next_dp[prev][1]);
            }
            int running_sum_up = 0;
            for (int prev = k; prev >= 1; prev--) {
                curr_dp[prev][1] = running_sum_up;
                running_sum_up = modadd(running_sum_up, next_dp[prev][0]);
            }
            memcpy(next_dp, curr_dp, sizeof(int) * (k + 1) * 2);
        }
        
        int total_valid_arrays = 0;
        for (int x = 1; x <= k; x++) {
            total_valid_arrays = modadd(total_valid_arrays, next_dp[x][0]);
            total_valid_arrays = modadd(total_valid_arrays, next_dp[x][1]);
        }

        return total_valid_arrays;
    }
};