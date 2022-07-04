class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        // Initialise a array with all values 1 to store the candy distribution.
        vector<int> candies(n, 1);
        // Traverse the 'ratings' from left to right and update the number of candies.
        for (int i = 1; i < n; i++) {
            if (ratings[i] > ratings[i-1])
                candies[i] = candies[i-1] + 1;
        }
        int ans = candies[n-1];
        // Now move right to left and update the candies based on that while adding the sum.
        for (int i = n-2; i >= 0; i--) {
            if (ratings[i] > ratings[i+1])
                candies[i] = max(candies[i], candies[i+1] + 1);
            ans += candies[i];
        }
        return ans;
    }
};