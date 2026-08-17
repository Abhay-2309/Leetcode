class Solution {
public:
    int stoneGameV(vector<int>& stoneValue) {
        int n = stoneValue.size();
        vector<int> pref(n + 1, 0);
        for(int i = 0; i < n; i++) pref[i + 1] = pref[i] + stoneValue[i];
        vector<vector<int>> dp(n, vector<int>(n, 0));
        vector<vector<int>> maxLeft(n, vector<int>(n, 0));
        vector<vector<int>> maxRight(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            maxLeft[i][i] = stoneValue[i];
            maxRight[i][i] = stoneValue[i];
        }
        for (int L = n - 1; L >= 0; L--) {
            int mid = L; 
            for (int R = L + 1; R < n; R++) {
                int total_sum = pref[R + 1] - pref[L];
                while (mid < R && (pref[mid + 1] - pref[L]) * 2 < total_sum)mid++;
                int res = 0;
                if (mid > L) res = max(res, maxLeft[L][mid - 1]);
                int left_sum = pref[mid + 1] - pref[L];
                if (left_sum * 2 == total_sum) res = max(res, maxLeft[L][mid]);
                if (mid + 1 <= R) res = max(res, maxRight[mid + 1][R]);
                dp[L][R] = res;
                maxLeft[L][R] = max(maxLeft[L][R - 1], total_sum + dp[L][R]);
                maxRight[L][R] = max(maxRight[L + 1][R], total_sum + dp[L][R]);
            }
        }
        return dp[0][n - 1];
    }
};