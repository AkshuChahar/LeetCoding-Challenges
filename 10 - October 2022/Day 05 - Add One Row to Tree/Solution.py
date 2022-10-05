# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def addOneRow(self, root: Optional[TreeNode], val: int, depth: int) -> Optional[TreeNode]:
        # Edge case: If the 'depth' is 1.
        if depth == 1:
            node = TreeNode(val)
            # Update 'root' node.
            node.left = root
            return node
        # Initialise a queue for Level-Order Traversal and a variable to keep track of level.
        q = deque()
        level = 1
        q.append(root)
        # Traverse the tree till the required depth.
        while level < depth - 1:
            n = len(q)
            while n:
                node = q.popleft()
                if node.left:
                    q.append(node.left)
                if node.right:
                    q.append(node.right)
                n -= 1
            level += 1
        # Add the new row as the child to the current level.
        n = len(q)
        while n:
            node = q.popleft()
            # Update the child nodes.
            temp = node.left
            node.left = TreeNode(val)
            node.left.left = temp
            temp = node.right
            node.right = TreeNode(val)
            node.right.right = temp
            n -= 1
        return root