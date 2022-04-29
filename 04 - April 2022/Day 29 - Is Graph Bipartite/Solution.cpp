class Solution {
public:
    // Function to perform BFS.
    bool bfs(vector<vector<int>>& graph, vector<int>& color, int node) {
        queue<int> q;
        q.push(node);
        // Mark the node visited.
        color[node] = 1;
        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            for (auto it:graph[curr]) {
                // If we encounter an already twice visited, return 'false'.
                if (color[it] == color[curr])
                    return false;
                // Else add the node to queue and mark it as visited.
                if (color[it] == -1) {
                    q.push(it);
                    color[it] = 1 - color[curr];
                }
            }
        }
        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        // Initialise a node to keep track of visited nodes.
        vector<int> color(n, -1);
        for (int i = 0; i < n; i++) {
            // If the node is node is not visited yet, do a BFS.
            if (color[i] == -1) {
                if (!bfs(graph, color, i))
                    return false;
            }
        }
        return true;
    }
};