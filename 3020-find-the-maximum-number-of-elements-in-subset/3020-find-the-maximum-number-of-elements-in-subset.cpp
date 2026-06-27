#include <vector>
#include <array>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    static constexpr int len = 20;
    static constexpr std::array<int, len + 1> powerof2 = []() {
        std::array<int, len + 1> arr{};
        for (int i = 0; i <= len; ++i) {
            arr[i] = 1 << i;
        }
        return arr;
    }();
    
    long long binpow(long long a, long long b) {
        long long res = 1;
        while (b > 0) {
            if (b & 1) {
                res = (1LL * res * a);
            }
            b >>= 1;
            if (b > 0) { 
                a = (1LL * a * a);
            }
        }
        return res;
    }
    
    int maximumLength(vector<int>& nums) {
        sort(begin(nums), end(nums));
        vector<int> temp;
        int cnt = 0;
        unordered_map<long long, int> freq;
        
        for(const auto& itr: nums){
            if(itr != 1){
                temp.emplace_back(itr);
                freq[itr]++;
            } else {
                cnt++;
            }
        }
        vector<int> unq_nums = temp;
        int ans = 0;
        unq_nums.erase(unique(unq_nums.begin(), unq_nums.end()), unq_nums.end());
        for(int index = 0; index < unq_nums.size(); index++){
            int num = unq_nums[index];
            int tempcnt = 0;
            int e = 0;
            bool flag = false;
            while (true) {
                long long current_val = binpow(num, powerof2[e]);
                if (current_val > 1e9 || freq.find(current_val) == freq.end()) {
                    flag = true;
                    break;
                }
                if (freq[current_val] < 2) {
                    tempcnt++;
                    break; 
                }
                
                tempcnt += 2;
                e++;
            }
            
            if(flag == true && (tempcnt % 2) == 0 && tempcnt > 0) tempcnt--;
            ans = max(ans, tempcnt);
        }
        if (cnt % 2 == 0 && cnt > 0) {
            cnt--;
        }
        
        return max(ans, cnt);
    }
};