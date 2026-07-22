class SegmentTree {
public:
    struct Node {
        int p1;
        int p2;
        int sum;
    };

private:
    int num_pairs;
    vector<Node> tree;
    
    Node mergeNodes(Node left, Node right) {
        if (left.sum == -1e9) return right;
        if (right.sum == -1e9) return left;
        if (left.sum >= right.sum) {
            return left;
        } else {
            return right;
        }
    }

    void buildTree(int node, int start, int end, const vector<int>& arr) {
        if (start > end) return; 
        if (start == end) {
            tree[node].p1 = arr[start];
            tree[node].p2 = arr[start + 1];
            tree[node].sum = arr[start] + arr[start + 1];
            return;
        }
        
        int mid = (start + end) / 2;
        buildTree(2 * node, start, mid, arr);
        buildTree(2 * node + 1, mid + 1, end, arr);
        
        tree[node] = mergeNodes(tree[2 * node], tree[2 * node + 1]);
    }

    void updateTree(int node, int start, int end, int pair_idx, int new_p1, int new_p2) {
        if (start > end) return; 
        if (start == end) {
            tree[node].p1 = new_p1;
            tree[node].p2 = new_p2;
            tree[node].sum = new_p1 + new_p2;
            return;
        }
        
        int mid = (start + end) / 2;
        if (start <= pair_idx && pair_idx <= mid) {
            updateTree(2 * node, start, mid, pair_idx, new_p1, new_p2);
        } else {
            updateTree(2 * node + 1, mid + 1, end, pair_idx, new_p1, new_p2);
        }
        
        tree[node] = mergeNodes(tree[2 * node], tree[2 * node + 1]);
    }

    Node queryTree(int node, int start, int end, int l, int r) {
        if (start > end || r < start || end < l) {
            return {0, 0, (int)-1e9};
        }
        if (l <= start && end <= r) {
            return tree[node];
        }
        
        int mid = (start + end) / 2;
        Node leftNode = queryTree(2 * node, start, mid, l, r);
        Node rightNode = queryTree(2 * node + 1, mid + 1, end, l, r);
        
        return mergeNodes(leftNode, rightNode);
    }

public:
    SegmentTree(const vector<int>& arr, int n) {
        num_pairs = n - 1;
        if (num_pairs > 0) {
            tree.resize(4 * num_pairs + 1); 
            buildTree(1, 1, num_pairs, arr);
        }
    }
    
    void update(int pair_idx, int new_p1, int new_p2) {
        if (num_pairs > 0) {
            updateTree(1, 1, num_pairs, pair_idx, new_p1, new_p2);
        }
    }
    
    Node query(int l, int r) {
        if (l > r || num_pairs <= 0) return {0, 0, (int)-1e9}; 
        return queryTree(1, 1, num_pairs, l, r);
    }
};

class Solution {
public:
    vector<int> maxActiveSectionsAfterTrade(string s, vector<vector<int>>& queries) {
        int n = s.size();
        
        vector<int> leftmefirstone(n + 1, -1);
        vector<int> rightmefirstone(n + 1, n);
        vector<int> leftmefirstzero(n + 1, -1);
        vector<int> rightmefirstzero(n + 1, n);
        
        vector<int> numberofonesprefix(n + 1, 0);
        int totalones_overall = 0;
        
        for (int i = 0; i < n; i++) {
            if (s[i] == '1') {
                numberofonesprefix[i + 1] = numberofonesprefix[i] + 1;
                totalones_overall++;
            } else {
                numberofonesprefix[i + 1] = numberofonesprefix[i];
            }
        }
        
        for (int i = 0; i < n; ++i) {
            if (s[i] == '1') leftmefirstone[i] = i;
            else leftmefirstone[i] = (i > 0) ? leftmefirstone[i - 1] : -1;
            
            if (s[i] == '0') leftmefirstzero[i] = i;
            else leftmefirstzero[i] = (i > 0) ? leftmefirstzero[i - 1] : -1;
        }
        for (int i = n - 1; i >= 0; --i) {
            if (s[i] == '1') rightmefirstone[i] = i;
            else rightmefirstone[i] = rightmefirstone[i + 1];
            
            if (s[i] == '0') rightmefirstzero[i] = i;
            else rightmefirstzero[i] = rightmefirstzero[i + 1];
        }
        
        int index = 1;
        vector<int> block_id(n, -1);
        vector<int> block;
        block.push_back(0);
        
        int temp = 0;
        for (int i = 0; i <= n; i++) {
            if (i < n && s[i] == '0') {
                temp++;
            } else {
                if (temp > 0) {
                    block.push_back(temp);
                    for (int j = i - temp; j < i; j++) {
                        block_id[j] = index;
                    }
                    index++;
                    temp = 0;
                }
            }
        }
        
        int treesize = block.size() - 1;
        SegmentTree sgTree(block, treesize);
        
        vector<int> ans;
        int noofqueries = queries.size();
        ans.reserve(noofqueries); 
        for (const auto &itr : queries) {
            int templ = itr[0];
            int tempr = itr[1];
            
            int first_0 = rightmefirstzero[templ];
            if (first_0 > tempr) {
                ans.push_back(totalones_overall);
                continue;
            }
            
            int last_0 = leftmefirstzero[tempr];
            int id1 = block_id[first_0];
            int id2 = block_id[last_0];
            
            if (id1 == id2) {
                ans.push_back(totalones_overall);
                continue;
            }
            
            int size1 = rightmefirstone[first_0] - first_0;
            int size2 = last_0 - leftmefirstone[last_0];
            int orig1 = block[id1];
            int orig2 = block[id2];
            block[id1] = size1;
            block[id2] = size2;
            
            int num_pairs = treesize - 1;
            if (id1 - 1 >= 1) {
                sgTree.update(id1 - 1, block[id1 - 1], block[id1]);
            }
            if (id1 <= num_pairs) {
                sgTree.update(id1, block[id1], block[id1 + 1]);
            }
            if (id2 - 1 >= 1 && id2 - 1 != id1) {
                sgTree.update(id2 - 1, block[id2 - 1], block[id2]);
            }
            if (id2 <= num_pairs) {
                sgTree.update(id2, block[id2], block[id2 + 1]);
            }
            int max_pair = 0;
            if (id1 <= id2 - 1) {
                max_pair = sgTree.query(id1, id2 - 1).sum;
            }
            ans.push_back(totalones_overall + max_pair);
            block[id1] = orig1;
            block[id2] = orig2;
            if (id1 - 1 >= 1) {
                sgTree.update(id1 - 1, block[id1 - 1], block[id1]);
            }
            if (id1 <= num_pairs) {
                sgTree.update(id1, block[id1], block[id1 + 1]);
            }
            if (id2 - 1 >= 1 && id2 - 1 != id1) {
                sgTree.update(id2 - 1, block[id2 - 1], block[id2]);
            }
            if (id2 <= num_pairs) {
                sgTree.update(id2, block[id2], block[id2 + 1]);
            }
        }
        return ans;
    }
};