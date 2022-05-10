class Solution {
public:
    // Function for Backtracking.
    void backtrack(int k, int n, int start, int sum, vector<vector<int>>& ans, vector<int>& res) {
        // If we have reached the limit and sum, add the result to final answer.
        if (k == 0) {
            if (sum == n)
                ans.push_back(res);
            return;
        }
        // If the required sum has already been reached, return.
        if (k != 0 && sum >= n)
            return;
        // Check by placing all integers at current index and backtracking.
        for (int i = start; i < 10; i++) {
            res.push_back(i);
            backtrack(k - 1, n, i + 1, sum + i, ans, res);
            res.pop_back();
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        // Initialise vectors to store the final answer and temporary answers.
        vector<vector<int>> ans;
        vector<int> res;
        // Use 'Backtracking' starting from integer '1' and sum '0' .
        backtrack(k, n, 1, 0, ans, res);
        return ans;
    }
};