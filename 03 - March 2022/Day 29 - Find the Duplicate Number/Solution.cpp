class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // Here we will use Floyd's Algorithm.
        // Initialise 2 pointers.
        int slow = nums[0], fast = nums[0];
        // Check for cycle.
        do {
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while(slow != fast);

        // Get 1 pointer to start and move both pointers by 1 step at a time.
        slow = nums[0];
        while (slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }

        return fast;
    }
};