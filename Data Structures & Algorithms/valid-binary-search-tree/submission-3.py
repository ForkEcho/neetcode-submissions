# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def isValidBST(self, root: Optional[TreeNode]) -> bool:
        dq = deque([(root, float("-inf"), float("inf"))])
        while dq:
            curr, curr_min, curr_max = dq.popleft()
            print(f'curr.val: {curr.val} min: {curr_min} max: {curr_max}')
            if curr.val <= curr_min or curr.val >= curr_max:
                return False
            if curr.left:
                dq.append((curr.left, curr_min, curr.val))
            if curr.right:
                dq.append((curr.right, curr.val, curr_max))
        return True