class Solution {
public:
    void f(string s, int o, int c, vector<string> &ans, int n){
        if(c==n) {
            ans.push_back(s);
            return;
        }
        if(o<n) f(s+'(', o+1, c, ans, n);
        if(c<o) f(s+')', o, c+1, ans, n);
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string s="";
        f(s, 0, 0, ans, n);
        return ans;
    }
};