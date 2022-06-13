class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        // Start traversing from the 1st level as the 0th level will be the same for every combination.
        for (int level = 1; level < triangle.size(); level++) {
            // Check for different combinations and add the path sum in-place.
            for (int i = 0; i <= level; i++) {
                triangle[level][i] += min(triangle[level-1][min(i, (int)triangle[level-1].size()-1)], triangle[level-1][max(i-1, 0)]);
            }
        }
        return *min_element(begin(triangle.back()), end(triangle.back()));
    }
};