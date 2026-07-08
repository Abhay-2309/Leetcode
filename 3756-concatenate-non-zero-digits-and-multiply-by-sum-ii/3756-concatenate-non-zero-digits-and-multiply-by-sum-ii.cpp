#include <bits/stdc++.h>
using namespace std;

class SegmentTree {
private:
    struct Node {
        int len;          // number of non-zero digits
        long long val;    // value modulo MOD
    };

    const long long MOD = 1e9+7;

    int n;
    string s;
    vector<Node> tree;
    vector<long long> pow10;

    Node combine(const Node &L, const Node &R) {
        Node res;
        res.len = L.len + R.len;
        res.val = ( (L.val * pow10[R.len]) % MOD + R.val ) % MOD;
        return res;
    }

    void build(int L, int R, int idx) {
        if (L == R) {
            if (s[L] == '0') tree[idx] = {0, 0};
            else tree[idx] = {1, (s[L] - '0') % MOD};
            return;
        }
        int mid = L + (R - L) / 2;
        build(L, mid, 2*idx+1);
        build(mid+1, R, 2*idx+2);
        tree[idx] = combine(tree[2*idx+1], tree[2*idx+2]);
    }

    Node queryRec(int L, int R, int ql, int qr, int idx) {
        if (ql > R || qr < L) return {0, 0};
        if (ql <= L && R <= qr) return tree[idx];
        int mid = L + (R - L) / 2;
        Node left = queryRec(L, mid, ql, qr, 2*idx+1);
        Node right = queryRec(mid+1, R, ql, qr, 2*idx+2);
        return combine(left, right);
    }

    void updateRec(int L, int R, int pos, char val, int idx) {
        if (L == R) {
            s[pos] = val;
            if (val == '0') tree[idx] = {0, 0};
            else tree[idx] = {1, (val - '0') % MOD};
            return;
        }
        int mid = L + (R - L) / 2;
        if (pos <= mid) updateRec(L, mid, pos, val, 2*idx+1);
        else updateRec(mid+1, R, pos, val, 2*idx+2);
        tree[idx] = combine(tree[2*idx+1], tree[2*idx+2]);
    }

public:
    SegmentTree(const string &input) {
        s = input;
        n = s.size();
        if (n == 0) return;

        tree.assign(4*n, {0,0});

        pow10.assign(n+1, 1);
        for (int i = 1; i <= n; i++)
            pow10[i] = (pow10[i-1] * 10) % MOD;

        build(0, n-1, 0);
    }

    long long queryVal(int l, int r) {
        if (n == 0) return 0;
        if (l < 0) l = 0;
        if (r >= n) r = n-1;
        if (l > r) return 0;
        return queryRec(0, n-1, l, r, 0).val;
    }

    void update(int pos, char val) {
        if (pos < 0 || pos >= n) return;
        updateRec(0, n-1, pos, val, 0);
    }
};

class Solution {
public:
    const long long MOD = 1e9 + 7;

    long long modularmultiplication(long long a, long long b) {
        return ((a % MOD) * (b % MOD)) % MOD;
    }

    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int n = s.size();

        vector<int> pre(n);
        pre[0] = s[0] - '0';
        for (int i = 1; i < n; i++)
            pre[i] = pre[i-1] + (s[i]-'0');

        SegmentTree st(s);
        vector<int> ans;

        for (auto &itr : queries) {
            int start = itr[0];
            int end = itr[1];

            long long x = st.queryVal(start, end);   // value mod MOD

            long long sum = pre[end] - (start == 0 ? 0 : pre[start-1]);

            long long mul = modularmultiplication(x, sum);
            ans.push_back((int)mul);
        }
        return ans;
    }
};
