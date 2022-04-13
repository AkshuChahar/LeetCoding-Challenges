class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        // Get the number of layers.
        int layers = (n + 1)/2;
        // Initialise a 2-D vector to store the matrix.
        vector<vector<int>> ans(n, vector<int>(n));
        // Start with the 1st layer.
        int l = 1;
        // Keep track of which number to fill in the cell.
        int i = 1;
        // Iterate till we fill all layers.
        while (l <= layers) {
            // Get the current row and column.
            int row = l - 1, col = l - 1;
            // Move from left to right.
            while (col < n - l + 1) {
                ans[row][col] = i;
                i++;
                col++;
            }
            // Move 1 column back and 1 row forward.
            col--;
            row++;
            // Move from top to bottom.
            while (row < n - l + 1) {
                ans[row][col] = i;
                i++;
                row++;
            }
            // Move 1 row and column back.
            row--;
            col--;
            // Move from right to left.
            while (col >= l - 1) {
                ans[row][col] = i;
                i++;
                col--;
            }
            // Move 1 column forward and 1 row back.
            col++;
            row--;
            // Move from bottom to top.
            while (row >= l) {
                ans[row][col] = i;
                i++;
                row--;
            }
            // Increment layer.
            l++;
        }
        return ans;
    }
};