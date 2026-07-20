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
    int cnt =0;
    int f(TreeNode* root){
        if(root->left==NULL && root->right==NULL){
            cnt++;
            return root->val;
        }
        int leftmaxi = 0;
        int rightmaxi =0;
        if(root->left)leftmaxi = f(root->left);
        if(root->right)rightmaxi = f(root->right);
        cnt+= (root->val == (max({leftmaxi,rightmaxi,root->val})));
        return max({leftmaxi,rightmaxi,root->val});
    }
    int countDominantNodes(TreeNode* root) {
        if(!root) return 0;
        f(root);
        return cnt;
    }
};