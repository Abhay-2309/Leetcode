class Solution {
public:
    vector<bool> transformStr(string s, vector<string>& strs) {
        int n = s.length();
        int target_ones = 0;
        vector<int> pref_s(n, 0);
        
        for (int i = 0; i < n; i++) {
            if (s[i] == '1') {
                target_ones++;
            }
            pref_s[i] = target_ones;
        }
        
        int target_zeros = n - target_ones;
        vector<bool> ans;
        ans.reserve(strs.size());
        for (string& str : strs) {
            int current_ones = 0;
            int current_zeros = 0;
            
            for (char c : str) {
                if (c == '1') current_ones++;
                else if (c == '0') current_zeros++;
            }
            if (current_ones > target_ones || current_zeros > target_zeros) {
                ans.push_back(false);
                continue;
            }
            int needed_ones = target_ones - current_ones;
            for (int i = n - 1; i >= 0; i--) {
                if (str[i] == '?') {
                    if (needed_ones > 0) {
                        str[i] = '1';
                        needed_ones--;
                    } else {
                        str[i] = '0';
                    }
                }
            }
            bool possible = true;
            int running_ones = 0;
            
            for (int i = 0; i < n; i++) {
                if (str[i] == '1') {
                    running_ones++;
                }
                if (running_ones > pref_s[i]) {
                    possible = false;
                    break;
                }
            }
            
            ans.push_back(possible);
        }
        
        return ans;
    }
};