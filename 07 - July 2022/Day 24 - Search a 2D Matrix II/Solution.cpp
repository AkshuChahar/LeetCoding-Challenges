class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        // Initialise our pointer at the end of first row.
        int i = 0, j = n - 1;
        // Traverse the matrix.
        while (i < m && j >= 0) {
            // Check if we found the match.
            if (target == matrix[i][j])
                return true;
            // If the 'target' is less than current element, check in the same row.
            if (target < matrix[i][j])
                j--;
            // Else move to next row.
            else
                i++;
        }
        return false;
    }
};