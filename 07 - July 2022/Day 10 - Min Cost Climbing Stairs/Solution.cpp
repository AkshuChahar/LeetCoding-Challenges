class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int ans = 0;
        // Initialise the dp vector and add the cost of first 2 to it.
        vector<int> dp;
        dp.push_back(cost[0]);
        dp.push_back(cost[1]);
        // Traverse the array.
        for (int i = 2; i <= cost.size(); i++) {
            // If we have reached the end, the cost will be 0.
            int n = (i == cost.size()) ? 0 : cost[i];
            // Add the minimum of the cost and push it into the vector.
            ans = n + min(dp[i-1], dp[i-2]);
            dp.push_back(ans);
        }
        return dp[cost.size()];
    }
};