class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        // Apply Greedy.
        int ans = 0, curr = 0, total = 0;

        for (int i=0; i<gas.size(); i++) {
            total += gas[i] - cost[i];
            curr += gas[i] - cost[i];

            // If 'curr' becomes negative, set it back to 0 and 'ans' to i+1.
            if (curr < 0) {
                curr = 0;
                ans = i+1;
            }
        }
        // If the total cost is more than gas required (that is, 'total' < 0), return -1.
        return (total < 0) ? -1 : ans;
    }
};