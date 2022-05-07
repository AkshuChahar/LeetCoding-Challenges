class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n = nums.size();
        // Initialise the a variable to keep track of middle element and a stack.
        int last = INT_MIN;
        stack<int> s;
        // Traverse the array backwards.
        for (int i = n - 1; i >= 0; i--) {
            // If we encounter an element less than 'last', we return 'true'.
            if (nums[i] < last)
                return true;
            else {
                // If 'pop' elements from the stack if they are greater than current element.
                while (!s.empty() && nums[i] > s.top()) {
                    // We update 'last' to be the second largest element.
                    last = s.top();
                    s.pop();
                }
            }
            // Push the current element in stack.
            s.push(nums[i]);
        }
        return false;
    }
};