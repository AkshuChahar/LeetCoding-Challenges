class Solution {
public:
    // Function to check if the current position is valid or not.
    bool safe(vector<string>& res, int row, int col, int n) {
        for (int i = 0; i < n; i++) {
            // Check if there is a Queen in the same column.
            if (res[i][col] == 'Q')
                return false;
            // Check for Queens present diagonally to the current position.
            if (row - i >= 0 && col - i >= 0 && res[row - i][col - i] == 'Q')
                return false;
            if (row - i >= 0 && col + i < n && res[row - i][col + i] == 'Q')
                return false;
            if (row + i < n && col - i >= 0 && res[row + i][col - i] == 'Q')
                return false;
            if (row + i < n && col + i < n && res[row + i][col + i] == 'Q')
                return false;
        }
        return true;
    }

    // Function for 'Backtracking'.
    void backtrack(vector<vector<string>>& ans, vector<string>& res, int row, int n) {
        // When we reach the last row, we add that combination to the final answer.
        if (row == n) {
            ans.push_back(res);
            return;
        }
        // Check by placing the Queen to all valid columns in the current row.
        for (int col = 0; col < n; col++) {
            // Check if the current position is valid or not.
            if (safe(res, row, col, n)) {
                res[row][col] = 'Q';
                // Backtrack.
                backtrack(ans, res, row + 1, n);
                res[row][col] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> res(n, string(n, '.'));
        // Check for all possible positions of Queen starting with 1st row.
        backtrack(ans, res, 0, n);
        return ans;
    }
};