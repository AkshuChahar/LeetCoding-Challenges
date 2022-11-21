class Solution:
    def nearestExit(self, maze: List[List[str]], entrance: List[int]) -> int:
        m, n, ans = len(maze), len(maze[0]), 0
        # Initialise a queue for 'BFS' and a list containing the directions.
        q = collections.deque()
        d_x, d_y = [0, 0, 1, -1], [1, -1, 0, 0]
        # Mark the entrance as visited.
        if (entrance[0] == 0 or entrance[0] == m - 1 or entrance[1] == 0 or entrance[1] == n - 1):
            maze[entrance[0]][entrance[1]] = '+'
        q.append((entrance[0], entrance[1]))
        # Perform 'BFS'.
        while q:
            s = len(q)
            for i in range(s):
                r, c = q.popleft()
                if (maze[r][c] != '+' and (r == 0 or c == 0 or r == m-1 or c == n-1)):
                    return ans
                for j in range(4):
                    x, y = r + d_x[j], c + d_y[j]
                    if (x >= 0 and y >= 0 and x < m and y < n and maze[x][y] == '.'):
                        q.append((x, y))
                        maze[x][y] = '*'
            ans += 1
        return -1