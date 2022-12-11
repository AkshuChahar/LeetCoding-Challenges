# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def maxPathSum(self, root: Optional[TreeNode]) -> int:
        ans = -float('inf')
        # Function for Post-Order Traversal.
        def traversal(node: Optional[TreeNode]) -> int:
            nonlocal ans
            if not node:
                return 0
            # Get the sum of left subtree.
            left = max(traversal(node.left), 0)
            # Get the sum of right subtree.
            right = max(traversal(node.right), 0)
            # Update 'ans'.
            ans = max(ans, left + right + node.val)
            return max(left + node.val, right + node.val)
        traversal(root)
        return ans