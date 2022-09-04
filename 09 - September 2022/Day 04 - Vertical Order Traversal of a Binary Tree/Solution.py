# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def verticalTraversal(self, root: Optional[TreeNode]) -> List[List[int]]:
        ans = defaultdict(list)
        # Intialise a dictionary to store the nodes with their rows and columns. 
        res = defaultdict(list)
        # Initialise a queue for 'Breadth-First Traversal'.
        q = deque()
        q.append((root, 0, 0))
        while q:
            node, col, row = q.popleft()
            # Update the dictionary.
            res[(col, row)].append(node.val)
            # Sort the result.
            res[(col, row)].sort()
            if node.left:
                q.append((node.left, col - 1, row + 1))
            if node.right:
                q.append((node.right, col + 1, row + 1))
        # Get the keys of the dictionary in sorted order.
        keys = sorted(list(res.keys()), key = lambda x : (x[0], x[1]))
        # Add the values to the final answer.
        for key in keys:
            col, row = key
            ans[col].extend(res[key])
        return ans.values()