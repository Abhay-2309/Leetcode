class FenwickTree {
    vector<int> tree;
public:
    FenwickTree(int n) : tree(n + 1, 0) {}
    
    void add(int i, int delta) {
        for (; i < tree.size(); i += i & -i) {
            tree[i] += delta;
        }
    }
    
    int query(int i) {
        int sum = 0;
        for (; i > 0; i -= i & -i) {
            sum += tree[i];
        }
        return sum;
    }
};

class Solution {
public:
    long long countRatioSubarrays(vector<int>& nums, int a, int b) {
        int n = nums.size();
        vector<long long> V(n + 1, 0);
        long long evens = 0;
        long long odds = 0;
        
        for (int i = 0; i < n; i++) {
            if (nums[i] % 2 == 0) {
                evens++;
            } else {
                odds++;
            }
            V[i + 1] = evens * b - odds * a;
        }
        vector<long long> sorted_V = V;
        sort(sorted_V.begin(), sorted_V.end());
        sorted_V.erase(unique(sorted_V.begin(), sorted_V.end()), sorted_V.end());
        
        FenwickTree bit(sorted_V.size());
        long long valid_subarrays = 0;
        for (int i = 0; i <= n; i++) {
            int rank = lower_bound(sorted_V.begin(), sorted_V.end(), V[i]) - sorted_V.begin() + 1;
            long long strictly_smaller = bit.query(rank - 1);
            long long elements_greater_or_equal = i - strictly_smaller;
            
            valid_subarrays += elements_greater_or_equal;
            bit.add(rank, 1);
        }
        
        return valid_subarrays;
    }
};