class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n = nums.size();
        vector<int>bits(32,0);
        int totalbitsum =0;
        for(int bit =0;bit<31;bit++){
            for(int i=0;i<n;i++){
                int temp = (nums[i]>>bit)&1;
                bits[bit]+=temp;
            }
            totalbitsum+=bits[bit];
        }
        if(!totalbitsum) return 0;
        int flag =0;
        for(int i=0;i<31;i++){
            if(bits[i]&1) return n;
        }
        return n-1;
    }
};