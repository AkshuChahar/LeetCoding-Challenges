class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size(), ans = 0;
        // Initialise a matrix and store the prefix sum in it.
        vector<vector<int>> pref(m + 1, vector<int>(n));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++)
                pref[i + 1][j] = pref[i][j] + matrix[i][j];
        }
        // Iterate over all possible sub-matrices and count those with sum equal to 'target'.
        for (int i = 0; i < m; i++) {
            for (int j = i + 1; j <= m; j++) {
                for (int k = 0; k < n; k++) {
                    int sum = 0;
                    for (int l = k; l < n; l++) {
                        sum += pref[j][l] - pref[i][l];
                        if (sum == target)
                            ans++;
                    }
                }
            }
        }
        return ans;
    }
};