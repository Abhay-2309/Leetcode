class segmentTree {
private:
    vector<int> tree;
    int n;
    
    void build(int index, int low, int high, const vector<int>& arr) {
        if(low == high) {
            tree[index] = arr[low];
            return;
        }
        int mid = low + ((high - low) >> 1);
        build(index << 1, low, mid, arr);
        build(index << 1 | 1, mid + 1, high, arr);
        tree[index] = std::gcd(tree[index << 1], tree[index << 1 | 1]);
    }

    int query(int index, int low, int high, int left, int right) {
        if(low >= left && high <= right) return tree[index];
        int mid = low + ((high - low) >> 1);
        if (right <= mid) {
            return query(index << 1, low, mid, left, right);
        } else if (left > mid) {
            return query(index << 1 | 1, mid + 1, high, left, right);
        } else {
            return std::gcd(
                query(index << 1, low, mid, left, right),
                query(index << 1 | 1, mid + 1, high, left, right)
            );
        }
    }

public:
    segmentTree(int n) {
        this->n = n;
        tree.resize(4 * n + 1);
    }

    void build(const vector<int>& arr) {
        build(1, 0, n - 1, arr);
    }

    int query(int left, int right) {
        if (left > right) return 0;
        return query(1, 0, n - 1, left, right);
    }
};

class Solution {
private:
    int get_gcd(segmentTree& sgTree, int left, int right, int j, int left_static, int right_static, int n) {
        if (left > right) return 0;

        if (j < left || j > right) {
            return sgTree.query(left, right);
        }
        
        int left_part = 0;
        if (j > left) {
            left_part = (left == 0) ? left_static : sgTree.query(left, j - 1);
        }
        
        int right_part = 0;
        if (j < right) {
            right_part = (right == n - 1) ? right_static : sgTree.query(j + 1, right);
        }
        
        if (left_part == 0) return right_part;
        if (right_part == 0) return left_part;

        return std::gcd(left_part, right_part);
    }

public:
    int maxValidSplits(vector<int>& nums) {
        int n = nums.size();

        if (n == 2) return nums[0] == nums[1] ? 1 : 0;
        
        segmentTree sgTree(n);
        sgTree.build(nums);
        
        int max_score = 0;

        for (int j = -1; j < n; j++) {
            int left_static = (j > 0) ? sgTree.query(0, j - 1) : 0;
            int right_static = (j != -1 && j < n - 1) ? sgTree.query(j + 1, n - 1) : 0;
            
            int total_gcd = get_gcd(
                sgTree, 0, n - 1, j,
                left_static, right_static, n
            );
            
            int L_orig = n;
            int low = 0, high = n - 1;
            
            int first_idx = (j == 0) ? 1 : 0;

            if (get_gcd(
                sgTree, 0, first_idx, j,
                left_static, right_static, n
            ) == total_gcd) {
                L_orig = first_idx;
            } else {
                while (low <= high) {
                    int mid = low + ((high - low) >> 1);

                    int val = get_gcd(
                        sgTree, 0, mid, j,
                        left_static, right_static, n
                    );

                    if (val == total_gcd) {
                        L_orig = mid;
                        high = mid - 1;
                    } else {
                        low = mid + 1;
                    }
                }
            }

            if (L_orig == n) continue;
            
            int R_orig = -1;
            low = 0;
            high = n - 1;
            
            int last_idx = (j == n - 1) ? n - 2 : n - 1;

            if (get_gcd(
                sgTree, last_idx, n - 1, j,
                left_static, right_static, n
            ) == total_gcd) {
                R_orig = last_idx;
            } else {
                while (low <= high) {
                    int mid = low + ((high - low) >> 1);

                    int val = get_gcd(
                        sgTree, mid, n - 1, j,
                        left_static, right_static, n
                    );

                    if (val == total_gcd) {
                        R_orig = mid;
                        low = mid + 1;
                    } else {
                        high = mid - 1;
                    }
                }
            }
            
            int L_prime = L_orig - (j != -1 && L_orig > j ? 1 : 0);
            int R_prime = R_orig - (j != -1 && R_orig > j ? 1 : 0);

            int score = max(0, R_prime - L_prime);
            max_score = max(max_score, score);
        }

        return max_score;
    }
};