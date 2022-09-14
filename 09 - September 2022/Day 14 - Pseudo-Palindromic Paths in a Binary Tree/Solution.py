# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def pseudoPalindromicPaths (self, root: Optional[TreeNode]) -> int:
        ans = 0
        # Initialise a stack for 'Preorder Traversal' and to keep track of frequency of odd count of numbers.
        st = [(root, 0)]
        while st:
            node, count = st.pop()
            if node:
                # Compute the frequency.
                count ^= (1 << node.val)
                # Check if we have arrived at a leaf node.
                if (not node.left) and (not node.right):
                    # Check if we have atmpst 1 number with odd frequency.
                    if count & (count - 1) == 0:
                        ans += 1
                else:
                    st.append((node.right, count))
                    st.append((node.left, count))
        return ans