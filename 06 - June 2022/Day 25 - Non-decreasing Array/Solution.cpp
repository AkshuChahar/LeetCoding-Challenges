class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        bool ans = false;
        // Traverse the array.
        for (int i = 1, curr, prev = nums[0]; i < nums.size(); i++) {
            curr = nums[i];
            // Check if the current element is smaller than the previous element.
            if (curr < prev) {
                // Check if we have already encountered the case of decreasing array.
                if (ans)
                    return false;
                // If this is the first time, set the answer to 'true'.
                ans = true;
                // Set the previous element equal to the current element and move to next element.
                prev = (i > 1 && nums[i-2] > curr) ? prev : curr;
                continue;
            }
            prev = curr;
        }
        return true;
    }
};