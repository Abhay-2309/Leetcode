// class Solution {
// public:
//     bool isValid(string s) {
//         vector<char> str ={'(', ')','[',']', '{', '}'};
//         int n = s.size();
//         if(n%2!=0) return false;
//         if(n<2||s[0]==str[1]||s[0]==str[3]||s[0]==str[5]) return false;
//         if(n==2) {
//             for(int i=0;i<2;i++){
//                 if(s[0]==str[0]&&s[1]==str[1]) return true;
//                 else if(s[0]==str[2]&&s[1]==str[3]) return true;
//                 else if(s[0]==str[4]&&s[1]==str[5]) return true;
//                 else return false;
//             }
//         }
//         int idx =-1;
//         for(int i=0i<)
//         int flag =0;
//         for(int i=0;i<n/2;i++){
            
//         } 
//         if(flag==1) return true;
//         return false;
//     }
// };
#include <stack>
#include <unordered_map>

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        unordered_map<char, char> matching_bracket = {
            {')', '('},
            {'}', '{'},
            {']', '['}
        };
        
        for (char c : s) {
            if (c == '(' || c == '{' || c == '[') {
                st.push(c);
            } else {
                if (st.empty() || st.top() != matching_bracket[c]) {
                    return false;
                }
                st.pop();
            }
        }
        
        return st.empty();
    }
};
