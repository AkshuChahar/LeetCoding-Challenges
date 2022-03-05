class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        // Edge case: If the array contains only 1 element.
        if (nums.size() == 1)
            return nums[0];

        // Initialise vectors to compute the sums at each point.
        vector<int> sums(10001, 0);
        vector<int> dp(10001, 0);

        // Store the elements in ascending order.
        for (int num:nums)
            sums[num] += num;

        // Use Dynamic Programming.
        dp[1] = sums[1];
        for (int i = 2; i < 10001; i++)
            dp[i] = max(dp[i-1], sums[i] + dp[i-2]);

        return dp[10000];
    }
};