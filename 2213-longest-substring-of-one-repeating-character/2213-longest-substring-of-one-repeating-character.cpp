// segment tree solution
struct Node {
    int max_len;
    int pref_len;
    int suff_len;
    char pref_char;
    char suff_char;
    int size;
};

class SegmentTree {
private:
    vector<Node> tree;
    int n;

    Node merge(const Node& left, const Node& right) {
        Node res;
        res.size = left.size + right.size;
        res.pref_char = left.pref_char;
        res.suff_char = right.suff_char;

        res.pref_len = left.pref_len;
        if (left.pref_len == left.size && left.pref_char == right.pref_char) {
            res.pref_len += right.pref_len;
        }

        res.suff_len = right.suff_len;
        if (right.suff_len == right.size && right.suff_char == left.suff_char) {
            res.suff_len += left.suff_len;
        }

        res.max_len = max(left.max_len, right.max_len);
        if (left.suff_char == right.pref_char) {
            res.max_len = max(res.max_len, left.suff_len + right.pref_len);
        }

        return res;
    }

    void buildUtil(int index, int left, int right, const string& s) {
        if (left == right) {
            tree[index] = {1, 1, 1, s[left], s[left], 1};
            return;
        }
        int mid = left + ((right - left) >> 1);
        buildUtil(index << 1, left, mid, s);
        buildUtil(index << 1 | 1, mid + 1, right, s);
        
        tree[index] = merge(tree[index << 1], tree[index << 1 | 1]);
    }

    void updateUtil(int index, int left, int right, int ind, char c) {
        if (left == right) {
            tree[index] = {1, 1, 1, c, c, 1};
            return;
        }
        int mid = left + ((right - left) >> 1);
        if (ind <= mid) {
            updateUtil(index << 1, left, mid, ind, c);
        } else {
            updateUtil(index << 1 | 1, mid + 1, right, ind, c);
        }
        
        tree[index] = merge(tree[index << 1], tree[index << 1 | 1]);
    }

public:
    SegmentTree(int n, const string& s) {
        this->n = n;
        tree.resize(n << 2);
        buildUtil(1, 0, n - 1, s);
    }

    void update(int ind, char c) {
        updateUtil(1, 0, n - 1, ind, c);
    }

    int getMax() {
        return tree[1].max_len;
    }
};

class Solution {
public:
    vector<int> longestRepeating(string s, string queryCharacters, vector<int>& queryIndices) {
        int n = s.size();
        int k = queryCharacters.size();
        
        SegmentTree sgTree(n, s);
        vector<int> ans(k);
        
        for (int i = 0; i < k; i++) {
            sgTree.update(queryIndices[i], queryCharacters[i]);
            ans[i] = sgTree.getMax();
        }
        
        return ans;
    }
};
// ordered set solution
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
