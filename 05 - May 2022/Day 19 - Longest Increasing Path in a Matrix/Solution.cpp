class Solution {
public:    
    // Define the direction matrix.
    vector<vector<int>> dirs = {{-1,0}, {0,-1}, {0,1}, {1,0}};

    // Function for 'DFS'.
    int dfs(vector<vector<int>>& matrix, int r, int c, vector<vector<int>>& dp, int prev) {
        // If we are out of bounds, return 0.
        if (r < 0 || r >= matrix.size() || c < 0 || c >= matrix[r].size()) 
            return 0;
        // If the current element is smaller than previous element, return 0.
        if (matrix[r][c] <= prev) 
            return 0;

        // If we have already visited the current cell, return the length of path.
        if (dp[r][c] != -1) 
            return dp[r][c];
        int best = 0;
        // Traverse in all directions.
        for (auto& dir : dirs) {
            // Do a 'DFS'.
            int nr = dir[0] + r, nc = dir[1] + c;
            int cur = dfs(matrix, nr, nc, dp, matrix[r][c]);
            best = max(best, cur);
        }
        return dp[r][c] = best + 1;
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        // Here we will use 'Dynamic Programming' with 'DFS'.
        int m = matrix.size(), n = matrix[0].size();
        int ans = 0;
        // Initialise the 'dp' vector.
        vector<vector<int>> dp(m, vector<int>(n, -1));
        // Traverse the matrix.
        for(int r = 0; r < m; r++) {
            for(int c = 0; c < n; c++) {
                // Do 'DFS' and return the length of longest increasing path from current cell.
                int lip = dfs(matrix, r, c, dp, -1000000);
                // Update the answer.
                ans = max(ans, lip);
            }
        }
        return ans;
    }
};