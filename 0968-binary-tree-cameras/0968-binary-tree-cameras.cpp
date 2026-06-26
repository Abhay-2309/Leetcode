class Solution {
public:
    int minCameraCover(TreeNode* root) {
        auto f = [&](auto&& self, TreeNode* node) -> std::array<int, 3> {
            if(!node){
                return {99999, 0, 0}; 
            }
            auto left = self(self, node->left);
            auto right = self(self, node->right);
            int put_camera = 1 + std::min({left[0], left[1], left[2]}) 
                               + std::min({right[0], right[1], right[2]});
            int safe_no_camera = std::min(
                left[0] + std::min(right[0], right[1]),
                right[0] + std::min(left[0], left[1]) 
            );
            int needs_camera = left[1] + right[1];
            
            return {put_camera, safe_no_camera, needs_camera};
        };
        
        auto result = f(f, root);
        return std::min(result[0], result[1]);
    }
};