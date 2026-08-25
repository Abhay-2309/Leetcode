class Solution {
public:
    inline static const int MAXL = 100005;
    inline static bool is_precomputed = false;
    inline static vector<int> divisors[MAXL + 1];
    void calculate() {
        if (is_precomputed) return;
        for (int i = 2; i <= MAXL; i++) {
            if (divisors[i].empty()) {
                for (int j = i; j <= MAXL; j += i) {
                    divisors[j].emplace_back(i);
                }
            }
        }
        is_precomputed = true;
    }
    
    int longestSubarray(vector<int>& nums, int k) {
        calculate(); 
        
        int n = nums.size();
        int left = 0;
        int right = 0;
        unordered_map<int, int> factor;
        int maxilen = 0;
        
        while (right < n) {
            for (auto f : divisors[nums[right]]) {
                factor[f]++;
            }
            
            while (factor.size() > k) {
                for (auto f : divisors[nums[left]]) {
                    factor[f]--;
                    if (factor[f] == 0) {
                        factor.erase(f);
                    }
                }
                left++;
            }
            
            maxilen = max(maxilen, right - left + 1); 
            right++;
        }
        
        return maxilen;
    }
};