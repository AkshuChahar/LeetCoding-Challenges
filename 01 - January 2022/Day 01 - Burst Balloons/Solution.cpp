class Solution {
public:
    int maxCoins(vector<int>& nums) {
        // Use padding to handle edge case.
        int n = nums.size() + 2;
        vector<int> new_nums(n, 1);
        int i = 1;
        for (auto num:nums)
            new_nums[i++] = num;

        // Apply DP. Iniatilise a 2-D for backtracking.
        vector<vector<int>> res(n, vector<int>(n));
        for (int len = 2; len <= n; len++) {
            for (int i = 0; i <= n - len; i++) {
                int j = i + len - 1;
                for (int k = i + 1; k < j; k++) {
                    res[i][j] = max(res[i][j], res[i][k] + new_nums[i] * new_nums[k] * new_nums[j] + res[k][j]);
                }
            }
        }

        return res[0][n - 1]; // Top rightmost element.
    }
};