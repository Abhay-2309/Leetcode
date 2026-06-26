class Solution:
    def minCameraCover(self, root: TreeNode) -> int:
        
        def dfs(node) -> tuple:
            if not node:
                return (float('inf'), 0, 0)
            
            left = dfs(node.left)
            right = dfs(node.right)
            
            put_camera = 1 + min(left) + min(right)
            
            safe_no_camera = min(
                left[0] + min(right[0], right[1]), 
                right[0] + min(left[0], left[1])
            )
            
            needs_camera = left[1] + right[1]
            
            return (put_camera, safe_no_camera, needs_camera)
        
        result = dfs(root)
        
        return min(result[0], result[1])