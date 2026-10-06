class Solution {
public:
    int minAddToMakeValid(string s) {
        int n = s.size();
        stack<int>st; 
        int ptr =0;
        int cnt=0;
        
        while(ptr<n){
            if(s[ptr]=='('){
                st.push(s[ptr]);
            }else{
                if(!st.empty() && st.top()=='('){
                    st.pop();
                }else{
                    cnt++;
                }
            }
            ptr++;
        }
        return cnt + st.size(); 
    }
};