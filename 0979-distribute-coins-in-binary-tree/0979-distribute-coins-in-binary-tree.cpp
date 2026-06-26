/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int distributeCoins(TreeNode* root) {
        if(!root) return 0;
        int moves =0;
        auto f = [&](auto&& self,TreeNode*node)->int{
            if(!root->left && !root->right) return node->val - 1;
            int leftextra =0;
            int rightextra =0;
            if(node->left) leftextra = self(self,node->left);
            if(node->right) rightextra = self(self,node->right);
            moves += (abs(leftextra) + abs(rightextra));
            return (leftextra+rightextra + node->val) - 1; 
        };
        f(f,root);
        return moves;
    }
};