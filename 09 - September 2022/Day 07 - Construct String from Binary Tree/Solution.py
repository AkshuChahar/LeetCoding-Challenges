# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def tree2str(self, root: Optional[TreeNode]) -> str:
        # Check if we have reached the end of the tree.
        if not root:
            return ""
        ans = str(root.val)
        # Check if we have to add parenthesis for the left node.
        if root.left or root.right:
            ans += "(" + self.tree2str(root.left) + ")"
        # Check if we have to add parenthesis for the right node.
        if root.right:
            ans += "(" + self.tree2str(root.right) + ")"
        return ans