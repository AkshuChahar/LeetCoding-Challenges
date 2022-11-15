# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def countNodes(self, root: Optional[TreeNode]) -> int:
        # Check if we have reached the end.
        if not root:
            return 0
        # Initialise two pointers.
        left = right = root
        left_depth = right_depth = 0
        # Compute the depths.
        while left:
            left = left.left
            left_depth += 1
        while right:
            right = right.right
            right_depth += 1
        # Check if we have a 'Full tree'.
        if left_depth == right_depth:
            return (2 ** left_depth) - 1
        return 1 + self.countNodes(root.left) + self.countNodes(root.right)