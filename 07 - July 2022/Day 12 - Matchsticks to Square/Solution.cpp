class Solution {
public:
    // Initialise an array to keep track of length of matches on each side.
    vector<int> edge = {0, 0, 0, 0};

    // Function for Backtracking.
    bool backtrack(int i, int n, vector<int>& matchsticks, int side) {
        if (i == n)
            return true;
        // Check for every matchstick combination.
        for (int j = 0; j < 4; j++) {
            // Check if current matchstick can be put in the current side.
            if (matchsticks[i] + edge[j] <= side) {
                edge[j] += matchsticks[i];
                // Recurse and Backtrack.
                if (backtrack(i + 1, n, matchsticks, side))
                    return true;
                edge[j] -= matchsticks[i];
            }
        }
        return false;
    }

    bool makesquare(vector<int>& matchsticks) {
        int n = matchsticks.size(), sum = accumulate(matchsticks.begin(), matchsticks.end(), 0);
        // Check if the 'sum' is divisible by 4.
        if (sum % 4)
            return false;
        // Sort the array and call for helper function.
        sort(matchsticks.begin(), matchsticks.end(), greater<int>());
        return backtrack(0, n, matchsticks, sum / 4);
    }
};