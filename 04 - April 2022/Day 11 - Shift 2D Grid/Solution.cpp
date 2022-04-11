class Solution {
public:
    // Store the size of matrix globally.
    int m, n;

    // Helper function for the reverse operation.
    void reverse(vector<vector<int>>& grid, int start, int end) {
        while (start < end) {
            // Get the row and column of the current 'start' and 'end'.
            int s_row = start / n, s_col = start % n;
            int e_row = end / n, e_col = end % n;
            // Swap these elements and move the pointers.
            swap(grid[s_row][s_col], grid[e_row][e_col]);
            start++;
            end--;
        }
    }

    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        m = grid.size(), n = grid[0].size();
        // Update the value of 'k'.
        k = k % (m * n);
        // Now we reverse the whole matrix.
        reverse(grid, 0, m * n - 1);
        // Now we reverse the parts the of matrix to get the answer.
        reverse(grid, 0, k - 1);
        reverse(grid, k, m * n - 1);
        return grid;
    }
};