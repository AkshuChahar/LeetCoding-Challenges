class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ans = 0;
        // Apply 'DFS'.
        for (int i=0; i<grid.size(); i++) {
            for (int j=0; j<grid[0].size(); j++) {
                // Check if we have found an island.
                if (grid[i][j] == 1) {
                    int count = 0;
                    // Initialise a stack for tracking how big the island is.
                    stack<pair<int, int>> s;
                    s.push(make_pair(i, j));
                    while (!s.empty()) {
                        int r = s.top().first, c = s.top().second;
                        s.pop();
                        // Check if the current cell is part of an island.
                        if (grid[r][c] == 1) {
                            count++;
                            // Mark the cell as visited.
                            grid[r][c] = 0;
                            // Search for cells in every direction.
                            if (r+1 < grid.size())
                                s.push(make_pair(r+1, c));
                            if (c+1 < grid[0].size())
                                s.push(make_pair(r, c+1));
                            if (r-1 >= 0)
                                s.push(make_pair(r-1, c));
                            if (c-1 >= 0)
                                s.push(make_pair(r, c-1));
                        }
                    }
                    // Update 'ans'.
                    ans = max(ans, count);
                }
            }
        }
        return ans;
    }
};