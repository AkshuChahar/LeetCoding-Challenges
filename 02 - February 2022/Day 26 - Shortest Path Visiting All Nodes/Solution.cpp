class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int n = graph.size();
        // Edge case: If graph has only 1 node.
        if (n == 1)
            return 0;

        // Mask value when all nodese are visited.
        int end = (1 << n) - 1;
        // List to store the visited nodes.
        vector<vector<int>> visited(n, vector<int>(end+1));
        queue<tuple<int, int, int>> q;

        // Fill the queue and 'visited' array.
        for (int i = 0; i < n; i++) {
            q.push(tuple<int, int, int> (i, 1 << i, 0));
            visited[i][1 << i] = true;
        }

        while (!q.empty()) {
            auto [ind, mask, steps] = q.front();
            q.pop();
            // If 'mask' equals 'end', return steps.
            if (mask == end)
                return steps;
            // Else if this node is not visited, add it to array.
            for (auto g:graph[ind]) {
                int temp = mask | 1 << g;
                if (!visited[g][temp]) {
                    q.push(tuple<int, int, int>(g, temp, steps+1));
                    visited[g][temp] = true;
                }
            }
        }
        return 0;
    }
};