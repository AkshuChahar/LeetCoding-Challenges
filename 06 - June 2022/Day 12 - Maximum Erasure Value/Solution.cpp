class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n = nums.size(), ans = 0;
        // We will be 'Sliding Window Approach'.
        unordered_set<int> s;
        int res = 0, left = 0;
        // Traverse the array.
        for (int num:nums) {
            // Repeat untill the current element is already in the set.
            while (s.find(num) != s.end()) {
                // Subtract the number at the 'left' pointer from the current sum.
                res -= nums[left];
                // Delete the element from the set and move the 'left' pointer.
                s.erase(nums[left]);
                left++;
            }
            // Add 'num' to current sum and insert it into the set.
            res += num;
            s.insert(num);
            // Update 'ans'.
            ans = max(ans, res);
        }
        return ans;
    }
};