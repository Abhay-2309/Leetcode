class Solution {
public:
    vector<int> longestRepeating(string s, string queryCharacters, vector<int>& queryIndices) {
        int n = s.size();
        int k = queryCharacters.size();
        set<tuple<int, int, char>> st;
        multiset<int> lengths;
        int left = 0;
        for (int right = 1; right <= n; right++) {
            if (right == n || s[right] != s[right - 1]) {
                st.insert(make_tuple(left, right - 1, s[left]));
                lengths.insert(right - left);
                left = right;
            }
        }
        
        vector<int> ans;
        for (int i = 0; i < k; i++) {
            int idx = queryIndices[i];
            char newChar = queryCharacters[i];
            auto it = st.upper_bound(make_tuple(idx, INT_MAX, 127));
            it--;
            int L = get<0>(*it);
            int R = get<1>(*it);
            char oldChar = get<2>(*it);
            if (oldChar == newChar) {
                ans.push_back(*lengths.rbegin());
                continue;
            }
            st.erase(it);
            lengths.erase(lengths.find(R - L + 1));
            if (L < idx) {
                st.insert(make_tuple(L, idx - 1, oldChar));
                lengths.insert((idx - 1) - L + 1);
            }
            if (R > idx) {
                st.insert(make_tuple(idx + 1, R, oldChar));
                lengths.insert(R - (idx + 1) + 1);
            }
            int newL = idx;
            int newR = idx;
            auto next_it = st.upper_bound(make_tuple(idx, INT_MAX, 127));
            if (next_it != st.end() && get<0>(*next_it) == idx + 1 && get<2>(*next_it) == newChar) {
                newR = get<1>(*next_it);
                lengths.erase(lengths.find(get<1>(*next_it) - get<0>(*next_it) + 1));
                next_it = st.erase(next_it);
            }
            if (next_it != st.begin()) {
                auto prev_it = prev(next_it);
                if (get<1>(*prev_it) == idx - 1 && get<2>(*prev_it) == newChar) {
                    newL = get<0>(*prev_it);
                    lengths.erase(lengths.find(get<1>(*prev_it) - get<0>(*prev_it) + 1));
                    st.erase(prev_it);
                }
            }
            st.insert(make_tuple(newL, newR, newChar));
            lengths.insert(newR - newL + 1);
            ans.push_back(*lengths.rbegin());
        }
        
        return ans;
    }
};