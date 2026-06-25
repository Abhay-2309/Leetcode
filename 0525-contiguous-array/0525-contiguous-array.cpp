class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n =nums.size();
        unordered_map<int,int> prev_occurance;
        prev_occurance[0] = -1;
        int cnt1 = 0;
        int cnt2 = 0;
        int maxi = 0;
        for(int i=0;i<n;i++){
            if(nums[i]==1) cnt1++;
            else cnt2++;
            int diff = cnt1-cnt2;
            if(prev_occurance.count(diff)) maxi = max(maxi, i - prev_occurance[diff]);
            else prev_occurance[diff] = i;
        }
        return maxi;
    }
};