﻿class Solution:
    def uniquePathsIII(self, grid: List[List[int]]) -> int:
        self.ans = 0
        m, n, empty = len(grid), len(grid[0]), 1
        # Check for empty cells.
        for i in range(m):
            for j in range(n):
                if grid[i][j] == 1:
                    x, y = (i, j)
                elif grid[i][j] == 0:
                    empty += 1
        # Function for 'DFS'.
        def dfs(x, y, empty):
            if not (0 <= x < m and 0 <= y < n and grid[x][y] >= 0): 
                return
            if grid[x][y] == 2:
                self.ans += empty == 0
                return
            grid[x][y] = -2
            dfs(x + 1, y, empty - 1)
            dfs(x - 1, y, empty - 1)
            dfs(x, y + 1, empty - 1)
            dfs(x, y - 1, empty - 1)
            grid[x][y] = 0
        dfs(x, y, empty)
        return self.ans