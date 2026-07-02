class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int n = grid.size();
        int m = grid[0].size();
        int start_health = health - grid[0][0];
        if (start_health < 1) return false;
        queue<pair<int, pair<int, int>>> pq;
        pq.push({start_health, {0, 0}});
        vector<vector<int>> max_health(n, vector<int>(m, -1));
        max_health[0][0] = start_health;
        vector<pair<int, int>> dir = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}};
        while (!pq.empty()) {
            auto itr = pq.front();
            pq.pop();
            int curr_health = itr.first;
            int curr_row = itr.second.first;
            int curr_col = itr.second.second;
            if (curr_row == n - 1 && curr_col == m - 1) {
                return true;
            }
            
            for (const auto& d : dir) {
                int next_row = curr_row + d.first;
                int next_col = curr_col + d.second;
                if (next_row >= 0 && next_row < n && next_col >= 0 && next_col < m) {
                    int next_health = curr_health - grid[next_row][next_col];
                    if (next_health >= 1 && next_health > max_health[next_row][next_col]) {
                        max_health[next_row][next_col] = next_health;
                        pq.push({next_health, {next_row, next_col}});
                    }
                }
            }
        }
        
        return false;
    }
};