class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int ans = 0, h = heights.size();
        stack<int> s;
        s.push(0);

        for (int i = 1; i <= h; i++) {
            // Initialise current height. 0 when i==heights.length.
            int curr = (i == h) ? 0 : heights[i];
            // Now when a decreasing trend is encountered, check for area.
            while (!s.empty() && curr < heights[s.top()]) {
                // Current height is the top element of stack.
                int height = s.top();
                s.pop();
                // If stack is empty, then the width is equal to 'i', else it is i-s.top()-1.
                int width = (s.empty()) ? i : i-s.top()-1;
                ans = max(ans, heights[height]*width);
            }
            // Add index to stack.
            s.push(i);
        }
        return ans;
    }
};