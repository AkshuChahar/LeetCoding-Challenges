class Solution:
    def outerTrees(self, trees: List[List[int]]) -> List[List[int]]:
        # Sort the list.
        trees = sorted(trees)
        # Initialise two stacks to keep the trees above and below the leftmost point seperate.
        above, below = [], []
        # Function to calculate the cross product.
        def cross(b, a, tree):
            return (tree[1] - b[1]) * (b[0] - a[0]) - (b[1] - a[1]) * (tree[0] - b[0])
        # Traverse the list.
        for tree in trees:
            # Check if the point in above or below the leftmost point.
            while len(above) >= 2 and cross(above[-1], above[-2], tree) < 0:
                above.pop()
            above.append(tree)
            while len(below) >= 2 and cross(below[-1], below[-2], tree) > 0:
                below.pop()
            below.append(tree)
        return set(tuple(tree) for tree in (above + below))