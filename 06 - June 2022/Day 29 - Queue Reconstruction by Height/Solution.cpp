class Solution {
public:
    // Function for sorting.
    static bool cmp(vector<int>& a, vector<int>& b) {
        if (a[0] == b[0])
            return a[1] < b[1];
        return a[0] > b[0];
    }

    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        int n = people.size();
        vector<vector<int>> ans;
        // Sort the array.
        sort(people.begin(), people.end(), cmp);
        // Traverse through the array.
        for (int i = 0; i < n; i++) {
            // Consider the number of taller people as the index.
            int ind = people[i][1];
            // Insert the current element at their index.
            ans.insert(ans.begin() + ind, people[i]);
        }
        return ans;
    }
};