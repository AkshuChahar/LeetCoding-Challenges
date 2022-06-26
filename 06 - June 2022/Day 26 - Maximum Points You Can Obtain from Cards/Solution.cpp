class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        // Calculate the total sum.
        int sum = accumulate(cardPoints.begin(), cardPoints.end(), 0);
        // Edge case: Check if 'n == k'.
        if (n == k)
            return sum;
        // Initialise a window of size 'n-k' and calculate the sum of its elements.
        int left = 0, right = n - k, temp_sum = 0;
        for (int i = 0; i < right; i++)
            temp_sum += cardPoints[i];
        int ans = sum - temp_sum;
        // Now traverse the array and find the minimum window sum.
        while (right < n) {
            // Update the window sum.
            temp_sum += cardPoints[right] - cardPoints[left];
            left++;
            right++;
            // Update 'ans'.
            ans = max(ans, sum - temp_sum);
        }
        return ans;
    }
};