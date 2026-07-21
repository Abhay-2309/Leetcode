class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int n = s.length();
        int one = count(s.begin(), s.end(), '1');
        s = "1" + s + "1";
        int newlength = s.length();
        
        vector<int> leftmefirstone(newlength + 1, -1);
        vector<int> rightmefirstone(newlength + 1, newlength);
        for (int i = 0; i < newlength; ++i) {
            if (s[i] == '1') {
                leftmefirstone[i] = i;
            } else {
                leftmefirstone[i] = leftmefirstone[i - 1];
            }
        }
        for (int i = newlength - 1; i >= 0; --i) {
            if (s[i] == '1') {
                rightmefirstone[i] = i;
            } else {
                rightmefirstone[i] = rightmefirstone[i + 1];
            }
        }
        
        int maxi = one;
        int ptr = 1;
        while (ptr < newlength - 1) {
            if (s[ptr] == '1') {
                int left = ptr;
                int right = ptr;
                while (right + 1 < newlength && s[right + 1] == '1') {
                    right++;
                }
                if (s[left - 1] == '0' && right + 1 < newlength && s[right + 1] == '0') {
                    int nextfirstone = rightmefirstone[right + 2];
                    int prevfirstone = leftmefirstone[left - 1];
                    int current_val = one + nextfirstone - prevfirstone - 1 - (right - left + 1);
                    maxi = max(maxi, min(n, current_val));
                }
                ptr = right + 1;
            } else {
                ptr++;
            }
        }
        
        return maxi;
    }
};