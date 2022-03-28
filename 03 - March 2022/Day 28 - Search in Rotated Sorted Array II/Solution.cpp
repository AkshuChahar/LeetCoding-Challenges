class Solution {
public:
    // Helper function to check if we can apply binary search to current searchspace.
    bool helper1(vector<int>& nums, int element, int start) {
        return nums[start] != element;
    }

    // Helper function to check in which searchspace the element exist.
    bool helper2(vector<int>& nums, int element, int start) {
        return nums[start] <= element;
    }

    bool search(vector<int>& nums, int target) {
        int n = nums.size();

        // Initialise 2 pointers.
        int start = 0, end = n - 1;
        // Traverse the array.
        while (start <= end) {
            // Get the middle element index.
            int mid = start + (end - start)/2;
            // If we have reached the target element.
            if (nums[mid] == target)
                return true;
            // If we cannot apply binary search to current searchspace, increment 'start'.
            if (!helper1(nums, nums[mid], start)) {
                start++;
                continue;
            }
            // Now we check which subarray the pivot element belongs to.
            bool pivot = helper2(nums, nums[mid], start);
            // Now we check which subarray the pivot element belongs to.
            bool tar = helper2(nums, target, start);
            // If 'pivot' and 'tar' exists in different arrays.
            if (pivot ^ tar) {
                // If 'pivot' is in first and 'tar' is in second, we search in (mid, end].
                if (pivot)
                    start = mid + 1;
                // Else we search in [start, mid).
                else
                    end = mid - 1;
            }
            // If 'pivot' and 'tar' exists in same arrays.
            else {
                // Apply classic binary search.
                if (nums[mid] < target)
                    start = mid + 1;
                else
                    end = mid - 1;
            }
        }

        return false;
    }
};