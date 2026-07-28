#define ll long long
class Solution {
public:
    const ll CAP = 1000000;
    ll binomCap(ll n, ll r){
        if(r < 0 || r > n) return 0;
        r = min(r, n - r);
        ll res = 1;
        for(ll i = 1; i <= r; i++){
            res = res * (n - r + i) / i;  
            if(res > CAP) return CAP;
        }
        return res;
    }
    ll perms(vector<int>& cnt){
        ll res = 1, rem = 0;
        for(int c = 0; c < 26; c++){
            if(!cnt[c]) continue;
            rem += cnt[c];
            res = res * binomCap(rem, cnt[c]);
            if(res > CAP) return CAP;
        }
        return res;
    }

    string smallestPalindrome(string s, int k) {
        int n = s.size();
        int m = n >> 1;
        string half = s.substr(0, m);
        sort(half.begin(), half.end());
        string mid = (n & 1) ? string(1, s[m]) : "";

        vector<int> cnt(26, 0);
        for(char ch : half) cnt[ch - 'a']++;

        if(perms(cnt) < k) return ""; 
        vector<int> suf(26, 0);
        int t = 0;
        while(t < m){
            suf[half[m - 1 - t] - 'a']++;
            t++;
            if(perms(suf) >= k) break; 
        }

        string ans = half.substr(0, m - t); 
        ll kk = k;
        for(int pos = 0; pos < t; pos++){
            for(int c = 0; c < 26; c++){
                if(!suf[c]) continue;
                suf[c]--;
                ll ways = perms(suf);      
                if(ways >= kk){             
                    ans += char('a' + c);
                    break;
                }
                kk -= ways;        
                suf[c]++;
            }
        }
        string rev = ans;
        reverse(rev.begin(), rev.end());
        return ans + mid + rev;
    }
};