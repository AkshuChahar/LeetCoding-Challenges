class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        // Start fro the first row.
        int i = 0;
        while (i < numRows) {
            // Store the result in a temporary vector.
            vector<int> temp(i + 1, 1);
            int j = 1;
            while (j < i) {
                temp[j] = ans[i-1][j-1] + ans[i-1][j];
                j++;
            }
            i++;
            // Add to the final result.
            ans.push_back(temp);
        }

        return ans;
    }
};