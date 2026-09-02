# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def levelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
        if not root:
            return []
        sol = []
        dq = deque([root])
        while dq:
            innerSol = []
            for i in range(len(dq)):
                curr = dq.popleft()
                innerSol.append(curr.val)
                if curr.left:
                    dq.append(curr.left)
                if curr.right:
                    dq.append(curr.right)
            sol.append(innerSol)
        return sol
            
        