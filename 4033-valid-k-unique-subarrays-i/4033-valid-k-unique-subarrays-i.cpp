auto init = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 'c';
}();

class Solution {
private:
    vector<int> bit;
    int n;
    inline void add(int idx, int val) {
        for (; idx <= n; idx += idx & -idx) {
            bit[idx] += val;
        }
    }
    inline int query(int idx) {
        int sum = 0;
        for (; idx > 0; idx -= idx & -idx) {
            sum += bit[idx];
        }
        return sum;
    }

public:
    vector<bool> validSubarrays(vector<int>& nums, int k, vector<vector<int>>& queries) {
        n = nums.size();
        int q = queries.size();
        vector<bool> ans(q, false);
        vector<vector<pair<int, int>>> queries_by_r(n);
        for (int i = 0; i < q; ++i) {
            queries_by_r[queries[i][1]].push_back({queries[i][0], i});
        }
        mt19937_64 rng(1337);
        const int MAXL = 100005;
        vector<uint64_t> hash_val(MAXL);
        for (int i = 0; i < MAXL; ++i) {
            hash_val[i] = rng();
        }
        
        vector<uint64_t> pref_xor(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            pref_xor[i + 1] = pref_xor[i] ^ hash_val[nums[i]];
        }
        bit.assign(n + 1, 0);
        vector<int> last_pos(MAXL, -1);
        
        for (int r = 0; r < n; ++r) {
            int val = nums[r];
            if (last_pos[val] != -1) {
                add(last_pos[val] + 1, -1);
            }
            add(r + 1, 1);
            last_pos[val] = r;
            for (const auto& q_data : queries_by_r[r]) {
                int l = q_data.first;
                int q_idx = q_data.second;
                
                int distinct_count = query(r + 1) - query(l);
                bool is_even = (pref_xor[r + 1] == pref_xor[l]);
                
                if (distinct_count == k && is_even) {
                    ans[q_idx] = true;
                }
            }
        }
        
        return ans;
    }
};