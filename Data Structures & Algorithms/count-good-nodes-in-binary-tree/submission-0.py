# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def goodNodes(self, root: TreeNode) -> int:
        if not root:
            return 0
        sol = 0
        dq = deque([(root, float('-inf'))])
        while dq:
            curr, curr_max = dq.popleft()
            if curr.val >= curr_max:
                sol += 1
                curr_max = curr.val
            if curr.left:
                dq.append((curr.left, curr_max))
            if curr.right:
                dq.append((curr.right, curr_max))
        return sol