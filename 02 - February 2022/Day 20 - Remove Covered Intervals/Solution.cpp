class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        // Sort the intervals.
        sort(intervals.begin(), intervals.end());

        // Variables to store the interval.
        int x = intervals[0][0], y = intervals[0][1];
        int n = intervals.size(), ans = 1;
        // Traverse the array.
        for (int i = 1; i < n; i++) {
            // If the current interval has both start and end points greater than '[x][y]', increment count.
            if (intervals[i][0] > x  && intervals[i][1] > y)
                ans++;
            // Update 'x' and 'y'.
            if (intervals[i][1] > y) {
                x = intervals[i][0];
                y = intervals[i][1];
            }
        }
        return ans;
    }
};