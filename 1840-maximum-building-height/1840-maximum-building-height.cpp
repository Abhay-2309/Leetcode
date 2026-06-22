#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxBuilding(int n, vector<vector<int>>& restrictions) {
        restrictions.push_back({1, 0});
        restrictions.push_back({n, n - 1});
        sort(restrictions.begin(), restrictions.end());
        
        int m = restrictions.size();
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> h(m);
        for (int i = 0; i < m; ++i) {
            h[i] = restrictions[i][1];
            pq.push({h[i], i});
        }
        while (!pq.empty()) {
            auto [curr_h, u] = pq.top();
            pq.pop();
            if (curr_h > h[u]) continue;
            if (u > 0) {
                int dist = restrictions[u][0] - restrictions[u - 1][0];
                if (h[u - 1] > curr_h + dist) {
                    h[u - 1] = curr_h + dist;
                    pq.push({h[u - 1], u - 1});
                }
            }
            if (u < m - 1) {
                int dist = restrictions[u + 1][0] - restrictions[u][0];
                if (h[u + 1] > curr_h + dist) {
                    h[u + 1] = curr_h + dist;
                    pq.push({h[u + 1], u + 1});
                }
            }
        }
        int max_height = 0;
        for (int i = 0; i < m - 1; ++i) {
            int x1 = restrictions[i][0], h1 = h[i];
            int x2 = restrictions[i + 1][0], h2 = h[i + 1];
            int peak = (h1 + h2 + (x2 - x1)) / 2;
            max_height = max(max_height, peak);
        }
        return max_height;
    }
};