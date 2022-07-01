class Solution {
public:
    // Function for sorting.
    static bool cmp(vector<int>& a, vector<int>& b) {
        return a[1] > b[1];
    }

    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        int ans = 0, space = 0;
        // Sort the array in decreasing order of number of units per box.
        sort(boxTypes.begin(), boxTypes.end(), cmp);
        // Traverse the array.
        for (vector<int> box:boxTypes) {
            // Fill the truck.
            while (box[0] > 0 && space < truckSize) {
                // Update the number of boxes left and the space occupied.
                box[0]--;
                space++;
                ans += box[1];
            }
        }
        return ans;
    }
};