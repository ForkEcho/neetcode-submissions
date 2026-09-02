# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:   
    def isSubtree(self, root: Optional[TreeNode], subRoot: Optional[TreeNode]) -> bool:
        if not subRoot:
            return True
        if not root:
            return False
        queue = [root]
        while queue:
            if (self.sameTree(queue[0], subRoot)):
                return True
            else:
                if queue[0].left:
                    queue.append(queue[0].left)
                if queue[0].right:
                    queue.append(queue[0].right)
            queue.pop(0)
        return False
            

        
    def sameTree(self, root, subroot):
        if not root and not subroot:
            return True
        if (not root and subroot) or (root and not subroot):
            return False
        if root.val == subroot.val:
            return (self.sameTree(root.left, subroot.left)) and (self.sameTree(root.right, subroot.right))
        return False