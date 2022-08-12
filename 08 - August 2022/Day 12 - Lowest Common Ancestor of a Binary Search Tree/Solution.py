# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        # Traverse the tree.
        while (root):
            # If the current node is less than both the nodes, move to the left subtree.
            if (root.val > p.val and root.val > q.val):
                root = root.left
            # If the current node is more than both the nodes, move to right subtree.
            elif (root.val < p.val and root.val < q.val):
                root = root.right
            else:
                return root
        return root