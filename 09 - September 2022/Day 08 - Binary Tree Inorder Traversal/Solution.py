# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def inorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        ans = []
        # Check if the 'root' node is NULL.
        if not root:
            return ans
        # Initialise a atack for traversal.
        s = deque()
        curr = root
        # Traverse the tree.
        while s or curr:
            # If the current node is not NULL, keep moving left.
            if curr:
                s.append(curr)
                curr = curr.left
            # If the current node is NULL, move towards right and update 'ans'.
            else:
                node = s.pop()
                ans.append(node.val)
                curr = node.right
        return ans