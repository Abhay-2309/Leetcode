class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        auto f = [&](bool is_multiply) -> long long {
            const long long MIN_INF = -1e16;
            long long nottaken = MIN_INF;
            long long operationcontinue = MIN_INF;
            long long finished = MIN_INF;
            long long res = MIN_INF;
            for (int i = 0; i < n; i++) {
                long long x = nums[i];
                long long op_x = is_multiply ? (x * k) : (x / k);
                long long next_nottaken = max(x, nottaken + x);
                long long next_operationcontinue = max({op_x,nottaken + op_x,operationcontinue + op_x});
                long long next_finished = max(finished + x,operationcontinue + x);
                nottaken = next_nottaken;
                operationcontinue = next_operationcontinue;
                finished = next_finished;
                res = max({res, nottaken,operationcontinue, finished});
            }
            
            return res;
        };
        long long case1 = f(true);
        long long case2 = f(false);
        
        return max(case1, case2);
    }
};