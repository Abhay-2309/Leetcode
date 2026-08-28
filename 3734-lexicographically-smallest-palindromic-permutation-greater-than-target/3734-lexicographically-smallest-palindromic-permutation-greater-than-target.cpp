class Solution {
public:
    string res = "";
    char midChar = 0; 
    bool solve(string& curr, vector<int>& count, string& target, int ind, bool greater){
        if(ind == (target.length() >> 1)){
            if(greater){
                res = curr;
                return true;
            }
            string full = curr;
            if (target.length() % 2 != 0) full += midChar;
            for (int i = (int)curr.size() - 1; i >= 0; i--) full += curr[i];
            
            if (full > target) {
                res = curr;
                return true;
            }
            return false;
        }
        for(char ch = 'a'; ch <= 'z'; ch++){
            if(count[ch-'a'] == 0) continue;
            if(greater == false && ch < target[ind]){
                continue;
            }
            curr.push_back(ch);
            count[ch-'a']--;
            bool isGreater = greater || ch > target[ind];
            
            if(solve(curr, count, target, ind + 1, isGreater)) return true;
            
            curr.pop_back();
            count[ch-'a']++;
        }
        return false;
    }
    
    string lexPalindromicPermutation(string s, string target) {
        int n = s.size();
        vector<int> cnt(26, 0);
        for(char & ch: s){
            cnt[ch-'a']++;
        }
        
        int oddcnt = 0;
        for(int i = 0; i < 26; i++){
            if(cnt[i] == 0) continue;
            if(cnt[i] & 1) { 
                oddcnt++; 
                midChar = i + 'a';
            }
            if(oddcnt > 1) return "";
            cnt[i] = cnt[i] >> 1;
        }
        
        string curr;
        bool possible = solve(curr, cnt, target, 0, false);
        
        if(!possible) return "";
        
        string rev = "";
        for(int i = (int)res.size() - 1; i >= 0; i--) rev += res[i];
        string ans = res;
        if(n % 2 != 0) ans += midChar;
        ans += rev;
        
        return ans;
    }
};