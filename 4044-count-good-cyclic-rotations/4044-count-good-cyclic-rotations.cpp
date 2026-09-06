class Solution {
public:
    int countGoodRotations(vector<int>& nums) {
        int n = nums.size();
        vector<long long >prefix(n+1,0),suffix(n+1,0);
        for(int i=0;i<n;i++) prefix[i+1] = prefix[i] + nums[i];
        for(int i=n-1;i>=0;i--) suffix[i] = suffix[i+1] + nums[i];
        int cnt =0;
        int blocksize = n>>1;
        for(int index =0;index<n;index++){
            int front = (index+blocksize<=n)?prefix[index+blocksize]-prefix[index] : suffix[index]+prefix[(index+blocksize)%n];
            int back = prefix[n]-front;
            if(front>back) cnt++;
        }
        return cnt;
    }
};