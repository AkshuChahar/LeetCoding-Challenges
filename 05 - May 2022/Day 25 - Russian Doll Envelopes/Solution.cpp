class Solution {
    // Function for sorting.
    static bool cmp(vector<int>& a, vector<int>& b) {
        if (a[0] == b[0])
            return a[1] > b[1];
        return a[0] < b[0];
    }

public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        int n = envelopes.size();
        // First sort the array with respect to the widths and heights.
        sort(envelopes.begin(), envelopes.end(), cmp);
        vector<int> heights;
        // Traverse the sorted array.
        for (int i = 0; i < n; i++) {
            // Get the current height.
            int height = envelopes[i][1];
            // Use 'lower_bound' to get the first element greater than or equal to current height in 'heights'.
            int ind = lower_bound(heights.begin(), heights.end(), height) - heights.begin();
            // If no greater element is present in the list, we add the current height to it.
            if (ind >= heights.size())
                heights.push_back(height);
            // Else we replace the element at 'ind' with current height.
            else
                heights[ind] = height;
        }
        return heights.size();
    }
};