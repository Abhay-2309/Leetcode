class FenwickTree {
private:
    vector<int> tree;
public:
    FenwickTree(int n) {
        tree.assign(n + 1, 0);
    }
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
    vector<int> resultArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> sorted_unique = nums;
        sort(sorted_unique.begin(), sorted_unique.end());
        sorted_unique.erase(unique(sorted_unique.begin(), sorted_unique.end()), sorted_unique.end());
        int K = sorted_unique.size();
        auto get_rank = [&](int val) -> int {
            return lower_bound(sorted_unique.begin(), sorted_unique.end(), val) - sorted_unique.begin() + 1;
        };
        FenwickTree bit1(K), bit2(K);
        vector<int> arr1, arr2;
        arr1.push_back(nums[0]);
        bit1.add(get_rank(nums[0]), 1);
        arr2.push_back(nums[1]);
        bit2.add(get_rank(nums[1]), 1);
        for (int i = 2; i < n; i++) {
            int rank = get_rank(nums[i]);
            int greaterCount1 = arr1.size() - bit1.query(rank);
            int greaterCount2 = arr2.size() - bit2.query(rank);
            if (greaterCount1 > greaterCount2) {
                arr1.push_back(nums[i]);
                bit1.add(rank, 1);
            } else if (greaterCount1 < greaterCount2) {
                arr2.push_back(nums[i]);
                bit2.add(rank, 1);
            } else {
                if (arr1.size() <= arr2.size()) {
                    arr1.push_back(nums[i]);
                    bit1.add(rank, 1);
                } else {
                    arr2.push_back(nums[i]);
                    bit2.add(rank, 1);
                }
            }
        }
        arr1.insert(arr1.end(), arr2.begin(), arr2.end());
        return arr1;
    }
};