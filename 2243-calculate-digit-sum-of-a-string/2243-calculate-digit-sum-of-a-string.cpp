class Solution {
public:
    string digitSum(string s, int k) {
        if(s.size()<=k)return s;
        while(s.size()>k){
            string t = "";
            string st="";
            for(int i=0;i<s.size();i++){
                st += s[i];
                int num = 0;
                
                if(st.size()==k){
                    for(int j=0;j<k;j++){
                        num += st[j] - '0'; // Subtract '0' to convert char to int
                    }
                    t += to_string(num);
                    st = "";
                }
                
                else if(st.size()<k && i==s.size()-1){
                    for(int j=0;j<st.size();j++){ 
                        num += st[j] - '0'; // Subtract '0' to convert char to int
                    }
                    t += to_string(num);
                    st = "";
                }
            }
            s = t;
        }

        return s;
    }
};