class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        int n = nums.size();
        // Initialise the dp vector and a max heap to store the cost till a particular index.
        vector<int> dp(n);
        dp[n - 1] = nums[n - 1];
        priority_queue<pair<int, int>> pq;
        pq.push(make_pair(dp[n - 1], n - 1));
        // Traverse the array from right to left.
        for (int i = n - 2; i >= 0; i--) {
            // Pop the elements from heap that are out of jumping range.
            while (!pq.empty() && pq.top().second > i + k)
                pq.pop();
            // Update the dp vector and the heap.
            dp[i] = pq.top().first + nums[i];
            pq.push(make_pair(dp[i], i));
        }
        return dp[0];
    }
};