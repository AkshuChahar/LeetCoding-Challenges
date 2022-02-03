class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        // Initialise variable to store the count and a map to store the sums.
        int ans = 0;
        unordered_map<int, int> m;

        // Store the sum to all combinations of 'nums1' and 'nums2'.
        for (int i:nums1) {
            for (int j:nums2)
                m[i+j]++;
        }

        // Now check the stored sums against sums of all combinations of 'nums3' and 'nums4'.
        for (int k:nums3) {
            for (int l:nums4) {
                // We increment 'ans' by the frequency of the negative of sum of nums3[ind] and nums4[ind].
                ans += m[-(k+l)];
            }
        }

        return ans;
    }
};