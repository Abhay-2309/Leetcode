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