using ll = long long;
using pp = pair<ll,ll>;

class Solution {
public:
    int rob(TreeNode* root) {
        if (!root) return 0;
        
        auto f = [&](auto& self, TreeNode* currnode) -> pp {
            int take = currnode->val; 
            int nottake = 0;
            int lefttake = 0, righttake = 0, leftnottake = 0, rightnottake = 0;
            if (currnode->left) tie(lefttake, leftnottake) = self(self, currnode->left);
            if (currnode->right) tie(righttake, rightnottake) = self(self, currnode->right);
            take = currnode->val + leftnottake + rightnottake;
            nottake = max(lefttake, leftnottake) + max(righttake, rightnottake);
            return pp{take, nottake};
        };
        pp ans = f(f, root);
        return max(ans.first, ans.second);
    }
};