class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        // We first compute the cost of sending everyone to city A.
        // Simultaneously we calculate the difference in costs.
        // Now we add the n people with minimum difference to city B.
        int cost = 0;
        vector<int> diff = {};

        for (int i = 0; i < costs.size(); i++) {
            cost += costs[i][0];
            diff.push_back(costs[i][1] - costs[i][0]);
        }

        // Sort the differences.
        sort(diff.begin(), diff.end());

        // Now add first n differences to cost.
        for (int i = 0; i < costs.size()/2; i++)
            cost += diff[i];

        return cost;
    }
};