class Solution {
public:
    inline long long C(int n) {return (1LL*n*(n+1))/2;}
    inline long long f(string s,char ch){
        int n = s.size();
        int left = 0;
        int right =0;
        long long total = 0;
        while(right<n){
            if(s[right]!=ch){
                right++;
            }
            else{
                total+= C(right-left);
                right++;
                left = right;
            }
        }
        if(left!=right) total += C(right-left);
        return 1LL*total;
    }
    long long appealSum(string s) {
        int n = s.size();
        long long totalsubstring = C(n);
        long long ans = 0;
        unordered_set<char> st(s.begin(),s.end());
        for(char ch = 'a';ch<='z';ch++) if(st.count(ch)) ans += (totalsubstring - f(s,ch));
        return ans;
    }
};