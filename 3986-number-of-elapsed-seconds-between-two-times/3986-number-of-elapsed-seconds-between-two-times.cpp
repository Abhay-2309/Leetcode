class Solution {
public:
    int secondsBetweenTimes(string st, string et) {
        int hr1=stoi(st.substr(0,2));
        int min1=stoi(st.substr(3,2));
        int sec1=stoi(st.substr(6,2));
        int first = hr1*3600 +min1*60+sec1;
        int hr2=stoi(et.substr(0,2));
        int min2=stoi(et.substr(3,2));
        int sec2=stoi(et.substr(6,2));
        int second = hr2*3600 +min2*60+sec2;
        return second-first;
    
    
        
    }
};