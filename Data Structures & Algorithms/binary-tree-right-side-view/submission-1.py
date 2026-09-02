# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def rightSideView(self, root: Optional[TreeNode]) -> List[int]:
        if not root:
            return []
        sol = []
        dq = deque([root])
        while dq:
            depthLenth = len(dq)
            for i in range(depthLenth):
                curr = dq.popleft()
                if curr.left:
                    dq.append(curr.left)
                if curr.right:
                    dq.append(curr.right)
                if i == (depthLenth - 1):
                    sol.append(curr.val)
        return sol