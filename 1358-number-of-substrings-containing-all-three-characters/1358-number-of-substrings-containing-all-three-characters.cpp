class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();
        int left = 0;
        int right  = 0;
        int count =0;
        unordered_map<char,int>st;
        while(right <n){
            if(st.size()<3){
                if(s[right]=='a'||s[right]=='b'||s[right]=='c'){
                    st[s[right]]++;
                }
                right++;
            }
            else{
                count+= (n-right+1);
                while(left<right&&st.size()>=3){
                    if(st.find(s[left])!=st.end()){
                        st[s[left]]--;
                        if(st[s[left]]==0) st.erase(s[left]);
                    }
                    if(st.size()==3) count+= (n-right+1);
                    left++;
                }
            }
        }
        while(left<right&&st.size()>=3){
            if(st.size()==3) count++;
            if(st.find(s[left])!=st.end()){
                st[s[left]]--;
                if(st[s[left]]==0) st.erase(s[left]);
            }
            left++;
        }
        return count;

    }
};