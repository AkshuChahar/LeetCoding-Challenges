# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def isValidBST(self, root: Optional[TreeNode]) -> bool:
        # Define a function to check if the current node value falls into valid range.
        def check(node, min_val, max_val):
            # If we have reached the end of subtree, return 'True'.
            if node is None:
                return True
            # Check for validation.
            if node.val <= min_val or node.val >= max_val:
                return False
            # Check for next node.
            return check(node.left, min_val, node.val) and check(node.right, node.val, max_val)
        return check(root, -2**31 - 1, 2**31)