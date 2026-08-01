class Solution {
public:
    int n;
    int solve(vector<int>&nums, int person, int s,int e){
        if(s==e){
            if(person==1)return nums[s];
            else return 0;
        }
        int res = 0;
        int score = 0;
        if(person==1){
            res = max(nums[s]+solve(nums, 0, s+1,e), nums[e]+solve(nums, 0,s, e-1));
        }else{
            res = min(solve(nums, 1, s+1, e), solve(nums, 1, s, e-1));
        }
        return res;
    }
    bool predictTheWinner(vector<int>& nums) {
        n = nums.size();
        int tot = accumulate(nums.begin(), nums.end(),0);
        int res = solve(nums,1,0,n-1);
        cout<<res<<endl;
        if(res >= (tot-res)) return true;
        return false;
    }
};