class Solution {
public:
    int mini = INT_MAX;
    TreeNode* prev = nullptr; 

    int getMinimumDifference(TreeNode* root) {
        if(!root) return INT_MAX;
        getMinimumDifference(root->left);
        if(prev != nullptr){
            mini = min(mini, abs(root->val - prev->val));
        }
        prev = root;
        getMinimumDifference(root->right);
        
        return mini;
    }
};