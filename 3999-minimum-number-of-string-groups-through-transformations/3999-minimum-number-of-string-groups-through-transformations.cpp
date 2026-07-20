class Solution {
public:
    static const int base = 31;
    static const int MOD = 1000000087;
    
    static inline int modadd(int a, int b) {
        return (a + b) % MOD;
    } 
    
    static inline int modmull(int a, int b) {
        return (1LL * a * b) % MOD;
    }
    
    static inline int modPow(int b, int exp) {
        int res = 1;
        b %= MOD;
        while (exp > 0) {
            if (exp % 2 == 1) res = (1LL * res * b) % MOD;
            b = (1LL * b * b) % MOD;
            exp /= 2;
        }
        return res;
    }
    
    inline static const vector<int> powerof31 = []() {
        int MAX_LEN = 500005; 
        vector<int> p(MAX_LEN);
        p[0] = 1;
        for (int i = 1; i < MAX_LEN; i++) {
            p[i] = modmull(p[i - 1], base);
        }
        return p;
    }();

    inline static const vector<int> inversemodulo = []() {
        int MAX_LEN = 500005;
        vector<int> inv(MAX_LEN);
        inv[0] = 1;
        int inv_base = modPow(base, MOD - 2); 
        
        for (int i = 1; i < MAX_LEN; i++) {
            inv[i] = modmull(inv[i - 1], inv_base);
        }
        return inv;
    }();
    
    int minimumGroups(vector<string>& words) {
        int n = (int)words.size();
        set<pair<int, int>> st;
        
        for(auto str: words){
            string odd = "", even = "";
            int ptr = 0;
            while(ptr < str.size()){
                if(ptr & 1) odd += (str[ptr]);
                else even += (str[ptr]);
                ptr++;
            }
            
            int size1 = (int)even.size();
            int size2 = (int)odd.size();
            even += even;
            odd += odd;
            
            int evenhash = 0;
            int oddhash = 0;
            
            for(int i = 0; i < size1; i++){
                evenhash = modadd(evenhash, modmull((even[i]-'a' + 1), powerof31[i]));
            }
            for(int i = 0; i < size2; i++){
                oddhash = modadd(oddhash, modmull((odd[i]-'a' + 1), powerof31[i]));
            }
            
            int minieven = evenhash;
            int miniodd = oddhash;
            if (size1 > 0) {
                int left = 1;
                int right = size1;
                while(right < even.size()){
                    int remove_val = (even[left-1] - 'a' + 1);
                    evenhash = (evenhash - remove_val + MOD) % MOD;
                    evenhash = modmull(evenhash, inversemodulo[1]);
                    evenhash = modadd(evenhash, modmull((even[right]-'a' + 1), powerof31[size1-1]));
                    
                    minieven = min(minieven, evenhash);
                    left++;
                    right++;
                }
            }
            if (size2 > 0) {
                int left = 1;
                int right = size2;
                while(right < odd.size()){
                    int remove_val = (odd[left-1] - 'a' + 1);
                    oddhash = (oddhash - remove_val + MOD) % MOD;
                    oddhash = modmull(oddhash, inversemodulo[1]);
                    oddhash = modadd(oddhash, modmull((odd[right]-'a' + 1), powerof31[size2-1]));
                    
                    miniodd = min(miniodd, oddhash);
                    left++;
                    right++;
                }
            }
            st.insert({minieven, miniodd});
        }
        return st.size();
    }
};