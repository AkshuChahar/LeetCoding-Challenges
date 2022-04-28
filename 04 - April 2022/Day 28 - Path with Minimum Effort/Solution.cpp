class Solution {
public:
    // Initialise a direction array and variables to store the matrix size.
    int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    int m, n;

    // Function to check for paths with a given effort using 'BFS'.
    bool bfs(vector<vector<int>>& heights, int effort) {
        // Initialise a vector to keep track of visited cells.
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        queue<pair<int, int>> q;
        // Push the starting cell in the queue and mark it as visited.
        q.push(make_pair(0, 0));
        visited[0][0] = true;
        while (!q.empty()) {
            int row = q.front().first, col = q.front().second;
            q.pop();
            // Check if we have reached the end of matrix indicating that we have found a valid path.
            if (row == m - 1 && col == n - 1)
                return true;
            // Move to next cell in all directions.
            for (int i = 0; i < 4; i++) {
                int x = row + dir[i][0], y = col + dir[i][1];
                // If the cell is valid and not visited yet and has the height difference less than 'effort', push it in the queue.
                if (x >= 0 && y >= 0 && x < m && y < n && !visited[x][y] && (abs(heights[row][col] - heights[x][y]) <= effort)) {
                    q.push(make_pair(x, y));
                    visited[x][y] = true;
                }
            }
        }
        return false;
    }

    int minimumEffortPath(vector<vector<int>>& heights) {
        m = heights.size(), n = heights[0].size();
        // Do a 'Binary Search' for every possible effort.
        int low = 0, high = 1e6;
        int ans = -1;
        while (low <= high) {
            int mid = low + (high - low)/2;
            // Check if there is a path with 'mid' effort.
            if (bfs(heights, mid)) {
                // Update 'ans' and check for lower values of 'mid'.
                ans = mid;
                high = mid - 1;
            }
            // Else check for higher values of 'mid'.
            else
                low = mid + 1;
        }
        return ans;
    }
};