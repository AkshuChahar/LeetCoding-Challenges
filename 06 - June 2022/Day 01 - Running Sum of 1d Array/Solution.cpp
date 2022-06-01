class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        int n = nums.size(), sum = 0;
        vector<int> ans(n, 0);
        // Traverse the array.
        for (int i = 0; i < n; i++) {
            // Update 'sum' and 'ans'.
            sum += nums[i];
            ans[i] = sum;
        }
        return ans;
    }
};