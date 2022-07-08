class Solution {
public:
    // The maximum cost possible will be 10^6.
    const int MAX_COST = 1000001;

    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        int ans = MAX_COST;
        // Initialise the vector to keep track of previous houses.
        vector<vector<int>> prev(target + 1, vector<int>(n, MAX_COST));
        // Update the cost and color for the 1st house.
        for (int color = 1; color <= n; color++) {
            // Check if the house is painted with the same color.
            if (houses[0] == color)
                prev[1][color - 1] = 0;
            // Check if the house is not yet painted.
            else if (houses[0] == 0)
                prev[1][color - 1] = cost[0][color - 1];
        }
        // Iterate over all houses.
        for (int house = 1; house < m; house++) {
            // Initialise the dp vector.
            vector<vector<int>> dp(target + 1, vector<int>(n, MAX_COST));
            // Iterate for all neighbourhoods and colors.
            for (int neigh = 1; neigh <= min(target, house + 1); neigh++) {
                for (int color = 1; color <= n; color++) {
                    // If the house is already painted with different color, it cannot be repainted.
                    if (houses[house] && color != houses[house])
                        continue;
                    int curr = MAX_COST;
                    // Check for all possible colors for previous house.
                    for (int p_color = 1; p_color <= n; p_color++) {
                        // If the previous color is different, decrement the number of neighbourhoods available.
                        if (p_color != color)
                            curr = min(curr, prev[neigh - 1][p_color - 1]);
                        else
                            curr = min(curr, prev[neigh][p_color - 1]);
                    }
                    // If the house is already painted, cost is 0.
                    int res = houses[house] ? 0 : cost[house][color - 1];
                    dp[neigh][color - 1] = curr + res;
                }
            }
            // Update the 'prev' vector.
            prev = dp;
        }
        // The minimum cost will be obtained by comparing the cost for different colors for the last house.
        for (int color = 1; color <= n; color++)
            ans = min(ans, prev[target][color - 1]);
        // Return the required answer.
        return (ans == MAX_COST) ? -1 : ans;
    }
};