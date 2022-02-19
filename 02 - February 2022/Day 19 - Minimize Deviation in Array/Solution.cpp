class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        // Initialise variables to keep track of current minimum deviation and current minimum element.
        int ans = INT_MAX, min_n = INT_MAX;

        // Now make all the odd numbers even by multiplying by 2. Also keep track of minimum element.
        for (int i = 0; i < nums.size(); i++) {
            nums[i] = (nums[i] % 2) ? nums[i] * 2 : nums[i];
            min_n = min(min_n, nums[i]);
        }

        // Make heap.
        make_heap(nums.begin(), nums.end());
        // Now keep dividing the maximum elements by 2 while they are even. Keep track of deviation and minimum element.
        while (nums[0] % 2 == 0) {
            ans = min(ans, nums[0] - min_n);
            min_n = min(min_n, nums[0] / 2);
            // Use 'pop_heap' to transfer the current maximum to end of vector.
            pop_heap(nums.begin(), nums.end());
            // Divide the last element of vector(current maximum) by 2.
            nums.back() /= 2;
            // Push the element back into the heap.
            push_heap(nums.begin(), nums.end());
        }

        // Return the minimum deviation.
        return min(ans, nums[0] - min_n);
    }
};