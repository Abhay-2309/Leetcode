class Solution {
public:
    const int MOD = 1e9 + 7;
    int modpow(long long base, int exp) {
        long long res = 1;
        base %= MOD;
        while (exp > 0) {
            if (exp % 2 == 1) {
                res = (res * base) % MOD;
            }
            base = (base * base) % MOD;
            exp /= 2;
        }
        return res;
    }
    int modmul(int a, int b) {
        return (1LL * a * b) % MOD;
    }
    int moddiv(int a, int b) {
        return modmul(a, modpow(b, MOD - 2));
    }

    string smallestPalindrome(string s, int k) {
        k--;
        int n = (s.length()>>1);
        string str(s.begin(), s.begin() + n);

        sort(str.begin(), str.end());

        vector<short> freq(500, 0);
        int fact = 1;
        int denom = 1;
        int sp = -1;
        int cnt;
        if(k==0) goto here;
        for(int i = n-1, j = 1; i>=0; i--, j++){
            denom = modmul(denom, ++freq[str[i]]);
            fact = modmul(fact, j);
            int res = moddiv(fact, denom);
            if(res > k){
                sp = i;
                cnt = j;
                break;
            }
        }

        if(sp==-1) return "";

        while(k){
            fact = moddiv(fact, cnt--);
            for(char i = 'a'; i<='z'; i++){
                if(!freq[i]) continue;
                denom = moddiv(denom, freq[i]);
                int res = moddiv(fact, denom);
                if(res <= k){
                    k -= res;
                    denom = modmul(denom, freq[i]);
                }
                else{
                    freq[i]--;
                    str[sp] = i;
                    break;
                }
            }
            sp++;

        }

        for(char i = 'a'; i<='z'; i++){
            while(freq[i]--) str[sp++] = i;
        }
        here:
        string fStr = str;
        if(s.length()&1) fStr += s[n];
        reverse(str.begin(), str.end());
        fStr += str;
        return fStr;

    }
};