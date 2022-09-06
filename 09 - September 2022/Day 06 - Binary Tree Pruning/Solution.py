# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def pruneTree(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
        # Function for 'Depth-First Search'.
        def dfs(node: TreeNode) -> bool:
            # Check if we traversed the subtree.
            if not node:
                return False
            # Check if the lest subtree has a 1.
            left = dfs(node.left)
            # Check if the right subtree has a 1.
            right = dfs(node.right)
            # Drop subtrees accordingly.
            if not left:
                node.left = None
            if not right:
                node.right = None
            # Check if the current node is 1.
            return node.val or left or right
        # Check if there is a 1 in the tree.
        if dfs(root):
            return root
        else:
            return None