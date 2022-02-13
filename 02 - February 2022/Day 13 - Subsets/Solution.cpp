class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans = {{}};
        // Now we make subsets for each element.
        for(int num:nums) {
            // Store the current length of output.
            int n = ans.size();
            for (int i = 0; i < n; i++) {
                // Add the 'i-th' array of output array to the back.
                ans.push_back(ans[i]);
                // Add the current element to the newly added array at the back.
                ans.back().push_back(num);
            }
        }
        return ans;
    }
};