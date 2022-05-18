class Solution {
public:
    // Function to perform DFS.
    void dfs(int node, int parent, int reach, vector<vector<int>>& ans, vector<int> adj[], vector<int>& visited, vector<int>& id, vector<int>& low) {
        // Set the id and lowest reachable node to 'reach', increment 'reach' and mark the node as visited.
        id[node] = low[node] = reach++;
        visited[node] = 1;
        // Traverse the neighbors.
        for (auto n:adj[node]) {
            // Skip the 'parent' node.
            if (n == parent)
                continue;
            // Check if the child('n') node is already visited.
            if (visited[n] == 0) {
                // Do the DFS.
                dfs(n, node, reach, ans, adj, visited, id, low);
                // Update the lowest reachable to minimum of child('n') and parent('node') node.
                low[node] = min(low[node], low[n]);
                // If the lowest reachable node of child('n') node is greater than id of parent('node') node, we have a 'critical connection'.
                if (low[n] > id[node])
                    ans.push_back({node, n});
            }
            // Update the lowest reachable node.
            else
                low[node] = min(low[node], id[n]);
        }
    }

    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        // Here we will be using 'Tarjan's Algorithm'.
        vector<vector<int>> ans;
        // Initialise vectors for adjacency list and keeping track of visited nodes, their id and lowest id node reachable as per 'Tarjan's Algorithm'.
        vector<int> adj[n];
        vector<int> visited(n, 0), id(n, -1), low(n, -1);

        for (vector<int> connection:connections) {
            adj[connection[0]].push_back(connection[1]);
            adj[connection[1]].push_back(connection[0]);
        }
        // Do a DFS starting at node 0 with parent node -1 and lowest reachable node as itself.
        dfs(0, -1, 0, ans, adj, visited, id, low);
        return ans;
    }
};