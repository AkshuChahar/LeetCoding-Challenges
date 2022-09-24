# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:    
    def pathSum(self, root: Optional[TreeNode], targetSum: int) -> List[List[int]]:
        ans = []
        # Function for 'Backtracking'.
        def backtrack(root, targetSum, ans, res):
            # Check if we have reached the leaf node.
            if not root:
                return
            # Add the current node to the 'res' list.
            res.append(root.val)
            # Check if we have reached the 'targetSum'.
            if (not root.left and not root.right and targetSum == root.val):
                ans.append(list(res))
            # Move to the left and right subtree.
            backtrack(root.left, targetSum - root.val, ans, res)
            backtrack(root.right, targetSum - root.val, ans, res)
            # Backtrack.
            res.pop()
        # Call the recursive function.
        backtrack(root, targetSum, ans, [])
        return ans