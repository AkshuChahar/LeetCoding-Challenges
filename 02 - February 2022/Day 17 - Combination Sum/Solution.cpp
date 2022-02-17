class Solution {
public:
    void backtrack(vector<int>& candidates, int start, vector<vector<int>>& ans, vector<int>& res, int target) {
        // If the current sum is 0, that means the current 'res' array is a required combination.
        if (target == 0) {
            ans.push_back(res);
            return;
        }

        // If the current sum reaches negative value, it means that the current array is not a required combination.
        if (target < 0)
            return;

        for (int i = start; i < candidates.size(); i++) {
            // Add the current element to 'res'.
            res.push_back(candidates[i]);
            // Make recursive call.
            backtrack(candidates, i, ans, res, target - candidates[i]);
            // Backtrack.
            res.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        // Create an array to store the combinations and an array to store current combination.
        vector<vector<int>> ans;
        vector<int> res;
        // Call the recursive function to backtrack.
        backtrack(candidates, 0, ans, res, target);
        return ans;
    }
};