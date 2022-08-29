class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        m, n, ans = len(grid), len(grid[0]), 0
        # Traverse the grid.
        for i in range(m):
            for j in range(n):
                # Check if we found an island.
                if grid[i][j] == "1":
                    ans += 1
                    # Initialise a stack to keep track of the current island.
                    st = deque([(i, j)])
                    # Check untill the stack is empty.
                    while len(st) != 0:
                        # Move in all directions from the current position.
                        row, col = st.popleft()
                        # Check if we are currently on the island.
                        if grid[row][col] == "1":
                            # Mark the position as visited.
                            grid[row][col] = "0"
                            if row + 1 < m:
                                st.append((row + 1, col))
                            if row - 1 >= 0:
                                st.append((row - 1, col))
                            if col + 1 < n:
                                st.append((row, col + 1))
                            if col - 1 >= 0:
                                st.append((row, col - 1))
        return ans