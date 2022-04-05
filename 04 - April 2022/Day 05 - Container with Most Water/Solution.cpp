class Solution {
public:
    int maxArea(vector<int>& height) {
        // Initialise 2 pointers.
        int i = 0, j = height.size() - 1;
        int ans = 0;
        // Traverse the array.
        while (i < j) {
            // Update 'ans'.
            ans = max(ans, (j - i) * min(height[i], height[j]));
            // If 'i-th' height is less than 'j-th' height, move the 'i' pointer.
            if (height[i] < height[j])
                i++;
            // Else move the 'j' pointer.
            else
                j--;
        }
        return ans;
    }
};