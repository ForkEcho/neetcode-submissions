# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def maxPathSum(self, root: Optional[TreeNode]) -> int:
        self.res = float('-inf')
        def dfs(root):
            if not root:
                return 0
            left = dfs(root.left)
            right = dfs(root.right)
            rootSum = max(left + right + root.val, root.val, right + root.val, left + root.val)
            pathSum = max(root.val, right + root.val, left + root.val)
            if rootSum > self.res:
                self.res = rootSum
            return pathSum
        dfs(root)
        return self.res
            