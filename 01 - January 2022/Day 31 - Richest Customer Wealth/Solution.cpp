class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        // Initialise a variable to store maximum wealth.
        int ans = 0;
        // Traverse the grid.
        for (int i=0; i<accounts.size(); i++) {
            // Initialise a variable to store wealth of each customer.
            int wealth = 0;
            for (int j=0; j<accounts[0].size(); j++)
                wealth += accounts[i][j];
            // Update maximum wealth.
            ans = max(ans, wealth);
        }
        return ans;
    }
};