class Solution {
public:
    vector<vector<int>> findDisappearedNumbers(vector<int>& nums, int lower, int upper) {
        bitset<100005> mask;
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            if (nums[i] >= lower && nums[i] <= upper) {
                mask.set(nums[i] - lower);
            }
        }
        
        vector<vector<int>> ans;
        int left = lower;
        int right = upper;
        
        while (left <= right) {
            if (mask.test(left - lower)) {
                left++;
            } else {
                int end_range = left;
                while (end_range <= right && !mask.test(end_range - lower)) {
                    end_range++;
                }
                ans.push_back({left, end_range - 1});
                left = end_range;
            }
        }
        
        return ans;
    }
};