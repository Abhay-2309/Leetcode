class Solution {
public:
    bool check(int n,int ind){
        int sum = 0;
        while(n>0){
            sum += n%10;
            n = n/10;
        }
        return sum==ind;
    }
    int smallestIndex(vector<int>& nums) {
        int n = nums.size();
        for(int i=0;i<n;i++){
            if(check(nums[i],i)) return i;
        }
        return -1;
    }
};