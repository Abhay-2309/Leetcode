class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def distributeCoins(self, root: TreeNode) -> int:
        self.moves = 0
        
        def dfs(node: TreeNode) -> int:
            if not node:
                return 0
            left_extra = dfs(node.left)
            right_extra = dfs(node.right)
            self.moves += abs(left_extra) + abs(right_extra)
            return node.val + left_extra + right_extra - 1
        dfs(root)
        return self.moves