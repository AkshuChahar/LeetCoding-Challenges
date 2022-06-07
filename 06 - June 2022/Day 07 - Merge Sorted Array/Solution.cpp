class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        // Initialise 3 pointers, one each at the end of first, second and final array.
        int i = m - 1, j = n - 1, k = m + n - 1;
        // Traverse the arrays.
        while (i >= 0 && j >= 0) {
            // Put the greater element at 'k'.
            if (nums1[i] < nums2[j]) {
                nums1[k] = nums2[j];
                k--;
                j--;
            }
            else {
                nums1[k] = nums1[i];
                k--;
                i--;
            }
        }
        // Put the rest of the elements in the final array.
        while (j >= 0) {
            nums1[k] = nums2[j];
            k--;
            j--;
        }
    }
};