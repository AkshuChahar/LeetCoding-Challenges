class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        // Get the maximum difference between the vertical and horizontal cuts after sorting them.
        // Maximum horizontal difference.
        horizontalCuts.push_back(h);
        sort(horizontalCuts.begin(), horizontalCuts.end());
        int diff_h = horizontalCuts[0];
        for (int i = 1; i < horizontalCuts.size(); i++)
            diff_h = max(diff_h, horizontalCuts[i] - horizontalCuts[i-1]);
        // Maximum vertical difference.
        verticalCuts.push_back(w);
        sort(verticalCuts.begin(), verticalCuts.end());
        int diff_v = verticalCuts[0];
        for (int i = 1; i < verticalCuts.size(); i++)
            diff_v = max(diff_v, verticalCuts[i] - verticalCuts[i-1]);
        // Return the product of the maximum differences.
        return (1LL * diff_h * diff_v) % 1000000007;
    }
};