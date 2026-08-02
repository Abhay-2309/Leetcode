class Solution {
public:
    int n;
    int dp[2][501][501];
    int solve(vector<int>&nums, int person, int s,int e){
        if(s==e){
            if(person==1)return nums[s];
            else return 0;
        }
        if(dp[person][s][e]!=-1) return dp[person][s][e];
        int res = 0;
        int score = 0;
        if(person==1){
            res = max(nums[s]+solve(nums, 0, s+1,e), nums[e]+solve(nums, 0,s, e-1));
        }else{
            res = min(solve(nums, 1, s+1, e), solve(nums, 1, s, e-1));
        }
        return dp[person][s][e] = res;
    }
    bool stoneGame(vector<int>& piles) {
        n = piles.size();
        int tot = accumulate(piles.begin(), piles.end(),0);
        memset(dp,-1,sizeof(dp));
        int res = solve(piles,1,0,n-1);
        cout<<res<<endl;
        if(res >= (tot-res)) return true;
        return false;
    }
};