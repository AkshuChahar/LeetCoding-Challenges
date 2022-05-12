class Solution {
public:
    // Function for 'Backtracking'.
    void backtrack(int n, vector<vector<int>>& ans, vector<int>& res, unordered_map<int, int>& m) {
        // If we temporary result is of the size 'n', add it to final answer.
        if (res.size() == n) {
            ans.push_back(res);
            return;
        }
        // Traverse the map.
        for (auto [num, count]:m) {
            // If we have used all instances of current element, we move to next.
            if (count == 0)
                continue;
            // Add the current element to 'res'.
            res.push_back(num);
            // Update map.
            m[num]--;
            // Backtrack again.
            backtrack(n, ans, res, m);
            res.pop_back();
            // Update map.
            m[num]++;
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int n = nums.size();
        // Initialise vectors to store the final answer and the temporary results.
        vector<vector<int>> ans;
        vector<int> res;
        // Initialise a map to keep the frequency of each element.
        unordered_map<int, int> m;
        for (int num:nums)
            m[num]++;
        // Use 'Backtracking'.
        backtrack(n, ans, res, m);
        return ans;
    }
};