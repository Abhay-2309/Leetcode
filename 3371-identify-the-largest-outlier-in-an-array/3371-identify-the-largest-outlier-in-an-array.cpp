class Solution {
public:
    int getLargestOutlier(vector<int>& nums) {
        long long totalsum = accumulate(nums.begin(), nums.end(), 0LL);
        unordered_map<long long, int> freq;
        for(int num : nums) freq[num]++;
        
        int maxi = INT_MIN;
        for(int num : nums){
            long long target = totalsum - num;
            if(target % 2 == 0){
                long long req = target / 2;
                if(freq[req] > (req == num ? 1 : 0)){
                    maxi = max(maxi, num);
                }
            }
        }
        return maxi;
    }
};