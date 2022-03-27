class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        int n = mat.size();

        // Initialise a vector to store the answer and a set of pairs to keep track of rows and number of 1's.
        vector<int> ans = {};
        set<pair<int, int>> s;

        // Traverse the matrix row-wise.
        for (int i = 0; i < n; i++) {
            // Count the 1's.
            int temp = count(mat[i].begin(), mat[i].end(), 1);
            // Add into set.
            s.insert(make_pair(temp, i));
        }

        // Now add first 'k' rows into 'ans'.
        for (auto i:s) {
            if (k == 0)
                break;
            ans.push_back(i.second);
            k--;
        }

        return ans;
    }
};