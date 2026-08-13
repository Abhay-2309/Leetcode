class segmentTree {
private:
    vector<long long> tree;
    int n;

    void updateUtil(int index, int left, int right, int ind, long long val) {
        if(left == right) {
            tree[index] = max(tree[index], val);
            return;
        }
        int mid = left + ((right - left) >> 1); 
        
        if(ind <= mid) {
            updateUtil(index << 1, left, mid, ind, val);
        } else {
            updateUtil(index << 1 | 1, mid + 1, right, ind, val);
        }
        tree[index] = max(tree[index << 1], tree[index << 1 | 1]);
    }

    long long queryUtil(int index, int left, int right, int low, int high) {
        if(left > right) return -1e18;
        if(high < left || low > right) return -1e18;
        
        if(low <= left && high >= right) return tree[index]; 
        
        int mid = left + ((right - left) >> 1); 
        long long left_val = queryUtil(index << 1, left, mid, low, high);
        long long right_val = queryUtil(index << 1 | 1, mid + 1, right, low, high);
        
        return max(left_val, right_val);
    }

public:
    segmentTree(int n) {
        this->n = n;
        tree.resize((n << 2), 0);
    }

    void update(int ind, long long val) {
        updateUtil(1, 0, n - 1, ind, val);
    }

    long long query(int low, int high) {
        return queryUtil(1, 0, n - 1, low, high);
    }
};

class Solution {
public:
    long long maxBalancedSubsequenceSum(vector<int>& nums) {
        int n = (int)nums.size();
        vector<int> temp(n);
        for(int i = 0; i < n; i++) {
            temp[i] = nums[i] - i;
        }
        sort(temp.begin(), temp.end());
        temp.erase(unique(temp.begin(), temp.end()), temp.end());
        
        int size = temp.size();
        segmentTree sgTree(size + 1);
        long long maxi = -1e18; 
        
        for(int i = 0; i < n; i++) {
            int rankindex = lower_bound(temp.begin(), temp.end(), nums[i] - i) - temp.begin();
            
            long long prevdata = sgTree.query(0, rankindex); 
            long long newvalue = prevdata + nums[i];
            
            maxi = max(maxi, newvalue);
            sgTree.update(rankindex, newvalue);
        }
        
        return maxi;
    } 
};