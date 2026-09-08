class Solution {
public:
    int countCommas(int n) {
        string str = to_string(n);
        int si = str.size();
        if(si<4) return 0;
        int total =0;
        for(int i=1000;i<=n;i++){
            string temp = to_string(i);
            if(temp.size()%3==0) total += (temp.size()/3)-1;
            else total += (temp.size()/3);
        }
        return total;
    }
};