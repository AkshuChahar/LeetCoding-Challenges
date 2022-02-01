class Solution {
public:

    // Bottom-up approach.

    vector<vector<vector<int>>> dp = vector<vector<vector<int>>>(70, vector<vector<int>>(70, vector<int>(70))); // Initialising the 'dp' vector using constraints.

    int cherryPickup(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();    // m, n = number of rows and columns.
        int dir[3] = {-1, 0, 1};                    // Direction array.

        // Iterating for rows.
        for (int r = m-1; r >= 0; r--) {
            // Iterating for robot 1.
            for (int c1 = 0; c1 < n; c1++) {
                // Iterating for robot 2.
                for (int c2 = 0; c2 < n; c2++) {
                    // Now, we check when can we get the max sum value in the present row and the next row (for all 9 possible moves of robots).
                    // Possible directions in which robot 1 can move.
                    for (int dir1 : dir) {
                        // Possible directions in which robot 2 can move.
                        for (int dir2 : dir) {
                            int temp_c1 = c1 + dir1, temp_c2 = c2 + dir2;
                            // Check if robots are out of boundary.
                            if (temp_c1 >= 0 && temp_c2 >= 0 && temp_c1 < n && temp_c2 < n) {
                                // Get the max value of 'dp' at present.
                                dp[r][c1][c2] = max(dp[r][c1][c2], dp[r+1][temp_c1][temp_c2]);
                            }
                        }
                    }
                    // Increment the grid values to the 'dp' (Check if c1 == c2).
                    dp[r][c1][c2] += grid[r][c1] + ((c1 != c2) ? (grid[r][c2]) : 0);
                }
            }
        }

        return dp[0][0][n-1];
    }
};