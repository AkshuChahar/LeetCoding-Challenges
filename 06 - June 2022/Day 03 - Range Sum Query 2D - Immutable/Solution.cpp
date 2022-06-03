class NumMatrix {
public:
    // Initialise a vector to store the matrix.
    vector<vector<int>>& mat;

    NumMatrix(vector<vector<int>>& matrix) : mat(matrix) {
        int row = mat.size(), col = mat[0].size();
        // Store the row-wise sum.
        for (int i = 0; i < row; i++) {
            for (int j = 1; j < col; j++)
                mat[i][j] += mat[i][j-1];
        }
        // Store the column-wise sum.
        for (int i = 1; i < row; i++) {
            for (int j = 0; j < col; j++)
                mat[i][j] += mat[i-1][j];
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        // Subtract the repeated sum and return the required result.
        return mat[row2][col2] - (row1 > 0 ? mat[row1 - 1][col2] : 0) - (col1 > 0 ? mat[row2][col1 - 1] : 0) + (row1 > 0 && col1 > 0 ? mat[row1 - 1][col1 - 1] : 0);
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */