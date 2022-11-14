class Solution:
    def removeStones(self, stones: List[List[int]]) -> int:
        n, res = len(stones), 0
        # Initialise dictionaries to store the connected components and a set to keep track of visited stones.
        row_dict, col_dict = defaultdict(list), defaultdict(list)
        vis = set()
        for stone in stones:
            row_dict[stone[0]].append(stone[1])
            col_dict[stone[1]].append(stone[0])
        # Function for 'DFS'.
        def dfs(stone):
            # Check if the current 'stone' has been visited.
            if stone in vis:
                return
            # Update 'vis'.
            vis.add(stone)
            row, col = stone
            # Recurse.
            for c in row_dict[row]:
                dfs((row, c))
            for r in col_dict[col]:
                dfs((r, col))
        # Do a 'DFS'.
        for r, c in stones:
            if (r, c) not in vis:
                dfs((r, c))
                res += 1
        return n - res