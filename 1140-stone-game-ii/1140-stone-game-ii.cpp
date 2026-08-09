class Solution {
public:
    int f(int person, int ind, int M, vector<int>& arr, vector<vector<vector<int>>>& dp) {
        int n = arr.size();
        if (ind >= n) return 0;

        if (dp[person][ind][M] != -1)
            return dp[person][ind][M];

        int take = 0;
        int result = (person == 1) ? -1 : 1e9;

        for (int x = 1; x <= min(2 * M, n - ind); ++x) {
            take += arr[ind + x - 1];
            if (person == 1) {
                result = max(result, take + f(0, ind + x, max(M, x), arr, dp)); // Alice's turn
            } else {
                result = min(result, f(1, ind + x, max(M, x), arr, dp)); // Bob's turn
            }
        }

        return dp[person][ind][M] = result;
    }

    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        vector<vector<vector<int>>> dp(2, vector<vector<int>>(n + 1, vector<int>(n + 1, -1)));
        return f(1, 0, 1, piles, dp);
    }
};
