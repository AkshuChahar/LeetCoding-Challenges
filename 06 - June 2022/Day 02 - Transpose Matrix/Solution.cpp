class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        // Initialise a vector of size 'n*m'.
        vector<vector<int>> ans(n, vector<int>(m, 0));
        // Traverse the matrix and fill 'ans'.
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++)
                ans[j][i] = matrix[i][j];
        }
        return ans;
    }
};