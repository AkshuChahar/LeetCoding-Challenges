class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        // Edge case: If the vector contains less than 3 elements.
        if (n < 3)
            return 0;

        // Use 'Dynamic Programming'.
        int dp = 0, ans = 0;
        // Traverse the vector.
        for (int i = 2; i < n; i++) {
            // If a arithmetic slice is found, increment 'dp' by 1 and 'ans' by 'dp'.
            dp = (nums[i] - nums[i-1] == nums[i-1] - nums[i-2]) ? dp + 1 : 0;
            ans += dp;
        }

        return ans;
    }
};