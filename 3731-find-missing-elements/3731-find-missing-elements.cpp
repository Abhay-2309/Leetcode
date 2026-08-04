class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int n = nums.size();
        sort(begin(nums), end(nums));
        int mini = nums[0];
        int maxi = nums[n-1];
        vector<int>res;
        int num = mini+1;
        int i=1;
        while(i<n){
            if(nums[i]==num)i++;
            else{
                res.push_back(num);
            }
            num++;
        }
        return res;
    }
};