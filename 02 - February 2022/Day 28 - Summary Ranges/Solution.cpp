class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int n = nums.size();
        // Edge case: When the input is an empty array.
        if (n == 0)
            return {};

        vector<string> ans;
        // Initialise start pointer.
        int i=0;
        while (i < n) {
            // String to store current range.
            string temp = "";
            temp += to_string(nums[i]);
            // Check for range.
            int j = i + 1;
            while (j < n && nums[j] == nums[j-1] + 1)
                j++;
            // Update string and output accordingly.
            temp += (j == i + 1) ? "" : "->" + to_string(nums[j-1]);
            ans.push_back(temp);
            // Update the start of next range.
            i = j;
        }

        return ans;
    }
};