class Solution {
public:
    long long maxSum(vector<int>& nums, int k, int mul) {
        int n = nums.size();
        sort(nums.rbegin(),nums.rend());
        if(k==1 && mul==1) return nums[0];
        int op = min(k,mul);
        long long ans = 0ll;
        for(int i=0;i<k;i++){
            if(mul<1) mul=1;
            if(mul>=1){
                ans += (1LL*mul*nums[i]);
                
                mul--;
            }
        }
        return ans;
    }
};