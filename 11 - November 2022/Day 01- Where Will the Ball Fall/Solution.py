class Solution:
    def findBall(self, grid: List[List[int]]) -> List[int]:
        m, n = len(grid), len(grid[0])
        ans = []
        # Function for 'DFS'.
        def dfs(row, col):
            # Check if the ball is going out of the box.
            if row == m:
                return col
            new_col = col + grid[row][col]
            # Check if the ball is getting stuck.
            if new_col == n or new_col == -1 or grid[row][new_col] != grid[row][col]:
                return -1
            else:
                return dfs(row + 1, new_col)
        for col in range(n):
            ans.append(dfs(0, col))
        return ans