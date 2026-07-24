class Solution {
public:
    long long minimumReplacement(vector<int>& nums) {
        int n = nums.size();
        long long cost =0;
        for(int i=n-2;i>=0;i--){
            if(nums[i]<=nums[i+1]) continue;
            int parts = nums[i]/nums[i+1];
            if(nums[i]%nums[i+1]!=0) parts++;
            cost += (parts-1);
            nums[i] = nums[i]/parts;
         }

        return cost;

    }
};